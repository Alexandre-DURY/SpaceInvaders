#include "SDL_Basique.h"
#include <cassert>
#include <time.h>
#include <stdlib.h>
#include <iostream>

int main (int argc, char** argv)
{
    srand(time(NULL));
    SDL_Basique SpaceInvader;
    SpaceInvader.sdlLoop();
    return 0;
}
