#ifndef MAZE_HPP
#define MAZE_HPP

#include <vector>
#include <string>

#include "GameObject.hpp"

class Maze: public GameObject {
private:
	std::vector<std::vector<char>> mazeData;
	std::vector<sf::Sprite> spriteVector;

	sf::Texture wallTexture;
	sf::Texture pathTexture;
	sf::Texture startTexture;
	sf::Texture exitTexture;
public:
	Maze(std::string &mazeString) {
		if (!wallTexture.loadFromFile("Assets/Maze/wall.png")
				|| !pathTexture.loadFromFile("Assets/Maze/path.png")
				|| !startTexture.loadFromFile("Assets/Maze/start.png")
				|| !exitTexture.loadFromFile("Assets/Maze/exit.png")) {
			std::cerr << "Falha ao carregar as texturas do labirinto";
		} else {
			wallTexture.loadFromFile("Assets/Maze/wall.png");
			pathTexture.loadFromFile("Assets/Maze/path.png");
			startTexture.loadFromFile("Assets/Maze/start.png");
			exitTexture.loadFromFile("Assets/Maze/exit.png");
		}

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

		const int tileSize = 32;
		for (std::size_t y = 0; y < mazeData.size(); y++) {
			for (std::size_t x = 0; x < mazeData[y].size(); x++) {
				sf::Sprite mazeSprite;

				mazeSprite.setPosition(x * tileSize, y * tileSize);

				if (mazeData[y][x] == '#') {
					mazeSprite.setTexture(wallTexture);
				} else if (mazeData[y][x] == '.') {
					mazeSprite.setTexture(pathTexture);
				}

				objectSprite = mazeSprite;
				objectSprite.setScale(sf::Vector2f(2.0f, 2.0f));
				spriteVector.push_back(objectSprite);
			}
		}
	}

	void drawOnWindow(sf::RenderWindow &window) override {
		for (auto &sprite : spriteVector) {
			window.draw(sprite);
		}
	}
};

#endif
