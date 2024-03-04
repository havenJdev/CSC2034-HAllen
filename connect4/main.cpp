#include <iostream>

const int COLUMNS = 7;
const int ROWS = 6;

char board[COLUMNS][ROWS] = {0};

char currentPlayer = 'R';

bool checkDirection(int dx, int dy) {
    for (int i = 0; i < COLUMNS; ++i) {
        for (int j = 0; j < ROWS; ++j) {
            if (board[i][j] == currentPlayer) {
                for (int k = 1; k < 4; ++k) {
                    int ni = i + k * dx;
                    int nj = j + k * dy;
                    if (ni < 0 || ni >= ROWS || nj < 0 || nj >= COLUMNS || board[ni][nj] != currentPlayer) {
                        break;
                    }
                    if (k == 3) {
                        return true; // Four in a row found
                    }
                }
            }
        }
    }
    return false;
}

bool isWinner() {
    // Check for a win horizontally, vertically, and diagonally
    // (This simple implementation checks all possible directions, but more optimized solutions are possible)
    return checkDirection(0, 1) || checkDirection(1, 0) || checkDirection(1, 1) || checkDirection(1, -1);
}



void fillBoard(){
    for(int i = 0; i < COLUMNS; i++){
        for(int j = 0; j < ROWS; j++){
            board[i][j] = ' ';
        }
    }
}

void printBoard(){
    for(int i = ROWS - 1; i >= 0; i--){
        printf("|");
        for(int j = 0; j < COLUMNS; j++){
            printf("%c|", board[j][i]);
        }
        std::cout << std::endl;
    }
}

int getOpenSpot(int column){
    for(int i = 0; i < ROWS; i++){
        if(board[column][i] == ' '){
            return i;
        }
    }
}

bool isValidMove(int column){
    // make sure there is room at the top of the column e.g. board[column][5]
    return board[column][ROWS - 1] == ' ';
}

void makeMove(int column){
    if(!isValidMove(column)){
        std::cout << "invald move" << std::endl;
        return;
    }
    const char ply = redsTurn ? 'R' : 'Y';
    board[column][getOpenSpot(column)] = ply;
}

int main() {
    fillBoard();
    printBoard();
    makeMove(1);
    std::cout << std::endl << std::endl;
    printBoard();
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
