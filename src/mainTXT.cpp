#include "winTxt.h"
#include "ImageTXT.h"
#include "Jeu.h"
#include <stdlib.h>
#include <time.h>

int main(int argc, char **argv)
{
	srand(time(NULL));
	termClear();
	Jeu jeu;
	txtBoucle(jeu);
	termClear();
	return 0;
}