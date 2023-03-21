#ifndef TUI_HPP
#define TUI_HPP

#include <iostream>

namespace se{//Search Engin

class TextUI
{
public:
    TextUI() = default;
    TextUI(TextUI const& other) = default;
    TextUI& operator=(TextUI const& other) = default;
    ~TextUI() = default;

    void stertRequest();
};

void se::TextUI::stertRequest()
{
    std::cout<<
}

}
#endif