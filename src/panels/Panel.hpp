#pragma once

/**  * Use method input when you want to override basic handler.
     * If you don't, just use [onKeyPressed(), onKeyReleased(), onEvent()] methods.
     * Basic input handler handles only "CloseWindow" event and redirects other events to these methods.
     * When you want to use onEvent() method, remember that actual event is stored in this->event.
     * */

#include <SFML/Window/Event.hpp>

class Panel {
public:
    sf::RenderWindow *window;
    sf::Event event{};
    sf::Vector2f previousPos, dragDropStartPos;

    explicit Panel(sf::RenderWindow *win);

    virtual void update() = 0;

    virtual void input();

    virtual void render() = 0;

    virtual void onCloseRequest();

    virtual void onEvent();

    virtual void onKeyPressed(sf::Keyboard::Key key);

    virtual void onKeyReleased(sf::Keyboard::Key key);

    virtual void onMousePressed(sf::Mouse::Button button, sf::Vector2f pos);

    virtual void onMouseReleased(sf::Mouse::Button button, sf::Vector2f pos);

    virtual void onMouseDragDrop(sf::Vector2f startPos, sf::Vector2f endPos);

    virtual void onMouseMoved(sf::Vector2f prevPos, sf::Vector2f currPos);

private:
    sf::Vector2f getClickedVector(sf::Event::MouseMoveEvent moveEvent) const;

    sf::Vector2f getClickedVector(sf::Event::MouseButtonEvent buttonEvent) const;
};