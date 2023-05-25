#include "MenuPanel.hpp"
#include "../Application.hpp"

MenuPanel::MenuPanel(sf::RenderWindow *window) :
        Panel(Panel_ID::MAIN_MENU, window) {
}

void MenuPanel::input() {
    Panel::input();
}

void MenuPanel::update() {
    Panel::update();
}

void MenuPanel::render() {
    Panel::render();
    sf::Texture& font = GlobalResources::Get().getMainFont();
    float y = 20;
    for(int i = 0;i<4;i++){
        if(actualChoose == i){
            RenderHelper::Get().renderSelectedText(RenderSide::CENTER, this->context[i], 1, 0, y);
        }else{
            RenderHelper::Get().renderText(RenderSide::CENTER, this->context[i], 1, 0, y);
        }
        y += 20;
    }
}

void MenuPanel::onCloseRequest() {
    printf("Close menu\n");
    this->window->close();
}

void MenuPanel::onEvent() {}

void MenuPanel::onKeyPressed(sf::Keyboard::Key key) {
    switch (key) {
        case sf::Keyboard::W:
            if(actualChoose > 0)
                actualChoose -= 1;
            break;
        case sf::Keyboard::S:
            if(actualChoose < 3)
                actualChoose += 1;
            break;
        case sf::Keyboard::Enter:
            onSelected();
            break;
        default:
            break;
    }
}

void MenuPanel::onKeyReleased(sf::Keyboard::Key key) {

}

void MenuPanel::onSelected() {
    switch (actualChoose) {
        case 0:
        case 1:
            Application::Get().requestChangePanel(Panel_ID::GAME);
            break;
        case 2:
            Application::Get().requestChangePanel(Panel_ID::OPTIONS_MENU);
            break;
        case 3:
            this->window->close();
            break;
        default:
            break;
    }
}
