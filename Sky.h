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
	void check();
	std::vector<sf::Sprite *> spriteVector;
	std::vector<Bullet*> herobulletVector;
	std::vector<Bullet*> enemybulletVector;
	std::vector<sf::Sprite *> enemy_1Vector;
	std::vector<sf::Sprite *> animationVector;
	sf::Sprite* enemyNum[100];
};
// Firer class
class Firer{
public:
	Firer(Firer &firer);
	Firer(Sky &sky , LoadTexture &loadtexture);
	void fire(sf::Vector2f positon , int type);
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
	void kill(Sky *sky);
	bool ifCouldErase();
	bool ifkill();
	void moveThis();
	void setTextureVector(std::vector<sf::Texture*> *v);
	void setTimePerTexture(float time);
private:
	sf::Clock planeClock;
	int type;
	Firer *planeFirer;
	sf::Sound bulletSound;
	sf::SoundBuffer bulletSoundBuffer;
	bool ifStop;
	bool ifKilled;
	int nowTexture;
	std::vector<sf::Texture*> *textureVector;
	sf::Clock textureClock;
	float timePerTexture;
};
#endif