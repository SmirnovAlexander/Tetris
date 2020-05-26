/*
 * Terminal tetris game.
 *
 * MIT License
 *
 * Copyright (c) 2020 Alexander Smirnov
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

#include <ncurses.h>
#include <signal.h>
#include <unistd.h>
#include <vector>
#include "../include/functions.h"
#include "../include/globals.h"

/**
 * Checking if tetromino fits.
 *
 * @param tetrominoIndex Tetromino index to check (0-6).
 * @param r Rotate index, may be
 *   one of the following:
 *   0: 0 degrees,
 *   1: 90 degrees,
 *   2: 180 degrees,
 *   3: 270 degrees.
 * @param posX, posY Coordinates of top left
 *   corner of tetromino.
 * @return if tetromino fits.
 */
bool doesPieceFit(int tetrominoIndex, int r, int posX, int posY) {

    for (int x = 0; x < tetrominoWidth; x++) {
        for (int y = 0; y < tetrominoWidth; y++) {

            // Index of rotated pixel.
            int pi = rotate(x, y, r);

            // Index of pixel in field.
            int fi = ((posY + y) * fieldWidth) + (posX + x);

            if (posX + x >= 0 && posX + x < fieldWidth) {
                if (posY + y >= 0 && posY + y < fieldHeight) {

                    // If tetromino has piece on current pixel
                    // and current pixel on field is not empty
                    // then piece does not fits.
                    if (tetromino[tetrominoIndex][pi] == 'X' &&
                        field[fi] != 0) {
                        return false;
                    }
                }
            }
        }
    }

    return true;
}



/**
 * Printing game field in the center of the screen.
 */
void printScreen(char screen[]) {

    for (int i = 0; i < fieldArea; i++) {
        if (i % (fieldWidth) == 0) {
            mvaddch(i / (fieldWidth) + (row / 2 - fieldHeight / 2),
                    i % (fieldWidth) + (col / 2 - fieldWidth / 2), '\n');
        }
        mvaddch(i / (fieldWidth) + (row / 2 - fieldHeight / 2),
                i % (fieldWidth) + (col / 2 - fieldWidth / 2), screen[i]);
    }
}

/**
 * Exiting ncurses before exiting program
 * so terminal doesn't broke.
 */
void interruptionHandler(int signal) {
    endwin();
    printf("Caught signal %d, exiting...\n", signal);
    exit(1);
}

