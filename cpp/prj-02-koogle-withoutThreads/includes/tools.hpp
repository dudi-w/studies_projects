#ifndef TOOLS_HPP
#define TOOLS_HPP

#include <nlohmann/json.hpp>

#include "request.hpp"
#include "result.hpp"

void from_json(const nlohmann::json& j, std::vector<std::string>& srcURL, size_t& maxPages, bool& bounded);
void from_json(const nlohmann::json& j, std::vector<std::string>& query);
void from_json(const nlohmann::json& j, std::vector<std::pair<std::string, size_t>>& result);
void isNetworkConnected();
void makeLowercase(std::string& word);
se::Request convertToRequest(std::string const& message);//? convert
se::Result convertToResult(std::string const& message);//? convert
std::string convertToString(se::Result const& result);//? convert
std::string convertToString(se::Request const& request);//? convert
void extractHTTP(std::string const& srcPage, std::string& result);
void extractPrefix(std::string const& srcPage, std::string& result);

#endif
