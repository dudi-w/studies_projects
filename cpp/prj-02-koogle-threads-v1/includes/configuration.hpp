#ifndef CONFIGURATION_HPP
#define CONFIGURATION_HPP

#include <string>
#include <vector>
#include <fstream>

namespace se{

class Configuration
{
public:
    ~Configuration() = default;
    std::vector<std::string> static const& getSrcURLs();
    size_t static maxPages();
    size_t static maxThreads();
    bool static isBounded();

private:
    explicit Configuration(std::string const& configurationFilePath);
    Configuration(Configuration const& other) = delete;
    Configuration& operator=(Configuration const& other) = delete;

    static Configuration& getInstance();
    void laodConfiguration(std::string const& configurationFilePath);

private:
    std::vector<std::string> m_srcURL;
    size_t m_maxPages;
    size_t m_maxThreads;
    bool m_bounded;
};

}

#endif
