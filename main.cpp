//void fulfillBoard(Board &board) {
//    for (int i = 0; i < BOARD_SIZE; ++i) {
//        board.addPawn(new NormalPawn(Vector2(i, 1), PlayerColor::WHITE));
//    }
//    board.addPawn(new Rook(Vector2(0, 0), PlayerColor::WHITE));
//    board.addPawn(new Rook(Vector2(7, 0), PlayerColor::WHITE));
//    board.addPawn(new Knight(Vector2(1, 0), PlayerColor::WHITE));
//    board.addPawn(new Knight(Vector2(6, 0), PlayerColor::WHITE));
//}


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