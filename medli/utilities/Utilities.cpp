/*
 * Utilities.cpp
 *
 *  Created on: 12 Sep 2013
 *      Author: deano
 */

#include <math.h>
#include <sstream>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>
#ifdef WINDOWS
#include <windows.h>
#else
#include <unistd.h>
#endif
#include "Utilities.h"

const double Utilities::MILLISECONDS_IN_ONE_SECOND = 1000.0;
const double Utilities::MICROSECONDS_IN_ONE_SECOND = 1000000.0;
const double Utilities::MICROSECONDS_IN_ONE_MILLISECOND = 1000.0;
const std::string WHITESPACE = " \n\r\t";

float Utilities::clamp(float value, float min, float max)
{
  return (value > min) ? (value < max) ? value : max : min;
}

int Utilities::stringToInteger(const std::string str)
{
  return atoi(str.c_str());
}

std::string Utilities::integerToString(int value)
{
  std::ostringstream os ;

  os << value ;

  return os.str() ;
}

bool Utilities::stringToBool(const std::string str)
{
  return atoi(str.c_str()) == 1 ? true : false;
}

std::string Utilities::boolToString(bool value)
{
  std::ostringstream os ;

  os << value ;

  return os.str() ;
}

float Utilities::stringToFloat(const std::string str)
{
  return (float)atof(str.c_str());
}

std::string Utilities::floatToString(float value)
{
  std::ostringstream os ;

  os << value ;

  return os.str() ;
}

double Utilities::stringToDouble(const std::string str)
{
  return atof(str.c_str());
}

std::string Utilities::doubleToString(double value)
{
  std::ostringstream os ;

  os << value ;

  return os.str() ;
}

std::string Utilities::triml(std::string text)
{
  return text.erase(0, text.find_first_not_of(WHITESPACE));
}

std::string Utilities::trimr(std::string text)
{
  return text.erase(text.find_last_not_of(WHITESPACE) + 1);
}

std::string Utilities::trim(std::string text)
{
  return triml(trimr(text));
}

std::vector<std::string> Utilities::split(std::string text, std::string delimiter)
{
  std::vector<std::string> results;

  char str[text.length() + 1];
  strncpy(str, text.c_str(), text.length() + 1);
  const char* p;
  for (p = strtok(str, delimiter.c_str());
       p;
       p = strtok(nullptr, delimiter.c_str()))
  {
    results.push_back(trim(std::string(p)));
  }

  return results;
}

float Utilities::smoothStep(float edge0, float edge1, float x)
{
  return x * x * x * (x * (x * 6 - 15) + 10);
}

float Utilities::linearTween(float time, float startValue, float changeValue, float duration)
{
  return changeValue * time / duration + startValue;
}

double Utilities::getDistanceBetweenPoints(double x1, double y1, double x2, double y2)
{
  double xDist = x2 - x1;
  double yDist = y2 - y1;

  return sqrt((xDist * xDist) + (yDist * yDist));
}

void Utilities::sleep(double t, TimeFormat format)
{
  switch (format)
  {
    case SECONDS:
      t = t * MILLISECONDS_IN_ONE_SECOND;
      break;
    case MILLISECONDS:
    default:
      break;
  }

#ifdef WINDOWS
  Sleep(t);
#else
  usleep(t * MICROSECONDS_IN_ONE_MILLISECOND);
#endif
}

double Utilities::getCurrentTimeInSeconds()
{
  struct timeval tv;
  gettimeofday(&tv, nullptr);
  return tv.tv_sec + (tv.tv_usec / MICROSECONDS_IN_ONE_SECOND);
}

Utilities::Utilities()
{

}

Utilities::~Utilities()
{

}

