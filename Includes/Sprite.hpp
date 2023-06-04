#include <SFML/Graphics.hpp>
using sf::IntRect;
using sf::Vector2f;

#include <iostream>

class calvoSprite{
private:
  sf::Texture calvoTexture;
  sf::Sprite spriteCalvo;

public:
  calvoSprite (std::string textureFile, const IntRect textureCrop, const Vector2f textureScale){
    if (!calvoTexture.loadFromFile(textureFile)){
      std::cerr << "Arquivo Calvo não foi encontrado";
    }

    spriteCalvo.setTexture(calvoTexture);
    spriteCalvo.setTextureRect(textureCrop);
    spriteCalvo.setScale(textureScale);
  }

  void setPosition(float x, float y){
    spriteCalvo.setPosition(x, y);
  }

  void drawCharacter(sf::RenderWindow *window){
    window -> draw(spriteCalvo);
  }
};