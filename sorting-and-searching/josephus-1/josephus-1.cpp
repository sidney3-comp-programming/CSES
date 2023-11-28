#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<pair<int,int>> vii;

#define REP(i,a,b) for(int i = a; i < b; i++)
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define all(v) (v).begin(), (v).end()
#define sz size
#define putl(x) cout << x << endl;
#define put(x) cout << x << " ";
#define debug(x) cout << #x << ": " << x << endl;

int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    int n;
    cin >> n;
    deque<int> remaining_children;
    for(int i = 1; i <= n; i++) remaining_children.pb(i);
    vi removal_order;
    while(remaining_children.size() > 1){
        deque<int> after_children;
        for(size_t i = 0; i + 1 < remaining_children.size(); i += 2){
            after_children.pb(remaining_children[i]);
            removal_order.pb(remaining_children[i + 1]);
        }
        if(remaining_children.size() % 2 != 0){
            removal_order.pb(remaining_children.front());
            after_children.pop_front();
            after_children.pb(remaining_children.back());
        }
        remaining_children.swap(after_children);
    }
    for(int y : removal_order) cout << y << " ";
    cout << remaining_children.front() << endl;
}
