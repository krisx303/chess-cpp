#include <SFML/Graphics/RenderWindow.hpp>
#include "Panel.hpp"
#include "../Application.hpp"

Panel::Panel(sf::RenderWindow *win) {
    this->window = win;
}

void Panel::input() {
    while (this->window->pollEvent(this->event)) {
        switch (this->event.type) {
            case sf::Event::MouseButtonPressed:
                onMousePressed(event.mouseButton.button, getClickedVector(event.mouseButton));
                break;
            case sf::Event::MouseButtonReleased:
                onMouseReleased(event.mouseButton.button, getClickedVector(event.mouseButton));
                break;
            case sf::Event::MouseMoved:
                onMouseMoved(previousPos, getClickedVector(event.mouseMove));
                break;
            case sf::Event::Closed:
                onCloseRequest();
                break;
            case sf::Event::KeyPressed:
                onKeyPressed(event.key.code);
                break;
            case sf::Event::KeyReleased:
                onKeyReleased(event.key.code);
                break;
            case sf::Event::Resized:
                // update the view to the new size of the window
                Application::Get().resizeScreen((float)event.size.width, (float)event.size.height);
                break;
            default:
                onEvent();
                break;
        }
    }
}

void Panel::onCloseRequest() {}

void Panel::onEvent() {}

void Panel::onKeyPressed(sf::Keyboard::Key key) {}

void Panel::onKeyReleased(sf::Keyboard::Key key) {}

void Panel::onMousePressed(sf::Mouse::Button button, sf::Vector2f pos) {}

void Panel::onMouseReleased(sf::Mouse::Button button, sf::Vector2f pos) {}

void Panel::onMouseDragDrop(sf::Vector2f startPos, sf::Vector2f endPos) {}

void Panel::onMouseMoved(sf::Vector2f prevPos, sf::Vector2f currPos) {}

sf::Vector2f Panel::getClickedVector(sf::Event::MouseMoveEvent moveEvent) const {
    return window->mapPixelToCoords(sf::Vector2i(moveEvent.x, moveEvent.y));
}

sf::Vector2f Panel::getClickedVector(sf::Event::MouseButtonEvent buttonEvent) const {
    return window->mapPixelToCoords(sf::Vector2i(buttonEvent.x, buttonEvent.y));
}