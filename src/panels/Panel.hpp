#pragma once

/**  * Use method input when you want to override basic handler.
     * If you don't, just use [onKeyPressed(), onKeyReleased(), onEvent()] methods.
     * Basic input handler handles only "CloseWindow" event and redirects other events to these methods.
     * When you want to use onEvent() method, remember that actual event is stored in this->event.
     * */

#include <SFML/Window/Event.hpp>
enum Panel_ID {
    MAIN_MENU = 0,
    GAME = 1,
    OPTIONS_MENU = 2
};

class Panel {
public:
    sf::RenderWindow *window;
    sf::Event event;

    Panel(Panel_ID id, sf::RenderWindow *win);

    virtual void update();

    virtual void input();

    virtual void render();

    virtual void onCloseRequest();

    virtual void onEvent();

    virtual void onKeyPressed(sf::Keyboard::Key key);

    virtual void onKeyReleased(sf::Keyboard::Key key);

private:
    Panel_ID PANEL_ID;
};