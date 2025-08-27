#ifndef BOARD_H
#define BOARD_H

class Board
{
private:
    char cells[3][3];

public:
    Board();
    Board(const Board &other);
    Board &operator=(const Board &other);

    void drawboard() const;
    bool isValidMove(int row, int col) const;
    void makeMove(int row, int col, char symbol);
    bool checkWin(char symbol) const;
    bool isFull() const;
    void reset();
};

#endif // BOARD_H
