#include <iostream>
#include <string>

// Incluindo Header Files de Classes
#include "Includes/Classes/Player.hpp"
#include "Includes/Classes/Maze.hpp"

// Incluindo Header Files de Funções
#include "Includes/Functions/Window.hpp"

int main() {
	sf::RenderWindow gameWindow(sf::VideoMode(1280, 720), "Normal Maze :P");
	sf::Clock gameTime;

	//*****************************************Icone da janela*******************************************
		sf::Image image = sf::Image { };
		image.loadFromFile("Assets/Icons/monkey.jpg");
		gameWindow.setIcon(image.getSize().x, image.getSize().y, image.getPixelsPtr());

	Player player1;
	Maze maze(gameWindow);

	while (gameWindow.isOpen()) {
		windowClose(gameWindow);

		float deltaTime = gameTime.restart().asSeconds();

		gameWindow.clear();
		maze.drawOnWindow(gameWindow);
		player1.updatePlayer(deltaTime, maze);
		player1.drawOnWindow(gameWindow);
		gameWindow.display();
	}

	return 0;
}
