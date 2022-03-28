#include "gameboard.h"
#include <QTableWidget>
Gameboard::Gameboard()
{
    startGame();
}
void Gameboard::startGame() {
    turns_counter = 0;
    for (int i = 0; i < 16; i++) {
        num_sequence[i] = i+1;
    }
    makeBoard();
}
void Gameboard::makeBoard() {
    std::random_shuffle(num_sequence, num_sequence+16);
    int counter = 0;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            numbers[i][j] = num_sequence[counter];
            counter++;
        }
    }
}
bool Gameboard::isFinished() {
    int counter = 1;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (!( (i==3) && ((j==1)||(j==2))) && (numbers[i][j] != counter)){
                return false;
            }
            counter++;
        }
    }
    return true;
}
