#include "Jeu.h"
#include <iostream>
#include <cassert>
using namespace std;

void Jeu::DesactiverBonus(int indice)
{
    if (tab_bonus[indice].getType() == 1)
    {
        score_multiplicateur = 1;
    }
    if (tab_bonus[indice].getType() == 3)
    {
        tire_multiple = false;
    }
    tab_bonus[indice].DetruireBonus();
}

void Jeu::RemplirTabEnnemies(int x)
{
    Lvl.Lire_Niveau(x%11,"data/NiveauxZinzins.txt",nb_ennemies,tab_ennemie,ter);
}

void Jeu::RemplirTabBonus()
{
    tab_bonus = new Bonus[nb_bonus];
    tire_multiple = false;
    score_multiplicateur = 1;
    for (int i = 0; i < 10; i++)
    {
        DesactiverBonus(i);
    }
    ind_bonus = 0;
}

Jeu::Jeu() : ter(), vaisseau(), tab_ennemie(), Lvl()
{
    nb_ennemies = 15;
    nb_bonus = 10;
    RemplirTabEnnemies(0);
    RemplirTabBonus();
    score = 0;
}

Jeu::~Jeu()
{
    score = 0;
    delete[] tab_ennemie;
    delete[] tab_bonus;
}

const Terrain &Jeu::getConstTerrain() const { return ter; }

const SpaceShip &Jeu::getConstSpaceShip() const { return vaisseau; }

const Ennemie *Jeu::getConstEnnemie() const { return tab_ennemie; }

int Jeu::getNombreDeEnnemie() const { return nb_ennemies; }

int Jeu::getNiveau() const { return Lvl.niveau; }

int Jeu::getScore() const { return score; }

void Jeu::setScore(int x) { score += x; }

const Bonus *Jeu::getConstBonus() const { return tab_bonus; }

int Jeu::getNbBonus() const { return nb_bonus; }

bool Jeu::EnnemisEnVie() const
{
    for (int i = 0; i < nb_ennemies; i++)
    {
        if (tab_ennemie[i].getVie() != 0)
            return false;
    }
    return true;
}

void Jeu::UpdateTabMissile()
{
    //Missiles Ennemies
    int nb_missile = tab_ennemie[0].getNombreDeMissiles();
    for (int i = 0; i < nb_ennemies; i++)
    {
        for (int j = 0; j < nb_missile; j++)
        {
            if (tab_ennemie[i].getMissiles()[j].getMouvement() == false)
                tab_ennemie[i].getMissiles()[j].setXY(tab_ennemie[i].getX(), tab_ennemie[i].getY(), ter);
            else
                tab_ennemie[i].getMissiles()[j].dep(ter);
        }
    }

    //Missiles Vaisseau
    int nb_miss = vaisseau.getNombreDeMissiles();
    for (int i = 0; i < nb_miss; i++)
    {
        if (vaisseau.getMissiles()[i].getMouvement() == false)
            vaisseau.getMissiles()[i].setXY(vaisseau.getX(), vaisseau.getY(), ter);
        else
            vaisseau.getMissiles()[i].dep(ter);
    }
}

void Jeu::UpdateTabBonus()
{
    bool once = false;
    for (int i = 0; i < nb_bonus; i++)
    {
        if (tab_bonus[i].getActif() == true)
        {
            tab_bonus[i].setTime(tab_bonus[i].getTime() + 1);
            switch (tab_bonus[i].getType())
            {
            case 1:
                score_multiplicateur = 10;
                if (tab_bonus[i].getTime() > 100)
                {
                    DesactiverBonus(i);
                }
                break;
            case 2:
                if (vaisseau.getVie() < 24)
                {
                    vaisseau.setVie(1);
                }
                DesactiverBonus(i);
                ind_bonus = i;
                once = true;
                break;
            case 3:
                tire_multiple = true;
                if (tab_bonus[i].getTime() > 100)
                {
                    DesactiverBonus(i);
                }
                break;
            }
        }
        else
        {
            if ((vaisseau.getX() == tab_bonus[i].getX()) && (vaisseau.getY() == tab_bonus[i].getY()))
            {
                tab_bonus[i].setActif(true);
            }
            else
            {
                if (tab_bonus[i].getType() != 0)
                {
                    if (tab_bonus[i].getY() > getConstTerrain().getDimY())
                    {
                        DesactiverBonus(i);
                    }
                    else
                    {
                        tab_bonus[i].dep();
                    }
                }
                else
                {
                    if (once == false)
                    {
                        ind_bonus = i;
                        once = true;
                    }
                }
            }
        }
    }
}

