#include "Player.h"

// Using initializer lists (better in practice)
// Player::Player(const std::string &name, char symbol)
//     : name(name), symbol(symbol) {}

// good ol constructor
Player::Player(const std::string &name, char symbol)
{
    this->name = name;
    this->symbol = symbol;
}