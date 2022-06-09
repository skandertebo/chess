#pragma once
#include <SFML/Graphics.hpp>
const int white = 0;
const int black = 1;
const int alive = 0;
const int dead = 1;

namespace gui {

	class board {
	public:
		sf::RectangleShape rectangles[8][8];
		board();
		void draw(sf::RenderWindow& window);
	};

	class piece {
	private:
		std::string type;
		std::string team;
		sf::Vector2f position;
		bool status;
		sf::Texture texture;
		sf::Sprite shape;
		int indice;
	public:
		int row, col;
		piece(const std::string& type, const std::string& team, int col, int row, int indice);
		void draw(sf::RenderWindow& window) const;
		void move(int col, int row);
		void kill();
		sf::Vector2f getPosition() const;
		static void drawPieces(gui::piece* teams[2][16], sf::RenderWindow& window);
		std::string getType() const {
			return type;
		}
		std::string getTeam() const {
			return team;
		}
		int getStatus() const{
			return status;
		}
	};

	void initiate_teams(gui::piece* teams[2][16]);
}