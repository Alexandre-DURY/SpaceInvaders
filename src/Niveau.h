#ifndef _NIVEAU_H
#define _NIVEAU_H

#include "Ennemie.h"
#include "Terrain.h"
#include <string>
#include <iostream>

/** @brief La classe niveau détermine le level-design des niveaux.
           Chaque niveau comprend un nombre d'ennemis différents et un positionnement
           dans le terrain qui est également différent.
*/
class Niveau
{

public:
    /** @brief Initialisation de la variable niveau
     */
    int niveau;

    /** @brief Constructeur de la classe Niveau
     */
    Niveau();

    /** @brief Destructeur de la classe niveau
     */
    ~Niveau();

    void resetLevel();

    void Lire_Niveau(int lvl ,std::string fichier, int& nb_ennemies, Ennemie *&tab_ennemie, Terrain ter);


};

#endif
