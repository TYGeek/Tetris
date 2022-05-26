#include <array>
#include <iostream>
#include<Windows.h>


/*

    Sprite / Board
|-------------- x+  
|0                  
|1   1
|0
|
y+

    #
    #
    ###
      #
      #

*/

/*
    00000000
    00002200 --> posXY
    00000200 --> posXY + sprite.size();
    11111111

    0000
    0000
    1100
    0011

*/


using boardSpace = std::array<std::array<int, 5>, 5>;
using spriteSpace = std::array<std::array<int, 2>, 2>;


//  ---------------------- Insert Sprite into Board -------------------------
bool isIntersection(const boardSpace& board, const spriteSpace& sprite, int posY, int posX)
{
    for (size_t colm = 0, spriteSize = sprite.size(); colm < spriteSize; colm++)
    {
        if ( sprite.at(sprite.size()-1 ).at(colm) == 1 )
        {
            if ( board.at(posY + sprite.size()).at(posX + colm) == 1 )
            {
                return true;
            }
        }
    }
    return false;
};

int getDeadLine(const boardSpace& board)
{
    for (int row = 0, rows = board.size(); row < rows; ++row)
    {
        for (int colm = 0, colms = board.at(0).size(); colm < colms; ++colm)
        {
            if (board.at(row).at(colm) == 1)
            {
                return row;
            }
        }
    }
};

void insertSprite(boardSpace& board, spriteSpace sprite, int posY, int posX)
{
    for (int row = 0, rows = sprite.size(); row < rows; ++row)
        for (int colm = 0, colms = sprite.size(); colm < colms; ++colm)
            board.at(posY + row).at(posX + colm) = sprite.at(row).at(colm);
};

void render(const boardSpace& board)
{
    system("cls");
    Sleep(1);

    for (int row = 0, boardSize = board.size(); row < boardSize; row++)
    {
        for (int colm = 0, colmSize = board.at(0).size(); colm < colmSize; colm++)
        {
            if (board.at(row).at(colm) == 1)
                std::cout << "#";
            else
                std::cout << " ";
        }
        std::cout << std::endl;
    }

}

boardSpace render_logic(boardSpace& board, spriteSpace const& sprite, int posY, int posX)
{

    if (isIntersection(board, sprite, posY, posX))
    {

        insertSprite(board, sprite, posY, posX);
        render(board);
        return board;
    }
    else
    {
        boardSpace buffer_board = board;
        insertSprite(buffer_board, sprite, posY, posX);
        render(buffer_board);
        ++posY;
        return render_logic(board, sprite, posY, posX);
    }

};



int main()
{
    boardSpace board = { { {0, 0, 0, 0, 0},
                           {0, 0, 0, 0, 0},
                           {0, 0, 0, 0, 0},
                           {0, 0, 0, 0, 0},
                           {1, 1, 1, 1, 1} } };
    
    spriteSpace sprite = { { {0, 1},
                             {1, 1} } };

    size_t posY = 0;   //счетчик положения обьекта
    bool endGame{ false };
    size_t deadLine{ board.size() - 1 };


    while (!endGame)
    {
        board = render_logic(board, sprite, 0, 1);
        deadLine = getDeadLine(board);
        if (deadLine == 0)
        {
            endGame = true;
        }

        
    }
    return 0;
}


/*

0010    0000    0010
0110 -> 0010 -> 0110
0000    0110    0110
1111    1111    1111



*/