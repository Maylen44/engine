#include "config.h"
#include <unordered_map>

ConfigManager::ConfigManager()
    : m_filePath("config.xml")
    , m_configPOD()
    , m_configOptionsPOD()
{
    pugi::xml_document doc;
    if (doc.load_file(m_filePath))
    {
        m_configPOD.ConfigVersion = doc.select_node("/settings/saved_config/config_version").node().attribute("value").as_float();
        m_configPOD.WindowResolution.x = doc.select_node("/settings/saved_config/window_resolution").node().attribute("x").as_int();
        m_configPOD.WindowResolution.y = doc.select_node("/settings/saved_config/window_resolution").node().attribute("y").as_int();
        m_configPOD.CellProportion = doc.select_node("/settings/saved_config/cell_proportion").node().attribute("value").as_int();

        m_configOptionsPOD.WindowResolution_800x600.x = doc.select_node("/settings/window_resolution/resolution_800x600").node().attribute("x").as_int();
        m_configOptionsPOD.WindowResolution_800x600.y = doc.select_node("/settings/window_resolution/resolution_800x600").node().attribute("y").as_int();
        m_configOptionsPOD.WindowResolution_1280x800.x = doc.select_node("/settings/window_resolution/resolution_1280x800").node().attribute("x").as_int();
        m_configOptionsPOD.WindowResolution_1280x800.y = doc.select_node("/settings/window_resolution/resolution_1280x800").node().attribute("y").as_int();
        m_configOptionsPOD.WindowResolution_1280x1024.x = doc.select_node("/settings/window_resolution/resolution_1280x1024").node().attribute("x").as_int();
        m_configOptionsPOD.WindowResolution_1280x1024.y = doc.select_node("/settings/window_resolution/resolution_1280x1024").node().attribute("y").as_int();
        m_configOptionsPOD.WindowResolution_1920x1080.x = doc.select_node("/settings/window_resolution/resolution_1920x1080").node().attribute("x").as_int();
        m_configOptionsPOD.WindowResolution_1920x1080.y = doc.select_node("/settings/window_resolution/resolution_1920x1080").node().attribute("y").as_int();
        m_configOptionsPOD.CellProportion_Default = doc.select_node("/settings/window_resolution/proportion_default").node().attribute("value").as_int();
    }
}

ConfigManager* ConfigManager::instance()
{
    static ConfigManager* ptrConfigManager = new ConfigManager();
    return ptrConfigManager;
}

void ConfigManager::changeConfigTo(ConfigOption argToSetTo)
{
    switch (argToSetTo)
    {
    case ConfigOption_WindowResolution_800x600:
        m_configPOD.WindowResolution = m_configOptionsPOD.WindowResolution_800x600;
        break;
    case ConfigOption_WindowResolution_1280x800:
        m_configPOD.WindowResolution = m_configOptionsPOD.WindowResolution_1280x800;
        break;
    case ConfigOption_WindowResolution_1280x1024:
        m_configPOD.WindowResolution = m_configOptionsPOD.WindowResolution_1280x1024;
        break;
    case ConfigOption_WindowResolution_1920x1080:
        m_configPOD.WindowResolution = m_configOptionsPOD.WindowResolution_1920x1080;
        break;
    case ConfigOption_CellProportion:
        m_configPOD.CellProportion = m_configOptionsPOD.CellProportion_Default;
        break;
    default:
        break;
    }
    m_configPOD.ConfigVersion += 0.01f;

    pugi::xml_document doc;
    if (doc.load_file(m_filePath))
    {
        doc.select_node("/settings/saved_config/config_version").node().attribute("value").set_value(m_configPOD.ConfigVersion);
        doc.select_node("/settings/saved_config/window_resolution").node().attribute("x").set_value(m_configPOD.WindowResolution.x);
        doc.select_node("/settings/saved_config/window_resolution").node().attribute("y").set_value(m_configPOD.WindowResolution.y);
        doc.select_node("/settings/saved_config/cell_proportion").node().attribute("value").set_value(m_configPOD.CellProportion);
        doc.save_file("config.xml");
    }
}