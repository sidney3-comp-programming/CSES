#include <bits/stdc++.h>
using namespace std;

template<typename... T>
void see(T&... args) { ((cin >> args), ...);}
template<typename... T>
void put(T&&... args) { ((cout << args << " "), ...);}
template<typename... T>
void putl(T&&... args) { ((cout << args << "\n"), ...);}
#define ll long long
#define ld long double
#define ii pair<int, int>
#define vi vector<int>
#define vii vector<ii>
#define vec vector
#define rep(i,a,b) for(int i = a; i < b; i++)
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define all(v) (v).begin(), (v).end()
#define sz size
#define debug(x) cout << #x << ": " << x << endl;

void solve()
{
    int n,q;
    see(n,q);
    vi parent(n+1);
    rep(i,2,n+1)
    {
        cin >> parent[i];
    }
    vec<vi> jump_table(n+1, vi(25, 0));
    rep(i,1,n + 1)
    {
        jump_table[i][0] = parent[i]; 
    }
    rep(p,1,25)
    {
        rep(i,1,n + 1)
        {
            jump_table[i][p] = jump_table[jump_table[i][p-1]][p-1];
        }
    }
    auto jump_fn = [](const vec<vi>& jump_table, int curr, int steps)
    {
        int res = curr;
        rep(p,0,25)
        {
            if((1<<p)&steps)
            {
                res = jump_table[res][p];
            }
        }
        return res;
    };
    rep(j,0,q)
    {
        int source, steps;
        see(source, steps);
        int steps_parent = jump_fn(jump_table, source, steps);
        cout << ((steps_parent == 0) ? -1 : (steps_parent)) << "\n";
    }
}

int32_t main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    solve();
}
