//
// Created by Yaroslav Teliuk on 25.05.2022.
//

#ifndef TETRIS_PIECES_H
#define TETRIS_PIECES_H

// forward declaration
struct matrix4x4;

// type of element
enum class EPiecesType
{
    L_element = 0,
    I_element,
    J_element,
    O_element,
    T_element,
    Z_element,
    S_element
};

struct IPieces {
    virtual ~IPieces();
    virtual matrix4x4 getPieces() = 0;
};

struct Z_Piece: IPieces
{
    Z_Piece();
    matrix4x4 getPieces();
    ~Z_Piece();
};

struct PiecesFactory
{
    IPieces createPiece(EPiecesType type);
};

// Singleton board
struct Board
{
    Board(Board&) = delete;                     // delete copy constructor
    Board operator=(const Board&) = delete;     //

    static Board* getInstance();

    void drawPiece(IPieces element);
private:
    Board();                                     // constructor
    static Board* instance_;                     // board instance
};

Board* Board::instance_ = nullptr;

#endif //TETRIS_PIECES_H
