#include <iostream>

#include <curses.h>


int main()
{
    int i = 0;
    bool isGameOver = false;
    while (not isGameOver)
    {
        for (int row = 0; row < 50; ++row)
        {
            for (int colm = 0; colm < 50; ++colm)
            {
                if ( row == 0 || row == 49 ) std::cout << '#';
                else if( colm == 0 || colm == 49 ) std::cout << '#';
                else std::cout << ' ';
            }
            std::cout << std::endl;
        }

        //1.  clear screen
        isGameOver = true;
    }
    return 0;
}