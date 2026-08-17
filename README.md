# Tic-Tac-Toe (C Console Game)

**Group Number:** 2

**Group Members:**
1. Sajir Rashdi Karim
2. Irfan Sadik Ahmed
3. Md. Mahfuz Hayder Dilshad
4. Ishteaque Ahnaf

## Overview
A classic two-player Tic-Tac-Toe game implemented in C, playable directly in the console/terminal. Players take turns placing their marker  (`X` or `O`) on a numbered 1–9 grid until one player wins or the board fills up in a draw.

## Features
- Simple, clear 3x3 board rendered using slot numbers (1–9) for easy input
- Turn-based two-player gameplay (Player 1 = X, Player 2 = O)
- Input validation (rejects non-numeric input, out-of-range slots, and already-taken slots)
- Win detection across all rows, columns, and both diagonals
- Draw detection when the board is full with no winner
- Screen is cleared before each turn for a clean, updated board view

## How to Play
1. Compile and run the program (see instructions below).
2. Player 1 (`X`) goes first, followed by Player 2 (`O`).
3. On your turn, enter a number from 1–9 corresponding to the slot you want to mark, based on the board layout below:

```
  1  |  2  |  3
_____|_____|_____
  4  |  5  |  6
_____|_____|_____
  7  |  8  |  9
```

4. The game continues until a player gets three of their markers in a row (horizontally, vertically, or diagonally), or the board fills up, resulting in a tie.

## How to Compile & Run

### Windows
```
gcc main.c -o tictactoe.exe
tictactoe.exe
```

### Linux / macOS
Note: this program uses `system("cls")` to clear the screen, which is a Windows-specific command. On Linux/macOS, replace `cls` with `clear` in `main.c` before compiling, or the screen simply won't clear between turns (the game will still function correctly otherwise).
```
gcc main.c -o tictactoe
./tictactoe
```

## Project Structure
```
.
├── main.c              # Main game source code
├── README.md           # Project documentation (this file)
├── requirements.txt    # Tools/compiler requirements
├── data/                # No datasets used in this project
├── support/             # No additional support code files
└── others/              # Presentation and report files
```

## Requirements
See `requirements.txt` for compiler requirements.
