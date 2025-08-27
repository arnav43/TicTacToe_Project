#include "Board.h"
#include <iostream>

using std::cout;
using std::endl;

Board::Board()
{
    reset();
}

Board::Board(const Board &other)
{
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            cells[i][j] = other.cells[i][j];
}

Board &Board::operator=(const Board &other)
{
    if (this != &other)
    {
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++)
                cells[i][j] = other.cells[i][j];
    }
    return *this;
}

void Board::reset()
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cells[i][j] = '.';
        }
    }
}

void Board::drawboard() const
{
    cout << "-------TIC----TAC----TOE-------" << endl;
    for (int i = 0; i < 3; i++)
    {
        cout << "| ";
        for (int j = 0; j < 3; j++)
        {
            cout << cells[i][j] << " ";
        }
        cout << endl
             << "-------------" << endl;
    }
    cout << "-------Made-by-Arnav-------" << endl;
}

bool Board::isValidMove(int row, int col) const
{
    return row >= 0 && row < 3 && col >= 0 && col < 3 && cells[row][col] == '.';
}

void Board::makeMove(int row, int col, char symbol)
{
    if (isValidMove(row, col))
        cells[row][col] = symbol;
}

bool Board::checkWin(char symbol) const
{
    for (int i = 0; i < 3; i++)
    {
        if (cells[i][0] == symbol && cells[i][1] == symbol && cells[i][2] == symbol)
            return true;
        if (cells[0][i] == symbol && cells[1][i] == symbol && cells[2][i] == symbol)
            return true;
    }
    if (cells[0][0] == symbol && cells[1][1] == symbol && cells[2][2] == symbol)
        return true;
    if (cells[0][2] == symbol && cells[1][1] == symbol && cells[2][0] == symbol)
        return true;
    return false;
}

bool Board::isFull() const
{
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j)
            if (cells[i][j] == '.')
                return false;
    return true;
}
