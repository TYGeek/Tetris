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
    virtual matrix4x4 getMesh() = 0;
    virtual void rotate() = 0;
};

struct Z_Piece: IPieces
{
    Z_Piece();
    matrix4x4 getMesh();
    ~Z_Piece();
};

struct PiecesFactory
{
    IPieces createPiece(EPiecesType type);
    IPieces createRandomPiece();
};

// Singleton board
struct Board
{
    Board() = delete;
    Board(Board const&) = delete;               // delete copy constructor
    Board operator=(Board const&) = delete;     //

    static Board* getInstance();

    void drawPiece(IPieces const& element);

    // interact with user
    void userEvent();
    void moveLeft();
    void moveRight();
    void rotate();

    bool stopMoveElement(IPieces const& element);
    unsigned int checkFullLine();//search fulling polygons on the board
    void repaintField();//
private:
    Board(unsigned int height, unsigned int width);         // constructor
    static Board* instance_;                                // board instance

    unsigned int deadLine;      // current upper position of elements on board
    unsigned int curX_element;  // current element position on board axis X
    unsigned int curY_element;  // current element position on board axis Y
};

Board* Board::instance_ = nullptr;


#endif //TETRIS_PIECES_H
