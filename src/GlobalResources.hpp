#pragma once

#include <iostream>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include "board/PlayerColor.hpp"

using std::string;

class GlobalResources {
public:

    // deleting the copy constructor
    // (instanced object cannot be copied)
    GlobalResources(const GlobalResources&) = delete;

    static GlobalResources& Get();

    sf::Texture& getMainFont();

    sf::Texture &getBoard();

    sf::Sprite getPawnSprite(int typeID, PlayerColor color);

    void loadResources();

private:

    // private constructor
    GlobalResources();

    // instance of the object
    static GlobalResources s_Instance;

    sf::Texture mainFont;
    sf::Texture board;
    sf::Texture pawns;

    static void loadTexture(sf::Texture &texture, const string &path);
};