//
// Created by Yaroslav Teliuk on 25.05.2022.
//

#include "Pieces.h"

ISprite* L_Sprite::object = nullptr;
ISprite* I_Sprite::object = nullptr;
ISprite* J_Sprite::object = nullptr;
ISprite* O_Sprite::object = nullptr;
ISprite* T_Sprite::object = nullptr;
ISprite* Z_Sprite::object = nullptr;
ISprite* S_Sprite::object = nullptr;


int instruments::generateRandNum(int low, int high)
{

    int range = high - low + 1;
    int result = ( std::rand() % range + low );
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
    currentSkin = &wardrobe[currentSkinPos];
}

spriteSpace& ISprite::getBody() const
{
    return *currentSkin;
}

const spriteSpace& ISprite::getNextSkin() const
{
    if (currentSkinPos != wardrobe.size() - 1)
        return wardrobe.at(currentSkinPos + 1);
    else return wardrobe.at(0);
}

ISprite* createSprite()
{

    int genNumber = instruments::generateRandNum(0, static_cast<int>(ESpriteType::S_element));
    ISprite* catcher { nullptr };

    switch (static_cast<ESpriteType>(genNumber))
    {
    case(ESpriteType::L_element):
        catcher = L_Sprite::getInstance();
        break;
    case(ESpriteType::I_element):
        catcher = I_Sprite::getInstance();
        break;
    case(ESpriteType::J_element):
        catcher = J_Sprite::getInstance();
        break;
    case(ESpriteType::O_element):
        catcher = O_Sprite::getInstance();
        break;
    case(ESpriteType::T_element):
        catcher = T_Sprite::getInstance();
        break;
    case(ESpriteType::Z_element):
        catcher = Z_Sprite::getInstance();
        break;
    case(ESpriteType::S_element):
        catcher = S_Sprite::getInstance();
        break;
    default:
        catcher = nullptr;
        break;
    }

    catcher->posX = 2.0;
    catcher->posY = 0.0;
    catcher->currentSkinPos = instruments::generateRandNum(0, catcher->maxSkinPos);
    catcher->currentSkin = &catcher->wardrobe[catcher->currentSkinPos];

    return catcher;

}

void deleteSprites()
{
    for (size_t counter = 0; counter < static_cast<int>(ESpriteType::END); ++counter)
    {
        switch (static_cast<ESpriteType>(counter))
        {
        case ESpriteType::L_element: delete L_Sprite::getInstance(); break;
        case ESpriteType::I_element: delete I_Sprite::getInstance(); break;
        case ESpriteType::J_element: delete J_Sprite::getInstance(); break;
        case ESpriteType::O_element: delete O_Sprite::getInstance(); break;
        case ESpriteType::T_element: delete T_Sprite::getInstance(); break;
        case ESpriteType::Z_element: delete Z_Sprite::getInstance(); break;
        case ESpriteType::S_element: delete S_Sprite::getInstance(); break;
        }
    }      
}


L_Sprite::L_Sprite()
{
    createBody();
}

void L_Sprite::createBody()
{
    posX = 2.0;
    posY = 0.0;
    currentSkinPos = 0;
    currentSkin = nullptr;

    spriteSpace processSkin = { {1, 1},
                                {1, 0},
                                {1, 0} };

    wardrobe.push_back(processSkin);

    processSkin = {  {1, 1, 1},
                     {0, 0, 1} };

    wardrobe.push_back(processSkin);

    processSkin = {  {0, 1},
                     {0, 1},
                     {1, 1} };

    wardrobe.push_back(processSkin);

    processSkin = {  {1, 0, 0},
                      {1, 1, 1} };

    wardrobe.push_back(processSkin);

    maxSkinPos = wardrobe.size() - 1;
}

ISprite* L_Sprite::getInstance()
{
    if ( object == nullptr )
    {
        object = new L_Sprite();
    }
    
    return object;
}

I_Sprite::I_Sprite()
{
    createBody();
}

void I_Sprite::createBody()
{
    posX = 2.0;
    posY = 0.0; 
    currentSkinPos = 0; 
    currentSkin = nullptr;

    spriteSpace processSkin = { {1, 1, 1, 1} };

    wardrobe.push_back(processSkin);

    processSkin = { {1},
                    {1},
                    {1},
                    {1} };
    wardrobe.push_back(processSkin);

    maxSkinPos = wardrobe.size() - 1;

}

