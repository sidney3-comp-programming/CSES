
#include <iostream>
#include <vector>
 
using namespace std;
#define REP(i,a,b) for(int i = a; i < b; i++)
#define pb push_back
#define mp make_pair
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
 
int dp[1001][100001];
 
int main(){
    cin.tie(0)->sync_with_stdio(0);
 
    int nbooks, dollars, p;
    cin >> nbooks >> dollars;
    vii books(nbooks);
    REP(i,0,nbooks){
        cin >> p;
        books[i].first = p;
    }
    REP(i,0,nbooks){
        cin >> p;
        books[i].second = p;
    }
 
    REP(bookIndex, 0, nbooks){
        REP(currDollars, 1, dollars + 1){
            if(bookIndex == 0){
                dp[0][currDollars] = (books[0].first <= currDollars) ? books[0].second : 0;
            }
            else{
                dp[bookIndex][currDollars] = dp[bookIndex - 1][currDollars];
                if(books[bookIndex].first <= currDollars){
                    dp[bookIndex][currDollars] = max(dp[bookIndex][currDollars],
                    books[bookIndex].second + dp[bookIndex - 1][currDollars - books[bookIndex].first]);
                }
            }
        }
    }
 
    cout << dp[nbooks-1][dollars] << endl;
}