void Jeu::CollisionMissileSpaceShip()
{
    for (int i = 0; i < nb_ennemies; i++)
    {
        for (int j = 0; j < tab_ennemie[i].getNombreDeMissiles(); j++)
        {
            if (tab_ennemie[i].getMissiles()[j].getCollision() == false)
            {
                if ((tab_ennemie[i].getMissiles()[j].getX() == vaisseau.getX()) && (tab_ennemie[i].getMissiles()[j].getY() == vaisseau.getY() - 1))
                {
                    tab_ennemie[i].getMissiles()[j].setCollision(true);
                    vaisseau.setVie(-1);
                    tab_ennemie[i].getMissiles()[j].DestructionMissile();
                }
            }
        }
    }
}

void Jeu::CollisionMissileEnnemie()
{
    for (int i = 0; i < vaisseau.getNombreDeMissiles(); i++)
    {
        for (int j = 0; j < nb_ennemies; j++)
        {
            if ((vaisseau.getMissiles()[i].getX() == tab_ennemie[j].getX()) && (vaisseau.getMissiles()[i].getY() == tab_ennemie[j].getY() + 1))
            {
                vaisseau.getMissiles()[i].setCollision(true);
                vaisseau.getMissiles()[i].DestructionMissile();
                tab_ennemie[j].setVie(-1);
                if (tab_ennemie[j].getVie() == 0)
                {
                    tab_ennemie[j].DestructionEnnemie(tab_bonus[ind_bonus]);
                    score = score + score_multiplicateur;
                }
            }
        }
    }
}

bool Jeu::CollisionEnnemieSpaceShip()
{
    for (int i = nb_ennemies - 1; i >= 0; i--)
    {
        if ((tab_ennemie[i].getX() == vaisseau.getX()) && (tab_ennemie[i].getY() == vaisseau.getY() - 1))
            return true;
    }
    return false;
}

void Jeu::Collisions()
{
    CollisionMissileEnnemie();
    CollisionMissileSpaceShip();
}

void Jeu::actionClavier(const char touche)
{
    switch (touche)
    {
    case 'g':
        vaisseau.gauche(ter);
        break;
    case 'd':
        vaisseau.droite(ter);
        break;
    case 'm':
        if (tire_multiple)
        {
            vaisseau.TirerMultiMissile(ter);
        }
        else
        {
            vaisseau.TirerMissile(ter);
        }
        break;
    }
}

void Jeu::actionsAutomatiques()
{
    for (int i = nb_ennemies; i >= 0; i--)
    {
        tab_ennemie[i].bougeAuto(ter);
    }
}

void Jeu::reset()
{
    delete[] tab_bonus;
    Lvl.resetLevel();
    RemplirTabEnnemies(0);
    RemplirTabBonus();
    vaisseau.setVie(12 - vaisseau.getVie());
    vaisseau.setXY(17, 18, ter);
    vaisseau.RemplirTabMissiles();
    score = 0;
}

