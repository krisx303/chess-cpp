#include "GlobalResources.hpp"

sf::Texture& GlobalResources::getMainFont() {
    return this->mainFont;
}

sf::Texture& GlobalResources::getBoard() {
    return this->board;
}

sf::Sprite GlobalResources::getPawnSprite(int typeID, PlayerColor color) {
    sf::Sprite sprite;
    sprite.setTexture(pawns);

    sprite.setTextureRect(sf::IntRect(typeID*350, color*350, 350, 350));
    return sprite;
}

void GlobalResources::loadResources() {
    loadTexture(mainFont, "res/font/font.png");
    loadTexture(board, "res/board.png");
    loadTexture(pawns, "res/chess.png");
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
