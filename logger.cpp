#include "logger.h"
#include "utility.h"
#include <fstream>
#include <cstdarg>

static Logger* ptrLogger = nullptr;
static const char* logFilePath = "utility/loggs/log.txt";
static std::ofstream logFile;

Logger* Logger::instance()
{
	if (ptrLogger == nullptr)
	{
		ptrLogger = new Logger();
		logFile.open(logFilePath, std::ios::out | std::ios::app);
	}
	return ptrLogger;
}

void Logger::log(const char* format, ...)
{
	std::ostringstream oss;
	va_list args;
	va_start(args, format);
	char buffer[256];
	vsnprintf(buffer, sizeof(buffer), format, args);
	oss << buffer;
	va_end(args);
	logFile << Utility::getCurrentDateTime() << ":\t";
	logFile << oss.str() << std::endl;
}