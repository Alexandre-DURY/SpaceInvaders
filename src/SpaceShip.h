/**
@brief Module gérant un SpaceShip

@file SpaceShip.h
@date 2020/03/13
*/

#ifndef _SPACESHIP_H
#define _SPACESHIP_H

#include "Terrain.h"
#include "Missile.h"

/**
@brief La classe SpaceShip contient le nombre de vie que le vaisseau a, ses déplacements,
la collision avec un missile ennemi, les tirs qu'il envoie..
*/
class SpaceShip
{

private:
    int x, y;              // coordonnées
    int NbLife;            // nombre de vie
    int nb_missiles;       // nombre de missiles
    int missiles_tire;     // nombre de missiles tirés
    Missile *tab_missiles; // Tableau de missiles
    bool en_collision;     // Booléen de collision (true si collision sinon faux)

public:
    /** @brief
        @param
    */
    void RemplirTabMissiles();

    /** @brief Constructeur par défaut de la classe: initialise x et y à 0, le nombre de vie à 3,
               l'image du vaisseau et met à NULL tab_missiles
        @param
    */
    SpaceShip();

    /** @brief Destructeur de la classe: mise à jour de la position au point de départ,
               nombre de vie = 0, vitesse remise à 0 et déalloue tab_missiles cde la mémoire
        @param
     */
    ~SpaceShip();

    /** @brief accesseur pour cordonnée x
     */
    int getX() const;

    /** @brief accesseur pour cordonnée y
     */
    int getY() const;

    void setXY(int x, int y, Terrain t);

    /** @brief Renvoies le nombre de missiles
     */
    int getNombreDeMissiles() const;

    /** @brief Recupére le tableau de missiles
     */
    Missile *getMissiles() const;

    /** @brief Renvoies le nombre de vie
     */
    int getVie() const;

    /** @brief Modifie le nombre de vie
        @param x : Nombre de vies ajoutées ou enlevées
     */
    void setVie(int x);

    /** @brief  Change la position du vaisseau vers la droite
        @param t : terrain
     */
    void droite(const Terrain &t);

    /** @brief  Change la position du vaisseau vers la gauche
        @param  t : terrain
     */
    void gauche(const Terrain &t);

    /** @brief  Le vaisseau se prend un missile
     */
    bool CollisionMissile();

    /** @brief  Le vaisseau tire un missile
        @param
     */
    void TirerMissile(const Terrain &t);

    void TirerMultiMissile(const Terrain &t);
    //void haut (const Terrain & t);
    //void bas (const Terrain & t);

    /** @brief Test toutes les fonctions
    */
    void TestRegression(Terrain t);
};

#endif // _SPACESHIP_H
