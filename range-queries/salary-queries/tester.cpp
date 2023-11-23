#include "salary-queries.cpp"
#include <bits/stdc++.h>
vi brute_force_solve(vi salaries, vec<vi>& queries)
{
   vi res;
   for(vi q : queries) 
   {
       if(q[0] == CHG)
       {
           salaries[q[1]-1] = q[2];
       }
       else if(q[0] == CT)
       {
           int ct = 0;
           for(int x : salaries)
           {
               if(q[1] <= x && x <= q[2])
               {
                   ct++;
               }
           }
           res.pb(ct);
       }
   }
   return res;
}

int rand_range(int lo, int hi)
{
    static bool seeded = false;
    if(!seeded)
    {
        seeded = true;
        srand(0);
    }
    if(hi - lo + 1 == 0)
    {
        return hi;
    }
    return lo + (rand() % (hi - lo + 1));
}
void random_tester()
{
    const int TRIALS = 100, MAX_ARR_SZ = 100, MAX_SALARY = 100, MAX_QUERIES = 100;
    int correct=0, incorrect =0;
    for(int t = 0; t < TRIALS; t++)
    {
        const int arr_sz = rand_range(1, MAX_ARR_SZ);
        const int query_sz = rand_range(1, MAX_QUERIES);
        vi salaries(arr_sz);
        for(int j = 0; j < arr_sz; j++)
        {
            salaries[j] = rand_range(1, MAX_SALARY);
        }
        vec<vi> queries(query_sz); 
        for(int k = 0; k < query_sz; k++)
        {
            int query_type = CT;
            if(query_type == CHG)
            {
                int chg_idx = rand_range(1,arr_sz);
                int new_salary = rand_range(1, MAX_SALARY);
                queries[k] = {query_type, chg_idx, new_salary};
            }
            else if(query_type == CT)
            {
                int hi_idx = rand_range(1, arr_sz);
                int lo_idx = rand_range(1, hi_idx);
                queries[k] = {query_type, lo_idx, hi_idx};
            }
        }
        vi seen = solve(salaries, queries);
        vi exp  = brute_force_solve(salaries, queries);
        assert(seen.sz() == exp.sz());
        for(size_t i = 0; i < seen.sz(); i++)
        {
            if(seen[i] != exp[i])
            {
                incorrect++;
                cout << seen[i] << " " << exp[i] << "\n";
            }
            else
            {
                correct++;
            }
        }
    }
    cout << "CORRECT: " << correct << "\n INCORRECT: " << incorrect << "\n";
}
void unit_tester()
{ 
    std::vector<int> salaries = {2,2,3,4,5,6};
    std::vector<vector<int>> queries = {
        {CT, 2, 4},
        {CT, 6, 6},
        {CHG, 1, 9},
        {CT, 6, 10}
    };
    vi seen = solve(salaries, queries);
    vi exp  = brute_force_solve(salaries, queries);
    assert(seen.sz() == exp.sz());
    for(size_t i = 0; i < seen.sz(); i++)
    {
        assert(exp[i] == seen[i]);
    }

}
int main()
{
    unit_tester();
    random_tester();
}
