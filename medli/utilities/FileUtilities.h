/*
 * FileUtilities.h
 *
 *  Created on: 26 Feb 2017
 *      Author: deano
 */

#ifndef MEDLI_UTILITIES_FILEUTILITIES_H_
#define MEDLI_UTILITIES_FILEUTILITIES_H_

#include <string>

class FileUtilities
{
  public:
    static char* readFile(const std::string& fileName);

  private:
    FileUtilities();
    virtual ~FileUtilities();
};

#endif /* MEDLI_UTILITIES_FILEUTILITIES_H_ */
