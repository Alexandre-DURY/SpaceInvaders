/**
@brief Module gérant les missiles
@file Missile.h
@date 2020/03/19
*/

#ifndef _MISSILE_H
#define _MISSILE_H

#include "Terrain.h"

/**
@brief Un missile se définit par sa positoion 2D, sa provenance, s'il est en mouvement ainsi que s'il est en collision.
*/

class Missile
{

private:
	int x, y;
	bool est_ennemi, en_mouvement, en_collision;

public:
	/** @brief Constructeur de la classe missile
	*/
	Missile();

	/** @brief Destructeur de la classe missile
	*/
	~Missile();

	/** @brief Recupère la position en abscisse du missile
	*/
	int getX() const;

	/** @brief Recupère la position en ordonnée du missile
	*/
	int getY() const;

	/** @brief Permet la modification de la position des missiles
	*/
	void setXY(int x, int y, const Terrain &t);

	/** @brief Récupère la valeur de Ennemie
	*/
	bool getEnnemie() const;

	/** @brief Modifie la valeur de Ennemie
	*/
	void setEnnemie(bool ennemie);

	/** @brief Récupère la valeur de Mouvement
	*/
	bool getMouvement() const;

	/** @brief Modifie la valeur de Mouvement
	*/
	void setMouvement(bool mouvement);

	/** @brief Permet de savoir si un missile est en collision.
	*/
	bool getCollision() const;

	/** @brief Permet de modifier le statut de collision du missile pour le mettre à true
	*/
	void setCollision(bool collision);

	/** @brief 
	*/
	void dep(const Terrain &t);

	/** @brief Permet de savoir si oui ou non un missile touche
	*/
	bool heurteMissile(Missile m);

	/** @brief Procédure de destruction d'un missile après une collision avec quoi que ce soit du terrain.
	*/
	void DestructionMissile();

	/** @brief Test toutes les fonctions
    */
	void TestRegression(Terrain t, Missile m);
};

#endif
