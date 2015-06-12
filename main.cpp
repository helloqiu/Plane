/*
Time : 2015-6-9 8:42
Description : begin to rewrite it
Time : 2015-6-9 16:17
Dexcription : I add the bullet
Time :2015-6-9 20:55  
Description : begin to add the enemy
Time :2015-6-9 21:51
Description : finish the enemy
Time :2015-6-12 16:02
Description : begin to rewrite the plane class 
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
	// the clock to control the enemy
	sf::Clock enemyClock;
	enemyClock.restart();
	// the window
	sf::RenderWindow window(sf::VideoMode(480 , 800) , "plane");
	window.setFramerateLimit(60);
	// background music
	sf::Music backgroundMusic;
	backgroundMusic.openFromFile("resource/sounds/background.ogg");
	backgroundMusic.setLoop(true);
	backgroundMusic.setVolume(20);
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
	// the enemy_1 pointer
	// animation
	Animation enemy_1Animation;
	enemy_1Animation.addTexture(*loadtexture.getTextureByName("enemy1_down1"));
	enemy_1Animation.addTexture(*loadtexture.getTextureByName("enemy1_down2"));
	enemy_1Animation.addTexture(*loadtexture.getTextureByName("enemy1_down3"));
	enemy_1Animation.addTexture(*loadtexture.getTextureByName("enemy1_down4"));
	enemy_1Animation.setTime(1);
	Plane *enemy;
	// the loop
	while (window.isOpen()){
		sf::Event event;
		while (window.pollEvent(event)){
			if (event.type == sf::Event::Closed){
				window.close();
			}
		}
		// random add enemy
		if((rand() % 10 == 1) && (enemyClock.getElapsedTime().asSeconds() > sf::seconds(0.5f).asSeconds())){
			enemy = new Plane(ENEMY_1);
			enemy->setTexture(*loadtexture.getTextureByName("enemy1"));
			enemy->setOrigin(enemy->getTexture()->getSize().x / 2 , enemy->getTexture()->getSize().y / 2);
			enemy->setFirer(firer);
			enemy->setPosition(hero.getPosition().x , 0);
			enemy->setAnimation(enemy_1Animation);
			sky.add(*enemy);
			enemy->fire();
			enemyClock.restart();
		}
		window.clear();
		window.draw(backgroundSprite);
		controller.control(hero);
		sky.draw(window);
		window.display();
	}
}
