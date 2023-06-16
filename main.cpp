#include "src/Application.cpp"

int main() {
    Application& app = Application::Get();
    app.start();
    while (app.isRunning()) {
        app.update();
        app.render();
    }
    return 0;
}