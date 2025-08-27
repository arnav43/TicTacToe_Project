#include "humanplayer.h"
#include <iostream>

HumanPlayer::HumanPlayer(const std::string &name, char symbol) : Player(name, symbol) {}

void HumanPlayer::makeMove(Board &board)
{
    int row, col;
    do
    {
        std::cout << getName() << " (" << getSymbol() << ") - Enter your move (row and column: 0, 1, or 2): ";
        std::cin >> row >> col;

        if (!board.isValidMove(row, col))
        {
            std::cout << "Invalid move, please try again.\n";
        }
    } while (!board.isValidMove(row, col));

    board.makeMove(row, col, getSymbol());
}
