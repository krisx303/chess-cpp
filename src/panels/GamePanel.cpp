#include "GamePanel.hpp"

GamePanel::GamePanel(sf::RenderWindow *window) : Panel(window) {
    this->init();
}

void GamePanel::update() {
}

void GamePanel::render() {
    GlobalResources &resources = GlobalResources::Get();
    sf::Texture &font = resources.getMainFont();
    sf::Texture &bg = resources.getBoard();
    RenderHelper::Get().renderTexture(0, 0, bg, 0.547f);
    float x, y;
    if (chosenPawn != nullptr) {
        vector<Vector2> movements = board.getMovementsFromPawn(chosenPawn);
        for (const auto &item: movements) {
            RenderHelper::Get().renderCircle(item.getX() * 80.f + 20, item.getY() * 80.f + 20, 20, sf::Color::Black);
        }
        renderPawn(chosenPawn, chosenPawnPosition.x - 40.f, chosenPawnPosition.y - 40.f);
    }
    for (Pawn *pawn: board) {
        if (pawn == nullptr) continue;
        if (pawn == chosenPawn) continue;
        x = 80.0f * ((float) pawn->getPosition().getX());
        y = 80.0f * ((float) pawn->getPosition().getY());
        renderPawn(pawn, x, y);
    }
}

void GamePanel::onCloseRequest() {
    printf("Close menu\n");
    this->window->close();
}

void GamePanel::init() {
    for (int i = 0; i < BOARD_SIZE; ++i) {
        board.addPawn(new NormalPawn(Vector2(i, 1), PlayerColor::BLACK));
        board.addPawn(new NormalPawn(Vector2(i, 6), PlayerColor::WHITE));
    }
    board.addPawn(new Rook(Vector2(0, 0), PlayerColor::BLACK));
    board.addPawn(new Knight(Vector2(1, 0), PlayerColor::BLACK));
    board.addPawn(new Bishop(Vector2(2, 0), PlayerColor::BLACK));
    board.addPawn(new Queen(Vector2(3, 0), PlayerColor::BLACK));
    board.addKingPawn(new King(Vector2(4, 0), PlayerColor::BLACK));
    board.addPawn(new Bishop(Vector2(5, 0), PlayerColor::BLACK));
    board.addPawn(new Knight(Vector2(6, 0), PlayerColor::BLACK));
    board.addPawn(new Rook(Vector2(7, 0), PlayerColor::BLACK));

    board.addPawn(new Rook(Vector2(0, 7), PlayerColor::WHITE));
    board.addPawn(new Knight(Vector2(1, 7), PlayerColor::WHITE));
    board.addPawn(new Bishop(Vector2(2, 7), PlayerColor::WHITE));
    board.addKingPawn(new King(Vector2(3, 7), PlayerColor::WHITE));
    board.addPawn(new Queen(Vector2(4, 7), PlayerColor::WHITE));
    board.addPawn(new Bishop(Vector2(5, 7), PlayerColor::WHITE));
    board.addPawn(new Knight(Vector2(6, 7), PlayerColor::WHITE));
    board.addPawn(new Rook(Vector2(7, 7), PlayerColor::WHITE));
}

void GamePanel::onMousePressed(sf::Mouse::Button button, sf::Vector2f pos) {
    int x = (int) (pos.x / 80);
    int y = (int) (pos.y / 80);
    Pawn *pawn = board.getPawnAtPosition(Vector2(x, y));
    if (pawn == nullptr) return;
    if (pawn->getColor() == currentPlayer) {
        chosenPawn = pawn;
        chosenPawnPosition = pos;
    }
}

void GamePanel::onMouseMoved(sf::Vector2f prevPos, sf::Vector2f currPos) {
    if (chosenPawn == nullptr) return;
    chosenPawnPosition = currPos;
}

void GamePanel::renderPawn(Pawn *pawn, float x, float y) {
    GlobalResources &resources = GlobalResources::Get();
    sf::Sprite sprite = resources.getPawnSprite(pawn->getType(), pawn->getColor());
    RenderHelper::Get().renderRawSprite(x, y, sprite, 0.228f);
}

void GamePanel::onMouseReleased(sf::Mouse::Button button, sf::Vector2f pos) {
    if (chosenPawn == nullptr) return;
    Vector2 boardPos((int) ((pos.x) / 80.f), (int) ((pos.y) / 80.f));
    if (boardPos == chosenPawn->getPosition()) {
        chosenPawn = nullptr;
        return;
    }

    moveChosenPawn(boardPos);
}

void GamePanel::moveChosenPawn(Vector2 boardPos) {
    vector<Vector2> movements = board.getMovementsFromPawn(chosenPawn);
    bool isBoardPosInMovements = std::any_of(movements.begin(), movements.end(), [&](const Vector2 &movement) {
        return movement == boardPos;
    });

    if (!isBoardPosInMovements) {
        chosenPawn = nullptr;
        return;
    }
    PlayerColor previousCheck = board.getCheckColor();
    cout << "Wczesniej: " << previousCheck << " ";
    board.movePawn(chosenPawn, boardPos);
    PlayerColor check = board.kingCheck();
    cout << "Szach: " << check << endl;
    if(previousCheck == NONE && check == currentPlayer){
        cout << "Niedozwolony ruch, powoduje szach na twoim królu!" << endl;
        if(checkedPlayer == currentPlayer) {
            cout << "Pozostało " << 4-counter << " szans!" << endl;
            counter++;
        }else{
            counter = 0;
        }
        board.backMove();
    }
    else if(previousCheck == currentPlayer && check == currentPlayer){
        cout << "Niedozwolony ruch, nadal będzie szach na twoim królu!" << endl;
        cout << "Pozostało " << 4-counter << " szans!" << endl;
        if(counter == 4){
            cout << "Koniec gry";
            onCloseRequest();
        }
        counter++;
        board.backMove();
    }else{
        if (typeid(*chosenPawn) == typeid(NormalPawn)) {
            ((NormalPawn *) chosenPawn)->changeState();
        }
        if (currentPlayer == WHITE)
            currentPlayer = BLACK;
        else
            currentPlayer = WHITE;
        counter = 0;
    }
    checkedPlayer = check;
    board.setCheckColor(checkedPlayer);
    chosenPawn = nullptr;
}
