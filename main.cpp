#include <string>
#include <SFML/Graphics.hpp>
using sf::IntRect;
using sf::Vector2f;

#include "Includes/Sprite.hpp"

int main(){
  sf::RenderWindow window(sf::VideoMode (960, 540), "Sprite Render Test"); // Criacao da janela 
  
  IntRect characterTexture(3, 0, 10, 18); // Define uma area de corte na imagem do sprite
  Vector2f upscaleCharacter(2.5f, 2.5f); // Aumenta o tamanho do Sprite em 2.5x

  // Contrutor do objeto Sprite
  calvoSprite characterSprite("Assets/Images/Characters/Calvo.png", characterTexture, upscaleCharacter); 
  characterSprite.setPosition(100, 100); // Define a posicao inicial do Sprite

  while (window.isOpen()){
    sf::Event event;

    while (window.pollEvent(event)){
      if (event.type == sf::Event::Closed){
        window.close();
      }
    }

    window.clear();
    characterSprite.drawCharacter(&window);
    window.display();
  }

  return 0;
}