#ifndef AIPLAYER_H
#define AIPLAYER_H

#include "Player.h"
#include "Board.h"

class AIPlayer : public Player
{
public:
    AIPlayer(const std::string &name, char symbol);

    void makeMove(Board &board) override;

private:
    int minimax(Board board, bool isMaximizing, int alpha, int beta);
};

#endif // AIPLAYER_H
