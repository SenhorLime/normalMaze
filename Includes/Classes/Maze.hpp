#ifndef MAZE_HPP
#define MAZE_HPP

#include <vector>
#include <string>

#include "GameObject.hpp"

class Maze: public GameObject {
private: // Variaveis privadas da Classe Maze

	//Variavel para teste de vitoria
	bool isVictory ;

	// Variaveis da SFML
	sf::Texture wallTexture;
	sf::Texture pathTexture;

	// Vector para controle do labirinto
	std::vector<std::vector<char>> mazeData;
	std::vector<sf::Sprite> wallSpriteVector;
	std::vector<sf::Sprite> pathSpriteVector;

	// String para construção do labirinto
	std::string mazeString = "..###########################\n"
			"....#.........#...#.#.......#\n"
			"#.#########.#.###.#.#.#######\n"
			"#.....#.....#.#.....#...#.#.#\n"
			"#####.###.#.#####.#.#.###.#.#\n"
			"#...#.#.#.#...#...#.....#...#\n"
			"#.###.#.#.#####.###.#.###.###\n"
			"#.#.........#.....#.#.#...#.#\n"
			"#.#########.#####.#######.#.#\n"
			"#.....#.......#.....#.#...#.#\n"
			"#.#.#######.#####.###.#.###.#\n"
			"#.#.................#.#.#.#.#\n"
			"#.#########.#.#####.#.#.#.#.#\n"
			"#.........#.#.#.............#\n"
			"###########################F#";

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

	void loadMazeRows() {
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
	}

	void setMazeWalls(sf::RenderWindow &window) {
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
				wallSpriteVector.push_back(objectSprite);
			}
		}
	}

	void setMazePath(sf::RenderWindow &window) {
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

				if (mazeData[y][x] == '.') {
					mazeSprite.setTexture(pathTexture);
				}

				objectSprite = mazeSprite;
				objectSprite.setScale(sf::Vector2f(2.5f, 2.5f));
				pathSpriteVector.push_back(objectSprite);
			}
		}
	}
public:
	Maze(sf::RenderWindow &window) {
		isVictory = false;
		loadTextures();
		loadMazeRows();
		setMazeWalls(window);
		setMazePath(window);
	}

	bool checkVictory( const sf::Sprite &playerSprite){
		sf::Vector2f playerPosition = playerSprite.getPosition();
		const int tileSize = 40;
		sf::Vector2i initialPosition;

		//Audio de vitoria
		//sf::SoundBuffer Buffer;
		//sf::Sound Sound;
		//Sound.setBuffer(Buffer);


		int  mazeX = static_cast<int>((playerPosition.x - initialPosition.x) / tileSize);
		int mazeY = static_cast<int>((playerPosition.y - initialPosition.y) / tileSize);

		  if (mazeData[mazeY][mazeX] == 'F') {
		        isVictory = true;
				/*if(!Buffer.loadFromFile("Assets/Sound/ fifa.aac")){
					std::cout<<"erro";
				} else if(isVictory == true){
					return true;
					//Sound.play();
		        }*/

		    }
		  return false;
 }

	bool checkCollision(sf::Sprite &playerSprite) {
		for (auto &wallSprite : wallSpriteVector) {
			if (playerSprite.getGlobalBounds().intersects(
					wallSprite.getGlobalBounds())) {
				return true;
			}
		}

		return false;
	}

	void drawOnWindow(sf::RenderWindow &window) override {
		for (auto &sprite : wallSpriteVector) {
			window.draw(sprite);
		}

		for (auto& sprite : pathSpriteVector) {
			window.draw(sprite);
		}
	}
};

#endif
