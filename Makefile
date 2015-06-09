build: main.cpp Sky.cpp Sky.h Plane.h Plane.cpp LoadTexture.h LoadTexture.cpp
	g++ -c main.cpp Sky.cpp Plane.cpp LoadTexture.cpp
	g++ main.o Sky.o Plane.o LoadTexture.o  -o sfml-app -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio 
clear: main.o sfml-app Sky.o LoadTexture.o Plane.o
	rm main.o Sky.o sfml-app LoadTexture.o Plane.o