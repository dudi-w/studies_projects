#include "tools.hpp"
#include "myExceptions.hpp"
#include <iostream>

void from_json(const nlohmann::json& j, std::vector<std::string>& srcURL, size_t& maxPages, bool& bounded)
{
    j.at("srcURL").get_to(srcURL);
    j.at("maxPages").get_to(maxPages);
    j.at("bounded").get_to(bounded);
}

void from_json(const nlohmann::json& j, std::vector<std::string>& request)
{
    j.at("request").get_to(request);
}

void from_json(const nlohmann::json& j, std::vector<std::pair<std::string, size_t>>& result)
{
    j.at("result").get_to(result);
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

se::Request convertToRequest(std::string const& message)
{
    std::stringstream strs(message);
    std::vector<std::string> query;
    nlohmann::json j;
    strs >> j;
    from_json(j, query);
    return se::Request(query);
}

se::Result convertToResult(std::string const& message)
{
    std::stringstream strs(message);
    linkVec result;
    nlohmann::json j;
    strs >> j;
    from_json(j, result);
    return se::Result(result);
}

std::string convertToString(se::Result const& result)
{
    nlohmann::json data;
    data["result"] = result.getResult();
    return data.dump();
}

std::string convertToString(se::Request const& request)
{
    nlohmann::json data;
    data["request"] = request.getRequest();
    return data.dump();
}