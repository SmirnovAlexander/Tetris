#define CATCH_CONFIG_MAIN  // Provide main().
#include "../lib/catch.hpp"
#include "../include/functions.h"
#include "../include/globals.h"

TEST_CASE( "Tetromino pixel rotation function", "[rotate]" ) {
    REQUIRE( rotate(0, 0, 0) == 0 );
    REQUIRE( rotate(0, 0, 1) == 12 );
    REQUIRE( rotate(3, 0, 1) == 0 );
}

TEST_CASE( "Tetromino string rotation function", "[rotateTetromino]" ) {
    REQUIRE( rotateTetromino(tetromino[2], 2) == ".....XX..XX....." );
    REQUIRE( rotateTetromino(tetromino[1], 3) == "....XXX..X......" );
    REQUIRE( rotateTetromino(tetromino[5], 1) == ".....XXX.X......" );
    REQUIRE( rotateTetromino(tetromino[6], 2) == ".....XX..X...X.." );
}

TEST_CASE( "Custom power function for integers", "[power]" ) {
    REQUIRE( power(10, 0) == 1 );

    REQUIRE( power(2, 5) == 32 );
    REQUIRE( power(1, 10) == 1 );
}
