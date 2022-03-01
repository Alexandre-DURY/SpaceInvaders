#include <cassert>
#include <time.h>
#include <stdlib.h>
#include <iostream>
#include <cmath>
#include "SDL_Basique.h"

using namespace std;
const int SPRITE = 40;   //Il d�finit l'�chelonnage du terrain du jeu dans la fen�tre SDL
const int MAX_CHAR = 16; //Constante d�finissant le nombre maximum des caract�res d�s qu'on affiche les nombres

//Fonction permettant la conversion des donn�es de type entiers en char * n�cessaire pour l'affichage de texte en SDL

char *tab_char(int a, char *t)
{
    int i = 0;
    int m;
    if (a == 0)
    {
        t[0] = '0';
        t[1] = '\0';
        return t;
    }
    while (a >= 1)
    {
        m = a % 10;
        t[i] = '0' + m;
        a = a / 10;
        i++;
    }
    t[i] = '\0';
    char c_tmp;
    for (int j = 0; j < i / 2; j++)
    {
        c_tmp = t[j];
        t[j] = t[i - 1 - j];
        t[i - 1 - j] = c_tmp;
    }
    return t;
}

//Fonction qui verifie si un type de bonus est actif dans un tableau de bonus

bool bonusActif(int type, const Bonus *b, int nb_bonus)
{
    for (int i = 0; i < nb_bonus; i++)
    {
        if ((b[i].getType() == type) && (b[i].getActif()))
        {
            return true;
        }
    }
    return false;
}

SDL_Basique::SDL_Basique()
{
    // Initialisation des biblioth�ques SDL, SDL_ttf et puis SDL_image

    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        cout << "Erreur lors de l'initialisation de la SDL : " << SDL_GetError() << endl;
        SDL_Quit();
        exit(1);
    }

    if (TTF_Init() != 0)
    {
        cout << "Erreur lors de l'initialisation de la SDL_ttf : " << TTF_GetError() << endl;
        SDL_Quit();
        exit(1);
    }

    int imgFlags = IMG_INIT_PNG | IMG_INIT_JPG;
    if (!(IMG_Init(imgFlags) & imgFlags))
    {
        cout << "SDL_image could not initialize! SDL_image Error: " << IMG_GetError() << endl;
        SDL_Quit();
        exit(1);
    }
    //    if( Mix_OpenAudio( 44100, MIX_DEFAULT_FORMAT, 2, 2048 ) < 0 )
    //    {
    //        cout << "SDL_mixer could not initialize! SDL_mixer Error: " << Mix_GetError() << endl;
    //        cout << "No sound !!!" << endl;
    //        SDL_Quit();exit(1);
    //        withSound = false;
    //    }
    //    else withSound = true;

    //Cr�ation de la fen�tre SDL

    dimx = jeu.getConstTerrain().getDimX() * SPRITE;
    dimy = jeu.getConstTerrain().getDimY() * SPRITE;
    window = SDL_CreateWindow("Space Invader", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, dimx + 400, dimy, SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);
    if (window == NULL)
    {
        cout << "Erreur lors de la creation de la fenetre : " << SDL_GetError() << endl;
        SDL_Quit();
        exit(1);
    }
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    //Initialisation du font qui sera utilis� pour la saisie de texte en SDL

    font = TTF_OpenFont("data/DejaVuSansCondensed.ttf", 50);
    if (font == NULL)
    {
        cout << "Failed to load DejaVuSansCondensed.ttf! SDL_TTF Error: " << TTF_GetError() << endl;
        SDL_Quit();
        exit(1);
    }

    //Definition des couleurs utilis�s pour les textes SDL

    font_color1.r = 255;
    font_color1.g = 255;
    font_color1.b = 255;
    font_color2.r = 0;
    font_color2.g = 0;
    font_color2.b = 0;

    //Alloue sur le tas la variable c de type char * afin de permettre la conversion des entiers
    c = new char[MAX_CHAR];

    //Initialisation des images qui seront utlis�s pour la SDL

    //Images structurant l'arri�re plan de la fen�tre SDL
    background.loadFromFile("data/Fond.jpg", renderer);
    interface.loadFromFile("data/Bordure_Menu.jpg", renderer);
    border.loadFromFile("data/Bordure_Vie.jpg", renderer);

    //Ensembles des mod�les bitmap repr�sentant les �lements du jeu
    im_spaceship.loadFromFile("data/SpaceShip.png", renderer);
    im_ennemi.loadFromFile("data/Zinzin.png", renderer);
    im_missile_player.loadFromFile("data/Missile_SpaceShip.png", renderer);
    im_missile_ennemi.loadFromFile("data/Missile_Ennemie.png", renderer);

    //Images bitmap pour la gestion de la vie du joueur
    im_vie_moins.loadFromFile("data/PV_Moins.png", renderer);
    im_vie_plus.loadFromFile("data/PV_Plus.png", renderer);

    //Images r�f�rence aux bonus
    im_bonus.loadFromFile("data/Bonus.png", renderer);

    font_bonus2.setSurface(TTF_RenderText_Solid(font, "Tire multiple : ", font_color1));
    SDL_FreeSurface(TTF_RenderText_Solid(font, c, font_color1));
    font_bonus2.loadFromCurrentSurface(renderer);

    font_bonus1.setSurface(TTF_RenderText_Solid(font, "Score x10 : ", font_color1));
    SDL_FreeSurface(TTF_RenderText_Solid(font, c, font_color1));
    font_bonus1.loadFromCurrentSurface(renderer);

    //Un petit �cran de game over quand le joueur perd
    im_game_over.loadFromFile("data/Game_Over.jpg", renderer);

    //Images repr�sentant la partie texte de SDL
    font_score_char.setSurface(TTF_RenderText_Solid(font, "Score : ", font_color1));
    SDL_FreeSurface(TTF_RenderText_Solid(font, c, font_color1));
    font_score_char.loadFromCurrentSurface(renderer);

    font_lvl_char.setSurface(TTF_RenderText_Solid(font, "Niveau : ", font_color1));
    SDL_FreeSurface(TTF_RenderText_Solid(font, c, font_color1));
    font_lvl_char.loadFromCurrentSurface(renderer);

    //Variables necessaires pour la gestion de l'affichage des vies,score et niveaux
    score_affiche = -1;
    lvl_affiche = -1;
}

