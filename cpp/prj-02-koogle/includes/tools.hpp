#ifndef TOOLS_HPP
#define TOOLS_HPP

#include <nlohmann/json.hpp>

#include "request.hpp"
#include "result.hpp"
void from_json(const nlohmann::json& j, std::vector<std::string>& srcURL, size_t& maxPages, bool& bounded, size_t& maxTreads);
void from_json(const nlohmann::json& j, std::vector<std::string>& query);
void from_json(const nlohmann::json& j, std::vector<std::pair<std::string, size_t>>& result);
void isNetworkConnected();
void makeLowercase(std::string& word);
se::Request convertToRequest(std::string const& message);
se::Result convertToResult(std::string const& message);
std::string convertToString(se::Result const& result);
std::string convertToString(se::Request const& request);
void extractHTTP(std::string const& srcPage, std::string& result);
void extractPrefix(std::string const& srcPage, std::string& result);

#endif
