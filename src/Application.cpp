#include "Application.hpp"
#include "GlobalResources.hpp"
#include "panels/Panel.hpp"
#include "panels/GamePanel.hpp"

void Application::start() {
    Application::loadResources();
    this->initVariables();
    this->initWindow();
    this->initComponents();
}

void Application::initComponents() {
    RenderHelper::Get().Init(this->window);
    RenderHelper::Get().setFont(&GlobalResources::Get().getMainFont());
    RenderHelper::Get().setFontSize(9);
}


Application &Application::Get() {
    return s_Instance;
}

void Application::initVariables() {

}

void Application::loadResources() {
    GlobalResources::Get().loadResources();
}

void Application::initWindow() {
    this->videoMode.height = 640;
    this->videoMode.width = 640;
    sf::View view(sf::FloatRect(0, 0, 640, 640));
    view.setViewport(sf::FloatRect(0, 0, 1.f, 1.f));

    this->window = new sf::RenderWindow(this->videoMode, "Game", sf::Style::Default);
    this->window->setFramerateLimit(60);
    this->window->setView(view);
    this->panel = new GamePanel(window);
}

Application::~Application() {
    delete this->window;
    delete this->panel;
}

void Application::update() {
    this->panel->input();
    this->panel->update();
}

void Application::render() {
    this->window->clear(sf::Color(0, 0, 0, 255));
    sf::RectangleShape object;
    object.setSize(sf::Vector2f(640, 640));
    object.setFillColor(sf::Color(25, 25, 25, 255));
    this->window->draw(object);

    this->panel->render();
    this->window->display();
}

bool Application::isRunning() const {
    return this->window->isOpen();
}

Application::Application() = default;


// instancing the single instance of the class
Application Application::s_Instance;

void Application::resizeScreen(float width, float height) {
    sf::FloatRect visibleArea(0.f, 0.f, width, height);
    this->window->setView(sf::View(visibleArea));
    sf::View view = this->window->getView();
    float x = width / 640;
    float y = height / 640;
    float ratioX = x / y;
    view.reset(sf::FloatRect(0, 0, 640, 640));
    if (ratioX <= 1.0f) {
        float h = (float) height * ratioX;
        view.setViewport(sf::FloatRect(0.f, ((float) height - h) / (2 * (float) height) / 3, 1.0f, ratioX));
    } else {
        float w = (float) width * 1 / ratioX;
        view.setViewport(sf::FloatRect(((float) width - w) / (2 * (float) width), 0.f, 1 / ratioX, 1.0f));
    }
    window->setView(view);
}