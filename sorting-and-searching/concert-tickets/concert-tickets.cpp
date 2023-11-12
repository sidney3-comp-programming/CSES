#include <iostream>
#include <vector>
#include <set>

//this will be a binary search tree
using namespace std;

#define REP(i, a, b) for(int i = a; i < b; i++)

multiset<int> prices;

int main(){
    int numCustomers, numTickets;
    cin >> numTickets >>  numCustomers;

    long currTicket;
    REP(i, 0, numTickets){
        cin >> currTicket;
        prices.insert(currTicket);
    }
    long customerMaxPay;
    REP(j, 0, numCustomers){
        cin >> customerMaxPay;
        auto it = prices.upper_bound(customerMaxPay); //returns the smallest element greater than k
        if(it != prices.begin()){
            --it;
            cout << *it << endl;
            prices.erase(it);
        }
        else{
            cout << -1 << endl;
        }
    }
    
}