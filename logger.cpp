#include "logger.h"
#include "utility.h"
#include <sstream>
#include <fstream>
#include <cstdarg>

//TODO path is magic
static const char* logFilePath = "utility/loggs/log.txt";
static std::ofstream logFile;

Logger::Logger()
{
	logFile.open(logFilePath, std::ios::out | std::ios::app);
}

Logger* Logger::instance()
{
	static Logger* ptrLogger = new Logger();
	return ptrLogger;
}

void Logger::log(const char* format, ...)
{
	std::ostringstream oss;
	va_list args;
	va_start(args, format);
	char buffer[256]; //TODO Buffer size is magic
	vsnprintf(buffer, sizeof(buffer), format, args);
	oss << buffer;
	va_end(args);
	logFile << Utility::getCurrentDateTime() << ":\t";
	logFile << oss.str() << std::endl;
}