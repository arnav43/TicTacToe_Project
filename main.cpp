#include <iostream>
#include "Game.h"
#include "HumanPlayer.h"
#include "AIPlayer.h"

int main()
{
    std::cout << "Welcome to Tic-Tac-Toe!\n";

    std::string playerName;
    std::cout << "Enter your name: ";
    std::getline(std::cin, playerName);

    HumanPlayer *human = new HumanPlayer(playerName, 'X');
    AIPlayer *ai = new AIPlayer("Computer", 'O');

    Game game(human, ai);
    game.play();
    game.displayResult();

    return 0;
}
