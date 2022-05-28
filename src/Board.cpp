#include "Board.h"
#include "Pieces.h"

#include <iostream>
#include <Windows.h>
#include <conio.h>


Board* Board::body = nullptr;

Board::Board(float dX, float dY, float dt) :dX{ dX }, dY{ dY }, dt{ dt }
{
    createBoard();
};

boardSpace Board::render_logic(boardSpace& board, ISprite const& sprite)
{
    eventHandler(board, const_cast<ISprite&>(sprite));

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

void Board::createBoard(int rows, int colms)
{
    for(int row = 0; row < rows;row++)
    {
        for (int colm = 0; colm < colms; colm++)
        {
            if (row == rows - 1)
                boardBody.at(row).at(colm) = 1;
            else if (colm == 0 || colm == colms - 1)
                boardBody.at(row).at(colm) = 1;
            else
                boardBody.at(row).at(colm) = 0;
        }
    }
}


//  ---------------------- Insert Sprite into Board -------------------------
bool Board::isIntersection( boardSpace const& board, ISprite const& sprite)
{
    spriteSpace const& spriteBody = sprite.getBody();
    int spriteRows = spriteBody.size();
    int spriteColums = spriteBody.at(0).size();

    for (size_t colm = 0, spriteSize = spriteColums; colm < spriteSize; colm++)
    {
        if (spriteBody.at(spriteRows - 1 ).at(colm) == 1 )
        {
            if ( board.at(sprite.posY + spriteRows).at(sprite.posX + colm) == 1 )
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
}


void Board::insertSprite(boardSpace& board, ISprite const& sprite)
{
    spriteSpace const& spriteBody = sprite.getBody();
    int spriteRows = spriteBody.size();
    int spriteColums = spriteBody.at(0).size();

    for (int row = 0, rows = spriteRows; row < rows; ++row)
        for (int colm = 0, colms = spriteColums; colm < colms; ++colm)
            if( spriteBody.at(row).at(colm) == 1 )
                board.at(sprite.posY + row).at(sprite.posX + colm) = 1;

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
    spriteSpace const& spriteBody = sprite.getBody();
    int spriteRows = spriteBody.size();
    int spriteColums = spriteBody.at(0).size();

    int posY = static_cast<int>(sprite.posY);
    int posX = static_cast<int>(sprite.posX);

    for (size_t row = 0, rows = spriteRows; row < rows; row++)
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
    spriteSpace const& spriteBody = sprite.getBody();
    int spriteRows = spriteBody.size();
    int spriteColums = spriteBody.at(0).size();

    int posY = static_cast<int>(sprite.posY);
    int posX = static_cast<int>(sprite.posX);

    for (size_t row = 0, rows = spriteRows; row < rows; row++)
    {
        // check move right
        if (spriteBody.at(row).at(spriteColums - 1) == 1)
        {
            if (board.at(posY + row).at(posX + spriteColums) == 1)
            {
                return false;
            }
        }
    }
    return true;
}


bool Board::allowRotate(const boardSpace& board, ISprite const & sprite)
{
    spriteSpace const& curSprite = sprite.getBody();
    int curSpriteRows = curSprite.size();
    int curSpriteColums = curSprite.at(0).size();

    spriteSpace const& nextSprite = sprite.getNextSkin();
    int nextSpriteRows = nextSprite.size();
    int nextSpriteColums = nextSprite.at(0).size();

    int checkSquare = (curSpriteRows > nextSpriteRows) ? curSpriteRows : nextSpriteRows;

    int posY = static_cast<int>(sprite.posY);
    int posX = static_cast<int>(sprite.posX);

    // check if new sprite don't cross boards
    if (board.size() < nextSpriteRows + posY || board.at(0).size() < nextSpriteColums + posX)
        return false;

    // check if old sprite between rotation don't cross another element
    for (size_t row = 0, rows = checkSquare; row < rows; row++)
    {
        for (size_t colm = 0, colms = checkSquare; colm < colms; colm++)
        {
            if (board.at(posY + row).at(posX + colm) == 1)
            {
                return false;
            }
        }
    }

    return true;
}


void Board::eventHandler(boardSpace const& board, ISprite& sprite)
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
            if(allowRotate(board, sprite))
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
        for (size_t colm = 1, colms = board.at(0).size() - 1; colm < colms; colm++)
        {
            if (board.at(row).at(colm) == 0)
            {
                fullRow = false;
                break;
            }
        }

        if (fullRow)
        {
            for (size_t colm = 1, colms = board.at(0).size() - 1; colm < colms; colm++)
                board.at(row).at(colm) = 0;

            for (size_t cur_row = row, zero_row = 0; cur_row > zero_row; cur_row--)
                board.at(cur_row).swap(board.at(cur_row - 1));

        }
        else { fullRow = true; }
    }

    return board;
}


Board* Board::getInstance()
{
    if (body == nullptr)
    {
        body = new Board(100, 10, 0.01);
    }

    return body;
        
}


Board::~Board()
{
    { std::cout << "delete board" << std::endl; }
}
