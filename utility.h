#ifndef UTILITY_H
#define UTILITY_H

#include <time.h>
#include <iomanip>
#include <iostream>
#include <string>

namespace Utility
{
	std::string getCurrentDateTime()
	{
		time_t now = time(nullptr);
		struct tm tstruct;
		char buf[80];
		localtime_s(&tstruct, &now);
		strftime(buf, sizeof(buf), "%Y-%m-%d-%X", &tstruct);
		return buf;
	}
}

#endif //UTILITY_H