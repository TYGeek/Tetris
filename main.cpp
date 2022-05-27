#include <array>
#include <iostream>
#include <Windows.h>
#include <conio.h>
#include<thread>
#include<chrono>
#include<tuple>


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


using boardSpace = std::array<std::array<int, 10>, 10>;
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
        for (int colm = 1, colms = board.at(0).size()-1; colm < colms; ++colm)
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
    Sleep(100);
    system("cls");
    

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


bool allowMoveLeft(int posX, int posY, const boardSpace& board, const spriteSpace& sprite)
{
    for (size_t row = 0, rows = sprite.size(); row < rows; row++)
    {
        // check move left
        if (sprite.at(row).at(0) == 1)
        {
            if (board.at(posY+row).at(posX - 1) == 1)
            {
                return false;
            }
        }
    }
    return true;
}

bool allowMoveRight(int posX, int posY, const boardSpace& board, const spriteSpace& sprite)
{
    for (size_t row = 0, rows = sprite.size(); row < rows; row++)
    {
        // check move left
        if (sprite.at(row).at(sprite.size()-1) == 1)
        {
            if (board.at(posY+row).at(posX + sprite.size()) == 1)
            {
                return false;
            }
        }
    }
    return true;
}


std::pair<float, float> eventHandler(float posX, float posY, boardSpace const& board, spriteSpace const& sprite)
{
    posY += 10 * 0.01;

    if (_kbhit())
    {
        switch (getch())
        {
            // Right event handler
        case(77):
            if (allowMoveRight(static_cast<int>(posX), static_cast<int>(posY), board, sprite))
                posX += 100 * 0.01;
            break;

            // Left event handler
        case(75):
            if(allowMoveLeft(static_cast<int>(posX), static_cast<int>(posY), board, sprite))
                posX -= 100 * 0.01;
            break;

            // Down event handler
        case(80):
            // std::cout << "down" << std::endl;   
            break;

            // Escape event handler
        case(27):
            // std::cout << "escape" << std::endl;  
            break;

            // Space event handler
        case(32):
            // std::cout << "Space" << std::endl; 
            break;
        }
    }
 
    return std::make_pair(posX, posY);
}


boardSpace destroyLine(boardSpace board)
{
    bool fullRow = true;
    for (size_t row = 0, rows = board.size() - 1; row < rows; row++)
    {
        for (size_t colm = 1, colms = board.size() - 1; colm < colms; colm++)
        {
            if (board.at(row).at(colm) == 0)
            {
                fullRow = false;
                break;
            }
        }

        if (fullRow)
        {
            for (size_t colm = 1, colms = board.size() - 1; colm < colms; colm++)
                board.at(row).at(colm) = 0;

            for (size_t cur_row = row, zero_row = 0; cur_row > zero_row; cur_row--)
                board.at(cur_row).swap(board.at(cur_row - 1));

        }
        else { fullRow = true; }
    }

    return board;
}

boardSpace render_logic(boardSpace& board, spriteSpace const& sprite, float posY, float posX)
{
    auto temp = eventHandler(posX, posY, board, sprite);
    posX = temp.first;
    posY = temp.second;

    if (isIntersection(board, sprite, posY, posX))
    {
        insertSprite(board, sprite, static_cast<int>(posY), static_cast<int>(posX));
        board = destroyLine(board);
        render(board);
        return board;
    }
    else
    {
        boardSpace buffer_board = board;
        
        insertSprite(buffer_board, sprite, static_cast<int>(posY), static_cast<int>(posX));
        render(buffer_board);
        return render_logic(board, sprite, posY, posX);
    }

};




//std::chrono::milliseconds THREAD_WAIT{ 50 };
//
//void GetKeyPress(int posX, int posY, boardSpace const& board, spriteSpace const& sprite)
//{
//    while (1)
//    {
//
//
//        int& buff = const_cast<int&>(posX);
//        // Right event handler
//        if (GetAsyncKeyState(VK_RIGHT))
//        {
//            if (allowMoveRight(&buff, posY, board, sprite))
//                std::cout << "right press" << std::endl;
//            buff++;
//        }
//
//         Left event handler
//        if (GetAsyncKeyState(VK_LEFT))
//        {
//            if (allowMoveLeft(&buff, posY, board, sprite))
//                buff--;
//        }
//
//        if (GetAsyncKeyState(VK_SPACE))
//        {
//            insert handler
//        }
//
//        if (GetAsyncKeyState(VK_ESCAPE))
//        {
//             break;  // Use this only if you have td.join() below
//        }
//
//        std::this_thread::sleep_for(THREAD_WAIT);
//    }
//}



int main()
{


    boardSpace board = { { {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
                           {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
                           {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
                           {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
                           {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
                           {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
                           {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
                           {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
                           {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
                           {1, 1, 1, 1, 1, 1, 1, 1, 1, 1} } };
    
    spriteSpace sprite = { { {1, 1},
                             {1, 1} } };

    float dX = 10;    // pix/s 
    float dY = 1;     // pix/s
    float dt = 0.001; // s
    float posY = 0;   // pix положения обьекта Y
    float posX = 2;   // pix положения обьекта X

    bool endGame { false };
    size_t deadLine { board.size() - 1 };


    while (!endGame)
    {
        board = render_logic(board, sprite, posY, posX);
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