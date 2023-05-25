#include "GlobalResources.hpp"

sf::Texture& GlobalResources::getMainFont() {
    return this->mainFont;
}

void GlobalResources::loadResources() {
    loadTexture(mainFont, "res/font/font.png");
}

GlobalResources &GlobalResources::Get() {
    return s_Instance;
}

void GlobalResources::loadTexture(sf::Texture& texture, const string& path) {
    if(!texture.loadFromFile(path)){
        printf("Jak ja mam ladowac grafike ktorej nie ma? [%s]", path.c_str());
        return;
    }
}

GlobalResources::GlobalResources() = default;


// instancing the single instance of the class
GlobalResources GlobalResources::s_Instance;
