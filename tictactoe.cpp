#include <SDL.h>
#include <iostream>
#include <vector>

using namespace std;

const int WINDOW_WIDTH = 300;
const int WINDOW_HEIGHT = 300;

const int BOARD_SIZE = 3;
const int CELL_SIZE = WINDOW_WIDTH / BOARD_SIZE;

SDL_Window* window = nullptr;
SDL_Renderer* renderer = nullptr;

vector<vector<char>> board(BOARD_SIZE, vector<char>(BOARD_SIZE, '-'));

// Function to initialize SDL
bool initSDL() {
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        cout << "SDL could not initialize! SDL Error: " << SDL_GetError() << endl;
        return false;
    }
    window = SDL_CreateWindow("Tic Tac Toe", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_SHOWN);
    if (window == nullptr) {
        cout << "Window could not be created! SDL Error: " << SDL_GetError() << endl;
        return false;
    }
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (renderer == nullptr) {
        cout << "Renderer could not be created! SDL Error: " << SDL_GetError() << endl;
        return false;
    }
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderClear(renderer);
    return true;
}

// Function to close SDL
void closeSDL() {
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

// Function to draw the Tic Tac Toe board
void drawBoard() {
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    for (int i = 1; i < BOARD_SIZE; ++i) {
        SDL_RenderDrawLine(renderer, i * CELL_SIZE, 0, i * CELL_SIZE, WINDOW_HEIGHT);
        SDL_RenderDrawLine(renderer, 0, i * CELL_SIZE, WINDOW_WIDTH, i * CELL_SIZE);
    }
    for (int i = 0; i < BOARD_SIZE; ++i) {
        for (int j = 0; j < BOARD_SIZE; ++j) {
            if (board[i][j] == 'X') {
                SDL_RenderDrawLine(renderer, j * CELL_SIZE + 10, i * CELL_SIZE + 10, (j + 1) * CELL_SIZE - 10, (i + 1) * CELL_SIZE - 10);
                SDL_RenderDrawLine(renderer, (j + 1) * CELL_SIZE - 10, i * CELL_SIZE + 10, j * CELL_SIZE + 10, (i + 1) * CELL_SIZE - 10);
            } else if (board[i][j] == 'O') {
                int centerX = j * CELL_SIZE + CELL_SIZE / 2;
                int centerY = i * CELL_SIZE + CELL_SIZE / 2;
                int radius = CELL_SIZE / 2 - 10;
                for (int k = 0; k <= 360; k += 10) {
                    float angle = k * 3.14159 / 180;
                    int x = centerX + radius * cos(angle);
                    int y = centerY + radius * sin(angle);
                    SDL_RenderDrawPoint(renderer, x, y);
                }
            }
        }
    }
    SDL_RenderPresent(renderer);
}

// Function to check if the game is over
bool gameOver() {
    // Check rows
    for (int i = 0; i < BOARD_SIZE; ++i) {
        if (board[i][0] != '-' && board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
            return true;
        }
    }
    // Check columns
    for (int j = 0; j < BOARD_SIZE; ++j) {
        if (board[0][j] != '-' && board[0][j] == board[1][j] && board[1][j] == board[2][j]) {
            return true;
        }
    }
    // Check diagonals
    if (board[0][0] != '-' && board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
        return true;
    }
    if (board[0][2] != '-' && board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
        return true;
    }
    // Check if the board is full
    for (int i = 0; i < BOARD_SIZE; ++i) {
        for (int j = 0; j < BOARD_SIZE; ++j) {
            if (board[i][j] == '-') {
                return false;
            }
        }
    }
    return true;
}

// Function to handle player's move
void handleEvent(SDL_Event& event, char currentPlayer) {
    if (event.type == SDL_MOUSEBUTTONDOWN && !gameOver()) {
        int mouseX, mouseY;
        SDL_GetMouseState(&mouseX, &mouseY);
        int row = mouseY / CELL_SIZE;
        int col = mouseX / CELL_SIZE;
        if (board[row][col] == '-') {
            board[row][col] = currentPlayer;
        }
    }
}

int main(int argc, char* argv[]) {
    if (!initSDL()) {
        return 1;
    }

    bool quit = false;
    char currentPlayer = 'X';

    while (!quit) {
        SDL_Event event;
        while (SDL_PollEvent(&event) != 0) {
            if (event.type == SDL_QUIT) {
                quit = true;
            }
            handleEvent(event, currentPlayer);
        }

        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
        SDL_RenderClear(renderer);

        drawBoard();

        if (gameOver()) {
            cout << "Game over!" << endl;
            break;
        }

        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';

        SDL_Delay(10);
    }

    closeSDL();

    return 0;
}
