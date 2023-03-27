#ifndef TUI_HPP
#define TUI_HPP

#include <iostream>
#include <memory>
#include <regex>

#include "simpleRequest.hpp"
#include "result.hpp"

namespace se{//Search Engin

class TextUI
{
public:
    TextUI();
    TextUI(TextUI const& other) = default;
    TextUI& operator=(TextUI const& other) = default;
    ~TextUI() = default;

    std::unique_ptr<se::Request> makeRequest() const;
    void setAndShowResult(std::unique_ptr<se::Result>& result) const;

private:
    std::regex const m_checkInput;
};

}

#endif

