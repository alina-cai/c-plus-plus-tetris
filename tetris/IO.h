#ifndef_IO_
#define_IO_

// —————————— Includes ——————————

#ifndef LINUX
#include "sdl/include/SDL.h"
#include "SDL/SDL_GfxPrimitives/SDL_gfxPrimitives.h"
#else
#include <SDL/SDL.h>
#include <SDL/SDL_GfxPrimitives/sdl_gfxprimitives.h>
#endif
#pragma comment (lib, "SDL/lib/SDL.lib")
#pragma comment (lib, "SDL/SDL_GfxPrimitives/SDL_gfxPrimitives_Static.lib")

// —————————— Enums ——————————

enum color {BLACK, RED, GREEN, BLUE, CYAN, MAGENTA, YELLOW, WHITE, COLOR_MAX}; // Colours

// ================================
//              IO              
// ================================

class IO
{
    public:

    IO ();

    void DrawRectangle (int pX1, int pY1, int pX2, int pY2, enum color pC);
    void ClearScreen ();
    int GetScreenHeight ();
    int InitGraph ();
    int Pollkey ();
    int Getkey ();
    int IsKeyDown (int pKey);
    void UpdateScreen ();
};

#endif // _IO_