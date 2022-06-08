#include "UI.h"
#include <iostream>

gui :: board :: board() {
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            rectangles[i][j].setSize(sf::Vector2f(100, 100));
            rectangles[i][j].setPosition(sf::Vector2f((float)700 - (100 * i), (float)j * 100));
            if (i % 2 == 0) {
                if (j % 2 == 0) {
                    rectangles[i][j].setFillColor(sf::Color(165, 42, 42));
                }
                else {
                    rectangles[i][j].setFillColor(sf::Color(255, 255, 255));
                }
            }

            else {
                if (j % 2 == 1) {
                    rectangles[i][j].setFillColor(sf::Color(165, 42, 42));
                }
                else {
                    rectangles[i][j].setFillColor(sf::Color(255, 255, 255));
                }
            }

        }
    }

}

void gui::board::draw(sf::RenderWindow& window) {
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            window.draw(rectangles[i][j]);
        }
    }
}





gui::piece::piece(const std::string& type, const std::string& team, int col, int row, int indice) : indice(indice), row(row), col(col) {
    this->type = type;
    this->team = team;
    status = alive;
    if (!texture.loadFromFile(team + "/" + type + ".png")) {
        std::cout << "error loading file" << std::endl;
        exit(1);
    }
    else {
        shape.setTexture(texture);
        shape.setScale(sf::Vector2f(0.15, 0.15f));
        shape.setOrigin(sf::Vector2f(256.f, 256.f));

        position.x = (float)col * 100 + 50.f;
        position.y = (float)(700-(row * 100)) + 50.f;
        shape.setPosition(position);
    }
}

void gui::piece::draw(sf::RenderWindow& window) {
    if (status == alive)
        window.draw(shape);
}

void gui::piece::move(int col, int row) {
    position.x = (float)col * 100 + 50.f;
    position.y = (float)(700-(row * 100)) + 50.f;
    shape.setPosition(position);
}

sf::Vector2f gui::piece::getPosition() const {
    return position;
}

void gui::piece::drawPieces(gui::piece* teams[2][16], sf::RenderWindow& window) {
    for (int i = 0; i < 16; i++) {
        teams[white][i]->draw(window);
        teams[black][i]->draw(window);
    }
}

void gui::initiate_teams(gui::piece* teams[2][16]) {

    teams[white][0] = new gui::piece("king", "white", 4, 0, 0);
    teams[white][1] = new gui::piece("queen", "white", 3, 0, 1);
    teams[white][2] = new gui::piece("rook", "white", 0, 0, 2);
    teams[white][3] = new gui::piece("rook", "white", 7, 0, 3);
    teams[white][4] = new gui::piece("knight", "white", 1, 0, 4);
    teams[white][5] = new gui::piece("knight", "white", 6, 0, 5);
    teams[white][6] = new gui::piece("bishop", "white", 2, 0, 6);
    teams[white][7] = new gui::piece("bishop", "white", 5, 0, 7);
    for (int i = 0; i < 8; i++)
        teams[white][i + 8] = new gui::piece("pawn", "white", i, 1, i + 8);

    teams[black][0] = new gui::piece("king", "black", 4, 7, 0);
    teams[black][1] = new gui::piece("queen", "black", 3, 7, 1);
    teams[black][2] = new gui::piece("rook", "black", 0, 7, 2);
    teams[black][3] = new gui::piece("rook", "black", 7, 7, 3);
    teams[black][4] = new gui::piece("knight", "black", 1, 7, 4);
    teams[black][5] = new gui::piece("knight", "black", 6, 7, 5);
    teams[black][6] = new gui::piece("bishop", "black", 2, 7, 6);
    teams[black][7] = new gui::piece("bishop", "black", 5, 7, 7);
    for (int i = 0; i < 8; i++)
        teams[black][i + 8] = new gui::piece("pawn", "black", i, 6, i + 8);

}

void gui::piece::kill() {
    status = dead;
}