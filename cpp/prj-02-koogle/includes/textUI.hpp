#ifndef TUI_HPP
#define TUI_HPP

#include <iostream>
#include <memory>
#include <regex>

#include "simpleRequest.hpp"
#include "result.hpp"
#include "QueryUI.hpp"

namespace se{//Search Engin

class TextUI : public QuerysIF
{
public:
    TextUI();
    TextUI(TextUI const& other) = default;
    TextUI& operator=(TextUI const& other) = default;
    ~TextUI() = default;

    virtual std::unique_ptr<se::Request> makeRequest() const override;
    virtual void setAndShowResult(se::Result& result) const override;

private:
    std::regex const m_checkInput;
};

}

#endif

