#include "Sky.h"
Plane::Plane(int type){
	ifStop = false;
	this->type = type;
	planeClock.restart();
	bulletSoundBuffer.loadFromFile("resource/sounds/bullet.ogg");
	bulletSound.setBuffer(bulletSoundBuffer);
}
void Plane::fire(){
	if((planeClock.getElapsedTime().asSeconds() > sf::seconds(0.2f).asSeconds()) || (this->type != HERO)){
		planeFirer->fire(this->getPosition() , this->getType());
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
void Plane::kill(Sky *sky){
	ifStop = true;
	killAnimation.setPosition(this->getPosition());
	sky->add(*killAnimation.startPlay());
	killAnimation.setPosition(this->getPosition());
}
void Plane::setAnimation(Animation &animation){
	this->killAnimation = animation;
}
bool Plane::ifCouldErase(){
	if(ifStop && killAnimation.ifStop()){
		return true;
	}else{
		return false;
	}
}
bool Plane::ifkill(){
	return ifStop;
}
Animation* Plane::getAnimation(){
	return &killAnimation;
}