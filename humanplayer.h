#ifndef HUMANPLAYER_H
#define HUMANPLAYER_H

#include "Player.h"
#include "Board.h"
#include <string>

class HumanPlayer : public Player
{
public:
    HumanPlayer(const std::string &name, char symbol);
    void makeMove(Board &board) override;
};

#endif // HUMANPLAYER_H
