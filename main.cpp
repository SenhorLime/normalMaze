#include <iostream>
#include <string>

// Incluindo Header Files de Classes
#include "Includes/Classes/Player.hpp"

// Incluindo Header Files de Funções
#include "Includes/Functions/Window.hpp"

int main() {
	sf::RenderWindow gameWindow(sf::VideoMode(1024, 576), "Normal Maze :P");
	sf::Clock gameTime;

	Player player1;


	while (gameWindow.isOpen()) {
		windowClose(gameWindow);

		float deltaTime = gameTime.restart().asSeconds();

		gameWindow.clear();
		player1.playerFunction(gameWindow, deltaTime);
		player1.drawOnWindow(gameWindow);
		gameWindow.display();
	}

	return 0;
}
