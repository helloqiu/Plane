#include "Animation.h"
#include "iostream"
Animation::Animation(){
	ifPlaying = false;
	now = 0;
}
void Animation::addTexture(sf::Texture &texture){
	textureVector.push_back(&texture);
}
void Animation::setTime(float time){
	timePer = time;
}
void Animation::setPosition(sf::Vector2f position){
	this->position = position;
}
sf::Sprite* Animation::startPlay(){
	// calculate the time
	timePer = timePer / textureVector.size();
	ifPlaying = true;
	sprite.setTexture(*textureVector.at(now));
	sprite.setPosition(position);
	sprite.setOrigin(sprite.getTexture()->getSize().x / 2 , sprite.getTexture()->getSize().y / 2);
	playClock.restart();
	return &sprite;
}
void Animation::play(){
	if (!ifPlaying){
		return;
	}
	if((playClock.getElapsedTime().asSeconds() > sf::seconds(timePer).asSeconds())){
		now ++;
		playClock.restart();
		std::cout << "now : " << now << "\n";
		if(now == textureVector.size() - 1){
			ifPlaying = false;
			return;
		}
		sprite.setTexture(*textureVector.at(now));
		sprite.setPosition(position);
		sprite.setOrigin(sprite.getTexture()->getSize().x / 2 , sprite.getTexture()->getSize().y / 2);
	}
}
bool Animation::ifStop(){
	if (ifPlaying){
		return false;
	}else{
		return true;
	}
}
