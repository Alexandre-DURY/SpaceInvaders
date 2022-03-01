#include "SpaceShip.h"
#include <cstddef>
#include <cassert>
#include <iostream>

SpaceShip::SpaceShip()
{ // Initialisation
    y = 17;
    x = 18;
    NbLife = 5;
    nb_missiles = 200;
    missiles_tire = 0;
    RemplirTabMissiles();
}

SpaceShip::~SpaceShip()
{ // Supprime ce qui a sur le tas
    delete[] tab_missiles;
}

int SpaceShip::getX() const
{
    return x;
}

int SpaceShip::getY() const { return y; }

void SpaceShip::setXY(int nx, int ny, Terrain t)
{
    assert(t.estPositionPersoValide(nx, ny)); // vérifie la futur position du vaisseau
    x = nx;
    y = ny;
}

int SpaceShip::getNombreDeMissiles() const { return nb_missiles; }

Missile *SpaceShip::getMissiles() const { return tab_missiles; }

int SpaceShip::getVie() const { return NbLife; }

void SpaceShip::setVie(int x) { NbLife += x; }

void SpaceShip::gauche(const Terrain &t)
{
    if (t.estPositionPersoValide(x - 1, y))
        x--;
}

void SpaceShip::droite(const Terrain &t)
{
    if (t.estPositionPersoValide(x + 1, y))
        x++;
}

void SpaceShip::TirerMissile(const Terrain &t)
{
    tab_missiles[missiles_tire].setMouvement(true); // le missile part du vaisseau qui le tire
    missiles_tire++;
    if (missiles_tire == nb_missiles)
    {
        missiles_tire = 0;
        delete[] tab_missiles;
        RemplirTabMissiles();
    }
}

void SpaceShip::TirerMultiMissile(const Terrain &t)
{
    for (int i = 0; i < 6; i++)
    {
        tab_missiles[missiles_tire].setXY(x - 4 + i * 2, y, t);
        TirerMissile(t);
    }
}

void SpaceShip::RemplirTabMissiles()
{
    Terrain t;
    tab_missiles = new Missile[nb_missiles];
    for (int i = 0; i < nb_missiles; i++)
    {
        tab_missiles[i].setXY(x, y, t);
    }
}

void SpaceShip::TestRegression(Terrain t)
{
    assert(getX() == 18);
    std::cout << "X = " << getX() << std::endl;

    assert(getY() == 17);
    std::cout << "Y = " << getY() << std::endl;

    setXY(1, 4, t);
    assert(getX() == 1);
    std::cout << "X = " << getX() << std::endl;
    assert(getY() == 4);
    std::cout << "Y = " << getY() << std::endl;

    assert(getNombreDeMissiles() == 200);
    std::cout << "Nombre de missiles = " << getNombreDeMissiles() << std::endl;

    for (int i = 0; i < nb_missiles; i++)
    {
        assert(getMissiles()[i].getX() == tab_missiles[i].getX());
        assert(getMissiles()[i].getY() == tab_missiles[i].getY());
        std::cout << "X = " << getMissiles()[i].getX();
        std::cout << " | ";
        std::cout << "Y = " << getMissiles()[i].getY();
        std::cout << " | ";
    }
    std::cout << std::endl;

    assert(getVie() == 5);
    std::cout << "Nombre de vie = " << getVie() << std::endl;

    setVie(1);
    assert(getVie() == 6);
    std::cout << "Nombre de vie = " << getVie() << std::endl;

    gauche(t);
    assert(getX() == 1);
    std::cout << "X = " << getX() << std::endl;
    setXY(3, 4, t);
    gauche(t);
    assert(getX() == 2);
    std::cout << "X = " << getX() << std::endl;

    setXY(35, 4, t);
    droite(t);
    assert(getX() == 35);
    std::cout << "X = " << getX() << std::endl;
    setXY(31, 4, t);
    droite(t);
    assert(getX() == 32);
    std::cout << "X = " << getX() << std::endl;

    TirerMissile(t);
    assert(tab_missiles[0].getMouvement() == true);
    std::cout << "Mouvement = " << getMissiles()[0].getMouvement() << std::endl;
    assert(missiles_tire == 1);
    std::cout << "Missile tiré = " << missiles_tire << std::endl;

    missiles_tire = 199;
    TirerMissile(t);
    assert(tab_missiles[199].getMouvement() == false);
    std::cout << "Mouvement = " << getMissiles()[199].getMouvement() << std::endl;
    assert(missiles_tire == 0);
    std::cout << "Missile tiré = " << missiles_tire << std::endl;
    assert(tab_missiles[0].getMouvement() == false);
    std::cout << "Mouvement = " << getMissiles()[0].getMouvement() << std::endl;

    TirerMultiMissile(t);
    assert(tab_missiles[0].getX() == (x - 4));
    std::cout << "X = " << tab_missiles[0].getX() << " | ";
    assert(tab_missiles[1].getX() == (x - 2));
    std::cout << "X = " << tab_missiles[1].getX() << " | ";
    assert(tab_missiles[2].getX() == (x));
    std::cout << "X = " << tab_missiles[2].getX() << " | ";
    assert(tab_missiles[3].getX() == (x + 2));
    std::cout << "X = " << tab_missiles[3].getX() << " | ";
    assert(tab_missiles[4].getX() == (x + 4));
    std::cout << "X = " << tab_missiles[4].getX() << std::endl;
}