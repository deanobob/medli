/*
 * Logger.h
 *
 *  Created on: 31 Aug 2013
 *      Author: deano
 */

#ifndef LOGGER_H_
#define LOGGER_H_

#define INFO(pMessage, ...) Logger::logInfo(__DATE__, __TIME__, __FILE__, __LINE__, pMessage, __VA_ARGS__);
#define DBUG(pMessage, ...) Logger::logDebug(__DATE__, __TIME__, __FILE__, __LINE__, pMessage, __VA_ARGS__);
#define ERR(pMessage, ...) Logger::logError(__DATE__, __TIME__, __FILE__, __LINE__, pMessage, __VA_ARGS__);

class Logger
{
	public:
		static void logInfo(const char* date, const char* time, const char* file, int line, const char* pMessage, ...);
		static void logDebug(const char* date, const char* time, const char* file, int line, const char* pMessage, ...);
		static void logError(const char* date, const char* time, const char* file, int line, const char* pMessage, ...);

	private:
		Logger();
		virtual ~Logger();
};

#endif /* LOGGER_H_ */
