#include <string>
#include <SFML/Graphics.hpp>
using sf::IntRect;
using sf::Vector2f;

#include "Includes/Sprite.hpp"

int main(){
  sf::RenderWindow window(sf::VideoMode (960, 540), "Sprite Render Test"); // Criacao da janela 
  
  IntRect characterTexture(2, 2, 12, 15); // Define uma area de corte na imagem do sprite
  Vector2f upscaleCharacter(2.5f, 2.5f); // Aumenta o tamanho do Sprite em 2.5x
  Vector2f position(100.0f, 100.f);
  
  // Contrutor do objeto Sprite
  calvoSprite characterSprite("Assets/Images/Characters/Calvo.png", characterTexture, upscaleCharacter, position); 
  
  sf::Clock clock;
  while (window.isOpen()){
    sf::Event event;

    while (window.pollEvent(event)){
      if (event.type == sf::Event::Closed){
        window.close();
      }
    }
    
    float deltaTime = clock.restart().asSeconds();
    characterSprite.update(deltaTime);
    characterSprite.moveCharacter(&window);

    window.clear();
    characterSprite.drawCharacter(&window);
    window.display();
  }

  return 0;
}
