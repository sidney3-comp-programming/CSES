/*
Consider an infinite string that consists of all positive integers in increasing order:

12345678910111213141516171819202122232425...

Your task is to process q queries of the form: what is the digit at position k in the string?

Input:
The first input line has an integer q : the number of queries.
After this, there are q lines that describe the queries. Each line has an integer k : a 1-indexed position in the string.

Output:
For each query, print the corresponding digit.

Constraints
1≤q≤1000

1≤k≤10e17

Approach: we don't need a constant time formula for each query - we can do it in perhaps log base 10

So let's think about the cases for our result. The base case: our result has 1 digit - and then we just return
the result itself. We can think about our answer as being a function of digits? Bit of a tough problem


We can also think of this like a bit of a weird base problem:
The first 9 digits
123456789101112131415161718192021222324252627282930

The first 9 numbers in our k will get us one digit,
Then the next 99 - 9 = 90 numbers will take two numbers off k to parse
Then the next 999 - 99 = 900 numbers will take three numbers off k to parse 
Then the next 9999 - 999 = 9000 numbers will take four numbers off k to parse.

How do we actually determine the number once one of these values surpasses k?

I.E. remaining_k = 22 - so our response will be the 2nd value of the 11th (add one to it).
Let's say our value was instead 21 -> then we would be getting value number 22.
i.e. take add one to 22

i.e. if we had 21, we would still get to the 11th number 

What is the number that we get to? ceil(remaining_k / num_size)
what is the index within the number that we get to? If the number % num_size == 0, we get
to the end of the number. If the number % num_size == num_size - 1, then we get to the value before the end of the number.
Can't really test this buttttt just take my word



123456789101112131415161819202122
*/

#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

typedef long long ll;
#define REP(i, a, b) for(int i = a; i < b; i++)

long long pow10(int power){
    long long res = 1;
    REP(i, 0, power){
        res *= 10;
    }
    return res;
}

vector<int> getDigits(ll target){
    vector<int> res;
    if(target == 0) return res;
    for(int digit : getDigits(floor(target / 10))){
        res.push_back(digit);
    }
    res.push_back(target % 10);
    return res;
}

int processK(ll curr_k){
    ll base = 0;
    ll curr = 9;
    int currNumDigits = 1;

    while(curr_k >= currNumDigits * curr){
        curr_k -= currNumDigits * curr;
        base += curr;
        curr = pow10(currNumDigits)*9;
        currNumDigits++;
    }
    ll arrivedNum = base + ceil(curr_k / currNumDigits);
    int arrivedNumIndex = ((curr_k - 1) % currNumDigits);
    return getDigits(arrivedNum)[arrivedNumIndex];

}

int main(){
    ll k;
    cin >> k;
    while(cin >> k){
        cout << processK(k) << endl;
    }
}