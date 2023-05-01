#include <iostream>

#include "configuration.hpp"
#include "tools.hpp"

se::Configuration::Configuration(std::string const& configurationFilePath)
{
    laodConfiguration(configurationFilePath);
}

std::vector<std::string> const& se::Configuration::getSrcURLs()
{
    return getInstance().m_srcURL;
}

size_t se::Configuration::maxPages()
{
    return getInstance().m_maxPages;
}

bool se::Configuration::isBounded()
{
    return getInstance().m_bounded;
}

size_t se::Configuration::maxThreads()
{
    return getInstance().m_maxThreads;
}

se::Configuration& se::Configuration::getInstance()
{
    static se::Configuration configuration("config.json");
    return configuration;
}

void se::Configuration::laodConfiguration(std::string const& configurationFilePath)
{
    try{
        std::ifstream input_file(configurationFilePath);
        nlohmann::json j;
        input_file >> j;
        from_json(j, m_srcURL, m_maxPages, m_bounded , m_maxThreads);
    }
    catch(const nlohmann::json::exception& e)
    {
        throw std::runtime_error("load configuration file failed ,check yuor configuration file");
    }  
}