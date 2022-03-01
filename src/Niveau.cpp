#include "Niveau.h"
#include <stdlib.h>
#include <time.h>
#include <fstream>

Niveau::Niveau()
{
	niveau = -1;
}

Niveau::~Niveau()
{
	niveau = -1;
}

void Niveau::resetLevel()
{
	niveau = -1;
}

void Niveau::Lire_Niveau(int lvl, std::string fichier, int& nb_ennemies, Ennemie *&tab_ennemie, Terrain ter)
{
	niveau++;
	delete[] tab_ennemie;
	std::ifstream file(fichier);
	std::string line;
	int ind_ennemi = 0;
	int l = 0;
	for (l = 0; l < 1+23*lvl; l++)
	{
		getline(file, line);
	}
    file>>nb_ennemies;
	tab_ennemie = new Ennemie[nb_ennemies];
    getline(file,line);
    getline(file,line);
	for (int i = 0; i < 21; i++)
	{
		int taille = line.size();
		for (int j = 0; j <taille; j++)
		{
			if ((line[j] == 'x')&&(ind_ennemi<nb_ennemies))
			{
				tab_ennemie[ind_ennemi].setXY(j - 2, i, ter);
                tab_ennemie[ind_ennemi].RemplirTabMissiles(tab_ennemie[i].getX(), tab_ennemie[i].getY());
				ind_ennemi++;

			}
		}
		getline(file, line);

	}

	file.close();
}


