#include <stdio.h>
#include <stdlib.h>
#include <cmath>
#include <iostream>

/*
Let's try and find a more efficient algorithm for this O(n) perhaps?

From the outer ring, how many knights out do we get?
for each corner, we get 6 knights out
for each wall piece not corner, we get 4 knights out

From the 2nd outer ring, how many knights out do we get?
for each corner, we get 4 knights out
for each inner piece, we get 2 knights out

So our formula is as follows:

Total knights in board = 7 * k**2 - 
(6*num_outer_corners + 4*num_outer_edges_not_corner + 4*num_second_outer_corners
+ 2*num_second_outer_edges_not_corner)

for k = 2, answer is 6
for k = 3, answer is 28.

Rest can be tackled directly.

For arbitrary k, what will be the number of outer edges not corner?

Let's first test our formula. k = 4

8 outer edges that are not corners, no second outer edges

Looking for 96
so ans = 
(15) * 16 -
(6*4 + 8*5 + 4*4) 
/2


*/

using namespace std;
int n;

long long solve(long long k){
    long long total = k*k*(k*k - 1);
    long long mx = (long long) max(k-4, (long long) 0);
    long long reduced = k*k*8 - (8*5 + 6*4 + 4*4 + 24*mx);
    return (total - reduced)/2;

}

int main(){
    cin >> n;
    for(int i = 1; i <= n; i++){
        if(i == 1){
            cout << 0 << "\n";
        }
        else if(i == 2){
            cout << 6 << "\n";
        }
        else if(i == 3){
            cout << 28 << "\n";
        }
        else{
            cout << solve(i) << "\n";
        }
    }
}