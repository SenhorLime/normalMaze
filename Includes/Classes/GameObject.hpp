#include <SFML/Graphics.hpp>

class GameObject {
protected:
	sf::Sprite objectSprite;
public:
	void setTexture (std::string textureFilePath){
		sf::Texture objectTexture;

		if (objectTexture.loadFromFile(textureFilePath)){
			objectSprite.setTexture(objectTexture);
		} else {
			std::cerr << "Erro ao carregar textura do objeto!";
		}
	}

	sf::Sprite getSprite (){
		return objectSprite;
	}
};
