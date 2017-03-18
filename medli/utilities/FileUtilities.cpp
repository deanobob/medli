/*
 * FileUtilities.cpp
 *
 *  Created on: 26 Feb 2017
 *      Author: deano
 */

#include <iostream>
#include "../log/Logger.h"
#include "FileUtilities.h"

FileUtilities::FileUtilities()
{

}

FileUtilities::~FileUtilities()
{

}

//TODO: replace with something that doesn't require the caller to free
char* FileUtilities::readFile(const std::string& fileName)
{
  FILE* pFile = fopen( fileName.c_str(), "r" );
  if ( !pFile )
  {
    return 0;
  }

  fseek( pFile, 0, SEEK_END );
  auto length = ftell( pFile ) + 1;
  fseek( pFile, 0, SEEK_SET );

  void* buffer = malloc( length );
  fread( buffer, length, 1, pFile );
  fclose( pFile );

  ((char*)buffer)[ length-1 ] = 0;

  return (char*)buffer;
}
