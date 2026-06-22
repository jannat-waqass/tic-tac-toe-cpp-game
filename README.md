# Tic Tac Toe Game in C++

## Overview

This project is a console-based implementation of the classic Tic Tac Toe game developed in C++.

The application supports two gameplay modes:

* Human vs Human
* Human vs Computer

The project was developed as part of the CSCI 112 programming course at the American University of Ras Al Khaimah (AURAK).

---

## Project Objective

The objective of this project was to apply fundamental programming concepts learned during the first year of university, including:

* Functions
* Arrays
* Loops
* Conditional Statements
* User Input Validation
* Game Logic Development

The game allows players to compete against each other or against a computer opponent while maintaining score across multiple rounds.

---

## Features

### Human vs Human Mode

* Two-player gameplay
* Turn-based moves
* Win detection
* Tie detection
* Best-of-three scoring system

### Human vs Computer Mode

* Randomized computer moves
* Score tracking
* Input validation
* Multiple game rounds

### Additional Features

* Board reset after each round
* Invalid move detection
* Occupied cell validation
* Winner announcement
* Running score display

---

## Technologies Used

* C++
* Object-Oriented Programming Concepts
* Console Application Development

---

## Game Rules

1. Players take turns placing X and O marks on a 3×3 grid.
2. The first player to align three marks horizontally, vertically, or diagonally wins the round.
3. The game continues until a player wins three rounds.
4. If all cells are filled without a winning combination, the round ends in a draw.

---

## Program Structure

### Main Functions

| Function                 | Purpose                                       |
| ------------------------ | --------------------------------------------- |
| Display_Board()          | Displays the game board                       |
| HumanvsHuman_check()     | Handles player input                          |
| HumanvsHuman_check_win() | Detects winning conditions                    |
| check_tie()              | Detects tie situations                        |
| board_reset()            | Resets the board                              |
| ComputerChoice()         | Generates computer moves                      |
| playerInput()            | Handles human input in Human vs Computer mode |
| printWinOrDraw()         | Displays game results                         |
| startGame()              | Controls Human vs Computer gameplay           |
| main()                   | Program entry point                           |

---

## Challenges Encountered

During development, several challenges were identified and resolved:

### Array Indexing Errors

Incorrect array indexing caused logical errors when mapping user input to board positions.

### Computer Move Logic

The computer occasionally stopped generating moves after several rounds due to flaws in the game loop structure.

### Win Detection Issues

Specialized functions were introduced to properly evaluate winning conditions for both X and O players.

### Input Validation

Additional validation was implemented to prevent users from selecting invalid or already occupied positions.

---

## Learning Outcomes

Through this project, the team gained practical experience in:

* Problem-solving
* Debugging
* Team collaboration
* Algorithm design
* User input validation
* Game development fundamentals
* C++ programming

---

## Team Members

* Hana Rahiman
* Jannat Waqass
* Rabaa AlShbib
* Sara Barake
* Yasmine Abou Saeb

---

## My Contribution

* Integrated the Human vs Human and Human vs Computer modules into a single application.
* Assisted in developing the Human vs Computer gameplay logic.
* Designed the initial game output structure.
* Participated in debugging and resolving logical errors across both gameplay modes.

---

## Future Improvements

Potential enhancements include:

* Graphical User Interface (GUI)
* Smart AI using Minimax Algorithm
* Difficulty Levels
* Multiplayer Networking
* Improved Object-Oriented Design
* Save and Load Functionality

---

## Course Information

**Course:** CSCI 112 – Programming Fundamentals

**Institution:** American University of Ras Al Khaimah (AURAK)

---

## License

This project was developed for academic and educational purposes.
