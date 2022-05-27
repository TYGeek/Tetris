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

void ISprite::rotate()
{
    currentSkinPos = instruments::checkUpperLimit(currentSkinPos, maxSkinPos);
    currentSkin = &Wardrobe[currentSkinPos];
}

const spriteSpace& ISprite::getBody()
{
    return *currentSkin;
}

const ISprite* createSprite()
{

    int genNumber = instruments::generateRandNum(0, static_cast<int>(ESpriteType::S_element));
    ISprite* catcher{nullptr};
    
    switch (static_cast<ESpriteType>(genNumber))
    {
        case(ESpriteType::L_element):
        {
            catcher = L_Sprite::getInstance();
        };
        case(ESpriteType::I_element):
        {
            catcher = I_Sprite::getInstance();
        };
        case(ESpriteType::J_element):
        {
            catcher = J_Sprite::getInstance();
        };
        case(ESpriteType::O_element):
        {
            catcher = O_Sprite::getInstance();
        };
        case(ESpriteType::T_element):
        {
            catcher = T_Sprite::getInstance();
        }
        case(ESpriteType::Z_element):
        {
            catcher = Z_Sprite::getInstance();
        }
        case(ESpriteType::S_element):
        {
            catcher = S_Sprite::getInstance();
        }
        default:
        {
            return nullptr;
        }
    }
    catcher->currentSkinPos = instruments::generateRandNum(0, maxSkinPos);
        
    catcher->currentSkin = &Wardrobe[currentSkinPos];

}

void deleteSprites()
{
    for(size_t counter = 0; counter < static_cast<int>(ESpriteType::S_element);++counter)
        switch (counter)
        {
            case(static_cast<int>(ESpriteType::L_element)): delete L_Sprite::getInstance(); break;
            case(static_cast<int>(ESpriteType::I_element)): delete I_Sprite::getInstance(); break;
            case(static_cast<int>(ESpriteType::J_element)): delete J_Sprite::getInstance(); break;
            case(static_cast<int>(ESpriteType::O_element)): delete O_Sprite::getInstance(); break;
            case(static_cast<int>(ESpriteType::T_element)): delete T_Sprite::getInstance(); break;
            case(static_cast<int>(ESpriteType::Z_element)): delete Z_Sprite::getInstance(); break;
            case(static_cast<int>(ESpriteType::S_element)): delete S_Sprite::getInstance(); break;
        }

}


L_Sprite::L_Sprite() : posX{ 2.0 }, posY{0.0}, currentSkinPos{ 0 }, currentSkin{ nullptr }
{
    posX = 2.0;

    spriteSpace processSkin = {{{0, 0, 0, 0},
                                {1, 1, 0, 0},
                                {1, 0, 0, 0},
                                {1, 0, 0, 0}}};

    wardrobe.push_back(processSkin);

    processSkin = {{{0, 0, 0, 0},
                    {0, 0, 0, 0},
                    {1, 1, 1, 0},
                    {0, 0, 1, 0}}};

    wardrobe.push_back(processSkin);

    processSkin = {{{0, 0, 0, 0},
                    {0, 1, 0, 0},
                    {0, 1, 0, 0},
                    {1, 1, 0, 0}}};

    wardrobe.push_back(processSkin);

    processSkin = {{{0, 0, 0, 0},
                    {0, 0, 0, 0},
                    {1, 0, 0, 0},
                    {1, 1, 1, 0}}};

    wardrobe.push_back(processSkin);

    maxSkinPos = wardrobe.size() - 1;


}

ISprite* LSprite::getInstance()
{
    if (L_Sprite::object == nullptr)
    {
        object = new L_Sprite();
    }
    
    return object;
}



I_Sprite::I_Sprite(): posX{ 2.0 }, posY{0.0}, currentSkinPos{0}, currentSkin{nullptr}
{
    spriteSpace processSkin = {{{0, 0, 0, 0},
                                {0, 0, 0, 0},
                                {0, 0, 0, 0},
                                {1, 1, 1, 1}}}

    wardrobe.push_back(processSkin);

    processSkin = {{{1, 0, 0, 0},
                    {1, 0, 0, 0},
                    {1, 0, 0, 0},
                    {1, 0, 0, 0}}};
    wardrobe.push_back(processSkin);

    maxSkinPos = wardrobe.size() - 1;

    currentSkinPos = instruments::generateRandNum(0, maxSkinPos);
    currentSkin = &Wardrobe[currentSkinPos];
}


ISprite* I_Sprite::getInstance()
{
    if (I_Sprite::object == nullptr)
    {
        object = new I_Sprite();
    }
    return object;
}

