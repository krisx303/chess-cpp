#pragma once

#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <SFML/Window.hpp>
#include "panels/Panel.hpp"


class Application {
public:
    // deleting the copy constructor
    // (instanced object cannot be copied)
    Application(const Application &) = delete;

    static Application &Get();

    void start();

    virtual ~Application();

    void update();

    void render();

    bool isRunning() const;

    void resizeScreen(float width, float height);

private:

    // private constructor
    Application();

    // instance of the object
    static Application s_Instance;

    sf::RenderWindow *window{};

    sf::VideoMode videoMode;
    Panel *panel{};

    void initVariables();

    void initWindow();

    static void loadResources();

    void initComponents();

};