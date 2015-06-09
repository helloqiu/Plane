#include "Sky.h"
void Sky::add(sf::Sprite &sprite){
	if(((Plane*)(&sprite))->getType() == HERO){
		std::cout << "add Plane\n";
		spriteVector.push_back(&sprite);
		return;
	}
	if(((Plane*)(&sprite))->getType() == ENEMY_1){
		std::cout << "add enemy\n";
		enemy_1Vector.push_back(&sprite);
		return;
	}
}
void Sky::add(Bullet *bullet){
	if (bullet->getType() == HERO_BULLET){
		std::cout << "add hero bullet\n";
		herobulletVector.push_back(bullet);
		return;
	}
	if (bullet->getType() == ENEMY_BULLET){
		std::cout << "add enemy bullet\n";
		enemybulletVector.push_back(bullet);
		return;
	}
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
	// draw the enemy
	for (int i = 0 ; i < enemy_1Vector.size() ; i ++){
		window.draw(*enemy_1Vector.at(i));
	}
	// draw enemy bullet
	for (int i = 0 ; i < enemybulletVector.size() ; i ++){
		window.draw(*enemybulletVector.at(i));
	}
}
void Sky::moveAll(){
	// move hero bullets
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
	// move enemybullet
	i = 0;
	while (i < enemybulletVector.size()){
		if(enemybulletVector.at(i)->getPosition().y - enemybulletVector.at(i)->getTexture()->getSize().y / 2 > 800){
			// erase the bullet
			delete enemybulletVector.at(i);
			enemybulletVector.erase(enemybulletVector.begin() + i);
			continue;
		}
		enemybulletVector.at(i)->move(0 , 5);
		i++;
	}
	// move enemy 
	i = 0;
	while(i < enemy_1Vector.size()){
		if(enemy_1Vector.at(i)->getPosition().y - enemy_1Vector.at(i)->getTexture()->getSize().y / 2 > 800){
			// erase the enemy
			delete enemy_1Vector.at(i);
			enemy_1Vector.erase(enemy_1Vector.begin()+i);
			continue;
		}
		enemy_1Vector.at(i)->move(0, 3);
		i ++;
	}
}