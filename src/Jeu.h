/**
@brief Module Jeu de SpaceInvader

@file Jeu.h
@date 2020/03/13
*/

#ifndef _JEU_H
#define _JEU_H

#include "SpaceShip.h"
#include "Terrain.h"
#include "Ennemie.h"
#include "Niveau.h"

/** @brief Un jeu SpaceInvader = un terrain et un vaisseau ainsi que des ennemies
*/
class Jeu
{

private:
    Terrain ter;
    SpaceShip vaisseau;
    Ennemie *tab_ennemie;
    Niveau Lvl;
    int nb_ennemies;
    int score;
    Bonus *tab_bonus;
    int nb_bonus, ind_bonus;
    bool tire_multiple;
    int score_multiplicateur;

public:
    /** @brief Constructeur de la classe jeu
    */
    Jeu(); // constructeur

    /** @brief Destructeur de la classe jeu
    */
    ~Jeu();

    /** @brief Permet de récupérer le terrain
        @param
    */
    const Terrain &getConstTerrain() const;

    /** @brief Permet de récupérer le vaisseau allié
        @param
    */
    const SpaceShip &getConstSpaceShip() const;

    /** @brief Permet de récupérer les vaisseaux ennemis
        @param
    */
    const Ennemie *getConstEnnemie() const;

    /** @brief Permet de récupérer les niveaux
        @param
    */
    const Niveau getConstNiveau() const;

    /** @brief Permet de récupérer le score
    */
    int getScore() const;

    void setScore(int x);

    const Bonus *getConstBonus() const;

    int getNbBonus() const;

    void DesactiverBonus(int indice);

    /** @brief Procédure permettant de mettre en place les ennemis dans le tableau.
        @param x : Correspond au numéro de niveau
    */
    void RemplirTabEnnemies(int x);

    void RemplirTabBonus();

    /** @brief Permet de récupérer le nombre d'ennemis
    */
    int getNombreDeEnnemie() const;

    /** @brief Permet de récupérer les niveaux du jeu
    */
    int getNiveau() const;

    /** @brief Permet de savoir si les ennemis sont en vie ou non
    */
    bool EnnemisEnVie() const;

    /** @brief
    */
    void UpdateTabMissile();

    /** @brief Procédure permettant de savoir si il y a une collision entre un missile et le vaisseau allié
    */

    void UpdateTabBonus();

    void CollisionMissileSpaceShip();

    /** @brief  Procédure permettant de savoir si il y a une collision entre un missile allié et le(s) vaisseau(x) ennemi(s)
    */
    void CollisionMissileEnnemie();

    /** @brief Procédure permettant de savoir si il y a une collision entre un missile et le terrain
    */
    void CollisionMissileTerrain();

    /** @brief Permet de savoir si il y a une collision entre un ennemi et le vaisseau allié ou non
    */
    bool CollisionEnnemieSpaceShip();

    /** @brief Regroupe toutes les fonctions de collisions en une seule procédure
    */
    void Collisions();

    /** @brief Procédure de déplacement automatique des ennemis
    */
    void actionsAutomatiques();

    /** @brief Procédure exécutant une action selon la touche pressée sur le clavier
        @param touche : Correspond à la touche pressée sur le clavier
    */
    void actionClavier(const char touche); // rend vrai si mange une pastille, faux sinon

    /** @brief Procédure de réinitialisation de la partie
        @param vie_spaceship : Nombre de vies du vaisseau allié remis au nombre de vies de départ.
    */
    void reset();

    void TestRegression();
};

#endif
