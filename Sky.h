#ifndef SKY_H
#define SKY_H
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Bullet.h"
#include <vector>
#include "Plane.h"
#include <iostream>
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
#endif