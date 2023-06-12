#include <iostream>
#include <string>

// Incluindo Header Files de Classes
#include "Includes/Classes/Player.hpp"

// Incluindo Header Files de Funções
#include "Includes/Functions/Window.hpp"

int main() {
	sf::RenderWindow gameWindow(sf::VideoMode(1024, 576), "Normal Maze :P");

	Player player;

	while (gameWindow.isOpen()) {
		windowClose(gameWindow);

		gameWindow.clear();
		gameWindow.draw(player.getSprite());
		gameWindow.display();
	}

	return 0;
}
