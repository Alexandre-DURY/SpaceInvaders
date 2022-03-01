#ifndef WINTXT_H
#define WINTXT_H

//! \brief une fenetre texte est un tableau 2D de caracteres
class WinTXT {

private:

    int dimx;       //!< \brief largeur
    int dimy;       //!< \brief hauteur
    char* win;      //!< \brief stocke le contenu de la fenetre dans un tableau 1D mais on y accede en 2D

public:

    WinTXT (int dx, int dy);
    ~WinTXT();
    void clear (char c=' ');
    void print (int x, int y, char c);
    void print (int x, int y, char* c);
    void draw (int x=0, int y=0);
    void pause();
    char getCh();

};

void termClear ();

#endif
