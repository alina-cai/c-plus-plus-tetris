#ifndef_GAME_
#define_GAME_

// —————————— Includes ——————————

#include "Board.h"
#include "Pieces.h"
#include "IO.h"
#include <time.h>

// —————————— Defines ——————————

#define WAIT_TIME 700 // Number of milliseconds that the piece remains before going 1 block down

// ——————————————————————————————
//            Game
// ——————————————————————————————

class Game
{
    public:

    Game (Board *pBoard, Pieces *pPieces, IO *pIO, int pScreenHeight);

    void DrawScene ();
    void CreateNewPiece ();

    int mPosX, mPosY; // X and Y positions of the piece that is falling
    int mPiece, mRotation; // Type and rotation of the piece that is falling

    private:

    int mScreenHeight; // Screen height in pixels
    int mNextPosX, mNextPosY; // X and Y positions of the next piece
    int mNextPiece, mNextRotation; // Type and rotation of the next piece

    Board *mBoard;
    Pieces *mPieces;
    IO *mIO;

    int GetRand (int pA, int pB);
    void InitGame ();
    void DrawPiece (int pX, int pY, int pPiece, int pRotation);
    void DrawBoard ();
};

#endif // _GAME_