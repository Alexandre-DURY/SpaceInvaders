#ifndef _SDL_BASIQUE_H
#define _SDL_BASIQUE_H
#include "Image.h"
#include "Jeu.h"


class SDL_Basique
{
private:
    SDL_Renderer * renderer;
    SDL_Window * window;
    TTF_Font * font;

    Image font_score_im;
    Image font_lvl_im;
    Image font_score_char;
    Image font_lvl_char;
    Image font_bonus1;
    Image font_bonus2;
    Image button_pause;
    Image button_reset;
    Image button_quit;
    SDL_Color font_color1;
    SDL_Color font_color2;
    char * c;
    int score_affiche,lvl_affiche;

    Jeu jeu;
    int dimx,dimy;
    Image background;
    Image interface;
    Image border;
    Image im_spaceship;
    Image im_ennemi;
    Image im_missile_player;
    Image im_missile_ennemi;
    Image im_vie_moins;
    Image im_vie_plus;
    Image im_bonus;
    Image im_game_over;


public:
    SDL_Basique();
    void sdlAff();
    void sdlLoop();
    ~SDL_Basique();
};

#endif
