#include <SFML/Graphics.hpp>
using sf::IntRect;
using sf::Vector2f;
using sf::Keyboard;

#include <iostream>

class calvoSprite{
private:
  sf::Texture calvoTexture;
  sf::Sprite spriteCalvo;
  float speed;
  float deltaTime;

public:
  calvoSprite (std::string textureFile, const IntRect textureCrop, const Vector2f textureScale, const Vector2f position) : speed(200.0f){
    if (!calvoTexture.loadFromFile(textureFile)){
      std::cerr << "Arquivo Calvo não foi encontrado";
    }

    spriteCalvo.setTexture(calvoTexture);
    spriteCalvo.setTextureRect(textureCrop);
    spriteCalvo.setScale(textureScale);
    spriteCalvo.setPosition(position);
  }
  
  void moveCharacter(sf::RenderWindow *window){
    sf::Vector2f movement(0.0f, 0.0f);

    if (Keyboard::isKeyPressed(Keyboard::W)){
      movement.y -= 1.0f;
      spriteCalvo.setTextureRect(IntRect (34, 2, 12, 15));
    }

    if (Keyboard::isKeyPressed(Keyboard::S)){
      movement.y += 1.0f;
      spriteCalvo.setTextureRect(IntRect (2, 2, 12, 15));
    }

    if (Keyboard::isKeyPressed(Keyboard::A)){
      movement.x -= 1.0f;
      spriteCalvo.setTextureRect(IntRect (52, 2, 9, 15));
    }

    if (Keyboard::isKeyPressed(Keyboard::D)){
      movement.x += 1.0f;
      spriteCalvo.setTextureRect(IntRect (19, 2, 9, 15));
    }

    move(movement);
  }

  void move(const sf::Vector2f direction){
    sf::Vector2f movement = direction * speed * deltaTime;

    spriteCalvo.move(movement);
  }
  
  void update(float dt){
    deltaTime = dt;
  }
    
  void drawCharacter(sf::RenderWindow *window){
    window -> draw(spriteCalvo);
  }
};
