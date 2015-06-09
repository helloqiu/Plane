#ifndef SKY_H
#define SKY_H
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <vector>
class Sky{
public:
	void add(sf::Sprite &sprite);
	void draw(sf::RenderWindow &window);
private:
	std::vector<sf::Sprite *> spriteVector;
};
#endif