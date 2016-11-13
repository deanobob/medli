/*
 * ResourceManager.h
 *
 *  Created on: 6 Sep 2013
 *      Author: deano
 */

#ifndef RESOURCEMANAGER_H_
#define RESOURCEMANAGER_H_

#include <map>
#include <string>
#include <allegro5/allegro.h>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>

class ResourceManager
{
  public:
    ResourceManager();
    virtual ~ResourceManager();

    void initialise();
    bool loadParentBitmap(const std::string& imageName);
    bool loadSubBitmap(const std::string& imageId, const std::string& imageName, unsigned int left,
        unsigned int top, unsigned int width, unsigned int height);
    bool loadSound(const std::string soundName);
    ALLEGRO_FONT* loadFont(const std::string& fontName, unsigned int fontSize);
    ALLEGRO_BITMAP* getBitmap(const std::string& imageId);
    ALLEGRO_SAMPLE* getSound(const std::string* pSoundName);
    ALLEGRO_FONT* getFont(const std::string& fontName, unsigned int fontSize);
    bool deleteImage(const std::string* pImageName);
    bool deleteSound(const std::string* pSoundName);
    void deleteAll();

    std::string getFullImagePath(std::string imageName);
    std::string getFullSoundPath(std::string soundName);
    std::string getFullFontPath(std::string fontName);

    void setImageAssetsPath(std::string assetsPath);
    std::string getImageAssetsPath();
    void setSoundAssetsPath(std::string assetsPath);
    std::string getSoundAssetsPath();
    void setFontAssetsPath(std::string assetsPath);
    std::string getFontAssetsPath();

    void convertImagesToVideoBitmaps();

  private:
    std::map<const std::string, std::map<unsigned int, ALLEGRO_FONT*> > fontCache_;
    std::map<const std::string, ALLEGRO_BITMAP*> parentImageMap_;
    std::map<const std::string, ALLEGRO_BITMAP*> imageMap_;
    std::map<const std::string, ALLEGRO_SAMPLE*> soundMap_;

    ALLEGRO_PATH* pImageAssetsPath_;
    ALLEGRO_PATH* pSoundAssetsPath_;
    ALLEGRO_PATH* pFontAssetsPath_;

    std::string imageAssetsPath_;
    std::string soundAssetsPath_;
    std::string fontAssetsPath_;
};

#endif /* RESOURCEMANAGER_H_ */
