/*
 * ResourceManager.cpp
 *
 *  Created on: 6 Sep 2013
 *      Author: deano
 */

#include "allegro5/allegro.h"
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_font.h>
#include "allegro5/allegro_image.h"
#include "../log/Logger.h"
#include "ResourceManager.h"

const std::string DEFAULT_IMAGE_ASSETS_PATH = "../assets/images/";
const std::string DEFAULT_SOUND_ASSETS_PATH = "../assets/sounds/";
const std::string DEFAULT_FONT_ASSETS_PATH = "../assets/fonts/";

ResourceManager::ResourceManager()
{
  this->imageAssetsPath_ = DEFAULT_IMAGE_ASSETS_PATH;
  this->soundAssetsPath_ = DEFAULT_SOUND_ASSETS_PATH;
  this->fontAssetsPath_ = DEFAULT_FONT_ASSETS_PATH;

  this->pImageAssetsPath_ = nullptr;
  this->pSoundAssetsPath_ = nullptr;
  this->pFontAssetsPath_ = nullptr;
}

ResourceManager::~ResourceManager()
{
  this->deleteAll();

  if (this->pImageAssetsPath_ != nullptr)
  {
    al_destroy_path(this->pImageAssetsPath_);
  }

  if (this->pSoundAssetsPath_ != nullptr)
  {
    al_destroy_path(this->pSoundAssetsPath_);
  }

  if (this->pFontAssetsPath_ != nullptr)
  {
    al_destroy_path(this->pFontAssetsPath_);
  }
}

void ResourceManager::initialise()
{
  this->pImageAssetsPath_ = al_get_standard_path(ALLEGRO_RESOURCES_PATH);
  al_append_path_component(this->pImageAssetsPath_, DEFAULT_IMAGE_ASSETS_PATH.c_str());

  this->pSoundAssetsPath_ = al_get_standard_path(ALLEGRO_RESOURCES_PATH);
  al_append_path_component(this->pSoundAssetsPath_, DEFAULT_SOUND_ASSETS_PATH.c_str());

  this->pFontAssetsPath_ = al_get_standard_path(ALLEGRO_RESOURCES_PATH);
  al_append_path_component(this->pFontAssetsPath_, DEFAULT_FONT_ASSETS_PATH.c_str());
}

bool ResourceManager::loadSound(const std::string soundName)
{
  al_change_directory(al_path_cstr(this->pSoundAssetsPath_, ALLEGRO_NATIVE_PATH_SEP));

  ALLEGRO_SAMPLE* pSound = al_load_sample(soundName.c_str());

  if (pSound != nullptr)
  {
    this->soundMap_[soundName] = pSound;

    DBUG("Loaded file: %s", soundName.c_str());

    return true;
  }
  else
  {
    ERR("Failed to load image %s", soundName.c_str());
  }

  return false;
}

bool ResourceManager::loadParentBitmap(const std::string& imageName)
{
  al_change_directory(al_path_cstr(this->pImageAssetsPath_, ALLEGRO_NATIVE_PATH_SEP));

  ALLEGRO_BITMAP* pBitmap = al_load_bitmap(imageName.c_str());

  if (pBitmap != nullptr)
  {
    this->parentImageMap_[imageName] = pBitmap;

    DBUG("Loaded file: %s", imageName.c_str());

    return true;
  }
  else
  {
    ERR("Failed to load image %s", imageName.c_str());
  }

  return false;
}

bool ResourceManager::loadSubBitmap(const std::string& imageId, const std::string& imageName,
    unsigned int left, unsigned int top, unsigned int width, unsigned int height)
{
  std::map<const std::string, ALLEGRO_BITMAP*>::const_iterator it =
      this->parentImageMap_.find(imageName);

  if (it != this->parentImageMap_.end())
  {
    ALLEGRO_BITMAP* pParentBitmap = (*it).second;
    if (pParentBitmap != nullptr)
    {
      this->imageMap_[imageId] = al_create_sub_bitmap(pParentBitmap, left, top, width, height);
      return true;
    }
  }

  return false;
}

ALLEGRO_FONT* ResourceManager::loadFont(const std::string& fontName, unsigned int fontSize)
{
  al_change_directory(al_path_cstr(this->pFontAssetsPath_, '/'));

  ALLEGRO_FONT* pFont = al_load_ttf_font(fontName.c_str(), fontSize, 0);

  if (pFont != nullptr)
  {
    return pFont;
  }
  else
  {
    ERR("Failed to load font %s", fontName.c_str());
  }

  return nullptr;
}

ALLEGRO_BITMAP* ResourceManager::getBitmap(const std::string& imageId)
{
  std::map<std::string, ALLEGRO_BITMAP*>::iterator it = this->imageMap_.find(imageId);
  if (it != this->imageMap_.end())
  {
    return (*it).second;
  }
  else
  {
    ERR("Failed to find image: %s", imageId.c_str());
  }

  return nullptr;
}

ALLEGRO_SAMPLE* ResourceManager::getSound(const std::string* pSoundName)
{
  std::map<std::string, ALLEGRO_SAMPLE*>::iterator it = this->soundMap_.find(*pSoundName);
  if (it != this->soundMap_.end())
  {
    return this->soundMap_[*pSoundName];
  }

  return nullptr;
}

