#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include "Board.h"

class Player
{
protected:
    std::string name;
    char symbol;

public:
    Player(const std::string &name, char symbol);
    virtual ~Player() = default;

    std::string getName() const { return name; }
    char getSymbol() const { return symbol; }

    virtual void makeMove(Board &board) = 0;
};

#endif // PLAYER_H