ISprite* I_Sprite::getInstance()
{
    if (object == nullptr)
    {
        object = new I_Sprite();
    }
    return object;
}


J_Sprite::J_Sprite()
{
    createBody();
}

void J_Sprite::createBody()
{
    posX = 2.0;
    posY = 0.0;
    currentSkinPos = 0;
    currentSkin = nullptr;

    spriteSpace processSkin = {  {0, 1},
                                 {0, 1},
                                 {1, 1} };

    wardrobe.push_back(processSkin);

    processSkin = {  {1, 0, 0},
                     {1, 1, 1} };
    wardrobe.push_back(processSkin);

    processSkin = { {1, 1},
                    {1, 0},
                    {1, 0} };
    wardrobe.push_back(processSkin);

    processSkin = { {1, 1, 1},
                    {0, 0, 1} };
    wardrobe.push_back(processSkin);

    maxSkinPos = wardrobe.size() - 1;
}

ISprite* J_Sprite::getInstance()
{
    if (object == nullptr)
    {
        object = new J_Sprite();
    }
    return object;
}


O_Sprite::O_Sprite()
{
    createBody();
}

void O_Sprite::createBody()
{
    posX = 2.0;
    posY = 0.0;
    currentSkinPos = 0;
    currentSkin = nullptr;

    spriteSpace processSkin = {  {1, 1},
                                 {1, 1}  };
    wardrobe.push_back(processSkin);

    maxSkinPos = wardrobe.size() - 1;
}

ISprite* O_Sprite::getInstance()
{
    if (object == nullptr)
    {
        object = new O_Sprite();
    }
    return object;
}


T_Sprite::T_Sprite()
{
    createBody();
}

void T_Sprite::createBody()
{
    posX = 2.0; 
    posY = 0.0; 
    currentSkinPos = 0;
    currentSkin = nullptr;

    spriteSpace processSkin = {{0, 1, 0},
                               {1, 1, 1}} ;

    wardrobe.push_back(processSkin);

    processSkin =  {{1, 0},
                    {1, 1},
                    {1, 0}} ;
    wardrobe.push_back(processSkin);

    processSkin =  {{1, 1, 1},
                    {0, 1, 0}} ;
    wardrobe.push_back(processSkin);

    processSkin =  {{0, 1},
                    {1, 1},
                    {0, 1}} ;
    wardrobe.push_back(processSkin);

    maxSkinPos = wardrobe.size() - 1;
}

ISprite* T_Sprite::getInstance()
{
    if (object == nullptr)
    {
        object = new T_Sprite();
    }
    return object;
}

Z_Sprite::Z_Sprite() 
{
    createBody();
}

void Z_Sprite::createBody()
{
    posX = 2.0;
    posY = 0.0;
    currentSkinPos = 0;
    currentSkin = nullptr;
    spriteSpace processSkin = {{1, 1, 0},
                               {0, 1, 1}} ;

    wardrobe.push_back(processSkin);

    processSkin = {{0, 1},
                   {1, 1},
                   {1, 0}};
    wardrobe.push_back(processSkin);
    maxSkinPos = wardrobe.size() - 1;
}

ISprite* Z_Sprite::getInstance()
{
    if (object == nullptr)
    {
        object = new Z_Sprite();
    }
    return object;
}

S_Sprite::S_Sprite() 
{
    createBody();
}

void S_Sprite::createBody()
{
        
    posX = 2.0;
    posY = 0.0; 
    currentSkinPos = 0; 
    currentSkin = nullptr;

    spriteSpace processSkin =  {{0, 1, 1},
                                {1, 1, 0}} ;

    wardrobe.push_back(processSkin);


    processSkin = {{1, 0},
                   {1, 1},
                   {0, 1}};
    wardrobe.push_back(processSkin);
    maxSkinPos = wardrobe.size() - 1;
}


ISprite* S_Sprite::getInstance()
{
    if (object == nullptr)
    {
        object = new S_Sprite();
    }
    return object;
}



