#ifndef PLANE_H
#define PLANE_H
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Firer.h"
#define HERO 1
#define ENEMY_1 2
class Plane:public sf::Sprite{
public:
	Plane(int type);
	void setFirer(Firer &firer);
	void fire();
	int getType();
private:
	int type;
	Firer *firer;
};
#endif