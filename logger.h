#ifndef LOGGER_H
#define LOGGER_H

#include <sstream>

#define LOGGER Logger::instance()

class Logger
{
public:
	static Logger* instance();
	void log(const char* format, ...);

private:
	Logger() {};
};
#endif //LOGGER_H