void Jeu::TestRegression()
{
    cout << "Test de la classe jeu : " << endl;
    cout << endl;

    cout << "Test du constructeur : " << endl;
    assert(ter.getXY(vaisseau.getX(), vaisseau.getY()));
    assert((nb_ennemies == 15) && (nb_bonus == 10) && (score == 0));
    cout << "nb_ennemies est bien initialisee" << endl;
    cout << "nb_bonus est bien initialisee" << endl;
    cout << "score est bien initialisee" << endl;
    cout << endl;

    cout << "Test de la fonction DesactiverBonus" << endl;
    cout << endl;

    for (int i = 0; i <= 3; i++)
    {
        cout << " Test du cas type de bonus = " << i << endl;
        tab_bonus[0].setType(i);
        tab_bonus[0].setTime(150);
        if (i == 1)
        {
            score_multiplicateur = 10;
        }
        if (i == 3)
        {
            tire_multiple = true;
        }
        DesactiverBonus(0);
        assert((score_multiplicateur == 1) && (tire_multiple == false));
        cout << " score_multiplicateur bien initialisee" << endl;
        cout << " tire_multiple bien initialisee" << endl;
        assert((tab_bonus[i].getType() == 0) && (tab_bonus[i].getTime() == 0) && (tab_bonus[i].getActif() == false));
        cout << " type du bonus bien initialisee" << endl;
        cout << " time du bonus bien initialisee" << endl;
        cout << " actif du bonus bien initialisee" << endl;
        assert((tab_bonus[i].getX() == -1) && (tab_bonus[i].getY() == -1));
        cout << " x du bonus bien initialisee" << endl;
        cout << " y du bonus bien initialisee" << endl;
        cout << endl;
    }

    cout << "Test de la fonction RemplirTabEnnemies" << endl;
    cout << endl;
    for (int i = 0; i < 11; i++)
    {
        cout << " Test du cas x = " << i << " :" << endl;
        RemplirTabEnnemies(i);
        assert(nb_ennemies > 0);
        cout << " Le nombre d'ennemis est valide" << endl;
        for (int j = 0; j < nb_ennemies; j++)
        {
            assert((tab_ennemie[j].getX() != -1) && (tab_ennemie[j].getY() != -1));
            cout << "     L'ennemi " << j << " est bien defini" << endl;
            tab_ennemie[j].DestructionEnnemie(tab_bonus[ind_bonus]);
        }
        cout << endl;
    }

    cout << "Test de la fonction RemplirTabBonus" << endl;
    cout << endl;
    score_multiplicateur = 10;
    tire_multiple = true;
    RemplirTabBonus();
    assert((score_multiplicateur == 1) && (tire_multiple == false));
    cout << "score_multiplicateur bien initialisee" << endl;
    cout << "tire_multiple bien initialisee" << endl;
    assert((ind_bonus == 0) && (tab_bonus != NULL));
    cout << "ind_bonus est bien initialisee" << endl;
    cout << "tab_bonus est non vide" << endl;
    for (int i = 0; i < nb_bonus; i++)
    {
        cout << " Pour l'element " << i << " :" << endl;
        assert((tab_bonus[i].getType() == 0) && (tab_bonus[i].getTime() == 0) && (tab_bonus[i].getActif() == false));
        cout << " type du bonus bien initialisee" << endl;
        cout << " time du bonus bien initialisee" << endl;
        cout << " actif du bonus bien initialisee" << endl;
        assert((tab_bonus[i].getX() == -1) && (tab_bonus[i].getY() == -1));
        cout << " x du bonus bien initialisee" << endl;
        cout << " y du bonus bien initialisee" << endl;
        cout << endl;
    }

    cout << "Test de la fonction getConstTeerrain" << endl;
    assert((getConstTerrain().getDimX() == ter.getDimX()) && (getConstTerrain().getDimY() == ter.getDimY()));
    cout << "Les dimensions sont conformes" << endl;
    for (int i = 0; i < ter.getDimX(); i++)
    {
        for (int j = 0; j < ter.getDimY(); j++)
        {
            assert((getConstTerrain().getXY(i, j) == ter.getXY(i, j)));
            cout << " valeur ok pour les coordonnees (" << i << ";" << j << ")" << endl;
        }
    }
    cout << "Le choix du terrain est donc ok" << endl;
    cout << "L'accesseur est defini et fonctionnel" << endl;
    cout << endl;

    cout << "Test de la fonction getConstSpaceship" << endl;
    assert((getConstSpaceShip().getX() == vaisseau.getX()) && (getConstSpaceShip().getY() == vaisseau.getY()) && (getConstSpaceShip().getVie() == vaisseau.getVie()));
    assert((getConstSpaceShip().getNombreDeMissiles() == vaisseau.getNombreDeMissiles()) && (getConstSpaceShip().getMissiles() == vaisseau.getMissiles()));
    cout << "L'accesseur est defini et fonctionnel" << endl;
    cout << endl;

    cout << "Test de la fonction getConstEnnemie" << endl;
    assert(getConstEnnemie() == tab_ennemie);
    cout << "L'accesseur est defini et fonctionnel" << endl;
    cout << endl;

    cout << "Test de la fonction getConstNiveau" << endl;
    assert(getNiveau() == Lvl.niveau);
    cout << "L'accesseur est defini et fonctionnel" << endl;
    cout << endl;

    cout << "Test de la fonction getScore" << endl;
    assert(getScore() == score);
    cout << "L'accesseur est defini et fonctionnel" << endl;
    cout << endl;

    cout << "Test de la fonction setScore" << endl;
    setScore(100);
    assert(score == 100);
    cout << "Le mutateur est defini et fonctionnel" << endl;
    cout << endl;

    cout << "Test de la fonction getConstBonus" << endl;
    assert(getConstBonus() == tab_bonus);
    cout << "L'accesseur est defini et fonctionnel" << endl;
    cout << endl;

    cout << "Test de la fonction getNbBonus" << endl;
    assert(getNbBonus() == nb_bonus);
    cout << "L'accesseur est defini et fonctionnel" << endl;
    cout << endl;

    cout << "Test de la fonction EnnemieEnVie" << endl;
    cout << " Test de la reponse true" << endl;
    for (int i = 0; i < nb_ennemies; i++)
    {
        tab_ennemie[i].setVie(-tab_ennemie[i].getVie());
    }
    assert(EnnemisEnVie() == true);
    cout << " Test true ok" << endl;
    cout << " Test de la reponse false" << endl;
    tab_ennemie[0].setVie(1);
    assert(EnnemisEnVie() == false);
    cout << " Test false ok" << endl;
    cout << endl;

    cout << "Test de la fonction UpdateTabMissiles" << endl;
    cout << " Test sur l'ensemble des missiles ennemies (sur le nombre max d'ennemis)" << endl;
    RemplirTabEnnemies(10);
    cout << endl;
    int mx, my;
    for (int i = 0; i < nb_ennemies; i++)
    {
        cout << " Test de l'ensemble des missiles de l'ennemi " << i << endl;
        cout << endl;
        for (int j = 0; j < tab_ennemie[i].getNombreDeMissiles(); j++)
        {
            cout << "     Test du missile " << j << endl;
            cout << "     Test quand le missile n'est pas en mouvement" << endl;
            assert(tab_ennemie[i].getMissiles()[j].getMouvement() == false);
            mx = tab_ennemie[i].getMissiles()[j].getX();
            my = tab_ennemie[i].getMissiles()[j].getY();
            UpdateTabMissile();
            assert((tab_ennemie[i].getMissiles()[j].getX() == mx) && (tab_ennemie[i].getMissiles()[j].getY() == my));
            cout << "     Test ok" << endl;
            cout << "     Test quand le missile est en mouvement" << endl;
            tab_ennemie[i].getMissiles()[j].setMouvement(true);
            UpdateTabMissile();
            assert((tab_ennemie[i].getMissiles()[j].getX() == mx) && (tab_ennemie[i].getMissiles()[j].getY() == my + 1));
            cout << "     Test ok" << endl;
            tab_ennemie[i].getMissiles()[j].DestructionMissile();
        }
        cout << endl;
    }
    cout << endl;

    cout << " Test de l'ensemble des missiles du joueur" << endl;
    for (int i = 0; i < vaisseau.getNombreDeMissiles(); i++)
    {
        cout << "     Test du missile " << i << endl;
        cout << "     Test quand le missile n'est pas en mouvement" << endl;
        assert(vaisseau.getMissiles()[i].getMouvement() == false);
        mx = vaisseau.getMissiles()[i].getX();
        my = vaisseau.getMissiles()[i].getY();
        UpdateTabMissile();
        assert((vaisseau.getMissiles()[i].getX() == mx) && (vaisseau.getMissiles()[i].getY() == my));
        cout << "     Test ok" << endl;
        cout << "     Test quand le missile est en mouvement" << endl;
        vaisseau.getMissiles()[i].setMouvement(true);
        UpdateTabMissile();
        assert((vaisseau.getMissiles()[i].getX() == mx) && (vaisseau.getMissiles()[i].getY() == my - 1));
        cout << "     Test ok" << endl;
        vaisseau.getMissiles()[i].DestructionMissile();
    }
    cout << endl;

    cout << "Test de la fonction UpdateTabBonus" << endl;
    int bx, by;
    cout << " Test du fonctionnement des bonus" << endl;
    for (int i = 0; i < nb_bonus; i++)
    {
        cout << " Test du bonus " << i << endl;
        cout << " Test dans le cas du bonus inactif" << endl;
        cout << "     Test sur type de bonus par defaut" << endl;
        DesactiverBonus(i);
        bx = tab_bonus[i].getX();
        by = tab_bonus[i].getY();
        UpdateTabBonus();
        assert((tab_bonus[i].getX() == bx) && (tab_bonus[i].getY() == by));
        assert((tab_bonus[i].getType() == 0) && (tab_bonus[i].getTime() == 0) && (tab_bonus[i].getActif() == false));
        cout << "     Test ok" << endl;
        for (int j = 1; j <= 3; j++)
        {
            cout << "     Test sur type de bonus" << j << endl;
            tab_bonus[i].setType(j);
            UpdateTabBonus();
            assert((tab_bonus[i].getX() == bx) && (tab_bonus[i].getY() == by + 1));
            cout << "     Test deplacement bonus ok" << endl;
            tab_bonus[i].setXY(vaisseau.getX(), vaisseau.getY());
            UpdateTabBonus();
            assert(tab_bonus[i].getActif() == true);
            cout << "     Test activation bonus ok" << endl;
            DesactiverBonus(i);
        }
        cout << " Test dans le cas du bonus actif" << endl;
        int vie = vaisseau.getVie();
        for (int j = 1; j <= 3; j++)
        {
            cout << "     Test sur type de bonus" << j << endl;
            tab_bonus[i].setActif(true);
            tab_bonus[i].setType(j);
            UpdateTabBonus();
            if (j == 1)
            {
                assert(score_multiplicateur == 10);
            }
            if (j == 2)
            {
                assert(vaisseau.getVie() == vie + 1);
            }
            if (j == 3)
            {
                assert(tire_multiple == true);
            }
            cout << "     Test bonus fonctionnel ok" << endl;
            if (j != 2)
            {
                tab_bonus[i].setTime(100);
            }
            UpdateTabBonus();
            assert((tab_bonus[i].getActif() == false) && (tab_bonus[i].getTime() == 0) && (tab_bonus[i].getType() == 0));
            assert((tab_bonus[i].getX() == -1) && (tab_bonus[i].getY() == -1));
            cout << "     Test desactivation bonus ok" << endl;
        }
        cout << endl;
        tab_bonus[i].setType(3);
    }
    cout << " Test de l'affectation de ind_bonus" << endl;
    int pre_ind_bonus = ind_bonus;
    cout << "     Test du cas tous les bonus sont utilises" << endl;
    UpdateTabBonus();
    assert(pre_ind_bonus == ind_bonus);
    cout << "     Test ok" << endl;
    cout << "     Test du cas d'un bonus desactive" << endl;
    for (int i = 0; i < nb_bonus; i++)
    {
        cout << "         Test du cas bonus " << i << " desactive" << endl;
        DesactiverBonus(i);
        UpdateTabBonus();
        assert(ind_bonus == i);
        cout << "         Test ok" << endl;
        tab_bonus[i].setType(3);
    }
    cout << endl;

    cout << "Test de la fonction CollisionMissileSpaceShip" << endl;
    vaisseau.setXY(10, 10, ter);
    int vie;
    for (int i = 0; i < nb_ennemies; i++)
    {
        cout << " Test sur les missiles de l'ennemi " << i << endl;
        for (int j = 0; j < tab_ennemie[i].getNombreDeMissiles(); j++)
        {
            vie = vaisseau.getVie();
            cout << "     Test sur le missile " << j << endl;
            cout << "     Test du cas non-collision" << endl;
            for (int x = 1; x < ter.getDimX() - 1; x++)
            {
                for (int y = 1; y < ter.getDimY() - 2; y++)
                {
                    tab_ennemie[i].getMissiles()[j].setXY(x, y, ter);
                    if ((tab_ennemie[i].getMissiles()[j].getX() != 10) || (tab_ennemie[i].getMissiles()[j].getY() != 9))
                    {
                        CollisionMissileSpaceShip();
                        assert(vie == vaisseau.getVie());
                    }
                }
            }
            cout << "     Test ok" << endl;
            cout << "     Test du cas collision" << endl;
            tab_ennemie[i].getMissiles()[j].setXY(10, 9, ter);
            CollisionMissileSpaceShip();
            assert(vie - 1 == vaisseau.getVie());
            cout << "     Test ok" << endl;
            tab_ennemie[i].getMissiles()[j].DestructionMissile();
        }
        cout << endl;
        tab_ennemie[i].DestructionEnnemie(tab_bonus[ind_bonus]);
    }
    cout << endl;

}
