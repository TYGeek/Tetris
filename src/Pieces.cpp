//
// Created by Yaroslav Teliuk on 25.05.2022.
//

#include "Pieces.h"


int instruments::generateRandNum(int low, int high)
{
    int range = high - low + 1;
    int result = (std::rand() % range + low);
    return result;
}

int instruments::checkUpperLimit(int current, int max)
{
    if(current != max)
    {
        return ++current;
    }
    else
    {
        return 0;
    }
}

const IPieces* FigureGenerator::createPiece()
{

    int genNumber = instruments::generateRandNum(0, static_cast<int>(EPiecesType::S_element));

    switch (static_cast<EPiecesType>(genNumber))
    {
        case(EPiecesType::L_element):
        {
            return new L_Piece();
        };
        case(EPiecesType::I_element):
        {
            return new I_Piece();
        };
        case(EPiecesType::J_element):
        {
            return new J_Piece();
        };
        case(EPiecesType::O_element):
        {
            return new O_Piece();
        };
        case(EPiecesType::T_element):
        {
            return new T_Piece();
        }
        case(EPiecesType::Z_element):
        {
            return new Z_Piece();
        }
        case(EPiecesType::S_element):
        {
            return new S_Piece();
        }
        default:
        {
            return nullptr;
        }
    }
}

L_Piece::L_Piece(): maxSkinPos{3}, currentSkinPos{0}, currentSkin{nullptr}
{
    Wardrobe.at(0) = {{{1, 1, 0, 0},
                          {1, 0, 0, 0},
                          {1, 0, 0, 0},
                          {0, 0, 0, 0}}};

    Wardrobe.at(1) = {{{1, 1, 1, 0},
                          {0, 0, 1, 0},
                          {0, 0, 0, 0},
                          {0, 0, 0, 0}}};

    Wardrobe.at(2) = {{{0, 1, 0, 0},
                          {0, 1, 0, 0},
                          {1, 1, 0, 0},
                          {0, 0, 0, 0}}};

    Wardrobe.at(3) = {{{1, 0, 0, 0},
                          {1, 1, 1, 0},
                          {0, 0, 0, 0},
                          {0, 0, 0, 0}}};
    currentSkinPos = instruments::generateRandNum(0, maxSkinPos);
    currentSkin = &Wardrobe[currentSkinPos];
}

void L_Piece::rotate()
{
    currentSkinPos = instruments::checkUpperLimit(currentSkinPos, maxSkinPos);
    currentSkin = &Wardrobe[currentSkinPos];
}

I_Piece::I_Piece(): maxSkinPos{1}, currentSkinPos{0}, currentSkin{nullptr}
{
    Wardrobe.at(0) = {{{1, 1, 1, 1},
                       {0, 0, 0, 0},
                       {0, 0, 0, 0},
                       {0, 0, 0, 0}}};

    Wardrobe.at(1) = {{{1, 0, 0, 0},
                       {1, 0, 0, 0},
                       {1, 0, 0, 0},
                       {1, 0, 0, 0}}};
    currentSkinPos = instruments::generateRandNum(0, maxSkinPos);
    currentSkin = &Wardrobe[currentSkinPos];
}

void I_Piece::rotate()
{
    currentSkinPos = instruments::checkUpperLimit(currentSkinPos, maxSkinPos);
    currentSkin = &Wardrobe[currentSkinPos];
}



