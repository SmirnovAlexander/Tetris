#ifndef globals
#define globals

#include <string>

const int tetrominoWidth = 4;
static std::string tetromino[7] = {
	"..X...X...X...X.",
	"..X..XX...X.....",
	".....XX..XX.....",
	"..X..XX..X......",
	".X...XX...X.....",
	".X...X...XX.....",
	"..X...X..XX....."
};

const int fieldWidth = 12;
const int fieldHeight = 18;
const int fieldArea = fieldWidth * fieldHeight;

static char field[fieldArea];
static char screen[fieldArea];

static int row, col; // Dimensions of current terminal instance.

#endif


