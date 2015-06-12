#include "Sky.h"
#include "math.h"
Plane::Plane(int type){
	ifStop = false;
	ifKilled = false;
	this->type = type;
	planeClock.restart();
	bulletSoundBuffer.loadFromFile("resource/sounds/bullet.ogg");
	bulletSound.setBuffer(bulletSoundBuffer);
	nowTexture = 0;
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
	ifKilled = true;
	textureClock.restart();
	this->setTexture(*textureVector->at(0));
}
bool Plane::ifCouldErase(){
	if(ifStop && ifKilled){
		return true;
	}else{
		return false;
	}
}
bool Plane::ifkill(){
	return ifKilled;
}
Animation* Plane::getAnimation(){
	return &killAnimation;
}
void Plane::moveThis(){
	if (this->type == ENEMY_1){
		if (this->ifKilled){
			if (textureClock.getElapsedTime().asSeconds() > sf::seconds(timePerTexture).asSeconds()){
				std::cout << "texture move to : " << nowTexture+1 <<"\n";
				nowTexture ++;
				textureClock.restart();
				if (nowTexture > 3){
					ifStop = true;
					return;
				}
				this->setTexture(*textureVector->at(nowTexture));
				return;
			}
			return;
		}
		this->move(0 , 3);
	}
}
void Plane::setTextureVector(std::vector<sf::Texture*> *v){
	this->textureVector = v;
}
void Plane::setTimePerTexture(float time){
	timePerTexture = time;
}

