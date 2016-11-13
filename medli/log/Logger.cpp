/*
 * Logger.cpp
 *
 *  Created on: 31 Aug 2013
 *      Author: deano
 */

#include <cstdarg>
#include <stdio.h>
#include "Logger.h"

void Logger::logInfo(const char* date, const char* time, const char* file, int line, const char* pMessage, ...)
{
#ifdef DEBUG
	if (pMessage != nullptr)
	{
		fprintf(stdout, "(%s %s) %s:%d - INFO: ", date, time, file, line);

		va_list args;
		va_start(args, pMessage);
		vfprintf(stdout, pMessage, args);
		va_end(args);

		fprintf(stdout, "\n");
	}
#endif
}

void Logger::logDebug(const char* date, const char* time, const char* file, int line, const char* pMessage, ...)
{
#ifdef DEBUG
	if (pMessage != nullptr)
	{
		fprintf(stdout, "(%s %s) %s:%d - DEBUG: ", date, time, file, line);

		va_list args;
		va_start(args, pMessage);
		vfprintf(stdout, pMessage, args);
		va_end(args);

		fprintf(stdout, "\n");
	}
#endif
}

void Logger::logError(const char* date, const char* time, const char* file, int line, const char* pMessage, ...)
{
  //char buf[10000]; //TODO: implement this so it's only used in a release build
  //setvbuf(stdout, buf, _IOFBF, sizeof(buf));

	if (pMessage != nullptr)
	{
		fprintf(stderr, "(%s %s) %s:%d - ERROR: ", date, time, file, line);

		va_list args;
		va_start(args, pMessage);
		vfprintf(stderr, pMessage, args);
		va_end(args);

		fprintf(stderr, "\n");
	}
}

Logger::Logger()
{

}

Logger::~Logger()
{

}
