#define CATCH_CONFIG_MAIN  // Provide main().
#include "../lib/catch.hpp"
#include "../include/functions.h"
#include "../include/globals.h"

TEST_CASE( "Tetromino rotation function", "[rotate]" ) {

    REQUIRE( rotate(0, 0, 0) == 0 );
    REQUIRE( rotate(0, 0, 1) == 12 );

}
