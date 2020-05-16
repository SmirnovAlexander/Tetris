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
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

#include <iostream>
using namespace std;

string tetromino[7];
const int fieldWidth = 12;
const int fieldHeight = 18;
char field[fieldWidth * fieldHeight];

/**
 * Prints tetromino in nice format.
 *
 * @param tetromino Initial tetromino representation.
 * @param w Width of tetromino block.
 */
void printTetromino(string tetromino, int w = 4) {

  for (int i = 0; i < tetromino.length(); i++) {

    if (i % w == 0) {
      cout << "\n";
    }

    cout << tetromino.at(i);
  }

  cout << "\n";
}

/**
 * Rotating pixel.
 *
 * Maps x, y to index in tetromino array.
 *
 * @param x, y Piece coordinate to rotate.
 * @param r Rotate index, may be
 *     one of the following:
 *     0: 0 degrees,
 *     1: 90 degrees,
 *     2: 180 degrees,
 *     3: 270 degrees.
 * @param w Width of tetromino block.
 * @return Index in tetromino array.
 */
int rotate(int x, int y, int r, int w = 4) {

  switch (r % 4) {
  case 0:
    return w * y + x;
  case 1:
    return w * (w - 1) + y - w * x;
  case 2:
    return w * w - 1 - w * y - x;
  case 3:
    return w - 1 - y + w * x;
  }

  return 0;
}

/**
 * Rotating tetromino.
 *
 * @param tetromino Tetromino to rotate.
 * @param r Rotate index, may be
 *     one of the following:
 *     0: 0 degrees,
 *     1: 90 degrees,
 *     2: 180 degrees,
 *     3: 270 degrees.
 * @param w Width of tetromino block.
 * @return rotatedTetromino.
 */
string rotateTetromino(string tetromino, int r, int w = 4) {

  string rotatedTetromino;

  for (int y = 0; y < w; y++) {
    for (int x = 0; x < w; x++) {
      int indexToAppend = rotate(x, y, r, w);
      char pieceToAppend = tetromino[indexToAppend];
      rotatedTetromino += pieceToAppend;
    }
  }

  return rotatedTetromino;
}

int main() {

  tetromino[0].append("..X.");
  tetromino[0].append("..X.");
  tetromino[0].append("..X.");
  tetromino[0].append("..X.");

  tetromino[1].append("..X.");
  tetromino[1].append(".XX.");
  tetromino[1].append(".X..");
  tetromino[1].append("....");

  tetromino[2].append(".X..");
  tetromino[2].append(".XX.");
  tetromino[2].append("..X.");
  tetromino[2].append("....");

  tetromino[3].append("....");
  tetromino[3].append(".XX.");
  tetromino[3].append(".XX.");
  tetromino[3].append("....");

  tetromino[4].append("..X.");
  tetromino[4].append(".XX.");
  tetromino[4].append("..X.");
  tetromino[4].append("....");

  tetromino[5].append("....");
  tetromino[5].append(".XX.");
  tetromino[5].append("..X.");
  tetromino[5].append("..X.");

  tetromino[6].append("....");
  tetromino[6].append("..XX");
  tetromino[6].append("..X.");
  tetromino[6].append("..X.");

  printTetromino(tetromino[4]);
  cout << "\n";

  printTetromino(rotateTetromino(tetromino[4], 3));
  cout << "\n";

  for (int x = 0; x < fieldWidth; x++) {
    for (int y = 0; y < fieldHeight; y++) {
      field[y * fieldWidth + x] =
          (x == 0 || x == fieldWidth - 1 || y == fieldHeight) ? 9 : 0;
    }
  }

  for (int i = 0; i < sizeof(field); i++) {
    cout << field[i];
  }

  cout << "\n";
  cout << "\n";

  return 0;
}