ALLEGRO_FONT* ResourceManager::getFont(const std::string& fontName, unsigned int fontSize)
{
  std::map<const std::string, std::map<unsigned int, ALLEGRO_FONT*> >::iterator fontIt = this->fontCache_.find(fontName);
  if (fontIt == this->fontCache_.end())
  {
    this->fontCache_[fontName] = std::map<unsigned int, ALLEGRO_FONT*>();
  }

  fontIt = this->fontCache_.find(fontName);
  if (fontIt != this->fontCache_.end())
  {
    std::map<unsigned int, ALLEGRO_FONT*>::iterator sizeIt = (*fontIt).second.find(fontSize);
    if (sizeIt == (*fontIt).second.end())
    {
      ALLEGRO_FONT* pFont = this->loadFont(fontName, fontSize);

      if (pFont != nullptr)
      {
        DBUG("Loaded font: %s size %d", fontName.c_str(), fontSize);
      }

      (*fontIt).second[fontSize] = pFont;
    }
  }

  return this->fontCache_[fontName][fontSize];
}

bool ResourceManager::deleteSound(const std::string* pSoundName)
{
  bool rc = false;

  std::map<std::string, ALLEGRO_SAMPLE*>::iterator it = this->soundMap_.find(*pSoundName);
  if (it != this->soundMap_.end())
  {
    al_destroy_sample((*it).second);

    this->soundMap_.erase(it);

    DBUG("Unloaded file: %s", pSoundName->c_str());

    rc = true;
  }

  return rc;
}

bool ResourceManager::deleteImage(const std::string* pImageName)
{
  bool rc = false;

  std::map<std::string, ALLEGRO_BITMAP*>::iterator it = this->parentImageMap_.find(*pImageName);
  if (it != this->parentImageMap_.end())
  {
    al_destroy_bitmap((*it).second);

    this->parentImageMap_.erase(it);

    DBUG("Unloaded file: %s", pImageName->c_str());

    rc = true;
  }

  return rc;
}

void ResourceManager::deleteAll()
{
  std::map<std::string, ALLEGRO_BITMAP*>::iterator imageIt;
  for (imageIt = this->parentImageMap_.begin();
       imageIt != this->parentImageMap_.end();
       ++imageIt)
  {
    al_destroy_bitmap((*imageIt).second);

    DBUG("Unloaded file: %s", (*imageIt).first.c_str());
  }

  this->parentImageMap_.clear();


  std::map<std::string, ALLEGRO_SAMPLE*>::iterator soundIt;
  for (soundIt = this->soundMap_.begin();
       soundIt != this->soundMap_.end();
       ++soundIt)
  {
    al_destroy_sample((*soundIt).second);

    DBUG("Unloaded file: %s", (*soundIt).first.c_str());
  }

  this->soundMap_.clear();


  std::string fontName;
  std::map<std::string, std::map<unsigned int, ALLEGRO_FONT*> >::iterator fontIt;
  for (fontIt = this->fontCache_.begin();
       fontIt != this->fontCache_.end();
       ++fontIt)
  {
    fontName = (*fontIt).first;

    std::map<unsigned int, ALLEGRO_FONT*>::iterator sizeIt;
    for (sizeIt = (*fontIt).second.begin();
         sizeIt != (*fontIt).second.end();
         ++sizeIt)
    {
      if ((*sizeIt).second != nullptr)
      {
        al_destroy_font((*sizeIt).second);

        DBUG("Unloaded font: %s size: %d", fontName.c_str(), (*sizeIt).first);
      }
    }
  }

  this->fontCache_.clear();
}

std::string ResourceManager::getFullImagePath(std::string imageName)
{
  return this->getImageAssetsPath() + imageName;
}

std::string ResourceManager::getFullSoundPath(std::string soundName)
{
  return this->getSoundAssetsPath() + soundName;
}

std::string ResourceManager::getFullFontPath(std::string fontName)
{
  return this->getFontAssetsPath() + fontName;
}

void ResourceManager::setImageAssetsPath(std::string assetsPath)
{
  this->imageAssetsPath_ = assetsPath;
}

std::string ResourceManager::getImageAssetsPath()
{
  return this->imageAssetsPath_;
}

void ResourceManager::setSoundAssetsPath(std::string assetsPath)
{
  this->soundAssetsPath_ = assetsPath;
}

std::string ResourceManager::getSoundAssetsPath()
{
  return this->soundAssetsPath_;
}

void ResourceManager::setFontAssetsPath(std::string assetsPath)
{
  this->fontAssetsPath_ = assetsPath;
}

std::string ResourceManager::getFontAssetsPath()
{
  return this->fontAssetsPath_;
}

void ResourceManager::convertImagesToVideoBitmaps()
{
  ALLEGRO_BITMAP* pCurrentImage = nullptr;
  ALLEGRO_BITMAP* pConvertedImage = nullptr;
  for (auto image : this->parentImageMap_)
  {
    pCurrentImage = image.second;
    if (pCurrentImage != nullptr)
    {
      if (!(al_get_bitmap_flags(pCurrentImage) & ALLEGRO_VIDEO_BITMAP))
      {
        DBUG("Converting %s video bitmap", image.first.c_str());

        pConvertedImage = al_clone_bitmap(pCurrentImage);
        if (pConvertedImage != nullptr)
        {
          this->parentImageMap_[image.first] = pConvertedImage;
          al_destroy_bitmap(pCurrentImage);
        }
        pConvertedImage = nullptr;
      }
    }
  }
}
