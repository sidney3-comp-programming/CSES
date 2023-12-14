
#include <bits/stdc++.h>
using namespace std;

template<typename... T>
void see(T&... args) { ((cin >> args), ...);}
template<typename... T>
void put(T&&... args) { ((cout << args << " "), ...);}
template<typename... T>
void putl(T&&... args) { ((cout << args << "\n"), ...);}
int ciel(int a, int b) {return ceil(static_cast<double>(a) / static_cast<double>(b));}
#define ll long long
#define ld long double
#define ii pair<int, int>
#define vi vector<int>
#define vii vector<ii>
#define vec vector
#define rep(i,a,b) for(int i = a; i < b; i++)
#define f0r(i,a) for(int i = 0; i < a; i++)
#define r0f(i,a) for(int i = a; i >= 0; i--)
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define all(v) (v).begin(), (v).end()
#define sz size
#define debug(x) cout << #x << ": " << x << endl;

const string albet{"abcdefghijklmnopqrstuvwxyz"};
const ll inf = 1LL<<52;
const ld ep = 0.0000001;
const ld pi = acos(-1.0);
const ll md = 1000000007;
const int BIG = (INT_MAX-1)/2;
#define int long long

class sliding_median
{
public:
    sliding_median(): big_sum(0), small_sum(0)
    {}
    ll get_cost() const
    {
        int median = get_median();
        ll small_contribution = (median * smalls.sz()) - small_sum;
        ll big_contribution = big_sum - (median * bigs.sz());
        return small_contribution + big_contribution;
    }
    void insert(int x)
    {
        if(smalls.sz() == 0 || x < (*smalls.rbegin()))
        {
            insert_state(x, smalls, small_sum);
        }
        else
        {
            insert_state(x, bigs, big_sum);
        }
        make_even();
    }
    void remove(int x)
    {
        if(smalls.find(x) != smalls.end())
        {
            remove_state(x, smalls, small_sum);
        }
        else if(bigs.find(x) != bigs.end())
        {
            remove_state(x, bigs, big_sum);
        }
        else
        {
            throw("didn't find value to remove");
        }
        make_even();
    }
private:
    void debug_state() const
    {
        putl("smalls: ");
        for(int x : smalls)
        {
            cout << x << " ";
        }
        cout << "\n";
        putl("bigs: ");
        for(int x : bigs)
        {
            cout << x << " ";
        }
        cout << "\n";
        debug(small_sum);
        debug(big_sum);
    }
    int get_median() const
    {
        assert(smalls.sz() > 0);
        return (*smalls.rbegin());
    }
    void make_even()
    {
        while(smalls.sz() > bigs.sz() + 1)
        {
            int to_remove = *smalls.rbegin();
            insert_state(to_remove, bigs, big_sum);
            remove_state(to_remove, smalls, small_sum);
        }
        while(bigs.sz() > smalls.sz())
        {
            int to_remove = (*bigs.begin());
            insert_state(to_remove, smalls, small_sum);
            remove_state(to_remove, bigs, big_sum);
        }
    }
    void insert_state(int x, multiset<int>& S, ll& S_sum)
    {
        S_sum += x;
        S.insert(x);
    }
    void remove_state(int x, multiset<int>& S, ll& S_sum)
    {
        S_sum -= x;
        S.erase(S.find(x));
    }
    multiset<int> bigs;
    multiset<int> smalls;
    ll big_sum;
    ll small_sum;
};
void solve()
{
    int n,k;
    see(n,k);
    vi arr(n);
    f0r(i,n)
    {
        see(arr[i]);
    }
    sliding_median M;
    f0r(i,k)
    {
        M.insert(arr[i]);
    }
    cout << M.get_cost() << " ";
    rep(i,k,n)
    {
        M.remove(arr[i-k]);
        M.insert(arr[i]);
        cout << M.get_cost() << " ";
    }
    cout << "\n";
}

int32_t main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    solve();
}
