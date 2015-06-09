#include "Sky.h"
void Sky::add(sf::Sprite &sprite){
	spriteVector.push_back(&sprite);
}
void Sky::draw(sf::RenderWindow &window){
	for (int i = 0 ; i < spriteVector.size() ; i ++){
		window.draw(*spriteVector.at(i));
	}
}