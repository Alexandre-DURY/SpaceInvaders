all: bin/Jeu bin/JeuTXT bin/TestRegression

bin/JeuTXT :obj/mainTXT.o obj/ImageTXT.o obj/Ennemie.o obj/SpaceShip.o obj/Missile.o obj/Terrain.o obj/winTxt.o obj/Jeu.o obj/winTxt.o obj/Niveau.o obj/Bonus.o
	g++ -g obj/mainTXT.o obj/ImageTXT.o obj/Ennemie.o obj/SpaceShip.o obj/Missile.o obj/Terrain.o obj/Jeu.o obj/winTxt.o obj/Niveau.o obj/Bonus.o -o bin/JeuTXT

bin/Jeu :obj/mainSDL.o obj/Image.o obj/SDL_Basique.o obj/Ennemie.o obj/SpaceShip.o obj/Missile.o obj/Terrain.o obj/Jeu.o obj/Niveau.o obj/Bonus.o
	g++ -g obj/mainSDL.o obj/Image.o obj/SDL_Basique.o obj/Ennemie.o obj/SpaceShip.o obj/Missile.o obj/Terrain.o obj/Jeu.o obj/Niveau.o obj/Bonus.o -lSDL2 -lSDL2_image -lSDL2_ttf -o bin/Jeu

bin/TestRegression : obj/mainRegression.o obj/Bonus.o obj/Terrain.o obj/Ennemie.o obj/SpaceShip.o obj/Missile.o obj/Jeu.o obj/Niveau.o
	g++ -g obj/mainRegression.o obj/Bonus.o obj/Terrain.o obj/Ennemie.o obj/SpaceShip.o obj/Missile.o obj/Jeu.o obj/Niveau.o -o bin/TestRegression

obj/ImageTXT.o : src/Jeu.h src/ImageTXT.h src/ImageTXT.cpp
	g++ -g -Wall -c src/ImageTXT.cpp -o obj/ImageTXT.o

obj/SDL_Basique.o : src/SDL_Basique.h src/SDL_Basique.cpp src/Image.h src/Jeu.h
	g++ -g -Wall -c src/SDL_Basique.cpp -o obj/SDL_Basique.o -I/usr/include/SDL2 -lSDL2 -lSDL2_image -lSDL2_ttf

obj/Image.o : src/Image.h src/Image.cpp
	g++ -g -Wall -c src/Image.cpp -o obj/Image.o -I/usr/include/SDL2

obj/Jeu.o : src/Jeu.cpp src/Jeu.h src/SpaceShip.h src/Terrain.h src/Ennemie.h src/Niveau.h src/Bonus.h
	g++ -g -Wall -c src/Jeu.cpp -o obj/Jeu.o

obj/Niveau.o : src/Ennemie.h src/Terrain.h src/Niveau.cpp src/Niveau.h
	g++ -g -Wall -c src/Niveau.cpp -o obj/Niveau.o

obj/Ennemie.o : src/Terrain.h src/Missile.h src/Bonus.h src/Ennemie.cpp src/Ennemie.h
	g++ -g -Wall -c src/Ennemie.cpp -o obj/Ennemie.o

obj/SpaceShip.o : src/Terrain.h src/Missile.h src/SpaceShip.cpp src/SpaceShip.h
	g++ -g -Wall -c src/SpaceShip.cpp -o obj/SpaceShip.o

obj/Missile.o : src/Terrain.h src/Missile.cpp src/Missile.h
	g++ -g -Wall -c src/Missile.cpp -o obj/Missile.o

obj/Bonus.o : src/Bonus.cpp src/Bonus.h
	g++ -g -Wall -c src/Bonus.cpp -o obj/Bonus.o

obj/Terrain.o : src/Terrain.cpp src/Terrain.h
	g++ -g -Wall -c src/Terrain.cpp -o obj/Terrain.o

obj/winTxt.o : src/winTxt.cpp src/winTxt.h
	g++ -g -Wall -c src/winTxt.cpp -o obj/winTxt.o

obj/mainTXT.o: src/mainTXT.cpp src/ImageTXT.h
	g++ -Wall -c src/mainTXT.cpp -o obj/mainTXT.o

obj/mainSDL.o: src/mainSDL.cpp src/SDL_Basique.h
	g++ -Wall -c src/mainSDL.cpp -o obj/mainSDL.o

obj/mainRegression.o: src/mainRegression.cpp src/Bonus.h src/Terrain.h src/Ennemie.h src/SpaceShip.h src/Missile.h src/Jeu.h src/Niveau.h
	g++ -Wall -c src/mainRegression.cpp -o obj/mainRegression.o

clean:
	rm obj/*

veryclean: clean
	rm bin/*
