#include "tools.hpp"
#include "myExceptions.hpp"

void from_json(const nlohmann::json& j, std::vector<std::string>& srcURL, size_t& maxPages, bool& bounded)
{
    j.at("srcURL").get_to(srcURL);
    j.at("maxPages").get_to(maxPages);
    j.at("bounded").get_to(bounded);
}

void isNetworkConnected()
{
    if(system("ping -c 1 google.com >> /dev/null")) {
        throw se::CommunicationError("Check your network connection");
    }
}

void makeLowercase(std::string& string)
{
    std::transform(string.begin(), string.end(), string.begin(), [](unsigned char c){ return std::tolower(c);});
}

