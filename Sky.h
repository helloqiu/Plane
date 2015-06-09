#ifndef SKY_H
#define SKY_H
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Bullet.h"
#include <vector>
#include "Plane.h"
#include "LoadTexture.h"
#include <iostream>
// Sky Class
class Sky{
public:
	void add(sf::Sprite &sprite);
	void add(Bullet *bullet);
	void draw(sf::RenderWindow &window);
private:
	void moveAll();
	std::vector<sf::Sprite *> spriteVector;
	std::vector<Bullet*> herobulletVector;
};
// Firer class
class Firer{
public:
	Firer(Firer &firer);
	Firer(Sky &sky , LoadTexture &loadtexture);
	void fire(sf::Vector2f positon );
private:
	Bullet *bullet;
	Sky *sky;
	LoadTexture *loadtexture;
};
// Plane class
#define HERO 1
#define ENEMY_1 2
class Plane:public sf::Sprite{
public:
	Plane(int type);
	void setFirer(Firer &firer);
	void fire();
	int getType();
private:
	sf::Clock planeClock;
	int type;
	Firer *planeFirer;
	sf::Sound bulletSound;
	sf::SoundBuffer bulletSoundBuffer;
};
#endif