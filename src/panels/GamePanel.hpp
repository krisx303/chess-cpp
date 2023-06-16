#pragma once

#include <SFML/Graphics/RenderWindow.hpp>
#include "../GlobalResources.hpp"
#include "Panel.hpp"
#include "../helpers/RenderHelper.hpp"
#include "../board/Board.hpp"
#include "../Application.hpp"
#include "../board/Rook.hpp"
#include "../board/NormalPawn.hpp"
#include "../board/Knight.hpp"
#include "../board/Bishop.hpp"
#include "../board/Queen.hpp"

class GamePanel : public Panel {
private:
    Board board;
    Pawn* chosenPawn;
    sf::Vector2f chosenPawnPosition;
    PlayerColor currentPlayer = WHITE, checkedPlayer = NONE;
    int counter = 0;
public:
    explicit GamePanel(sf::RenderWindow *window);

    void update() override;

    void render() override;

    void onCloseRequest() override;

    void onMousePressed(sf::Mouse::Button button, sf::Vector2f pos) override;

    void onMouseReleased(sf::Mouse::Button button, sf::Vector2f pos) override;

    void onMouseMoved(sf::Vector2f prevPos, sf::Vector2f currPos) override;

    void init();

    static void renderPawn(Pawn *pawn, float x, float y);

    void moveChosenPawn(Vector2 vector2);
};