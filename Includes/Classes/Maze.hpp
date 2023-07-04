#ifndef MAZE_HPP
#define MAZE_HPP

#include <vector>
#include <string>

#include "GameObject.hpp"

class Maze: public GameObject {
private: // Variaveis privadas da Classe Maze
	std::vector<std::vector<char>> mazeData;
	std::vector<sf::Sprite> spriteVector;

	sf::Texture wallTexture;
	sf::Texture pathTexture;

private: // Funcoes privadas da Classe Maze
	void loadTextures() {
		if (!wallTexture.loadFromFile("Assets/Maze/wall.png")
				|| !pathTexture.loadFromFile("Assets/Maze/path.png")) {
			std::cerr << "Erro ao carregar texturas do Labirinto";
		} else {
			wallTexture.loadFromFile("Assets/Maze/wall.png");
			pathTexture.loadFromFile("Assets/Maze/path.png");
		}
	}

public:
	Maze(std::string &mazeString, sf::RenderWindow &window) {
		loadTextures();

		std::vector<char> row;
		for (char c : mazeString) {
			if (c == '\n') {
				mazeData.push_back(row);
				row.clear();
			} else {
				row.push_back(c);
			}
		}
		mazeData.push_back(row);

		const int tileSize = 40;
		for (std::size_t y = 0; y < mazeData.size(); y++) {
			for (std::size_t x = 0; x < mazeData[y].size(); x++) {
				sf::Sprite mazeSprite;

				sf::Vector2i windowSize(window.getSize().x, window.getSize().y);
				sf::Vector2i mazeSize(mazeData[0].size() * tileSize,
						mazeData.size() * tileSize);
				sf::Vector2i initialPosition((windowSize.x - mazeSize.x) / 2,
						(windowSize.y - mazeSize.y) / 2);

				mazeSprite.setPosition(initialPosition.x + x * tileSize,
						initialPosition.y + y * tileSize);

				if (mazeData[y][x] == '#') {
					mazeSprite.setTexture(wallTexture);
				}

				objectSprite = mazeSprite;
				objectSprite.setScale(sf::Vector2f(2.5f, 2.5f));
				spriteVector.push_back(objectSprite);
			}
		}
	}

	bool checkCollision(sf::Sprite &playerSprite) {
		for (auto &wallSprite : spriteVector) {
			if (playerSprite.getGlobalBounds().intersects(
					wallSprite.getGlobalBounds())) {
				return true;
			}
		}

		return false;
	}

	void drawOnWindow(sf::RenderWindow &window) override {
		for (auto &sprite : spriteVector) {
			window.draw(sprite);
		}
	}
};

#endif
