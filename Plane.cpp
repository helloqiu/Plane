#include "Sky.h"
Plane::Plane(int type){
	this->type = type;
	planeClock.restart();
	bulletSoundBuffer.loadFromFile("resource/sounds/bullet.ogg");
	bulletSound.setBuffer(bulletSoundBuffer);
}
void Plane::fire(){
	if(planeClock.getElapsedTime().asSeconds() > sf::seconds(0.2f).asSeconds()){
		planeFirer->fire(this->getPosition());
		planeClock.restart();
		bulletSound.play();
	}
}
int Plane::getType(){
	return type;
}
void Plane::setFirer(Firer &firer){
	this->planeFirer = &firer;
}