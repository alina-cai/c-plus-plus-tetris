// —————————— Includes ——————————

#include "Board.h"

/*
================================
Init the board blocks with free positions
================================
*/
void Board::InitBoard ()
{
    for (int i = 0; i < BOARD_WIDTH; i++)
    for (int j = 0; j < BOARD_HEIGHT; j++)
    mBoard [i][j] = POS_FREE;
}

/*
================================
Store a piece in the board by filling the blocks

Parameters:

>> pX: Horizontal position of the piece
>> pY: Vertical position of the piece
>> pPiece: Piece to draw
>> pRotation: 1 of the 4 possible rotations
================================
*/
void Board::StorePiece (int pX, int pY, int pPiece, int pRotation)
{
    // Store each block of the piece into the board
    for (int i1 = pX, i2 = 0; i1 < pX + PIECE_BLOCKS; i1++, i2++)
    {
        for (int j1 = pY, j2 = 0; j1 < pY + PIECE_BLOCKS; j1++, j2++)
        {
            // Store only the blocks of the piece that are not holes
            if (mPieces->GetBlockType (pPiece, pRotation, j2, i2) != 0)
            mBoard[i1][j1]  = POS_FILLED;
        }
    }
}

 /*
 ================================
 Check if the game is over because a piece has achieved the upper position

 Returns 1 or 0
 ================================
 */
bool Board::IsGameOver()
{
    // If the first line has any block, then the game is over
    for (int i = 0; i < BOARD_WIDTH; i++)
    {
        if (mBoard[i][0] == POS_FILLED)
        return true;
    }

    return false;
}

/*
================================
Delete a line of the board by moving all above lines down

Parameters:

>> pY: Vertical position of the line to delete
================================
*/
void Board::DeleteLine (int pY)
{
    // Moves all the upper lines one row down
    for (int j = pY; j > 0; j--)
    {
        for (int i = 0; i < BOARD_WIDTH; i++)
        {
            mBoard[i][j] = mBoard[i][j - 1];
        }
    }
}

/*
================================
Delete all the lines that should be removed
================================
*/
void Board::DeletePossibleLines ()
{
    for (int j = 0; j < BOARD_HEIGHT; j++)
    {
        int i = 0;
        while (i < BOARD_WIDTH)
        {
            if (mBoard[i][j] != POS_FILLED)
            break;

            i++;
        }

        if (i == BOARD_WIDTH)
        DeleteLine (j);
    }
}

/*
================================
Returns 1 if the block of the board is empty, 0 if it is filled

Parameters:

>> pX: Horizontal position of the blocks
>> pY: Vertical position of the blocks
================================
*/
bool Board::IsFreeBlock (int pX, int pY)
{
    if (mBoard [pX][pY] == POS_FREE)
    return true;
    else
    return false;
}

/*
================================
Returns the horizontal position of the board in pixels

Parameters:

>> pPos: Horizontal position of the blocks on the board
================================
*/
int Board::GetXPosInPixels (int pPos)
{
    return (BOARD_POSITION - (BLOCK_SIZE * (BOARD_WIDTH / 2))) + (pPos * BLOCK_SIZE);
}

/*
================================
Returns the vertical position of the board in pixels on the board

Parameters:

>> pPos: Vertical position of the blocks on the board
================================
*/
int Board::GetYPosInPixels (int pPos)
{
    return ((mScreenHeight - (BLOCK_SIZE * BOARD_HEIGHT)) + (pPos * BLOCK_SIZE));
}

/*
================================
Checks if the piece can be stored at this position without any collision

Returns 1 if the movement is possible, false if it is not possible

Parameters:

>> pX: Horizontal position in blocks
>> pY: Vertical position in blocks
>> pPiece: Piece to draw
>> pRotation: 1 of the 4 possible rotations
================================
*/
bool Board::IsPossibleMovement (int pX, int pY, int pPiece, int pRotation)
{
    // Checks collision with pieces already stored in the board or the board limits
    for (int i1 = pX, i2 = 0, i1 < pX + PIECE_BLOCKS; i1++, i2++)
    {
        for (int j1 = pY, j2 = 0; j1 < pY + PIECE_BLOCKS; j1++, j2++)
        {
            // Check if the piece is outside the limits of the board
            if (i1 < 0 || i1 > BOARD_WIDTH - 1 || j1 > BOARD_HEIGHT - 1)
            {
                if (mPieces->GetBlockType (pPiece, pRotation, j2, i2) != 0)
                return false;
            }

            // Check if the piece have collisioned with a block already stored in the map
            if (j1 >= 0)
            {
                if ((mPieces->GetBlockType (pPiece, pRotation, j2, i2) != 0) && (!IsFreeBlock (i1, j1)))
                return false;
            }
        }
    }

    // No collision
    return true;
}