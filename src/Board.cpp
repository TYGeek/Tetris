#include "Board.h"
#include <iostream>


boardSpace Board::render_logic(boardSpace const& board, ISprite const& sprite)
{
    eventHandler(board, sprite);

    if (isIntersection(board, sprite))
    {
        insertSprite(board, sprite);
        board = destroyLine(board);
        render(board);
        return board;
    }
    else
    {
        boardSpace buffer_board = board;

        insertSprite(buffer_board, sprite);
        render(buffer_board);
        return render_logic(board, sprite);
    }

};


//  ---------------------- Insert Sprite into Board -------------------------
bool Board::isIntersection(const boardSpace& board, ISprite const& sprite)
{
    auto spriteBody = sprite.getBody();
    for (size_t colm = 0, spriteSize = spriteBody.size(); colm < spriteSize; colm++)
    {
        if (spriteBody.at(spriteBody.size()-1 ).at(colm) == 1 )
        {
            if ( board.at(sprite.posY + spriteBody.size()).at(sprite.posX + colm) == 1 )
            {
                return true;
            }
        }
    }
    return false;
};

int Board::getDeadLine(const boardSpace& board)
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

void Board::insertSprite(boardSpace& board, ISprite const& sprite)
{
    auto spriteBody = sprite.getBody();

    for (int row = 0, rows = spriteBody.size(); row < rows; ++row)
        for (int colm = 0, colms = spriteBody.size(); colm < colms; ++colm)
            board.at(sprite.posY + row).at(sprite.posX + colm) = spriteBody.at(row).at(colm);

};

void Board::render(const boardSpace& board)
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


bool Board::allowMoveLeft(const boardSpace& board, ISprite const& sprite)
{
    auto spriteBody = sprite.getBody();
    int posY = static_cast<int>(sprite.posY);
    int posX = static_cast<int>(sprite.posX);

    for (size_t row = 0, rows = spriteBody.size(); row < rows; row++)
    {
        // check move left
        if (spriteBody.at(row).at(0) == 1)
        {
            if (board.at(posY + row).at(posX - 1) == 1)
            {
                return false;
            }
        }
    }
    return true;
}

bool Board::allowMoveRight(const boardSpace& board, ISprite const& sprite)
{
    auto spriteBody = sprite.getBody();
    int posY = static_cast<int>(sprite.posY);
    int posX = static_cast<int>(sprite.posX);

    for (size_t row = 0, rows = spriteBody.size(); row < rows; row++)
    {
        // check move left
        if (spriteBody.at(row).at(spriteBody.size()-1) == 1)
        {
            if (board.at(posY + row).at(posX + spriteBody.size()) == 1)
            {
                return false;
            }
        }
    }
    return true;
}


void Board::eventHandler(boardSpace const& board, ISprite const& sprite)
{

    sprite.posY += dY * dt;

    if (_kbhit())
    {
        switch (getch())
        {
        // Right event handler
        case(77):
            if ( allowMoveRight(board, sprite) )
                sprite.posX += dX * dt;
            break;

        // Left event handler
        case(75):
            if( allowMoveLeft( board, sprite) )
                sprite.posX -= dX * dt;
            break;

            // Down event handler
        case(80):
            sprite.posY += dY*10 * dt;
            break;

            // Escape event handler
        case(27):
            // std::cout << "escape" << std::endl;  
            break;

            // Space event handler
        case(32):
            sprite.rotate();
            break;
        }
    }
 
}


boardSpace Board::destroyLine(boardSpace board)
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

Board::Board(float dX, float dY, float dt) :dX{ dX }, dY{ dY }, dt{ dt } {};

Board* Board::getInstance()
{
    if (body == nullptr)
    {
        body = new Board(100, 10, 0.01);
    }

    return body;
        
}