void SDL_Basique::sdlAff()
{
    //Effa�age de l'�cran
    SDL_RenderClear(renderer);

    //Dessine l'arri�re-plan du jeu dans la fenetre
    background.draw(renderer, 0, 0, dimx, dimy);
    interface.draw(renderer, dimx + 100, 0, 300, dimy + 100);
    border.draw(renderer, dimx, 0, 100, dimy);

    //Dessin des indicateurs de la vie du joueur
    int v_ind = 1;
    int v_player = jeu.getConstSpaceShip().getVie();
    for (int i = 0; i < 12; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            if (v_player >= v_ind)
            {
                im_vie_plus.draw(renderer, dimx + 10 + 50 * j, 20 + 50 * i, 30, 30);
            }
            else
            {
                if (24 >= v_ind)
                {
                    im_vie_moins.draw(renderer, dimx + 10 + 50 * j, 20 + 50 * i, 30, 30);
                }
            }
            v_ind++;
        }
    }

    //Affichage des informations textualises
    SDL_Rect positioncharScore;
    positioncharScore.x = dimx + 180;
    positioncharScore.y = 50;
    positioncharScore.w = 100;
    positioncharScore.h = 40;
    SDL_RenderCopy(renderer, font_score_char.getTexture(), NULL, &positioncharScore);

    SDL_Rect positioncharLvl;
    positioncharLvl.x = dimx + 180;
    positioncharLvl.y = 100;
    positioncharLvl.w = 100;
    positioncharLvl.h = 40;
    SDL_RenderCopy(renderer, font_lvl_char.getTexture(), NULL, &positioncharLvl);

    SDL_Rect positionScore;
    positionScore.x = dimx + 300;
    positionScore.y = 50;
    positionScore.w = 20 * ((int(log10(jeu.getScore()))) + 1);
    positionScore.h = 40;
    SDL_RenderCopy(renderer, font_score_im.getTexture(), NULL, &positionScore);

    SDL_Rect positionLvl;
    positionLvl.x = dimx + 300;
    positionLvl.y = 100;
    positionLvl.w = 20 * ((int(log10(jeu.getNiveau()))) + 1);
    positionLvl.h = 40;
    SDL_RenderCopy(renderer, font_lvl_im.getTexture(), NULL, &positionLvl);

    SDL_Rect positionQuit;
    positionQuit.x = dimx + 200;
    positionQuit.y = dimy - 100;
    positionQuit.w = 100;
    positionQuit.h = 40;
    SDL_RenderCopy(renderer, button_quit.getTexture(), NULL, &positionQuit);

    SDL_Rect positionPause;
    positionPause.x = dimx + 200;
    positionPause.y = dimy - 200;
    positionPause.w = 100;
    positionPause.h = 40;
    SDL_RenderCopy(renderer, button_pause.getTexture(), NULL, &positionPause);

    SDL_Rect positionReset;
    positionReset.x = dimx + 150;
    positionReset.y = dimy - 300;
    positionReset.w = 200;
    positionReset.h = 40;
    SDL_RenderCopy(renderer, button_reset.getTexture(), NULL, &positionReset);

    //Affichage des informations relatives aux bonus
    SDL_Rect positionbonus1;
    positionbonus1.x = dimx + 135;
    positionbonus1.y = 150;
    positionbonus1.w = 150;
    positionbonus1.h = 40;
    SDL_RenderCopy(renderer, font_bonus1.getTexture(), NULL, &positionbonus1);

    SDL_Rect positionbonus2;
    positionbonus2.x = dimx + 135;
    positionbonus2.y = 200;
    positionbonus2.w = 150;
    positionbonus2.h = 40;
    SDL_RenderCopy(renderer, font_bonus2.getTexture(), NULL, &positionbonus2);

    //Dessin des �l�ments du jeu vaisseau, ennemies et missiles
    int px = jeu.getConstSpaceShip().getX() * SPRITE;
    int py = jeu.getConstSpaceShip().getY() * SPRITE;
    im_spaceship.draw(renderer, px, py, SPRITE, SPRITE);
    int ex, ey, mx, my;
    const Missile *m;
    const Ennemie *e = jeu.getConstEnnemie();
    int nbm;
    int nbe = jeu.getNombreDeEnnemie();
    for (int i = 0; i < nbe; i++)
    {
        ex = e[i].getX() * SPRITE;
        ey = e[i].getY() * SPRITE;
        im_ennemi.draw(renderer, ex, ey, SPRITE, SPRITE);
        m = e[i].getMissiles();
        nbm = e[i].getNombreDeMissiles();
        for (int j = 0; j < nbm; j++)
        {
            mx = m[j].getX() * SPRITE;
            my = m[j].getY() * SPRITE;
            if ((my > ey) && (my < dimy))
            {
                im_missile_ennemi.draw(renderer, mx, my, 20, SPRITE);
            }
        }
    }
    m = jeu.getConstSpaceShip().getMissiles();
    nbm = jeu.getConstSpaceShip().getNombreDeMissiles();
    for (int k = 0; k < nbm; k++)
    {
        mx = m[k].getX() * SPRITE;
        my = m[k].getY() * SPRITE;
        if ((py != my) && (my != 0))
        {
            im_missile_player.draw(renderer, mx, my, 20, SPRITE);
        }
    }

    //Dessin du mod�le des bonus
    int nbb = jeu.getNbBonus();
    const Bonus *b = jeu.getConstBonus();
    int bx, by;
    for (int i = 0; i < nbb; i++)
    {
        bx = b[i].getX() * SPRITE;
        by = b[i].getY() * SPRITE;
        if ((py != by) && (by != -30))
        {
            im_bonus.draw(renderer, bx, by, SPRITE, SPRITE);
        }
    }
    if (bonusActif(1, b, nbb))
    {
        im_vie_plus.draw(renderer, dimx + 300, 150, 40, 40);
    }
    else
    {
        im_vie_moins.draw(renderer, dimx + 300, 150, 40, 40);
    }
    if (bonusActif(3, b, nbb))
    {
        im_vie_plus.draw(renderer, dimx + 300, 200, 40, 40);
    }
    else
    {
        im_vie_moins.draw(renderer, dimx + 300, 200, 40, 40);
    }
}

