#include <iostream>

int main(){
    int n;
    std::cin >> n;
    int splits = 0, curr = 1;
    while(n > 1){
        splits++;
        if((n&(0b1))) curr += 1<<splits;
        n /= 2;
    }
    std::cout << curr << std::endl;
}