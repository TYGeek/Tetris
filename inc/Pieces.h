
#ifndef TETRIS_SpriteS_H
#define TETRIS_SpriteS_H
// forward declaration
#include "array"
#include "vector"
using spriteSpace = std::array<std::array<int, 4>,4>;
using skinsCollection = std::vector<spriteSpace>;  //1. skin_0_deg 2. skin_90_deg, 3.skin_180_deg, 4. skin_270_deg


// type of element
enum class ESpriteType
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


struct ISprite {
public:

    float posX;
    float posY;
public:

    ISprite() = delete;
    ISprite(ISprite const&) = delete;
    ISprite& operator=(ISprite const&) = delete;

    virtual const spriteSpace& getBody(); // get current skin
    virtual void rotate();                // rotate current skin 
    friend const ISprite* createSprite();
    virtual ~ISprite() = default;
protected:
    skinsCollection wardrobe;
    spriteSpace* currentSkin;
    int currentSkinPos;
    int maxSkinPos;
};


struct L_Sprite: ISprite
{
    L_Sprite(const L_Sprite&) = delete;
    L_Sprite& operator=(const L_Sprite&) = delete;
    ~L_Sprite() override = default;
    static ISprite* getInstance(); // get random skin L_sprite
private:
    static ISprite* object;
    L_Sprite();
};
ISprite* L_Sprite::object = nullptr;



struct I_Sprite: ISprite
{
    
    I_Sprite(const I_Sprite&) = delete;
    I_Sprite& operator=(const I_Sprite&) = delete;
    static ISprite* getInstance();
    ~I_Sprite() override = default;
private:  
    static ISprite* object;
    I_Sprite();
};
ISprite* I_Sprite::object = nullptr;

struct J_Sprite: ISprite
{
    J_Sprite(const J_Sprite&) = delete;
    J_Sprite& operator=(const J_Sprite&) = delete;
    static ISprite* getInstance();
    ~J_Sprite() override = default;
private:
    static ISprite* object;
    J_Sprite();
};
ISprite* J_Sprite::object = nullptr;

struct O_Sprite: ISprite
{
    O_Sprite(const O_Sprite&) = delete;
    O_Sprite& operator=(const O_Sprite&) = delete;
    ~O_Sprite() override = default;
    static ISprite* getInstance();
private:
    static ISprite* object;
    O_Sprite();
};
ISprite* O_Sprite::object = nullptr;

struct T_Sprite: ISprite
{
    T_Sprite(const T_Sprite&) = delete;
    T_Sprite& operator=(const T_Sprite&) = delete;
    ~T_Sprite() override = default;
     static ISprite* getInstance();
private:
    static ISprite* object;
    T_Sprite();
    
};
ISprite* T_Sprite::object = nullptr;


struct Z_Sprite: ISprite
{
    Z_Sprite(const Z_Sprite&) = delete;
    Z_Sprite& operator=(const Z_Sprite&) = delete;
    ~Z_Sprite() override = default;
    static ISprite* getInstance();
private:
    static ISprite* object;
    Z_Sprite();
};
ISprite* Z_Sprite::object = nullptr;

struct S_Sprite: ISprite
{
    S_Sprite(const S_Sprite&) = delete;
    S_Sprite& operator=(const S_Sprite&) = delete;
    ~S_Sprite() override = default;
    static ISprite* getInstance();
private:
    static ISprite* object;
    S_Sprite();
};
ISprite* S_Sprite::object = nullptr;



const ISprite* createSprite(); // random sprite
void deleteSprites();





#endif //TETRIS_SpriteS_H



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