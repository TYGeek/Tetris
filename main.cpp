#include <iostream>

#include <curses.h>
#include "Pieces.h"

void create_board(std::vector<std::vector<int>>& board, int height, int width)
{
    for(int row = 0; row < height; ++row) {
        for (int colm = 0; colm < width; ++colm)
        {
            if(row == 0 || row == height - 1)
            {
                board.at(row).push_back(1);
            }
        }
        board.emplace_back(std::vector<int>());

    }
}

int main()
{
//    char users_name[ 100 ];
//
//    initscr();
//    (void)echo();
//
//    addstr( "What is your name> " );
//    refresh();
//    getnstr( users_name, sizeof( users_name ) - 1 );
//
//    /* Here is where we clear the screen.                  */
//    /* (Remember, when using Curses, no change will appear */
//    /* on the screen until <b>refresh</b>() is called.     */
//    clear();
//
//    printw( "Greetings and salutations %s!\n", users_name );
//    refresh();
//
//    printw( "\n\n\nPress ENTER to quit." );
//    refresh();
//    getnstr( users_name, sizeof( users_name ) - 1 );
//
//    endwin();
    //FigureGenerator generator;
    //const IPieces* obj = generator.createPiece();
    int height{10};
    int width{10};
    std::vector<std::vector<int>> board;




    return 0;
}