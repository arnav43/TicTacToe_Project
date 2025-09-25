#include "AIPlayer.h"
#include <iostream>
#include <limits>
#include <vector>
#include <cstdlib>
#include <ctime>

// Helper to get opponent's symbol
static char opponent(char symbol)
{
    return (symbol == 'X') ? 'O' : 'X';
}

AIPlayer::AIPlayer(const std::string &name, char symbol) : Player(name, symbol)
{
    std::srand((unsigned)std::time(nullptr)); // Seed random for potential random moves
}

void AIPlayer::makeMove(Board &board)
{
    std::vector<std::pair<int, int>> legalMoves;
    for (int row = 0; row < 3; ++row)
    {
        for (int col = 0; col < 3; ++col)
        {
            if (board.isValidMove(row, col))
                legalMoves.push_back({row, col});
        }
    }

    if (legalMoves.empty())
        return; // No moves possible (should rarely happen if game checks properly)

    // For harder difficulty: use minimax to find best move
    int bestScore = std::numeric_limits<int>::min();
    std::pair<int, int> bestMove = legalMoves[0];

    for (auto &move : legalMoves)
    {
        Board boardCopy = board; // Copy the board
        boardCopy.makeMove(move.first, move.second, getSymbol());
        int score = minimax(boardCopy, false, std::numeric_limits<int>::min(), std::numeric_limits<int>::max());
        if (score > bestScore)
        {
            bestScore = score;
            bestMove = move;
        }
    }

    // Make the best move found
    board.makeMove(bestMove.first, bestMove.second, getSymbol());
    std::cout << getName() << " (" << getSymbol() << ") played at (" << bestMove.first << ", " << bestMove.second << ")\n";
}

int AIPlayer::minimax(Board board, bool isMaximizing, int alpha, int beta)
{
    char aiSymbol = getSymbol();
    char oppSymbol = opponent(aiSymbol);

    if (board.checkWin(aiSymbol))
        return 10; // AI win
    if (board.checkWin(oppSymbol))
        return -10; // Opponent win
    if (board.isFull())
        return 0; // Draw

    if (isMaximizing)
    {
        int maxEval = std::numeric_limits<int>::min();
        for (int row = 0; row < 3; ++row)
        {
            for (int col = 0; col < 3; ++col)
            {
                if (board.isValidMove(row, col))
                {
                    char prev = board.getCell(row, col);
                    board.setCell(row, col, aiSymbol);
                    int eval = minimax(board, false, alpha, beta);
                    board.setCell(row, col, prev); // Undo
                    maxEval = std::max(maxEval, eval);
                    alpha = std::max(alpha, eval);
                    if (beta <= alpha)
                        break; // Beta cut-off
                }
            }
        }
        return maxEval;
    }
    else // Minimizing
    {
        int minEval = std::numeric_limits<int>::max();
        for (int row = 0; row < 3; ++row)
        {
            for (int col = 0; col < 3; ++col)
            {
                if (board.isValidMove(row, col))
                {
                    char prev = board.getCell(row, col); // ✅ Save state
                    board.setCell(row, col, oppSymbol);  // ✅ Make move
                    int eval = minimax(board, true, alpha, beta);
                    board.setCell(row, col, prev); // ✅ Restore state
                    minEval = std::min(minEval, eval);
                    beta = std::min(beta, eval);
                    if (beta <= alpha)
                        break;
                }
            }
        }
        return minEval;
    }
}
