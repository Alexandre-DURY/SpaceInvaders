#ifndef _IMAGE_H
#define _IMAGE_H
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>

/** @brief La classe image permet de gérer
*/
class Image
{
private:
    SDL_Surface *surface;
    SDL_Texture *texture;
    bool has_changed;

public:
    /** @brief booléen permettant de savoir si oui ou non un objet est détruit dans le terrain
        @param
    */
    bool is_destroyed;
    /** @brief Constructeur de la classe
        @param
    */
    Image();

    /** @brief Destructeur de la classe
        @param
    */
    ~Image();

    /** @brief
        @param
    */
    void loadFromFile(const char *filename, SDL_Renderer *renderer);

    /** @brief
        @param
    */
    void loadFromCurrentSurface(SDL_Renderer *renderer);

    /** @brief
        @param
    */
    void draw(SDL_Renderer *renderer, int x, int y, int w = -1, int h = -1);

    /** @brief
        @param
    */
    SDL_Texture *getTexture() const;

    /** @brief
        @param
    */
    void setSurface(SDL_Surface *surf);
};

#endif // _IMAGE_H
