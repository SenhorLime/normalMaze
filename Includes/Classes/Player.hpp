#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "GameObject.hpp"
#include "Maze.hpp"
using sf::Keyboard;

class Player: public GameObject {
private: // Variaveis privadas da classe Player
	sf::Texture playerTexture;
	sf::Vector2f previousPosition;

	float playerSpeed;
	float deltaTime = 0;

private: // Funcoes privadas da classe Player
	void loadTextures() {
		if (!playerTexture.loadFromFile("Assets/Characters/Males/M_01.png")) {
			std::cerr << "Falha ao carregar textura do jogador!";
		} else {
			playerTexture.loadFromFile("Assets/Characters/Males/M_01.png");
		}
	}

	void setSprites() {
		objectSprite.setScale(sf::Vector2f(2.0f, 2.0f));
		objectSprite.setTexture(playerTexture);
		objectSprite.setTextureRect(sf::IntRect(2, 2, 12, 15));
	}

	void handlePlayerInput() {
		sf::Vector2f movement(0.0f, 0.0f);

		if (sf::Keyboard::isKeyPressed(Keyboard::W)) {
			movement.y -= 1.0f;
			objectSprite.setTextureRect(sf::IntRect(34, 2, 12, 15));
		}

		if (sf::Keyboard::isKeyPressed(Keyboard::S)) {
			movement.y += 1.0f;
			objectSprite.setTextureRect(sf::IntRect(2, 2, 12, 15));
		}

		if (sf::Keyboard::isKeyPressed(Keyboard::A)) {
			movement.x -= 1.0f;
			objectSprite.setTextureRect(sf::IntRect(52, 2, 9, 15));
		}

		if (sf::Keyboard::isKeyPressed(Keyboard::D)) {
			movement.x += 1.0f;
			objectSprite.setTextureRect(sf::IntRect(19, 2, 9, 15));
		}

		moveCharacter(movement);

	}

	void updateDeltaTime(float dt) {
		deltaTime = dt;
	}

	void moveCharacter(const sf::Vector2f direction) {
		previousPosition = objectSprite.getPosition();
		sf::Vector2f movement = direction * playerSpeed * deltaTime;
		objectSprite.move(movement);
	}

	void setPreviousPosition() {
		objectSprite.setPosition(previousPosition);
	}

	bool isCollidingWithMaze(Maze &maze) {
		 if(maze.checkCollision(objectSprite) == true) {
			 setPreviousPosition();
		 }

		 return maze.checkCollision(objectSprite);
	}

public: // Funcoes publicas
	Player() :
			playerSpeed(150.0f) {
		loadTextures();
		setSprites();
	}

	void updatePlayer(float deltaTime, Maze &maze) {
		handlePlayerInput();
		isCollidingWithMaze(maze);
		updateDeltaTime(deltaTime);
	}
};


class Player1: public GameObject {
private: // Variaveis privadas da classe Player
	sf::Texture playerTexture1;
	sf::Vector2f previousPosition1;

	float playerSpeed1;
	float deltaTime = 0;

private: // Funcoes privadas da classe Player
	void loadTextures1() {
		if (!playerTexture1.loadFromFile("Assets/Characters/Females/F_01.png")) {
			std::cerr << "Falha ao carregar textura do jogador!";
		} else {
			playerTexture1.loadFromFile("Assets/Characters/Females/F_01.png");
		}
	}

	void setSprites1() {
		objectSprite1.setScale(sf::Vector2f(2.0f, 2.0f));
		objectSprite1.setTexture(playerTexture1);
		objectSprite1.setTextureRect(sf::IntRect(2, 2, 12, 15));
	}

	void handlePlayerInput1() {
		sf::Vector2f movement1(0.0f, 0.0f);

		if (sf::Keyboard::isKeyPressed(Keyboard::Up)) {
			movement1.y -= 1.0f;
			objectSprite1.setTextureRect(sf::IntRect(34, 2, 12, 15));
		}

		if (sf::Keyboard::isKeyPressed(Keyboard::Down)) {
			movement1.y += 1.0f;
			objectSprite1.setTextureRect(sf::IntRect(2, 2, 12, 15));
		}

		if (sf::Keyboard::isKeyPressed(Keyboard::Left)) {
			movement1.x -= 1.0f;
			objectSprite1.setTextureRect(sf::IntRect(52, 2, 9, 15));
		}

		if (sf::Keyboard::isKeyPressed(Keyboard::Right)) {
			movement1.x += 1.0f;
			objectSprite1.setTextureRect(sf::IntRect(19, 2, 9, 15));
		}

		moveCharacter1(movement1);

	}

	void updateDeltaTime1(float dt) {
		deltaTime = dt;
	}

	void moveCharacter1(const sf::Vector2f direction) {
		previousPosition1 = objectSprite1.getPosition();
		sf::Vector2f movement1 = direction * playerSpeed1 * deltaTime;
		objectSprite.move(movement1);
	}

	void setPreviousPosition1() {
		objectSprite1.setPosition(previousPosition1);
	}

	bool isCollidingWithMaze1(Maze &maze) {
		 if(maze.checkCollision(objectSprite1) == true) {
			 setPreviousPosition1();
		 }

		 return maze.checkCollision(objectSprite1);
	}

public: // Funcoes publicas
	Player1() :
			playerSpeed1(150.0f) {
		loadTextures1();
		setSprites1();
	}

	void updatePlayer1(float deltaTime, Maze &maze) {
		handlePlayerInput1();
		isCollidingWithMaze1(maze);
		updateDeltaTime1(deltaTime);
	}
};

#endif
