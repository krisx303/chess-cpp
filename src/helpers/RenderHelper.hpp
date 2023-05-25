#pragma once

#include <string>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Texture.hpp>

enum RenderSide {
    LEFT,
    CENTER,
    RIGHT
};

class RenderHelper {
public:
    // deleting the copy constructor
    // (instanced object cannot be copied)
    RenderHelper(const RenderHelper &) = delete;

    static RenderHelper &Get();

    virtual ~RenderHelper();

    void Init(sf::RenderWindow* window);

    void setFont(sf::Texture* nFont);

    void renderText(RenderSide side, const std::string& string, float maxWidth, float x, float y);

    void renderSelectedText(RenderSide side, const std::string& string, float maxWidth, float x, float y);

    void renderCustomColorText(RenderSide side, const std::string& string, float maxWidth, float x, float y, const sf::Color& color);

    void setFontSize(int size);

private:
    // private constructor
    RenderHelper();

    float calculateStartXOnCenter(const std::string &string, float x, float width);

    void renderText(RenderSide side, const std::string& string, float maxWidth, float x, float y, const sf::Color& color);

    // instance of the object
    static RenderHelper s_Instance;
    sf::RenderWindow* window;
    sf::Texture* font;
    sf::Color defaultColor, selectedColor;
    int fontSize;

    float calculateStartXOnRight(const std::string &string, float width);
};