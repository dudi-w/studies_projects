#include <regex>
#include <iostream>
#include "tools.hpp"
#include "myExceptions.hpp"

void from_json(const nlohmann::json& j, std::vector<std::string>& srcURL, size_t& maxPages, bool& bounded, size_t& maxTreads)
{
    j.at("srcURL").get_to(srcURL);
    j.at("maxPages").get_to(maxPages);
    j.at("bounded").get_to(bounded);
    j.at("maxThreads").get_to(maxTreads);
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

void extractHTTP(std::string const& srcPage, std::string& result)
{
    std::regex txt_regex("https?:");
    std::smatch HTTPmatch;
    if(std::regex_search(srcPage, HTTPmatch, txt_regex)){
        result = static_cast<std::string>(HTTPmatch[0]);
    }
}

void extractPrefix(std::string const& srcPage, std::string& result)
{
    std::regex preRegex("^https?:\\/\\/(?:[a-zA-Z0-9]+)(?:\\.[a-zA-Z0-9]+)+");
    std::smatch preMatch;
    if(std::regex_search(srcPage, preMatch, preRegex)){
        result = preMatch[0];
    }else{
        result = "";
    }
}