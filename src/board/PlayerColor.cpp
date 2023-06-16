#include "PlayerColor.hpp"

std::ostream &operator<<(std::ostream &os, PlayerColor color) {
    switch (color) {
        case WHITE:
            os << "WHITE";
            break;
        case BLACK:
            os << "BLACK";
            break;
        case NONE:
            os << "NONE";
            break;
    }
    return os;
}