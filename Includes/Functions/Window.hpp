#include <SFML/Graphics.hpp>

void windowClose(sf::RenderWindow &window) {
	sf::Event closeWindow;

	while (window.pollEvent(closeWindow)) {
		if (closeWindow.type == sf::Event::Closed) {
			window.close();
		}
	}
}
