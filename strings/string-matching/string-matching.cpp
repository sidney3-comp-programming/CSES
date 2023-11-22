#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<pair<int, int>> vii;

#define REP(i, a, b) for (int i = a; i < b; i++)
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define all(v) (v).begin(), (v).end()
#define sz size
#define putl(x) cout << x << endl;
#define put(x) cout << x << " ";
#define debug(x) cout << #x << ": " << x << endl;

/*
At an arbitrary index, can we figure out in O(1) time if an instance of the pattern comes before it?

k = i - L

So we have this window that is a valid prefix of the string, [L,R]. So [L,R] in the string is a valid prefix.
So if we shift back L from the index L, then we would arrive at the start of the string, which would be a valid
prefix. However, if we shift back L from i, we will get that [k, R], we will get a match

*/
void solve()
{
    string s, p;
    cin >> s >> p;
    string M = p + "$" + s;

    vi Z(M.size());
    int L, R, k;
    int N = M.size();
    L = R = 0;
    Z[0] = M.size();
    for (int i = 1; i < N; i++)
    {
        if (i > R)
        {
            L = R = i;
            while (R < N && M[R] == M[R - L])
            {
                R++;
            }
            Z[i] = R - L;
            R--;
        }
        else
        {
            k = i - L;
            if (Z[k] < R - i + 1)
            {
                Z[i] = Z[k];
            }
            else
            {
                L = i;
                while (R < N && M[R] == M[R - L])
                {
                    R++;
                }
                Z[i] = R - L;
                R--;
            }
        }
    }
    int res = 0;
    for (int j = p.size(); j < Z.size(); j++)
    {
        if (Z[j] == p.size())
        {
            res++;
        }
    }
    cout << res << "\n";
}

int32_t main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    while (t--)
    {
        solve();
    }
}