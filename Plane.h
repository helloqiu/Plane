#ifndef PLANE_H
#define PLANE_H
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#define HERO 1
#define ENEMY_1 2
class Plane:public sf::Sprite{
public:
	Plane(int type);
private:
	int type;
};
#endif