/*
 * Utilities.h
 *
 *  Created on: 12 Sep 2013
 *      Author: deano
 */

#ifndef UTILITIES_H_
#define UTILITIES_H_

#include <string>
#include <vector>

/**
 * Multiplication value from format to milliseconds
 */
enum TimeFormat : int
{
  MINUTES = 60000,
  SECONDS = 1000,
  MILLISECONDS = 1
};

class Utilities
{
  public:
    static const double MILLISECONDS_IN_ONE_SECOND;
    static const double MICROSECONDS_IN_ONE_SECOND;
    static const double MICROSECONDS_IN_ONE_MILLISECOND;

    static float clamp(float value, float min, float max);
    static int stringToInteger(const std::string str);
    static std::string integerToString(int value);
    static bool stringToBool(const std::string str);
    static std::string boolToString(bool value);
    static float stringToFloat(const std::string str);
    static std::string floatToString(float value);
    static double stringToDouble(const std::string str);
    static std::string doubleToString(double value);
    static std::string triml(std::string text);
    static std::string trimr(std::string text);
    static std::string trim(std::string text);
    static std::vector<std::string> split(std::string text, std::string delimiter);
    static float smoothStep(float edge1, float edge2, float x);
    static float linearTween(float time, float startValue, float endValue, float duration);
    static double getDistanceBetweenPoints(double x1, double y1, double x2, double y2);
    static void sleep(double t, TimeFormat format = MILLISECONDS);
    static double getCurrentTimeInSeconds();

  private:
    Utilities();
    virtual ~Utilities();
};

#endif /* UTILITIES_H_ */
