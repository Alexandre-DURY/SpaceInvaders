/**
@brief Module gérant les bonus en jeu
@file Bonus.h
@date 2020/04/14
*/
#ifndef _BONUS_H
#define _BONUS_H

/** @brief La classe Bonus gère les bonus en jeu, ces derniers ont un temps d'apparition
           ainsi que les différents types de bonus pouvant apparaitre
*/
class Bonus
{

private:
    int x, y;
    int type, time;
    bool actif;

public:
    /** @brief Constructeur de la classe Bonus
    */
    Bonus();
    /** @brief Destructeur de la classe bonus
    */
    ~Bonus();
    /** @brief Récupère la coordonnée en abscisse du bonus
    */
    int getX() const;
    /** @brief Récupère la coordonnée en ordonnée du bonus
    */
    int getY() const;
    /** @brief Permet la modification des coordonnées des bonus.
        @param x : abscisse du bonus
        @param y : ordonnée du bonus
    */
    void setXY(int x, int y);
    /** @brief Récupère le type de bonus.
    */
    int getType() const;
    /** @brief Permet la modification du type de bonus
        @param t : temps d'activité du bonus
    */
    void setType(int t);
    /** @brief Permet de savoir si oui ou non le bonus est actif.
    */
    bool getActif() const;
    /** @brief Permet la modification du statut du bonus, de le rendre actif
        @param a : booléen pour savoir si le bonus est actif ou non
    */
    void setActif(bool a);
    /** @brief Récupère le temps d'activité du bonus
    */
    int getTime() const;
    /** @brief Permet la modification du temps d'activité du bonus
        @param t : temps d'activité du bonus
    */
    void setTime(int t);
    /** @brief ????
        @param
    */
    void dep();
    //    void BonusVie(SpaceShip vaisseau); //Ajoute une vie
    //    void BonusScore(Jeu jeu); //Augmente le score
    //    void BonusMissile(SpaceShip vaisseau,const Terrain & t); //Double Missile

    /** @brief Procédure de destruction du bonus
    */
    void DetruireBonus();

    /** @brief Test toutes les fonctions
    */
    void TestRegression();
};

#endif
