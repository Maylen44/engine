#ifndef CONFIG_H
#define CONFIG_H

#include "common_data.h"
#include <pugixml.hpp>

#define CONFIG ConfigManager::instance()
#define CONFIG_GET ConfigManager::instance()->m_configPOD

enum ConfigOption
{
	ConfigOption_WindowResolution_800x600,
	ConfigOption_WindowResolution_1280x800,
	ConfigOption_WindowResolution_1280x1024,
	ConfigOption_WindowResolution_1920x1080,
	ConfigOption_CellProportion
};

struct ConfigPOD
{
	float ConfigVersion;
	sf::Vector2i WindowResolution;
	int CellProportion;
};
struct ConfigOptionsPOD
{
	sf::Vector2i WindowResolution_800x600;
	sf::Vector2i WindowResolution_1280x800;
	sf::Vector2i WindowResolution_1280x1024;
	sf::Vector2i WindowResolution_1920x1080;
	int CellProportion_Default;
};

class ConfigManager
{
public:
	static ConfigManager* instance();
	void changeConfigTo(ConfigOption argToSetTo);
	ConfigPOD m_configPOD;
private:
	ConfigManager();
	const char* m_filePath;
	ConfigOptionsPOD m_configOptionsPOD;
};
#endif //CONFIG_H