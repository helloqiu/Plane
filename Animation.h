#ifndef ANIMATION_H
#define ANIMATION_H
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <vector>
class Animation{
public:	
	Animation();
	void addTexture(sf::Texture &texture);
	void setTime(float time);
	void setPosition(sf::Vector2f position);
	sf::Sprite* startPlay();
	void play();
	bool ifStop();
private:
	std::vector<sf::Texture*> textureVector;
	float timePer;
	sf::Vector2f position;
	sf::Clock playClock;
	int now;
	bool ifPlaying;
	sf::Sprite sprite;
};
#endif