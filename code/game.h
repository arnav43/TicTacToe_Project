#ifndef GAME_H
#define GAME_H

#include "board.h"
#include "player.h"

class Game
{
private:
    Board board;
    Player *players[2];
    int currentPlayerIndex;
    bool gameOver;

public:
    Game(Player *player1, Player *player2);
    ~Game();

    void play();
    void switchTurn();
    bool isGameOver() const;
    Player *getWinner() const;
    void displayResult() const;
};

#endif // GAME_H