void SDL_Basique::sdlLoop()
{
    //variables pour la gestion �venementielle
    SDL_Event events;
    int mx, my;
    //variable d�sigant l'�tat du jeu : en pause, en jeu ou si la fen�tre du jeu est toujours actif
    bool ok = true;
    bool in_game = true;
    bool on_pause = false;
    const char *pause;

    //variables pour la gestion temporelle dans le jeu
    Uint32 t = SDL_GetTicks(), nt;

    //Ex�cution en boucle de la fen�tre
    while (ok)
    {
        nt = SDL_GetTicks(); //d�finition de la variable temporelle nt

        //Partie s'�xecutant toutes les 100ms
        if (nt - t > 100)
        {
            //D�finition et mise � jour des boutons permettant de mettre en pause, recommencer ou quitter le jeu
            mx = events.motion.x;
            my = events.motion.y;
            if ((mx < dimx + 300) && (mx > dimx + 200) && (my < dimy - 60) && (my > dimy - 100))
            {
                button_quit.setSurface(TTF_RenderText_Blended(font, "Quitter", font_color2));
            }
            else
            {
                button_quit.setSurface(TTF_RenderText_Blended(font, "Quitter", font_color1));
            }
            button_quit.loadFromCurrentSurface(renderer);
            if (on_pause)
            {
                pause = "Reprendre";
            }
            else
            {
                pause = "Pause";
            }
            if ((mx < dimx + 300) && (mx > dimx + 200) && (my < dimy - 160) && (my > dimy - 200))
            {
                button_pause.setSurface(TTF_RenderText_Blended(font, pause, font_color2));
            }
            else
            {
                button_pause.setSurface(TTF_RenderText_Blended(font, pause, font_color1));
            }

            button_pause.loadFromCurrentSurface(renderer);

            if ((mx < dimx + 350) && (mx > dimx + 150) && (my < dimy - 260) && (my > dimy - 300))
            {
                button_reset.setSurface(TTF_RenderText_Blended(font, "Nouvelle Partie", font_color2));
            }
            else
            {
                button_reset.setSurface(TTF_RenderText_Blended(font, "Nouvelle Partie", font_color1));
            }
            button_reset.loadFromCurrentSurface(renderer);

            //D�finition et mise � jour de l'affichage des scores et des niveaux
            if (score_affiche != jeu.getScore())
            {
                score_affiche = jeu.getScore();
                tab_char(score_affiche, c);
                font_score_im.setSurface(TTF_RenderText_Solid(font, c, font_color1));
                SDL_FreeSurface(TTF_RenderText_Solid(font, c, font_color1));
                font_score_im.loadFromCurrentSurface(renderer);
            }
            if (lvl_affiche != jeu.getNiveau())
            {
                lvl_affiche = jeu.getNiveau();
                tab_char(lvl_affiche, c);
                font_lvl_im.setSurface(TTF_RenderText_Solid(font, c, font_color1));
                SDL_FreeSurface(TTF_RenderText_Solid(font, c, font_color1));
                font_lvl_im.loadFromCurrentSurface(renderer);
            }

            //Gestion des actions durant le jeu
            if ((in_game) && (!on_pause))
            {
                jeu.actionsAutomatiques();
                if (jeu.EnnemisEnVie())
                {
                    jeu.RemplirTabEnnemies(jeu.getNiveau() + 1);
                }
                jeu.UpdateTabMissile();
                jeu.Collisions();
                if (jeu.CollisionEnnemieSpaceShip() == true)
                {
                    in_game = false;
                }
                if (jeu.getConstSpaceShip().getVie() <= 0)
                {
                    in_game = false;
                }
                jeu.UpdateTabBonus();
            }
            //Gestion des actions du joueurs par le biai d'�venements
            while (SDL_PollEvent(&events))
            {
                switch (events.type)
                {
                //Clique sur le bouton fermer de SDL
                case SDL_QUIT:
                    ok = false;
                    break;
                //Interactions avec le clavier
                case SDL_KEYDOWN:
                    if ((in_game) && (!on_pause))
                    {
                        switch (events.key.keysym.scancode)
                        {
                        case SDL_SCANCODE_LEFT:
                            jeu.actionClavier('g');
                            break;
                        case SDL_SCANCODE_RIGHT:
                            jeu.actionClavier('d');
                            break;
                        case SDL_SCANCODE_UP:
                            jeu.actionClavier('m');
                            break;
                        case SDL_SCANCODE_ESCAPE:
                            ok = false;
                            break;
                        default:
                            break;
                        }
                    }
                    break;
                //Interactions avec la souris
                case SDL_MOUSEBUTTONDOWN:
                    int mouse_x, mouse_y;
                    mouse_x = events.button.x;
                    mouse_y = events.button.y;
                    if ((mouse_x < dimx + 300) && (mouse_x > dimx + 200) && (mouse_y < dimy - 60) && (mouse_y > dimy - 100))
                    {
                        ok = false;
                    }
                    if ((mouse_x < dimx + 300) && (mouse_x > dimx + 200) && (mouse_y < dimy - 160) && (mouse_y > dimy - 200))
                    {
                        on_pause = (!on_pause);
                    }
                    if ((mouse_x < dimx + 350) && (mouse_x > dimx + 150) && (mouse_y < dimy - 260) && (mouse_y > dimy - 300))
                    {
                        jeu.reset();
                        in_game = true;
                    }
                    break;
                default:
                    break;
                }
            }

            t = nt; //Mise � jour de la valeur temporelle  t
        }
        sdlAff(); //Appel � la fonction d'affichage des �l�ments de la fen�tre

        //Gestion de l'�cran game over
        if (!in_game)
        {
            im_game_over.draw(renderer, 0, 0, dimx, dimy);
        }

        SDL_RenderPresent(renderer); //Mise � jour des buffers
    }
}

SDL_Basique::~SDL_Basique()
{
    //Liberation de la variable c de la m�moire
    delete[] c;

    //Lib�ration du contenu de la fen�tre SDL de la m�moire
    TTF_CloseFont(font);
    TTF_Quit();
    IMG_Quit();
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_VideoQuit();
    SDL_Quit();
}
