#include "logger.h"
#include "config.h"

#include <iostream>

int main()
{
	LOGGER->log("Test to test %d %s %d", 556, "fff", 587);
	CONFIG_GET.WindowResolution.x;
	std::cout << CONFIG_GET.WindowResolution.x << std::endl;
	CONFIG->changeConfigTo(ConfigOption_WindowResolution_1280x800);
	std::cout << CONFIG_GET.WindowResolution.x << std::endl;


	return 0;
}


/*
	struct PlainOldData
		serialize
		version + weight in biyts
			header and content
	read config
	write config
*/