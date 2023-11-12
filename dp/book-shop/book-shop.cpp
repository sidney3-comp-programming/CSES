#include <iostream>
#include <vector>

using namespace std;
#define REP(i,a,b) for(int i = a; i < b; i++)
#define pb push_back
#define mp make_pair
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

int dp[100001][1001];

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
                dp[currDollars][0] = (books[0].first <= currDollars) ? books[0].second : 0;
            }
            else{
                dp[currDollars][bookIndex] = dp[currDollars][bookIndex - 1];
                if(books[bookIndex].first <= currDollars){
                    dp[currDollars][bookIndex] = max(dp[currDollars][bookIndex],
                    books[bookIndex].second + dp[currDollars - books[bookIndex].first][bookIndex - 1]);
                }
            }
        }
    }

    cout << dp[dollars][nbooks-1] << endl;
}



