#include <vector>
#include <unordered_map>
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
#define sz size
#define debug(x) cout << #x << ": " << x << endl;

struct range_counter_seg_tree
{
    public:
    range_counter_seg_tree(const int num_vals, const std::unordered_map<int,int>& init_val_counts);
    void update(int idx, int chg);
    int query(int l, int r);
    private:
    void update_recurse(int idx, int chg, int v, int tl, int tr);
    int query_recurse(int l, int r, int v, int tl, int tr);
    void build(const std::unordered_map<int,int>& init_val_counts, int v, int tl, int tr);
    std::vector<int> Tree;
    int num_vals;
};
std::unordered_map<int,int> compress(const std::vector<int>& vals);
std::vector<int> solve(std::vector<int> salaries, const std::vec<std::vector<int>>& queries);

const int CHG=1,CT=2;
