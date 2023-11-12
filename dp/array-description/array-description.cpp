#include <iostream>
#include <vector>

using namespace std;
#define REP(i,a,b) for(int i = a; i < b; i++)
#define pb push_back
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

int MOD = (int) 1e9+7;

vi nums;

int main(){
    int n,m,c;
    cin >> n >> m;

    REP(i,0,n){
        cin >> c;
        nums.pb(c);
    }
    vi state(m + 1);
    if(nums[0] != 0){
        state[nums[0]] = 1;
    }
    else{
        REP(i, 1, m + 1){
            state[i] = 1;
        }
    }
    REP(i, 1, n){
        int x = nums[i];
        vi newState(m + 1);
        if(x == 0){
            REP(i, 1, m + 1){
                newState[i] = (newState[i] + state[i]) % MOD;
                if(i > 1){
                    newState[i - 1] = (newState[i-1] + state[i]) % MOD;
                }
                if(i < m){
                    newState[i + 1] = (newState[i+1] + state[i]) % MOD;
                }
            }
        }
        else{
            newState[x] = state[x];
            if(x > 1){
                newState[x] = (newState[x] + state[x-1]) % MOD;
            }
            if(x < m){
                newState[x] = (newState[x] + state[x+1]) % MOD;
            }
        }
        state = newState;
    }
    int res = 0;
    for(int y : state){
        res += y;
        res %= MOD;
    }
    cout << res << endl;
}