J_Sprite::J_Sprite(): posX{ 2.0 }, posY{0.0}, currentSkinPos{0}, currentSkin{nullptr}
{
    spriteSpace processSkin = {{{0, 0, 0, 0},
                                {0, 1, 0, 0},
                                {0, 1, 0, 0},
                                {1, 1, 0, 0}}}

    wardrobe.push_back(processSkin);

    processSkin = {{{0, 0, 0, 0},
                    {0, 0, 0, 0},
                    {1, 0, 0, 0},
                    {1, 1, 1, 0}}};
    wardrobe.push_back(processSkin);

    processSkin = {{{0, 0, 0, 0},
                    {1, 1, 0, 0},
                    {1, 0, 0, 0},
                    {1, 0, 0, 0}}};
    wardrobe.push_back(processSkin);

    processSkin = {{{0, 0, 0, 0},
                    {0, 0, 0, 0},
                    {1, 1, 1, 0},
                    {0, 0, 1, 0}}};
    wardrobe.push_back(processSkin);

    maxSkinPos = wardrobe.size() - 1;
}

ISprite* J_Sprite::getInstance()
{
    if (J_Sprite::object == nullptr)
    {
        object = new J_Sprite();
    }
    return object;
}


O_Sprite::O_Sprite(): posX{ 2.0 }, posY{0.0}, currentSkinPos{0}, currentSkin{nullptr}
{
    spriteSpace processSkin = {{{0, 0, 0, 0},
                                {0, 0, 0, 0},
                                {1, 1, 0, 0},
                                {1, 1, 0, 0}}}
    maxSkinPos = wardrobe.size() - 1;
    currentSkin = &Wardrobe[currentSkinPos];
}

ISprite* O_Sprite::getInstance()
{
    if (O_Sprite::object == nullptr)
    {
        object = new O_Sprite();
    }
    return object;
}

T_Sprite::T_Sprite(): posX{ 2.0 }, posY{0.0}, currentSkinPos{0}, currentSkin{nullptr}
{
    spriteSpace processSkin = { {{0, 0, 0, 0},
                                {0, 0, 0, 0},
                                {0, 1, 0, 0},
                                {1, 1, 1, 0}} };

    wardrobe.push_back(processSkin);

    processSkin = {{{0, 0, 0, 0},
                    {1, 0, 0, 0},
                    {1, 1, 0, 0},
                    {1, 0, 0, 0}}};
    wardrobe.push_back(processSkin);

    processSkin = {{{0, 0, 0, 0},
                    {0, 0, 0, 0},
                    {1, 1, 1, 0},
                    {0, 1, 0, 0}}};
    wardrobe.push_back(processSkin);

    processSkin = {{{0, 0, 0, 0},
                    {0, 1, 0, 0},
                    {1, 1, 0, 0},
                    {0, 1, 0, 0}}};
    wardrobe.push_back(processSkin);

    maxSkinPos = wardrobe.size() - 1;
}

ISprite* T_Sprite::getInstance()
{
    if (T_Sprite::object == nullptr)
    {
        object = new T_Sprite();
    }
    return object;
}

Z_Sprite::Z_Sprite(): posX{ 2.0 }, posY{0.0}, currentSkinPos{0}, currentSkin{nullptr}
{
    spriteSpace processSkin = {{{0, 0, 0, 0},
                                {0, 0, 0, 0},
                                {1, 1, 0, 0},
                                {0, 1, 1, 0}}}

    wardrobe.push_back(processSkin);


    processSkin = {{{0, 0, 0, 0},
                    {0, 1, 0, 0},
                    {1, 1, 0, 0},
                    {1, 0, 0, 0}}};
    wardrobe.push_back(processSkin);

    maxSkinPos = wardrobe.size() - 1;
}

ISprite* Z_Sprite::getInstance()
{
    if (Z_Sprite::object == nullptr)
    {
        object = new Z_Sprite();
    }
    return object;
}

S_Sprite::S_Sprite(): posX{ 2.0 }, posY{0.0}, currentSkinPos{0}, currentSkin{nullptr}
{
    spriteSpace processSkin = {{{0, 0, 0, 0},
                                {0, 0, 0, 0},
                                {0, 1, 1, 0},
                                {1, 1, 0, 0}}}

    wardrobe.push_back(processSkin);


    processSkin = {{{0, 0, 0, 0},
                    {1, 0, 0, 0},
                    {1, 1, 0, 0},
                    {0, 1, 0, 0}}};
    wardrobe.push_back(processSkin);

    maxSkinPos = wardrobe.size() - 1;
}

ISprite* S_Sprite::getInstance()
{
    if (S_Sprite::object == nullptr)
    {
        object = new S_Sprite();
    }
    return object;
}



