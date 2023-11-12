#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <cmath>

using namespace std;
int LEFT = 1;
int RIGHT = 0;

long evaluateCoord(long x, long y){
    long layer = 2*(max(x,y)-1);
    long ceiled = ceil(layer / 2);
    long base = ((layer*layer + layer) / 2) -
               (ceiled * ceiled + ceiled);

    int direction = max(x,y) % 2;
    long fromRing;
    // 2,4 => direction = 0 = right
    if(direction == LEFT){
        if(x > y){
            fromRing = y;
        }
        else {
            fromRing = 2*y - x;
        }
    }
    else { 
        if(y > x){
            fromRing = x;
        }
        else {
            fromRing = 2*x - y;
        }
    }
    return base + fromRing;
}

int main(){
    int args;
    cin >> args;
    for(int i = 0; i < args; i++){
        long x, y;
        cin >> x;
        cin >> y;
        cout << evaluateCoord(x,y) << "\n";
    }
}