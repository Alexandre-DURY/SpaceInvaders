#include <iostream>
#include "Bonus.h"
#include "Terrain.h"
#include "Ennemie.h"
#include "SpaceShip.h"
#include "Missile.h"
#include "Jeu.h"
#include "Niveau.h"

int main(int argc, char **argv)
{
    Bonus bonus;
    std::cout << "CLASSSE BONUS" << std::endl;
    bonus.TestRegression();
    std::cout << "Test OK" << std::endl
              << std::endl;

    Terrain terrain;
    std::cout << "CLASSE TERRAIN" << std::endl;
    terrain.TestRegression();
    std::cout << "Test OK" << std::endl
              << std::endl;

    SpaceShip spaceShip;
    Terrain t1;
    std::cout << "CLASSE SPACESHIP" << std::endl;
    spaceShip.TestRegression(t1);
    std::cout << "Test OK" << std::endl
              << std::endl;

    Missile missile;
    Missile m;
    Terrain t2;
    std::cout << "CLASSE MISSILE" << std::endl;
    missile.TestRegression(t2, m);
    std::cout << "Test OK" << std::endl
              << std::endl;

    Ennemie ennemie;
    Terrain t3;
    Bonus b;
    std::cout << "CLASSE ENNEMIE" << std::endl;
    ennemie.TestRegression(t3, b);
    std::cout << "Test OK" << std::endl
              << std::endl;
}