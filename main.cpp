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

	std::string mazeString =
			"..###########################\n"
			"....#.........#...#.#.......#\n"
			"#.#########.#.###.#.#.#######\n"
			"#.....#.....#.#.....#...#.#.#\n"
			"#####.###.#.#####.#.#.###.#.#\n"
			"#...#.#.#.#...#...#.....#...#\n"
			"#.###.#.#.#####.###.#.###.###\n"
			"#.#.........#.....#.#.#...#.#\n"
			"#.#########.#####.#######.#.#\n"
			"#.....#.......#.....#.#...#.#\n"
			"#.#.#######.#####.###.#.###.#\n"
			"#.#.................#.#.#.#.#\n"
			"#.#########.#.#####.#.#.#.#.#\n"
			"#.........#.#.#.............#\n"
			"###########################.#";

	Player player1;
	Maze maze(mazeString, gameWindow);

	while (gameWindow.isOpen()) {
		windowClose(gameWindow);

		float deltaTime = gameTime.restart().asSeconds();

		gameWindow.clear();
		maze.drawOnWindow(gameWindow);
		player1.updatePlayer(gameWindow, deltaTime);
		player1.drawOnWindow(gameWindow);
		gameWindow.display();
	}

	return 0;
}
