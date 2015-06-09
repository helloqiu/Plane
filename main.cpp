/*
Time : 2015-6-9 8:42
Description : begin to rewrite it
*/
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Sky.h"
#include "LoadTexture.h"
#include "Plane.h"
int main(void){
	// the window
	sf::RenderWindow window(sf::VideoMode(480 , 800) , "plane");
	window.setFramerateLimit(60);
	// background
	sf::Sprite backgroundSprite;
	sf::Texture backgroundTexture;
	backgroundTexture.loadFromFile("resource/background.png");
	backgroundSprite.setTexture(backgroundTexture);
	// sky 
	Sky sky;
	sky.add(backgroundSprite);
	// loadtexture
	LoadTexture loadtexture;
	loadtexture.initLoad();
	loadtexture.loadFromFile("resource/shoot.png");
	// hero
	Plane hero(HERO);
	hero.setTexture(*loadtexture.getTextureByName("hero2"));
	// set hero position
	hero.setPosition(window.getSize().x / 2, window.getSize().y - hero.getTexture()->getSize().y);
	sky.add(hero);

	// the loop
	while (window.isOpen()){
		sf::Event event;
		while (window.pollEvent(event)){
			if (event.type == sf::Event::Closed){
				window.close();
			}
		}
		window.clear();
		sky.draw(window);
		window.display();
	}
}
