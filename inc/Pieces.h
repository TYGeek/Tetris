
#ifndef TETRIS_PIECES_H
#define TETRIS_PIECES_H
// forward declaration
#include "array"
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
};

struct L_Piece: IPieces
{
    L_Piece();
    const bodyType& getBody() override {return *currentSkin;};
    void rotate() override;
    ~L_Piece() = default;
private:
    using skinsCollection = std::array<bodyType, 4>;//1. skin_0_deg 2. skin_90_deg, 3.skin_180_deg, 4. skin_270_deg
    skinsCollection Wardrobe;
    bodyType* currentSkin;
    int currentSkinPos;
    int maxSkinPos;

};

struct I_Piece: IPieces
{
    I_Piece();
    const bodyType& getBody() override {return *currentSkin;};;
    void rotate() override;
    ~I_Piece() = default;
private:
    using skinsCollection = std::array<bodyType, 2>;//1. skin_0_deg 2. skin_90_deg
    skinsCollection Wardrobe;
    bodyType* currentSkin;
    int currentSkinPos;
    int maxSkinPos;

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
private:
    EPiecesType generatorVariants;
};

// Singleton board
//struct Board
//{
//    Board(Board&) = delete;                     // delete copy constructor
//    Board operator=(const Board&) = delete;     //
//
//    static Board* getInstance();
//
//    void drawPiece(IPieces element);
//private:
//    Board();                                     // constructor
//    static Board* instance_;                     // board instance
//};
//
//Board* Board::instance_ = nullptr;


#endif //TETRIS_PIECES_H
