#include "Missile.h"
#include <iostream>
#include <stdlib.h>
#include <cstddef>
#include <cassert>
#include <unistd.h>

Missile::Missile() //initialisation
{
    x = y = 1;
    est_ennemi = en_mouvement = en_collision = false;
}

Missile::~Missile() // enlève ce qui est créé sur le Tas + remise des paramètres à l'inital
{
    x = y = 0;
    est_ennemi = en_mouvement = en_collision = false;
}

int Missile::getX() const
{
    return x;
}

int Missile::getY() const { return y; }

void Missile::setXY(int x1, int y1, const Terrain &t)
{
    //assert(t.estPositionPersoValide(x1,y1));
    x = x1;
    y = y1;
}

bool Missile::getEnnemie() const { return est_ennemi; }

void Missile::setEnnemie(bool ennemie) { est_ennemi = ennemie; }

bool Missile::getMouvement() const { return en_mouvement; }

void Missile::setMouvement(bool mouvement) { en_mouvement = mouvement; }

bool Missile::getCollision() const { return en_collision; }

void Missile::setCollision(bool collision) { en_collision = collision; }

void Missile::dep(const Terrain &t)
{
    if (est_ennemi)
    {
        y++;
    }
    else
    {
        y--;
    }
    //usleep(int((1/y)*1000000));
}

bool Missile::heurteMissile(Missile m)
{
    assert(((est_ennemi) && (!m.est_ennemi)) || ((m.est_ennemi) && (!est_ennemi))); // les missiles alliés n'ont pas de collision entre eux
    return (((est_ennemi) && (y + 1 == m.y - 1)) || ((!est_ennemi) && (y - 1 == m.y + 1)));
}
void Missile::DestructionMissile()
{
    x = y = 0;
    est_ennemi = en_mouvement = en_collision = false;
}

void Missile::TestRegression(Terrain t, Missile m)
{
    assert(getX() == 1);
    std::cout << "X = " << getX() << std::endl;

    assert(getY() == 1);
    std::cout << "Y = " << getY() << std::endl;

    setXY(2, 4, t);
    assert(getX() == 2);
    std::cout << "X = " << getX() << std::endl;
    assert(getY() == 4);
    std::cout << "Y = " << getY() << std::endl;

    assert(getEnnemie() == false);
    std::cout << "Est_ennemi = " << getEnnemie() << std::endl;

    setEnnemie(true);
    assert(getEnnemie() == true);
    std::cout << "Est_ennemi = " << getEnnemie() << std::endl;

    assert(getMouvement() == false);
    std::cout << "En_mouvement = " << getMouvement() << std::endl;

    setMouvement(true);
    assert(getMouvement() == true);
    std::cout << "En_mouvement = " << getMouvement() << std::endl;

    assert(getCollision() == false);
    std::cout << "En_collision = " << getCollision() << std::endl;

    setCollision(true);
    assert(getCollision() == true);
    std::cout << "En_collision = " << getCollision() << std::endl;

    dep(t);
    assert(getY() == 5);
    std::cout << "Déplacement Y = " << getY() << std::endl;

    setEnnemie(false);
    dep(t);
    assert(getY() == 4);
    std::cout << "Déplacement Y = " << getY() << std::endl;

    setEnnemie(true);
    assert(heurteMissile(m) == false);
    std::cout << "Heurte_missile = " << heurteMissile(m) << std::endl;

    m.setXY(1, 6, t);
    assert(heurteMissile(m) == true);
    std::cout << "Heurte_missile = " << heurteMissile(m) << std::endl;

    setEnnemie(false);
    m.setEnnemie(true);
    assert(heurteMissile(m) == false);
    std::cout << "Heurte_missile = " << heurteMissile(m) << std::endl;

    m.setXY(1, 2, t);
    assert(heurteMissile(m) == true);
    std::cout << "Heurte_missile = " << heurteMissile(m) << std::endl;

    DestructionMissile();
    assert(getX() == 0);
    std::cout << "X = " << getX() << std::endl;
    assert(getY() == 0);
    std::cout << "Y = " << getY() << std::endl;
    assert(getEnnemie() == false);
    std::cout << "Est_ennemi = " << getEnnemie() << std::endl;
    assert(getMouvement() == false);
    std::cout << "En_mouvement = " << getMouvement() << std::endl;
    assert(getCollision() == false);
    std::cout << "En_collision = " << getCollision() << std::endl;
}
