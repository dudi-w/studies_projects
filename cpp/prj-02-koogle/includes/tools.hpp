#ifndef TOOLS_HPP
#define TOOLS_HPP

#include <nlohmann/json.hpp>

void from_json(const nlohmann::json& j, std::vector<std::string>& srcURL, size_t& maxPages, bool& bounded);
void isNetworkConnected();

#endif
