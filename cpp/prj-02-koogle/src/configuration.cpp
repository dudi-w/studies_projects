#include "configuration.hpp"
#include <iostream>

se::Configuration::Configuration(std::string const& configurationFilePath)
{
    laodConfiguration(configurationFilePath);
}

std::vector<std::string> const& se::Configuration::getSrcURLs() const
{
    return m_srcURL;
}

size_t se::Configuration::maxPages() const
{
    return m_maxPages;
}

bool se::Configuration::isBounded() const
{
    return m_bounded;
}

se::Configuration& se::Configuration::getInstance(std::string const& configurationFilePath)
{
    static se::Configuration configuration(configurationFilePath);
    return configuration;
}

void se::Configuration::laodConfiguration(std::string const& configurationFilePath)
{
    try{
        std::ifstream input_file(configurationFilePath);
        nlohmann::json j;
        input_file >> j;
        from_json(j, m_srcURL, m_maxPages, m_bounded);
    }
    catch(const nlohmann::json::exception& e)
    {
        throw std::runtime_error("load configuration file failed ,check yuor configuration file");
    }  
}

void from_json(const nlohmann::json& j, std::vector<std::string>& srcURL, size_t& maxPages, bool& bounded)
{
    j.at("srcURL").get_to(srcURL);
    j.at("maxPages").get_to(maxPages);
    j.at("bounded").get_to(bounded);
}