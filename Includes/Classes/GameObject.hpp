#ifndef GAME_OBJECT_HPP
#define GAME_OBJECT_HPP

#include <SFML/Graphics.hpp>

class GameObject {
protected:
	sf::Sprite objectSprite;
public:
	void drawOnWindow(sf::RenderWindow& window){
		window.draw(objectSprite);
	}
};

#endif
