#include <iostream>
#include <cmath>
#include <utility>
#include <unordered_map>
#include <algorithm>

using namespace std;

#define _CRT_SECURE_NO_DEPRECATE

// typedef pair<int, int> ii;

#define REP(i, a, b) for(int i = a; i < b; i++)

/*
Let dp[i][j][k] be the number of ways that we can get from (i,j) to the target, 6,6 with
exactly k moves
Then ans = dp(0,0,48)
*/

char path[49] = {'\0'};

int visited[9][9] = {0};

unordered_map<char, pair<int, int>> directionMap = {
    {'R', {0, 1}},
    {'L', {0, -1}},
    {'D', {1, 0}},
    {'U', {-1, 0}}
};

int distance(int sourceRow, int sourceCol, int targetRow, int targetCol){
    return abs(sourceRow - targetRow) + abs(sourceRow - sourceCol);
}

long backtrack(int row, int col, int movesMade){

    if(row == 7 and col == 1){
        if(movesMade == 48){
            return 1;
        }
        else{
            return 0;
        }
    }
    //if we can ONLY go left or right, terminate the path
    //really clever actually - think about the shape of the path
    if ((visited[row][col - 1] && visited[row][col + 1]) &&
	    (!visited[row - 1][col] && !visited[row + 1][col]))
		return 0;
	if ((visited[row - 1][col] && visited[row + 1][col]) &&
	    (!visited[row][col - 1] && !visited[row][col + 1]))
		return 0;
    if(movesMade >= 48){
        return 0;
    }
    visited[row][col] = 1;

    long res = 0;
    if(path[movesMade] == '?'){
        for(const pair<char, pair<int, int>> &move : directionMap){
            pair<int, int> directionShift = move.second;
            if(visited[row + directionShift.first][col + directionShift.second] == 0){
                int v = backtrack(row + directionShift.first, col + directionShift.second, movesMade + 1);
                res += v;
            }
        }
    }
    else{
        if(visited[row + directionMap[path[movesMade]].first][col + directionMap[path[movesMade]].second] == 0){
            int v = backtrack(row + directionMap[path[movesMade]].first, col + directionMap[path[movesMade]].second, movesMade + 1);
            res += v;
        }
    }

    visited[row][col] = 0;
    return res;
}

int main(){
    char c;
    REP(i, 0, 48){
        cin >> c;
        path[i] = c;
    }
    // fill(&dp[0][0][0], &dp[0][0][0] + sizeof(dp) / sizeof(int), -1);
    REP(i, 0, 8){
        visited[0][i] = 1;
        visited[8][i] = 1;
        visited[i][0] = 1;
        visited[i][8] = 1;
    }
    cout << backtrack(1,1,0) << endl;
}