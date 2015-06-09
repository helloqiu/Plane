#ifndef FIRER_H
#define FIRER_H
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Sky.h"
class Firer{
public:
	Firer(Firer &firer);
	Firer(Bullet &bullet , Sky &sky);
	void fire(sf::Vector2f positon );
private:
	Bullet bullet;
	Sky *sky;
};
#endif