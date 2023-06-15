#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "GameObject.hpp"

class Player: public GameObject {
private:
	sf::Texture mazeTexture;
public:
	Player() {
		if(!mazeTexture.loadFromFile("Assets/Characters/Males/M_01.png")) {
			std::cerr << "Falha ao carregar textura do jogador!";
		} else {
			mazeTexture.loadFromFile("Assets/Characters/Males/M_01.png");
		}

		objectSprite.setTexture(mazeTexture);
	}
};

#endif
