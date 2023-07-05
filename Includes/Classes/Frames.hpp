#ifndef FRAMES_HPP
#define FRAMES_HPP

#include <SFML/Graphics.hpp>
using sf::IntRect;

#include <vector>

class Frames {
public:
	std::vector<sf::IntRect> Up = { IntRect(34, 2, 12, 16), IntRect(34, 18, 12,
			16), IntRect(34, 35, 12, 16) };
	std::vector<sf::IntRect> Down = { IntRect(2, 2, 12, 16), IntRect(2, 18, 12,
			16), IntRect(2, 35, 12, 16) };
	std::vector<sf::IntRect> Left = { IntRect(52, 2, 12, 16), IntRect(52, 18,
			12, 16), IntRect(52, 35, 12, 16) };
	std::vector<sf::IntRect> Right = { IntRect(19, 2, 12, 16), IntRect(19, 18,
			12, 16), IntRect(19, 35, 12, 16) };
};
#endif

