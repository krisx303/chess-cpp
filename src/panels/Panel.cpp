#include <SFML/Graphics/RenderWindow.hpp>
#include "Panel.hpp"
#include "../Application.hpp"

Panel::Panel(Panel_ID id, sf::RenderWindow *win) {
    this->PANEL_ID = id;
    this->window = win;
}

void Panel::update() {}

void Panel::input() {
    while (this->window->pollEvent(this->event)) {
        if (event.type == sf::Event::Resized)
        {
            // update the view to the new size of the window
            sf::FloatRect visibleArea(0.f, 0.f, event.size.width, event.size.height);
            this->window->setView(sf::View(visibleArea));
        }
        switch (this->event.type) {
            case sf::Event::Closed:
                onCloseRequest();
                break;
            case sf::Event::Resized:
                Application::Get().resizeScreen(event.size.width, event.size.height);
                break;
            case sf::Event::KeyPressed:
                onKeyPressed(event.key.code);
                break;
            case sf::Event::KeyReleased:
                onKeyReleased(event.key.code);
                break;
            default:
                onEvent();
                break;
        }
    }
}

void Panel::render() {}

void Panel::onCloseRequest() {}

void Panel::onEvent() {}

void Panel::onKeyPressed(sf::Keyboard::Key key) {}

void Panel::onKeyReleased(sf::Keyboard::Key key) {}