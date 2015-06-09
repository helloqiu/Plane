build: main.cpp Sky.cpp Sky.h Plane.h Plane.cpp LoadTexture.h LoadTexture.cpp Controller.h Controller.cpp Bullet.cpp Bullet.h Firer.h Firer.cpp
	g++ -c main.cpp Sky.cpp Plane.cpp LoadTexture.cpp Controller.cpp Bullet.cpp Firer.cpp  
	g++ main.o Sky.o Plane.o LoadTexture.o Controller.o Bullet.o Firer.o  -o sfml-app -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio 
clear: main.o sfml-app Sky.o LoadTexture.o Plane.o Controller.o Bullet.o Firer.o
	rm main.o Sky.o sfml-app LoadTexture.o Plane.o Controller.o Bullet.o Firer.o