#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "GameObject.hpp"
#include "Frames.hpp"
#include "Maze.hpp"
using sf::Keyboard;

Frames playerFrame;
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
			objectSprite.setTextureRect(playerFrame.Up[0]);
		}

		if (sf::Keyboard::isKeyPressed(Keyboard::S)) {
			movement.y += 1.0f;
			objectSprite.setTextureRect(playerFrame.Down[0]);
		}

		if (sf::Keyboard::isKeyPressed(Keyboard::A)) {
			movement.x -= 1.0f;
			objectSprite.setTextureRect(playerFrame.Left[0]);
		}

		if (sf::Keyboard::isKeyPressed(Keyboard::D)) {
			movement.x += 1.0f;
			objectSprite.setTextureRect(playerFrame.Right[0]);
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


	bool isVictoryFinale(Maze &maze){
		if(maze.checkVictory(objectSprite) == true){
		     std::cout << "Parabéns, player venceu!" << std::endl;
		}
			return maze.checkVictory(objectSprite);
	}


	void updatePlayer(float deltaTime, Maze &maze) {
		handlePlayerInput();
		isCollidingWithMaze(maze);
		updateDeltaTime(deltaTime);
	}
};


class SecondPlayer: public GameObject {
private: // Variaveis privadas da classe Player
	sf::Texture playerTexture;
	sf::Vector2f previousPosition;

	float playerSpeed;
	float deltaTime = 0;

private: // Funcoes privadas da classe Player
	void loadTextures() {
		if (!playerTexture.loadFromFile("Assets/Characters/Females/F_01.png")) {
			std::cerr << "Falha ao carregar textura do jogador!";
		} else {
			playerTexture.loadFromFile("Assets/Characters/Females/F_07.png");
		}
	}

	void setSprites() {
		objectSprite.setScale(sf::Vector2f(2.0f, 2.0f));
		objectSprite.setTexture(playerTexture);
		objectSprite.setTextureRect(sf::IntRect(2, 2, 12, 15));
	}

	void handlePlayerInput() {
		sf::Vector2f movement(0.0f, 0.0f);

		if (sf::Keyboard::isKeyPressed(Keyboard::Up)) {
			movement.y -= 1.0f;
			objectSprite.setTextureRect(playerFrame.Up[0]);
		}

		if (sf::Keyboard::isKeyPressed(Keyboard::Down)) {
			movement.y += 1.0f;
			objectSprite.setTextureRect(playerFrame.Down[0]);
		}

		if (sf::Keyboard::isKeyPressed(Keyboard::Left)) {
			movement.x -= 1.0f;
			objectSprite.setTextureRect(playerFrame.Left[0]);
		}

		if (sf::Keyboard::isKeyPressed(Keyboard::Right)) {
			movement.x += 1.0f;
			objectSprite.setTextureRect(playerFrame.Right[0]);
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
	SecondPlayer() :
			playerSpeed(150.0f) {
		loadTextures();
		setSprites();
	}


	bool isVictoryFinale(Maze &maze){
		if(maze.checkVictory(objectSprite) == true){
		     std::cout << "Parabéns, player 2 venceu!" << std::endl;
		}
		return maze.checkVictory(objectSprite);
	}

	void updatePlayer(float deltaTime, Maze &maze) {
		handlePlayerInput();
		isCollidingWithMaze(maze);
		updateDeltaTime(deltaTime);
	}
};

#endif
