
#ifndef TETRIS_PIECES_H
#define TETRIS_PIECES_H
// forward declaration
#include "array"
#include "vector"
using bodyType = std::array<std::array<int, 4>,4>;
//struct matrix4x4;


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

namespace instruments
{
    int generateRandNum(int low, int high);
    int checkUpperLimit(int current, int max);
}

struct IPieces {
    virtual const bodyType& getBody() = 0;
    virtual void rotate() = 0;
    virtual ~IPieces() = default;

protected:
    using skinsCollection = std::vector<bodyType>; //1. skin_0_deg 2. skin_90_deg, 3.skin_180_deg, 4. skin_270_deg
    skinsCollection Wardrobe;
    bodyType* currentSkin;
    int currentSkinPos;
    int maxSkinPos;
};

struct L_Piece: IPieces
{
    L_Piece* getInstance();
    L_Piece(const L_Piece&) = delete;
    L_Piece& operator=(const L_Piece&) = delete;
    const bodyType& getBody() override { return *currentSkin; };
    void rotate() override;
    ~L_Piece() = default;
private:
    static L_Piece* object;
    L_Piece();
};
L_Piece* L_Piece::object = nullptr;

struct I_Piece: IPieces
{
    I_Piece();
    const bodyType& getBody() override {return *currentSkin;};;
    void rotate() override;
    ~I_Piece() = default;
private:

};

struct J_Piece: IPieces
{
    J_Piece();
    const bodyType& getBody() override;
    void rotate() override;
    ~J_Piece();

};

struct O_Piece: IPieces
{
    O_Piece();
    const bodyType& getBody() override;
    void rotate() override;
    ~O_Piece();
};

struct T_Piece: IPieces
{
    T_Piece();
    const bodyType& getBody() override;
    void rotate() override;
    ~T_Piece();
};

struct Z_Piece: IPieces
{
    Z_Piece();
    const bodyType& getBody() override;
    void rotate() override;
    ~Z_Piece() override;
};

struct S_Piece: IPieces
{
    S_Piece();
    const bodyType& getBody() override;
    void rotate() override;
    ~S_Piece();
};

struct FigureGenerator
{
    const IPieces* createPiece();
};

// Singleton board
struct Board
{
    Board() = delete;
    Board(Board const&) = delete;               // delete copy constructor
    Board operator=(Board const&) = delete;     //

    static Board* getInstance();

    void draw(IPieces const& element);

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

//1. Генерация элемента
//2. Отрисовка карты

Board* Board::instance_ = nullptr;

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



/**      cur_colm
 *
 *    |y+ (4 elem)
 *    |   1111
 *    | 1111
 *    |_________x+ (4 elem)
 *
 *               1                  // row 2
 *               1                  // row 1
 * ################################ // row 0
 * */



/*
 * e 2
 * e 0 -> sprite on posY
 * 0
 * 0
 * 0 2
 * 1 0
 *   0 -> sprite on posY
 * */

/**
 *
 * board[10] = [1, 0 .... 0];
 * sprite[3] = [0, 0, 2];
 *
 * posY = board.size() = 10;    //счетчик положения обьекта
 *
 * while( endGame )
 * {
 *      for( row = 0;  board.size()-1 ; row++)
 *      {
 *          if( board[row] == 1 ) { draw() }    // draw element from board
 *
 *          if ( row >= posY )                  // start draw sprite
 *          {
 *              int index = abs(row - posY); // 2
 *              if( index < sprite.size() )      // check out of array
 *              {
 *                  if( sprite[index] == 2 )      // draw if 2
 *                      draw()
 *
 *                  // save sprite on board if prev element on board == 1 and cur element in sprite == 2
 *                  if ( row != 0 && board[row-1] == sprite[index] )
 *                      save();     // save Sprite in board
 *                      createNewSprite = true;
 *                      break;      // exit from cycle
 *              }
 *          }
 *      }
 *
 *      if (createNewSprite)
 *      {
 *          posY = board.size();
 *          sprite = new Sprite;
 *          createNewSprite = false;
 *      }
 *
 *      posY--;
 *
 * }
 *
 *
 * */