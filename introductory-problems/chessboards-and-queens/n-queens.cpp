/*
Your task is to place eight queens on a chessboard so that no two queens are attacking each other. As an additional challenge, each square is either free or reserved, and you can only place queens on the free squares. However, the reserved squares do not prevent queens from attacking each other.

How many possible ways are there to place the queens?

Input

The input has eight lines, and each of them has eight characters. Each square is either free (.) or reserved (*).

Output

Print one integer: the number of ways you can place the queens.

Nah we ain't takin a combinatorial approach. We run a backtracking algorithm. 
*/
#include <iostream>
#include <cmath>
#include <vector>

#define REP(i, a,b) for(int i = a; i < b; i++)

using namespace std;

int reservedSquares[8][8] = {0};


pair<int, int> getCoords(int boardPos){ 
    return {floor(boardPos / 8), boardPos % 8};
}
pair<long, long> getDiagonals(pair<int, int> coords){
    return {coords.first + coords.second, 7 + coords.first - coords.second}; 
}

long backtrack(int i, int rowsControlled, int colsControlled, long leftDiagonalsControlled, long rightDiagonalsControlled, int numQueens){
    pair<int, int> coords = getCoords(i);
    pair<int, int> diagonals = getDiagonals(coords);

    if(i >= 64){
        if(numQueens == 8){
            return 1;
        }
        else{
            return 0;
        }
    }
    // case 1: not adding a queen
    long res = backtrack(i + 1, rowsControlled, colsControlled, leftDiagonalsControlled, rightDiagonalsControlled, numQueens);

    //case 2: adding queen
    if(!(rowsControlled & 1 << coords.first) & 
        !(colsControlled & 1 << coords.second) &
        !(leftDiagonalsControlled & 1 << diagonals.first) &
        !(rightDiagonalsControlled & 1 << diagonals.second) &
        !(reservedSquares[coords.first][coords.second])
    ){
        res += backtrack(i + 1, rowsControlled | 1 <<coords.first, colsControlled | 1 << coords.second, 
        leftDiagonalsControlled | 1 << diagonals.first, rightDiagonalsControlled | 1 << diagonals.second, numQueens + 1);
    }
    return res;
}

int main(){
    char c;
    REP(i, 0, 8){
        REP(j, 0 ,8){
            pair<int, int> diags = getDiagonals({i, j});
            cin >> c;
            if(c == '*'){
                reservedSquares[i][j] = 1;
            }
        }
    }
    cout << backtrack(0,0,0,0,0,0) << endl;
}