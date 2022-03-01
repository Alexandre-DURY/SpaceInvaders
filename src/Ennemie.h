/**
@brief Module gérant un vaisseau ennemi
@file Ennemie.h
@date 2020/04/02
*/

#ifndef _ENNEMIE_H
#define _ENNEMIE_H

#include "Terrain.h"
#include "Missile.h"
#include "Bonus.h"

/**
@brief Un Ennemi = sa position 2D
*/
class Ennemie
{

private:
    int x, y; //coor
    int dir;
    int NbVie;
    int nb_missiles;
    int missiles_tire;
    Missile *tab_missiles;
    bool en_collision;
    //Bonus bonus;

public:
    /** @brief
        @param x1 : Abscisse de départ des ennemis
        @param y1 : Ordonnée de départ des ennemis
    */
    void RemplirTabMissiles(int x1, int y1);

    /** @brief Constructeur par défaut de la classe : initialise x et y à 7, dir à 1,
               le nombre de missiles à 50 et le nombre de missiles tirés à 0.
    */
    Ennemie(); //constructeur

    /** @brief Destructeur de la classe : détruit les ennemis.
    */
    ~Ennemie(); //destructeur

    /** @brief Déplacement d'un vaisseau ennemi vers la gauche.
        @param t : terrain
    */
    void gauche(const Terrain &t);

    /** @brief Déplacement d'un vaisseau ennemi vers la droite.
        @param t : terrain
    */
    void droite(const Terrain &t);

    /** @brief Déplacement d'un vaisseau ennemi vers le haut.
        @param t : terrain
    */
    void haut(const Terrain &t);

    /** @brief Déplacement d'un vaisseau ennemi vers le bas
        @param t : terrain
    */
    void bas(const Terrain &t);

    /** @brief Accesseur pour la coordonnée x
    */
    int getX() const;

    /** @brief Accesseur pour la coordonnée y
    */
    int getY() const;

    /** @brief Permet de modifier les valeurs x et y
        @param x : abs de la case de l'objet
        @param y : ordonnée de la case de l'objet
    */
    void setXY(int x, int y, const Terrain &t);

    /** @brief Renvoies le nombre de vies
     */
    int getVie() const;

    /** @brief Modifie le nombre de vies
        @param x : nombre de vies
     */
    void setVie(int x);

    /** @brief Renvoies le nombre de missiles
     */
    int getNombreDeMissiles() const;

    /** @brief Recupére le tableau de missiles
     */
    Missile *getMissiles() const;

    /*Bonus getBonus() const;

    void setBonus(int x, int y, bool a);*/

    /** @brief Mouvement automatique des ennemis (vaisseau et missiles, en quelque sorte l'IA)
        @param t : terrain
    */
    void bougeAuto(const Terrain &t);

    /** @brief Le vaisseau ennemi tire un missile
        @param t : terrain
    */
    void TirerMissile(const Terrain &t);

    /** @brief Procédure de destruction de l'ennemi lorsqu'il meurt
    */
    void DestructionEnnemie(Bonus &b);

    /** @brief Test toutes les fonctions
    */
    void TestRegression(Terrain t, Bonus b);
};

#endif
