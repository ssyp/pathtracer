#ifndef __SURFACE_H__
#define __SURFACE_H__
 
#include "SDL.h"
 
class Surface {
    public:
        Surface();
 
    public:
        static SDL_Surface* OnLoad(char* File);
 
        static bool OnDraw(SDL_Surface* Surf_Dest, SDL_Surface* Surf_Src, int X, int Y);
};
 
#endif