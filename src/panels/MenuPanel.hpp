#pragma once

#include <SFML/Graphics/RenderWindow.hpp>
#include "../GlobalResources.hpp"
#include "Panel.hpp"
#include "../helpers/RenderHelper.hpp"

class MenuPanel : public Panel {
private:
    int actualChoose = 0;
    std::string context[4] = {"Singleplayer", "Multiplayer", "Options", "Exit :("};
public:
    explicit MenuPanel(sf::RenderWindow *window);

    void input() override;

    void update() override;

    void render() override;

    void onCloseRequest() override;

    void onEvent() override;

    void onKeyPressed(sf::Keyboard::Key key) override;

    void onKeyReleased(sf::Keyboard::Key key) override;

    void onSelected();
};