#include <SFML/Graphics/CircleShape.hpp>
#include "RenderHelper.hpp"

// instancing the single instance of the class
RenderHelper RenderHelper::s_Instance;

RenderHelper &RenderHelper::Get() {
    return s_Instance;
}

RenderHelper::~RenderHelper() = default;

void RenderHelper::Init(sf::RenderWindow *window) {
    this->window = window;
}

void RenderHelper::setFont(sf::Texture *nFont) {
    this->font = nFont;
}

void RenderHelper::setFontSize(int size) {
    this->fontSize = size;
}

RenderHelper::RenderHelper() {
    this->defaultColor = sf::Color(255, 255, 255, 200);
    this->selectedColor = sf::Color(155, 155, 255, 200);
}

void RenderHelper::renderText(RenderSide side, const std::string &string, float maxWidth, float x, float y) {
    renderText(side, string, maxWidth, x, y, this->defaultColor);
}

void RenderHelper::renderSelectedText(RenderSide side, const std::string &string, float maxWidth, float x, float y) {
    renderText(side, string, maxWidth, x, y, this->selectedColor);
}

void RenderHelper::renderCustomColorText(RenderSide side, const std::string &string, float maxWidth, float x, float y,
                                         const sf::Color &color) {
    renderText(side, string, maxWidth, x, y, color);
}



// Private functions

float RenderHelper::calculateStartXOnCenter(const std::string &string, const float x, const float width) const {
    size_t w = string.length();
    w = w * this->fontSize;
    return (width - (float) w) / 2 + x;
}

float RenderHelper::calculateStartXOnRight(const std::string &string, float width) const {
    size_t w = string.length();
    w = w * this->fontSize;
    return width - (float) w;
}

void RenderHelper::renderText(RenderSide side, const std::string &string, float maxWidth, float x, float y,
                              const sf::Color &color) {
    if (maxWidth <= 1) {
        maxWidth = 320 * maxWidth;
    }
    if (x > 0 && x <= 1) {
        x = 320 * x;
    }
    if (side == RIGHT) {
        x = calculateStartXOnRight(string, maxWidth);
    }
    if (side == CENTER) {
        x = calculateStartXOnCenter(string, x, maxWidth);
    }
    sf::Sprite letter;
    letter.setTexture(*this->font);
    letter.setColor(color);
    for (char c: string) {
        int pos = (int) c - 33;
        letter.setTextureRect(sf::IntRect(pos % 11 * 10, 30 + pos / 11 * 10, 10, 10));
        letter.setPosition(x, y);
        this->window->draw(letter);
        x += (float) this->fontSize;;
    }
}

void RenderHelper::renderTexture(float x, float y, sf::Texture &texture, float d) {
    sf::Sprite sprite;
    sprite.setTexture(texture);
    renderRawSprite(x, y, sprite, d);
}

void RenderHelper::renderRawSprite(float x, float y, sf::Sprite &sprite, float scale) {
    sprite.setPosition(x, y);
    sprite.setScale(scale, scale);
    this->window->draw(sprite);
}

void RenderHelper::renderCircle(float x, float y, float radius, sf::Color color) {
    sf::CircleShape circle;
    circle.setRadius(radius);
    circle.setOutlineColor(color);
    circle.setOutlineThickness(5);
    circle.setPosition(x, y);
    this->window->draw(circle);
}
