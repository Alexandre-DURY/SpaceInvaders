#include "Bonus.h"
#include <cassert>
#include <iostream>

Bonus::Bonus()
{
    x = y = -1;
    type = 0; // 3 différents type de bonus
    actif = false;
    time = 0;
}

Bonus::~Bonus()
{
    x = y = -1;
    type = 0;
    actif = false;
    time = 0;
}

int Bonus::getX() const
{
    return x;
}

int Bonus::getY() const { return y; }

void Bonus::setXY(int x1, int y1)
{
    x = x1;
    y = y1;
}

int Bonus::getType() const { return type; }

void Bonus::setType(int t)
{
    assert((type >= 0) && (type <= 3)); // vérification qu'on envoie un type qui existe
    type = t;
}

bool Bonus::getActif() const { return actif; }

void Bonus::setActif(bool a) { actif = a; }

int Bonus::getTime() const { return time; }

void Bonus::setTime(int t)
{
    assert(t >= 0);
    time = t;
}

void Bonus::dep()
{
    y++;
}

void Bonus::DetruireBonus()
{
    x = y = -1;
    type = 0;
    actif = false;
    time = 0;
}

void Bonus::TestRegression()
{
    assert(getX() == -1);
    std::cout << "X = " << getX() << std::endl;

    assert(getY() == -1);
    std::cout << "Y = " << getY() << std::endl;

    setXY(1, 2);
    assert(getX() == 1);
    std::cout << "X = " << getX() << std::endl;
    assert(getY() == 2);
    std::cout << "Y = " << getY() << std::endl;

    assert(getType() == 0);
    std::cout << "Type = " << getType() << std::endl;

    setType(1);
    assert(getType() == 1);
    std::cout << "Type = " << getType() << std::endl;

    assert(getActif() == false);
    std::cout << "Actif = " << getActif() << std::endl;

    setActif(true);
    assert(getActif() == true);
    std::cout << "Actif = " << getActif() << std::endl;

    assert(getTime() == 0);
    std::cout << "Time = " << getTime() << std::endl;

    setTime(20);
    assert(getTime() == 20);
    std::cout << "Time = " << getTime() << std::endl;

    dep();
    assert(getY() == 3);
    std::cout << "Y = " << getY() << std::endl;

    DetruireBonus();
    assert(getX() == -1);
    std::cout << "X = " << getX() << std::endl;
    assert(getY() == -1);
    std::cout << "Y = " << getY() << std::endl;
    assert(getType() == 0);
    std::cout << "Type = " << getType() << std::endl;
    assert(getActif() == false);
    std::cout << "Actif = " << getActif() << std::endl;
    assert(getTime() == 0);
    std::cout << "Time = " << getTime() << std::endl;
}
