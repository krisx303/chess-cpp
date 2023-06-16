#pragma once


#include <string>
#include <ostream>

using std::string;


enum PlayerColor{
    WHITE,
    BLACK,
    NONE
};

std::ostream &operator<<(std::ostream &os, PlayerColor color);