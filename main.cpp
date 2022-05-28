#include "Board.h"
#include "Pieces.h"
#include <iostream>


int main()
{

    ISprite* sprite = createSprite();
    Board* board = Board::getInstance();

    bool endGame { false };
    size_t deadLine { board->boardBody.size() - 1 };

    while (!endGame)
    {
        board->boardBody = board->render_logic( board->boardBody, *sprite );
        deadLine = board->getDeadLine( board->boardBody );
        if (deadLine == 0)
        {
            endGame = true;
            deleteSprites();
            sprite = nullptr;
            delete board;
        }
        else
        {
            sprite = createSprite();
        }
    }


    return 0;
}
