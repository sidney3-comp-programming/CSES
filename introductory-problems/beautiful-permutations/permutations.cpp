/*
First thought: this doesn't seem that hard to accomplish. I.E. we will have a solution most of the time.
All we need to do is swap elements.

Some edge cases: 1 is always true, and always 1
2 is never true. Start from 3:

1,2,3: also never possible.

Otherwise: take the sets of *4* elts and swap them as follows:

1,2,3,4 -> 2,4,1,3
1,2,3,4,5 -> 2,4,1,3,5
1,2,3,4,5,6 -> 6,2,4,1,3,5
1,2,3,4,5,6,7 -> 6,2,4,7,1,3,5

So for each grouping of 4, we group them using the above mappings. And two adjacent such groupings will always be good as we have neither the min nor the max on either end.
Then, for any excess elements above 4. If we have 2 excess elts - one at the back and one at the front.

If we have 1 excess elt - one at the back

If we have 3 excess elts 5,6,7 ->
middle at the front, 5,7 at the back.

So for each grouping of 4, rank them as follows:
1,2,3,4 in increasing order
And then place in ordering 2,4,1,3
*/

#include <stdio.h>
#include <iostream>
#include <vector>
#include <utility>
#include <sstream>

using namespace std;

typedef vector<int> vi;
typedef pair<int, int> pi;

#define PB push_back
#define REP(i,a,b) for (int i = a; a <= b; i++)

int main(){
    string toPrint, toPrintAfter;
    int n; 
    cin >> n;

    toPrint.reserve(2 * n);
    if(n == 1){
        cout << "1";
        return 0;
    }
    if(n <= 3){
        cout << "NO SOLUTION";
        return 0;
    }
    if(n % 4 == 3){
        toPrint += to_string(n - 1);
        toPrint += " ";
        toPrintAfter += to_string(n - 2);
        toPrintAfter += " ";
        toPrintAfter += to_string(n);
    }
    else if(n % 4 == 2){
        toPrint += to_string(n - 1);
        toPrint += " ";
        toPrintAfter += to_string(n);
    }
    else if (n % 4 == 1){
        toPrintAfter += to_string(n);
    }

    for(int i = 1; i + 3 <= n; i += 4) {
        toPrint += to_string(i + 1);
        toPrint += " ";
        toPrint += to_string(i + 3);
        toPrint += " ";
        toPrint += to_string(i);
        toPrint += " ";
        toPrint += to_string(i + 2);
        toPrint += " ";
    }

    cout << toPrint + toPrintAfter << " ";

}