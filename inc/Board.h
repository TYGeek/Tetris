#ifndef TETRIS_BOARD_H
#define TETRIS_BOARD_H
#include <array>


struct ISprite;

using boardSpace = std::array<std::array<int, 10>, 10>;


// Singleton board
struct Board
{
    Board() = delete;
    Board(Board const&) = delete;               // delete copy constructor
    Board& operator=(Board const&) = delete;    //

    static Board* getInstance();

    boardSpace render_logic(boardSpace& board, ISprite const& sprite);
    int getDeadLine( boardSpace const& board);
    boardSpace boardBody;
    ~Board();
private:
    int deadLine; // current upper position of elements on board
    float dX;     // [pix/s] 
    float dY;     // [pix/s]
    float dt;     // [s]
    

private:
    bool isIntersection( boardSpace const& board,  ISprite const& sprite);
    void insertSprite(boardSpace& board, ISprite const& sprite);
    void render(const boardSpace& board);

    bool allowMoveLeft(const boardSpace& board, ISprite const& sprite);
    bool allowMoveRight(const boardSpace& board, ISprite const& sprite);
    bool allowRotate(const boardSpace& board, ISprite const& sprite);

    // interact with user (move, rotate, exit)
    void eventHandler(boardSpace const& board, ISprite& sprite);
    
    boardSpace destroyLine(boardSpace board);
   
    Board(float dX, float dY, float dt);         // constructor

    void createBoard(int rows = 10, int colms = 10);

private:
    static Board* body;                         // board instance
    
};



#endif

