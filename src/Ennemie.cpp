#include "Ennemie.h"
#include <iostream>
#include <stdlib.h>
#include <cassert>
#include <unistd.h>
#include <time.h>

Ennemie::Ennemie()
{ //initialisation
    x = y = 7;
    dir = 1;
    nb_missiles = 50;
    NbVie = 1;
    missiles_tire = 0;
}

Ennemie::~Ennemie()
{ // supprime ce qui est défini sur la Tas + Réinitialisation des paramètres
    x = y = 0;
    dir = 1;
    nb_missiles = 0;
    NbVie = 0;
    missiles_tire = 0;
    delete[] tab_missiles;
}

int Ennemie::getX() const
{
    return x;
}

int Ennemie::getY() const { return y; }

void Ennemie::setXY(int x1, int y1, const Terrain &t)
{
    assert(t.estPositionPersoValide(x1, y1)); // vérifie si la futur position est valide
    x = x1;
    y = y1;
}

int Ennemie::getNombreDeMissiles() const { return nb_missiles; }

Missile *Ennemie::getMissiles() const { return tab_missiles; } //Necessite un tabeau de missiles déclaré préalablement.

int Ennemie::getVie() const { return NbVie; }

void Ennemie::setVie(int x) { NbVie += x; }

void Ennemie::gauche(const Terrain &t)
{
    if (t.estPositionPersoValide(x - 1, y))
        x--;
}

void Ennemie::droite(const Terrain &t)
{
    if (t.estPositionPersoValide(x + 1, y))
        x++;
}

void Ennemie::haut(const Terrain &t)
{
    if (t.estPositionPersoValide(x, y - 1))
        y--;
}

void Ennemie::bas(const Terrain &t)
{
    if (t.estPositionPersoValide(x, y + 1))
        y++;
}

void Ennemie::RemplirTabMissiles(int x1, int y1)
{
    Terrain t;
    tab_missiles = new Missile[nb_missiles];
    for (int i = 0; i < nb_missiles; i++)
    {
        tab_missiles[i].setXY(x1, y1, t);
        tab_missiles[i].setEnnemie(true);
    }
}

void Ennemie::TirerMissile(const Terrain &t)
{
    tab_missiles[missiles_tire].setMouvement(true);
    missiles_tire++;
    if (missiles_tire == nb_missiles)
    { // remplit le tableau de missiles si il y en plus
        delete[] tab_missiles;
        missiles_tire = 0;
        RemplirTabMissiles(x, y);
    }
}

void Ennemie::DestructionEnnemie(Bonus &b)
{
    int m = rand() % 7; // chance d'avoir un bonus = 1/7
    if (m == 1)         // si vous êtes chanceux
    {
        m = rand() % 3; // pour la chance du type de bonus
        if (b.getType() == 0)
        {
            b.setType(m + 1);
            b.setXY(x, y);
            b.setActif(false);
        }
    }
    //remet les paramètres à l'initial
    x = y = -1;
    dir = 1;
    NbVie = 0;
    missiles_tire = 0;
}

void Ennemie::bougeAuto(const Terrain &t)
{ // permet de faire bouger les ennemies, sans qu'il sorte de la zone prédéfini
    int m = rand() % 50;
    if ((dir == 1) && (t.estPositionPersoValide(x + 1, y))) // si l'ennemie peut bouger à droite
    {
        droite(t);
        if (m == 1)
        {
            TirerMissile(t);
        }
    }
    else
    {
        if ((dir == -1) && (t.estPositionPersoValide(x - 1, y))) // si l'ennemie peut bouger à gauche
        {
            gauche(t);
            if (m == 1)
            {
                TirerMissile(t);
            }
        }
        else
        {
            if (t.estPositionPersoValide(x, y + 1)) // si l'ennemie peut bouger en bas
            {
                bas(t);
                dir = dir * -1;
                if (m == 1)
                {
                    TirerMissile(t);
                }
            }
            else
            {
                dir = 0;
            }
        }
    }
}

