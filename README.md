🎮 Tic Tac Toe Game using SDL
Welcome to Tic Tac Toe, a classic two-player game with a modern twist brought to life using C++ and the SDL2 library! 🚀

🪄 Features
✨ Interactive Gameplay: Play against a friend in a beautifully rendered graphical interface.
✨ Simple & Fun: Classic 3x3 board layout, perfect for quick matches.
✨ Smart Logic: Automatically detects winners or draws.
✨ Minimal Design: Clean, distraction-free UI for a seamless experience.

⚙️ Requirements
Make sure you have the following before starting:
✅ SDL2 Library installed on your system.
✅ A C++ Compiler supporting C++11 or later.

🛠️ Setup Instructions
Follow these steps to get started:

Clone this repository:

bash
Copy code
git clone https://github.com/sachin2288/tic-tat-toe---c.git
cd tic-tat-toe---c
Install SDL2:

Ubuntu/Debian:
bash
Copy code
sudo apt update
sudo apt install libsdl2-dev
macOS:
bash
Copy code
brew install sdl2
Windows: Download the SDL2 development libraries from the SDL2 website.
Compile the code:

bash
Copy code
g++ -o tic_tac_toe tictactoe.cpp -lSDL2 -lSDL2main
Run the game:

bash
Copy code
./tic_tac_toe
🎮 How to Play
The game begins with an empty 3x3 grid.
Players take turns clicking on the board to place their mark (X or O).
Win the game by aligning three marks in:
A row
A column
A diagonal
The game ends in a draw if the board is full and no player has won.
🧩 Code Highlights
Here's what makes this game tick:

initSDL: Sets up the SDL window and renderer.
drawBoard: Dynamically draws the board and player moves.
gameOver: Detects if a player has won or if the game is a draw.
handleEvent: Processes player inputs like mouse clicks.
closeSDL: Cleans up SDL resources to ensure a graceful exit.
📸 Screenshots
Add screenshots of the game interface here for a better showcase!

🤝 Contributions
We love contributions!
🛠️ Found a bug? Open an issue.
🎨 Have an idea for improvement? Submit a pull request.

📜 License
This project is licensed under the MIT License. Feel free to use, modify, and distribute it as per the license terms. See the LICENSE file for details.

🌟 Acknowledgments
SDL2 Library: For making graphics programming intuitive.
Inspiration: The timeless charm of the classic Tic Tac Toe game.
