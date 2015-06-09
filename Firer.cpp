#include "Firer.h"
Firer::Firer(Firer &firer){
	this->bullet = firer.bullet;
	this->sky = firer.sky;
}
Firer::Firer(Bullet &bullet , Sky &sky){
	this->bullet = bullet;
	this->sky = &sky;
}
void Firer::fire(sf::Vector2f position){
	Bullet *bullet = new Bullet(this->bullet.getType());
	bullet->setTexture(*(this->bullet.getTexture()));
	bullet->setOrigin(bullet->getTexture()->getSize().x / 2 ,bullet->getTexture()->getSize().y / 2);
	bullet->setPosition(position);
	sky->add(bullet);
}