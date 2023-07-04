#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "GameObject.hpp"
using sf::Keyboard;

class Player: public GameObject {
private: // Variaveis privadas da classe Player
	sf::Texture playerTexture;

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
		objectSprite.setScale(sf::Vector2f(2.2f, 2.2f));
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

	void moveCharacter(const sf::Vector2f direction) {
		sf::Vector2f movement = direction * playerSpeed * deltaTime;

		objectSprite.move(movement);
	}
public:
	Player() :
			playerSpeed(150.0f) {
		loadTextures();
		setSprites();
	}

	void updateDeltaTime(float dt) {
		deltaTime = dt;
	}

//	bool Player::isCollidingWith(const Maze &maze) const {
//		const auto &wallSprites = maze.getWall
//	}

	void updatePlayer(float deltaTime) {
		handlePlayerInput();
		updateDeltaTime(deltaTime);
	}
};

#endif
