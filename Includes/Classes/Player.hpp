#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "GameObject.hpp"
using sf::Keyboard;

class Player: public GameObject {
private:
	sf::Texture playerTexture;

	float playerSpeed;
	float deltaTime = 0;

public:
	Player() : playerSpeed(200.0f) {
		if(!playerTexture.loadFromFile("Assets/Characters/Males/M_01.png")) {
			std::cerr << "Falha ao carregar textura do jogador!";
		} else {
			playerTexture.loadFromFile("Assets/Characters/Males/M_01.png");
		}

		objectSprite.setScale(sf::Vector2f (2.0f, 2.0f));
		objectSprite.setTexture(playerTexture);
		objectSprite.setTextureRect(sf::IntRect (2, 2, 12, 15));
	}

	void handlePlayerInput(sf::RenderWindow& window) {
		sf::Vector2f movement(0.0f, 0.0f);

		if(sf::Keyboard::isKeyPressed(Keyboard::W)) {
			movement.y -= 1.0f;
			objectSprite.setTextureRect(sf::IntRect (34, 2, 12, 15));
		}

		if(sf::Keyboard::isKeyPressed(Keyboard::S)) {
			movement.y += 1.0f;
			objectSprite.setTextureRect(sf::IntRect (2, 2, 12, 15));
		}

		if(sf::Keyboard::isKeyPressed(Keyboard::A)) {
			movement.x -= 1.0f;
			objectSprite.setTextureRect(sf::IntRect (52, 2, 9, 15));
		}

		if(sf::Keyboard::isKeyPressed(Keyboard::D)) {
			movement.x += 1.0f;
			objectSprite.setTextureRect(sf::IntRect (19, 2, 9, 15));
		}

		moveCharacter(movement);

	}

	void moveCharacter(const sf::Vector2f direction) {
		sf::Vector2f movement = direction * playerSpeed * deltaTime;

		objectSprite.move(movement);
	}

	void updateDeltaTime(float dt) {
		deltaTime = dt;
	}

	void playerFunction(sf::RenderWindow& window, float deltaTime){
		handlePlayerInput(window);
		updateDeltaTime(deltaTime);
	}
};

#endif
