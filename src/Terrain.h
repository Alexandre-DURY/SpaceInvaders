/**
@brief Module gérant un terrain dans l'application Spaceinvader

Un terrain dans l'application Spaceinvader est un tableau 2D de caractères dont la taille est dimx x dimy.
Un terrain ne peut pas dépasser 100x100 cases (ATTENTION : il n'y pas de vérification de ceci).

@file Terrain.h
@date 2020/03/13
*/

#ifndef _TERRAIN_H
#define _TERRAIN_H

/**
@brief La classe Terrain contient ses dimensions et un tab 2D de cases (une case=1 char)
*/
class Terrain
{

private:
    int dimx;
    int dimy;
    char ter[100][100];

public:
    /**
    @brief Construit un objet Terrain.
    Le constructeur remplit dimx et dimy et les cases du tableau ter avec un terrain par défaut.
    @param
    */
    Terrain();

    /**
    @brief Destructeur de la classe: Détruit le terrain
    @param
    */
    ~Terrain();

    /**
    @brief Renvoie vrai si on peut positionnner un personnage aux coordonnées (x,y), faux sinon
    @param x : abs de la case à tester
    @param y : ordonnée de la case à tester
    */
    bool estPositionPersoValide(const int x, const int y) const;

    /**
    @brief Renvoie le type d'objet se trouvant en (x,y)
    @param x : abscisse de la case de l'objet
    @param y : ordonnée de la case de l'objet
    */
    char getXY(const int x, const int y) const;

    /**
    @brief Permet de modifier les valeurs x et y
    @param x : abs de la case de l'objet
    @param y : ordonnée de la case de l'objet
    @param c : Permet de savoir si la case est libre pour un déplacement
     */
    void setXY(int x, int y, char c);

    /**
    @brief Renvoie la largeur du terrain
    @param
    */
    int getDimX() const;

    /**
    @brief : Renvoie la hauteur du terrain
    @param
    */
    int getDimY() const;

    /**
    @brief Permet la modification de la taille du terrain
    @param x : Taille en abscisse
    @param y : Taille en ordonnée
    */
    void setDim(int x, int y);

    /** @brief Test toutes les fonctions
    */
    void TestRegression();
};

#endif
