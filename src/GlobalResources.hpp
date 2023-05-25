#pragma once

#include <iostream>
#include <SFML/Graphics/Texture.hpp>

using std::string;

class GlobalResources {
public:

    // deleting the copy constructor
    // (instanced object cannot be copied)
    GlobalResources(const GlobalResources&) = delete;

    static GlobalResources& Get();

    sf::Texture& getMainFont();

    void loadResources();

private:

    // private constructor
    GlobalResources();

    // instance of the object
    static GlobalResources s_Instance;

    sf::Texture mainFont;

    void loadTexture(sf::Texture &texture, const string &path);
};