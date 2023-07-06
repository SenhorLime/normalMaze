#include <iostream>
#include <string>
#include <SFML/Audio.hpp>
// Incluindo Header Files de Classes
#include "Includes/Classes/Player.hpp"
#include "Includes/Classes/Maze.hpp"

// Incluindo Header Files de Funções
#include "Includes/Functions/Window.hpp"

void setMusic(sf::Music& music) {
	music.openFromFile("Assets/Audio/Music/NightRunning.ogg");
	music.play();
	music.setVolume(50);
	music.setLoop(true);
}

int main() {
	sf::RenderWindow gameWindow(sf::VideoMode(1280, 720), "Normal Maze :P");

	sf::Image gameIcon;
	gameIcon.loadFromFile("Assets/Icons/normalMaze.png");
	gameWindow.setIcon(gameIcon.getSize().x, gameIcon.getSize().y,
			gameIcon.getPixelsPtr());

	sf::Clock gameTime;

	sf::Music backgroundMusic;
	setMusic(backgroundMusic);

	Player player1;
	SecondPlayer player2;

	Maze maze(gameWindow);

	while (gameWindow.isOpen() && player1.isVictoryFinale(maze) == false && player2.isVictoryFinale(maze) == false) {
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
