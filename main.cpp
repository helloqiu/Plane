/*
Time : 2015-6-9 8:42
Description : begin to rewrite it
Time : 2015-6-9 16:17
Dexcription : I add the bullet
*/
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Sky.h"
#include "LoadTexture.h"
#include "Plane.h"
#include "Controller.h"
#include "Bullet.h"
#include "Firer.h"
int main(void){
	// the window
	sf::RenderWindow window(sf::VideoMode(480 , 800) , "plane");
	window.setFramerateLimit(60);
	// background music
	sf::Music backgroundMusic;
	backgroundMusic.openFromFile("resource/sounds/background.ogg");
	backgroundMusic.setLoop(true);
	backgroundMusic.play();
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
	// firer
	Firer firer(sky , loadtexture);
	// hero
	Plane hero(HERO);
	hero.setTexture(*loadtexture.getTextureByName("hero2"));
	// set hero position
	hero.setOrigin(hero.getTexture()->getSize().x / 2 , hero.getTexture()->getSize().y / 2);
	hero.setPosition(window.getSize().x / 2, window.getSize().y - hero.getTexture()->getSize().y / 2);
	hero.setFirer(firer);
	sky.add(hero);
	// the controller
	Controller controller;
	// the loop
	while (window.isOpen()){
		sf::Event event;
		while (window.pollEvent(event)){
			if (event.type == sf::Event::Closed){
				window.close();
			}
		}
		window.clear();
		controller.control(hero);
		sky.draw(window);
		window.display();
	}
}
