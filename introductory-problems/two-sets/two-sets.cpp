/*


Your task is to divide the numbers 1,2,…,n
 into two sets of equal sum.

Input

The only input line contains an integer n with 1 <= n <= 10^6
Output

Print "YES", if the division is possible, and "NO" otherwise.

After this, if the division is possible, print an example of how to create the sets.
First, print the number of elements in the first set followed by the elements themselves in a separate line,
and then, print the second set in a similar way.

METHOD: base analysis - this seems pretty doable. One thing to consider: the sets will sum to
(n+1)n/2, and so we're trying to make two sets that sum to (n+1)n/4

If we can succeed in making a single set that sums to this value, then we've won. That said, not
going to be a brute force algorithm because the size of n is so large. We're going to want to develop
a strategy to solve this. What if we put all the odds in one pile, and all the evens in another pile?
And then shuffle to adapt?

A potential target for this problem: if the sum of all values is odd, then not going to be possible!
i.e. if n(n+1)/2 is odd, then not possible! i.e. 5 -> 6(5)/2 = 3(5) = 15 so not possible.

what about 7 -> 7(8)/2 = 28 => target = 14
1,2,3,4,5,6,7:

7,4,3. Done.

Another idea: take the first and last elements and pair them together? There is a definite symmetry to these numbers
if the number of elts is divisible by 4, we can apply the following strategy:
1,2,3,4,5,6,7,8
1,8
2,7

3,6
4,5

Each first, last pairing will have the same value. Similarly, each such pairing (i.e. the first 3 elts with
the last 3 elts, the next 3 elts with the next 3 elts), will all have the same value.

So we want to divide the size of the set into chunks of 4. 

1,2,3,4,5,6,7

n = 7:

1,3,5,7
2,4,6 = 1 + 3 + 5 + 3


8 -> 1 8 2 7,   3 6 4 5
(this strategy will always be possible when n % 4 == 0). When n % 4 != 0, not often possible. Need either than
n % 4 == 0 or n + 1 % 4 == 0 => n = -1 (4)

9 -> not possible
10 -> not possible
11 -> target 11(12)/4 = 11*3 = 33. 11+10+1+9+2 -> great way to make 11.
Trying to make one subset of n, (n-1)/2 times. Sure




*/
#include <iostream>
#include <stdlib.h>
#include <vector>
#include <cmath>

using namespace std;

#define vi vector<int>
#define REP(i,a,b) for (int i = a; i < b; i++)
#define PB push_back

// 7 : 7*8/4 = 7*2

int main(){
    long n;
    cin >> n;

    vi sum1, sum2;

    if(n % 4 == 0){
        cout << "YES\n";
        //12 -> 0,11, 1,10, 2,9
        REP(i, 0, floor(n / 4)){
            sum1.PB(i + 1);
            sum1.PB(n - i);
        }
        // 3,8, 4,7, 5,6
        REP(i, floor(n / 4), 2*floor(n / 4)){
            sum2.PB(i + 1);
            sum2.PB(n - i);
        }
    }
    else if((n + 1) % 4 == 0){
        cout << "YES\n";
        // 11, (n+1)/4
        // going to be doing this process (n+1)/4 - 1 times 
        // of adding first elt then adding currlast elt
        // 11, doing this process 12/4 = 3 - 1 = 2 times.
        // 10,1, 9,2. So going to be adding numbers up to 9, starting from 2
        sum1.PB(n);
        REP(i, 0, floor(n + 1) / 4 - 1){
            sum1.PB(i+1);
            sum1.PB(n - i - 1);
        }
        REP(i, floor(n+1)/4 - 1, n - floor(n + 1) / 4){
            sum2.PB(i+1);
        }
    }
    else{
        cout << "NO\n";
        return 0;
    }
    cout << sum1.size() << "\n";
    for(int n : sum1){
        cout << n << " ";
    }
    cout << "\n" << sum2.size() << "\n";
    for(int n : sum2){
        cout << n << " ";
    }
}