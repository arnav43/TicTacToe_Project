#include "game.h"
#include <iostream>

Game::Game(Player *player1, Player *player2)
    : currentPlayerIndex(0), gameOver(false)
{
    players[0] = player1;
    players[1] = player2;
    board.reset();
}

Game::~Game()
{
    delete players[0];
    delete players[1];
}

void Game::play()
{
    while (!gameOver)
    {
        board.drawboard();
        players[currentPlayerIndex]->makeMove(board);

        if (board.checkWin(players[currentPlayerIndex]->getSymbol()))
        {
            board.drawboard();
            std::cout << players[currentPlayerIndex]->getName() << " wins!\n";
            gameOver = true;
        }
        else if (board.isFull())
        {
            board.drawboard();
            std::cout << "It's a draw!\n";
            gameOver = true;
        }
        else
        {
            switchTurn();
        }
    }
}

void Game::switchTurn()
{
    currentPlayerIndex = 1 - currentPlayerIndex;
}

bool Game::isGameOver() const
{
    return gameOver;
}

Player *Game::getWinner() const
{
    if (gameOver && board.checkWin(players[currentPlayerIndex]->getSymbol()))
    {
        return players[currentPlayerIndex];
    }
    return nullptr;
}

void Game::displayResult() const
{
    if (gameOver)
    {
        Player *winner = getWinner();
        if (winner)
        {
            std::cout << "Winner: " << winner->getName() << std::endl;
        }
        else
        {
            std::cout << "Game ended in a draw." << std::endl;
        }
    }
    else
    {
        std::cout << "Game is still ongoing." << std::endl;
    }
}