int main() {

    // Attaching interruption handler.
    struct sigaction sigIntHandler;
    sigIntHandler.sa_handler = interruptionHandler;
    sigemptyset(&sigIntHandler.sa_mask);
    sigIntHandler.sa_flags = 0;
    sigaction(SIGINT, &sigIntHandler, NULL);

    // Filling tetromino array.
    /* string *tetromino = prepareTetromino(); */

    // Filling play field.
    for (int x = 0; x < fieldWidth; x++) {
        for (int y = 0; y < fieldHeight; y++) {
            field[y * fieldWidth + x] =
                (x == 0 || x == fieldWidth - 1 || y == fieldHeight - 1) ? 9 : 0;
        }
    }

    // Game logic.
    bool isGameOver = false;
    int currentPiece = 2;
    int currentRotation = 0;
    int currentX = fieldWidth / 2;
    int currentY = 0;
    int pressedKey = 0;

    // Game speed.
    int tickTime = 10; // ms.
    int speed = 50;
    int speedCounter = 0;
    bool forceDown = false;
    int pieceCount = 0;
    int score = 0;

    // Storing completed row.
    vector<int> lines;

    // Ncurses initialization.
    initscr();
    cbreak();
    noecho();
    scrollok(stdscr, TRUE);
    nodelay(stdscr, TRUE);
    curs_set(0);
    getmaxyx(stdscr, row, col);
    clear();

    // Game cycle.
    while (!isGameOver) {

        // ========== GAME TIMING ==========

        usleep(tickTime * 1000);

        speedCounter++;
        forceDown = (speedCounter == speed);

        // ========== INPUT ================

        pressedKey = getch();
        clear();

        // ========== GAME LOGIC ===========

        // Handling movement.
        currentX -= ((pressedKey == 104 || pressedKey == 97) &&
                     doesPieceFit(currentPiece, currentRotation, currentX - 1,
                                  currentY))
                        ? 1
                        : 0;
        currentX += ((pressedKey == 108 || pressedKey == 100) &&
                     doesPieceFit(currentPiece, currentRotation, currentX + 1,
                                  currentY))
                        ? 1
                        : 0;
        currentY += ((pressedKey == 106 || pressedKey == 115) &&
                     doesPieceFit(currentPiece, currentRotation, currentX,
                                  currentY + 1))
                        ? 1
                        : 0;
        currentRotation +=
            ((pressedKey == 107 || pressedKey == 119 || pressedKey == 32) &&
             doesPieceFit(currentPiece, currentRotation + 1, currentX,
                          currentY))
                ? 1
                : 0;

        // Handling game.
        if (forceDown) {
            if (doesPieceFit(currentPiece, currentRotation, currentX,
                             currentY + 1)) {
                currentY++;
            }

            else {

                // Lock current piece in field.
                for (int x = 0; x < tetrominoWidth; x++) {
                    for (int y = 0; y < tetrominoWidth; y++) {
                        if (tetromino[currentPiece]
                                     [rotate(x, y, currentRotation)] == 'X') {
                            field[(currentY + y) * fieldWidth +
                                  (currentX + x)] = currentPiece + 1;
                        }
                    }
                }

                // Increase piece number.
                pieceCount++;
                if (pieceCount % 10 == 0) {
                    speed -= 10;
                }

                // Check if we got any lines.
                for (int y = 0; y < tetrominoWidth; y++) {
                    if (currentY + y < fieldHeight - 1) {

                        bool line = true;
                        for (int x = 1; x < fieldWidth - 1; x++) {
                            line &=
                                (field[(currentY + y) * fieldWidth + x]) != 0;
                        }

                        if (line) {

                            /* // Set line to '='. */
                            /* for (int x = 1; x < fieldWidth - 1; x++) { */
                            /*     field[(currentY + y) * fieldWidth + x] = 8;
                             */
                            /* } */

                            lines.push_back(currentY + y);
                        }
                    }
                }

                // Increasing score.
                score += 25;
                if (!lines.empty()) {
                    score += power(lines.size(), 2) * 100;
                }

                // Removing line.
                if (!lines.empty()) {

                    /* usleep(1000 * 1000); */

                    for (int v : lines) {
                        for (int x = 1; x < fieldWidth - 1; x++) {
                            for (int y = v; y > 0; y--) {
                                field[y * fieldWidth + x] =
                                    field[(y - 1) * fieldWidth + x];
                            }
                            field[x] = 0;
                        }
                    }
                    lines.clear();
                }

                // Choose next piece.
                currentX = fieldWidth / 2;
                currentY = 0;
                currentRotation = 0;
                srand(time(NULL));
                currentPiece = rand() % 7;

                // Exit if piece does not fit.
                isGameOver = !doesPieceFit(currentPiece, currentRotation,
                                           currentX, currentY + 1);
            }

            speedCounter = 0;
        }

        // ========== RENDER OUTPUT ========

        // Filling screen with field.
        for (int x = 0; x < fieldWidth; x++) {
            for (int y = 0; y < fieldHeight; y++) {
                screen[y * fieldWidth + x] =
                    " ABCDEFG=#"[field[y * fieldWidth + x]];
            }
        }

        // Filling screen with piece.
        for (int x = 0; x < tetrominoWidth; x++) {
            for (int y = 0; y < tetrominoWidth; y++) {

                if (tetromino[currentPiece][rotate(x, y, currentRotation)] ==
                    'X') {
                    screen[(currentY + y) * fieldWidth + (currentX + x)] =
                        "ABCDEFG"[currentPiece];
                }
            }
        }

        // Printing screen.
        printScreen(screen);
        mvprintw(row / 2 - 1, 3 * col / 4 - 3, "Score: %d", score);
        /* mvprintw(row - 1, col / 2, "%d", pressedKey); */
    }

    endwin();

    printf("You lost!\nScore: %d", score);

    return 0;
}
