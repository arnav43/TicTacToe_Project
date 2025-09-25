# Tic-Tac-Toe (C++ OOP / Minimax AI)
<img width="372" height="280" alt="image" src="https://github.com/user-attachments/assets/b14ae641-c945-424b-abec-63883a66a5ab" />

## Overview

An object-oriented implementation of the classic Tic-Tac-Toe game in C++, featuring a robust human-vs-AI mode. The AI uses the **Minimax algorithm with alpha-beta pruning** for mathematically perfect play, making it impossible to defeat. This project demonstrates advanced **OOP principles** and algorithmic programming.

---
In other words, a fun project that implements OOP and algorithm integration while guaranteeing you'll never beat the computer :P

---

## Features

- Play against an **unbeatable AI opponent** or a second human player via command line
- AI achieves optimal play using Minimax with alpha-beta pruning - it never loses
- Full input validation and friendly user prompts
- Clean, maintainable OOP code structure following industry standards
- Includes UML class diagram illustrating architecture

---

## UML Class Diagram

<img width="612" height="460" alt="image" src="https://github.com/user-attachments/assets/49cc879b-be78-48c8-9eb4-1f16a97585c8" />

*The diagram above shows clear relationships between classes, demonstrating abstraction, inheritance, and encapsulation.*

---

## Class Architecture

| Class       | Purpose                                                                 |
|-------------|------------------------------------------------------------------------|
| **Game**    | Controls overall gameplay, win/draw detection, player turns, final output |
| **Board**   | Manages game grid, validating moves, drawing board, win/draw checks      |
| **Player**  | Abstract base class for all players; defines name, symbol, and APIs      |
| **HumanPlayer** | Gets player moves from user input, validates them                    |
| **AIPlayer**    | Uses Minimax to calculate perfect moves - guaranteed never to lose       |

### Relationships

- `Game` "has-a" `Board` and two `Player` objects
- `Player` is extended by `HumanPlayer` and `AIPlayer`
- `AIPlayer` adds minimax logic for unbeatable gameplay

---

## OOP Concepts Used

**Abstraction**:  
The `Player` class abstracts generic player features.

**Encapsulation**:  
Private/protected members in `Board`, `Player`.

**Inheritance**:  
`HumanPlayer` and `AIPlayer` inherit from `Player`.

**Polymorphism**:  
The `makeMove()` function is declared virtual—in the main game loop, calls go through `Player*` pointers, enabling flexible player types.

---

## Minimax Algorithm

**Minimax** is a recursive, adversarial search algorithm that simulates every possible future move to select the one with the best outcome for the AI. The implementation ensures the computer **cannot be defeated** - it will either win or force a draw against any opponent.

**Alpha-beta pruning** optimizes the search by eliminating branches that cannot affect the final decision.

- **Board copies** are used to simulate moves safely in recursion
- **Score**: +10 (AI win), -10 (Human win), 0 (Draw)
- **Perfect play**: The algorithm evaluates all possible game states to guarantee optimal moves

**Pseudocode Example:**
```
int minimax(Board board, bool isMaximizing, int alpha, int beta) {
// Base cases: checkWin or isFull
// If maximizing: try all moves for AI, pick max score, prune with alpha
// If minimizing: try all moves for opponent, pick min score, prune with beta
}
```



---

## How to Run

1. **Clone the repository**
    ```
    git clone https://github.com/yourusername/TicTacToe_Project.git
    cd TicTacToe_Project
    ```

2. **Compile:**
    ```
    g++ code/main.cpp code/game.cpp code/board.cpp code/player.cpp code/humanplayer.cpp code/aiplayer.cpp -o TicTacToe.exe
    ```

3. **Play (and try to beat the unbeatable):**
    ```
    ./TicTacToe.exe
    ```

---

## Technology Stack

- **C++ (OOP, STL)**
- Command-line interface
- Version control: Git & GitHub

---

## Author & Credits

Developed by **Arnav Sinha**  
LinkedIn: [https://www.linkedin.com/in/arnavsinha4334/](https://www.linkedin.com/in/arnavsinha4334/)

---

## Program Output

<img width="815" height="620" alt="image" src="https://github.com/user-attachments/assets/b13e8bb6-9dfe-4547-a306-b962289b4dec" />
