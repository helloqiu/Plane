#include "Sky.h"
void Sky::add(sf::Sprite &sprite){
	std::cout << "add Plane\n";
	spriteVector.push_back(&sprite);
	return;
}
void Sky::add(Bullet *bullet){
	std::cout << "add hero bullet\n";
	herobulletVector.push_back(bullet);
	return;
}

void Sky::draw(sf::RenderWindow &window){
	// move all 
	this->moveAll();
	// draw the hero
	for (int i = 0 ; i < spriteVector.size() ; i ++){
		window.draw(*spriteVector.at(i));
	}
	// draw the hero bullet
	for (int i = 0 ; i < herobulletVector.size() ; i ++){
		window.draw(*herobulletVector.at(i));
	}
}
void Sky::moveAll(){
	int i = 0;
	while (i < herobulletVector.size()){
		if(herobulletVector.at(i)->getPosition().y + herobulletVector.at(i)->getTexture()->getSize().y / 2 < 0){
			// erase the bullet
			delete herobulletVector.at(i);
			herobulletVector.erase(herobulletVector.begin() + i);
			continue;
		}
		herobulletVector.at(i)->move(0, -5);
		i ++;
	}
}