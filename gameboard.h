#ifndef GAMEBOARD_H
#define GAMEBOARD_H

class Gameboard
{
public:
    Gameboard();
    void startGame();
    void makeBoard();
    bool isFinished();
    int numbers[4][4];
    int num_sequence[16];
    int turns_counter;
    int empty_row, empty_column;
};

#endif // GAMEBOARD_H
