#include "../include/globals.h"

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
 * @return Index in tetromino array.
 */
int rotate(int x, int y, int r) {

    switch (r % 4) {
    case 0:
        return tetrominoWidth * y + x;
    case 1:
        return tetrominoWidth * (tetrominoWidth - 1) + y - tetrominoWidth * x;
    case 2:
        return tetrominoWidth * tetrominoWidth - 1 - tetrominoWidth * y - x;
    case 3:
        return tetrominoWidth - 1 - y + tetrominoWidth * x;
    }

    return 0;
}

/**
  * Make integer to the power of integer.
  */
int power(int x, int p) {
    if (p == 0)
        return 1;
    if (p == 1)
        return x;

    int tmp = power(x, p / 2);
    if (p % 2 == 0)
        return tmp * tmp;
    else
        return x * tmp * tmp;
}
