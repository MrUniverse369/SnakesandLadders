# Snakes and Ladders Game - C++ Project

## Overview
This project is a console-based implementation of the classic **Snakes and Ladders** board game using C++. The game allows two players to compete, moving across a 10x10 game board, with the goal of reaching the 100th square first. Players must avoid snakes, which bring them down, and aim for ladders, which help them climb up the board faster.

## Features
- **Turn-based gameplay**: Two players alternate turns to roll the dice and move across the board.
- **Snakes and Ladders mechanics**: Land on a snake to slide down, or a ladder to climb up.
- **Dice rolling**: Players roll a dice to move forward, and if they roll a six, they get an extra turn.
- **Input validation**: Ensures that players follow the correct input format.
- **Victory conditions**: The game ends when a player reaches the 100th square.

## How to Play

1. The game starts with both players at the beginning of the board (position 0).
2. Players take turns rolling a dice by pressing 'R' to roll.
3. On each turn:
   - The player rolls a dice, and the result determines how many positions they move forward.
   - If a player lands on a snake's head, they slide down to the snake's tail.
   - If a player lands on the bottom of a ladder, they climb to the top.
   - If a player rolls a six, they get another turn.
4. The first player to reach or exceed position 100 wins the game.

## Game Rules

- **Snakes**: Landing on a snake head moves the player down to the tail.
- **Ladders**: Landing on the base of a ladder moves the player up to the top.
- **Dice Roll**: Players roll a six-sided dice to determine their move.
- **Turn System**: Players take alternate turns, and rolling a six grants an extra turn.
- **Victory Condition**: The first player to reach exactly 100 wins the game. If a player's roll would take them past 100, they bounce back by the excess moves.


## Code Structure

- **main.cpp**: Contains the main game logic and loop, along with function definitions for handling turns, board display, dice rolls, and snakes/ladders.

### Main Functions

- `setup()`: Initializes the game board and prints player instructions.
- `displayBoard()`: Displays the game board and the current position of each player.
- `snakesNLaddders()`: Checks if a player lands on a snake or ladder and updates their position accordingly.
- `PlayerInput()`: Ensures valid input from the player to roll the dice.
- `gameOver()`: Checks if any player has reached or exceeded position 100 to end the game.
- `diceRoll()`: Simulates a dice roll, returning a number between 1 and 6.
- `updateGameInternals()`: Updates the game state after each player's turn, applying snakes/ladders, extra rolls for rolling a six, and switching turns.
