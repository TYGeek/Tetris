
#ifndef TETRIS_PIECES_H
#define TETRIS_PIECES_H

#include <iostream>
#include "array"
#include "vector"
using spriteSpace = std::vector<std::vector<int>>;
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
    S_element,
    END
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

    //ISprite() = delete;
    //ISprite(ISprite const&) = delete;
    //ISprite& operator=(ISprite const&) = delete;
   
    virtual const spriteSpace& getNextSkin() const;
    virtual spriteSpace& getBody() const; // get current skin
    virtual void rotate();                // rotate current skin 
    
    virtual ~ISprite() { std::cout << "delete Sprite" << std::endl; };

protected:
    virtual void createBody() = 0;

protected:
    skinsCollection wardrobe;
    spriteSpace* currentSkin;
    int currentSkinPos;
    int maxSkinPos;

private:
    friend ISprite* createSprite();

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
   
protected:
    void createBody() override;
};




struct I_Sprite: ISprite
{
    
    I_Sprite(const I_Sprite&) = delete;
    I_Sprite& operator=(const I_Sprite&) = delete;
    static ISprite* getInstance();
    ~I_Sprite() override = default;

private:  
    static ISprite* object;
    I_Sprite();

protected:
    void createBody() override;
};




struct J_Sprite: ISprite
{
    J_Sprite(const J_Sprite&) = delete;
    J_Sprite& operator=(const J_Sprite&) = delete;
    static ISprite* getInstance();
    ~J_Sprite() override = default;

protected:
    void createBody() override;

private:
    static ISprite* object;
    J_Sprite();
};




struct O_Sprite: ISprite
{
    O_Sprite(const O_Sprite&) = delete;
    O_Sprite& operator=(const O_Sprite&) = delete;
    ~O_Sprite() override = default;
    static ISprite* getInstance();
private:
    static ISprite* object;
    O_Sprite();
protected:
    void createBody() override;
};




struct T_Sprite: ISprite
{
    T_Sprite(const T_Sprite&) = delete;
    T_Sprite& operator=(const T_Sprite&) = delete;
    ~T_Sprite() override = default;
     static ISprite* getInstance();
private:
    static ISprite* object;
    T_Sprite();
protected:
    void createBody() override;
    
};



struct Z_Sprite: ISprite
{
    Z_Sprite(const Z_Sprite&) = delete;
    Z_Sprite& operator=(const Z_Sprite&) = delete;
    ~Z_Sprite() override = default;
    static ISprite* getInstance();
private:
    static ISprite* object;
    Z_Sprite();
protected:
    void createBody() override;
};


struct S_Sprite: ISprite
{
    S_Sprite(const S_Sprite&) = delete;
    S_Sprite& operator=(const S_Sprite&) = delete;
    ~S_Sprite() override = default;
    static ISprite* getInstance();
private:
    static ISprite* object;
    S_Sprite();
protected:
    void createBody() override;
};




ISprite* createSprite(); // random sprite
void deleteSprites();


#endif //TETRIS_PIECES_H