void Ennemie::TestRegression(Terrain t, Bonus b)
{
    assert(getX() == 7);
    std::cout << "X = " << getX() << std::endl;

    assert(getY() == 7);
    std::cout << "Y = " << getY() << std::endl;

    setXY(1, 1, t);
    assert(getX() == 1);
    std::cout << "X = " << getX() << std::endl;
    assert(getY() == 1);
    std::cout << "Y = " << getY() << std::endl;

    assert(getNombreDeMissiles() == 50);
    std::cout << "Nombre de missiles = " << getNombreDeMissiles() << std::endl;

    RemplirTabMissiles(2, 4);
    for (int i = 0; i < nb_missiles; i++)
    {
        assert(tab_missiles[i].getX() == 2);
        assert(tab_missiles[i].getY() == 4);
        std::cout << "X = " << getMissiles()[i].getX();
        std::cout << " | ";
        std::cout << "Y = " << getMissiles()[i].getY();
        std::cout << " | ";
        assert(tab_missiles[i].getEnnemie() == true);
        std::cout << "Ennemie = " << tab_missiles[i].getEnnemie();
        std::cout << " || ";
    }
    std::cout << std::endl;

    for (int i = 0; i < nb_missiles; i++)
    {
        assert(getMissiles()[i].getX() == tab_missiles[i].getX());
        assert(getMissiles()[i].getY() == tab_missiles[i].getY());
        std::cout << "X = " << getMissiles()[i].getX();
        std::cout << " | ";
        std::cout << "Y = " << getMissiles()[i].getY();
        std::cout << " || ";
    }
    std::cout << std::endl;

    assert(getVie() == 1);
    std::cout << "Nombre de vie = " << getVie() << std::endl;

    setVie(1);
    assert(getVie() == 2);
    std::cout << "Nombre de vie = " << getVie() << std::endl;

    gauche(t);
    assert(getX() == 1);
    std::cout << "Gauche X = " << getX() << std::endl;

    haut(t);
    assert(getY() == 1);
    std::cout << "Haut Y = " << getY() << std::endl;

    setXY(3, 4, t);
    gauche(t);
    assert(getX() == 2);
    std::cout << "Gauche X = " << getX() << std::endl;

    haut(t);
    assert(getY() == 3);
    std::cout << "Haut Y = " << getY() << std::endl;

    setXY(35, 18, t);
    droite(t);
    assert(getX() == 35);
    std::cout << "Droite X = " << getX() << std::endl;

    bas(t);
    assert(getY() == 18);
    std::cout << "Bas Y = " << getY() << std::endl;

    setXY(31, 12, t);
    droite(t);
    assert(getX() == 32);
    std::cout << "Droite X = " << getX() << std::endl;

    bas(t);
    assert(getY() == 13);
    std::cout << "Bas Y = " << getY() << std::endl;

    TirerMissile(t);
    assert(tab_missiles[0].getMouvement() == true);
    std::cout << "Mouvement = " << getMissiles()[0].getMouvement() << std::endl;
    assert(missiles_tire == 1);
    std::cout << "Missile tiré = " << missiles_tire << std::endl;

    missiles_tire = 49;
    TirerMissile(t);
    assert(tab_missiles[49].getMouvement() == false);
    std::cout << "Mouvement = " << getMissiles()[49].getMouvement() << std::endl;
    assert(missiles_tire == 0);
    std::cout << "Missile tiré = " << missiles_tire << std::endl;
    assert(tab_missiles[0].getMouvement() == false);
    std::cout << "Mouvement = " << getMissiles()[0].getMouvement() << std::endl;

    DestructionEnnemie(b);
    assert(getX() == -1);
    std::cout << "X = " << getX() << std::endl;
    assert(getY() == -1);
    std::cout << "Y = " << getY() << std::endl;
    assert(dir == 1);
    std::cout << "Dir = " << dir << std::endl;
    assert(getNombreDeMissiles() == 50);
    std::cout << "Nombre de missiles = " << getNombreDeMissiles() << std::endl;
    assert(getVie() == 0);
    std::cout << "Vie = " << getVie() << std::endl;
    assert(missiles_tire == 0);
    std::cout << "Missiles tirés = " << missiles_tire << std::endl;
}