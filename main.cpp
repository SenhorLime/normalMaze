#include <iostream>
#include <string>

// Incluindo Header Files de Classes
#include "Includes/Classes/Player.hpp"
#include "Includes/Classes/Maze.hpp"

// Incluindo Header Files de Funções
#include "Includes/Functions/Window.hpp"

int main() {
	sf::RenderWindow gameWindow(sf::VideoMode(1280, 720), "Normal Maze :P");

	sf::Image gameIcon;
	gameIcon.loadFromFile("Assets/Icons/normalMaze.png");
	gameWindow.setIcon(gameIcon.getSize().x, gameIcon.getSize().y, gameIcon.getPixelsPtr());

	sf::Clock gameTime;

	Player player1;
	SecondPlayer player2;

	Maze maze(gameWindow);

	while (gameWindow.isOpen()) {
		windowClose(gameWindow);

		float deltaTime = gameTime.restart().asSeconds();

		gameWindow.clear();
		maze.drawOnWindow(gameWindow);
		player1.updatePlayer(deltaTime, maze);
		player1.drawOnWindow(gameWindow);

		player2.updatePlayer(deltaTime, maze);
		player2.drawOnWindow(gameWindow);
		gameWindow.display();
	}

	return 0;
}
