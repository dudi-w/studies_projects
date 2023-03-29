#ifndef CONFIGURATION_HPP
#define CONFIGURATION_HPP

#include <string>
#include <vector>
#include <fstream>
#include <nlohmann/json.hpp>

namespace se{

class Configuration
{
public:
    static Configuration& getInstens(std::string const& configurationFilePath);
    ~Configuration() = default;

    std::vector<std::string> const& getSrcURLs() const;
    size_t maxPages() const;
    bool isBounded() const;

private:
    explicit Configuration(std::string const& configurationFilePath);
    Configuration(Configuration const& other) = delete;
    Configuration& operator=(Configuration const& other) = delete;

    void laodConfiguration(std::string const& configurationFilePath);

private:
    std::vector<std::string> m_srcURL;
    size_t m_maxPages;
    bool m_bounded;
};

}

void from_json(const nlohmann::json& j, std::vector<std::string>& srcURL, size_t& maxPages, bool& bounded);

#endif
