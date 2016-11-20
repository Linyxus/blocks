#ifndef CONSOLE_DISPLAYER_HPP_
#define CONSOLE_DISPLAYER_HPP_

#include "DataManager.hpp"
#include <cstdlib>

class Displayer
{
public:
    Displayer(Manager* source);
    void paint();
private:
    Manager* man;
};

#endif
