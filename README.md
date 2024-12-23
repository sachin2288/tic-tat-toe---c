Tic Tac Toe Game using SDL
This project is a simple implementation of a Tic Tac Toe game built using C++ and the SDL2 library for rendering graphics.

Features
Interactive Tic Tac Toe game with a graphical interface.
Two-player gameplay where players take turns to place X and O.
Game state validation including:
Row, column, and diagonal win detection.
Draw detection when the board is full.
Clean and minimalist game board rendering.
Requirements
SDL2 library installed on your system.
A C++ compiler that supports C++11 or later.
Setup Instructions
Clone the repository:

bash
Copy code
git clone https://github.com/sachin2288/tic-tat-toe---c.git
cd tic-tat-toe---c
Install SDL2:

On Ubuntu/Debian:
bash
Copy code
sudo apt update
sudo apt install libsdl2-dev
On macOS:
bash
Copy code
brew install sdl2
On Windows: Download the SDL2 development libraries from the official SDL website.
Compile the code:

bash
Copy code
g++ -o tic_tac_toe tictactoe.cpp -lSDL2 -lSDL2main
Run the game:

bash
Copy code
./tic_tac_toe
How to Play
The game opens with an empty 3x3 board.
Players take turns clicking on the cells of the grid to place their mark (X or O).
The game ends when:
A player gets three of their marks in a row, column, or diagonal.
All cells are filled with no winner (draw).
Code Overview
Main Functions:

initSDL: Initializes SDL components.
drawBoard: Renders the game board and player moves.
gameOver: Checks the game state for a winner or draw.
handleEvent: Handles player input.
closeSDL: Cleans up SDL resources.
File Structure:

tictactoe.cpp: Contains the entire game logic and SDL2 integration.
Screenshots
Include screenshots of the game interface here if possible.

Contributions
Contributions are welcome! Feel free to open issues or submit pull requests to improve the game or add new features.

License
This project is licensed under the MIT License. See the LICENSE file for details.

Acknowledgments
Thanks to the SDL2 development team for providing an excellent graphics library.
Inspired by classic Tic Tac Toe games.
