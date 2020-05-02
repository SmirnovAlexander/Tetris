#include <iostream>
using namespace std;;

string tetromino[7];
int nFieldWidth = 12;
int nFieldHeight = 18;

void print_tetromino(string tetromino, int row_length=4) {

    for (int i = 0; i < tetromino.length(); i++) {

        if (i % row_length == 0) {
            cout << "\n";
        }

        cout << tetromino.at(i);
    }

    cout << "\n";
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

    print_tetromino(tetromino[6]);

    /* return 0; */
}
