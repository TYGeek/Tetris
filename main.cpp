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


int main()
{
 
    std::array<int, 4> board =  {0, 0, 0, 1};
    std::array<int, 2> sprite = {1, 1};
    size_t posY  = 0;   //счетчик положения обьекта
    bool endGame{ false };
    size_t deadLine{ board.size()-1 };
    bool createNewSprite{ false };

    while( !endGame )
    {

        for(int row = 0; row < board.size(); row++) // cycle from down to up 4
        {
            if( board[row] == 1 ) 
            { 
                std::cout << "#"; 
            };  // draw element from board

            if ( row <= posY )                   // start draw sprite
            {
                int index = posY - row; 
                if( index < sprite.size() )      // check out of array
                {
                    if (sprite[index] == 1) { std::cout << "#"; };    // draw if 1
                    
                    // save sprite on board if next element on board == 1 and cur element in sprite == 1
                    if ( row != board.size()-1 && board[row+1] == sprite[index] && !createNewSprite)
                    {
                        for (int i = 0; i < sprite.size(); i++)
                        {
                            if (row - i < 0) break;
                            board[row-i] = sprite[i];     // save Sprite in board 
                            deadLine--;
                        }

                        createNewSprite = true;    
                    }
                }
            }
            std::cout << std::endl;
        }
        if (deadLine == 0)
        {
            endGame = true;
            break;
        }

        if (createNewSprite)
        {
            system("cls");
            posY = 0;
            createNewSprite = false;
        }
        else
        {
            system("cls");
            Sleep(1);
            ++posY;
        }
        
    }
    return 0;
}