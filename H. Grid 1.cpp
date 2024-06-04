#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

//typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds; // find_by_order, order_of_key


#define make_fast() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define MOD 1000000007
#define MOD1 998244353
#define INF 1e18
#define nline "\n"
#define pb push_back
#define ppb pop_back
#define mp make_pair
#define ff first
#define ss second
#define pi 3.141592653589793238462
#define set_bits __builtin_popcountll
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;
#ifndef ONLINE_JUDGE

#include "template_cpp11_std.cpp"
#else
#define debug(...)
#define debugArr(...)
#endif

int solve(int i, int j, vector<string>&grid, vector<vector<int>>&dp) {
    if (i >= grid.size() || j >= grid[0].size() || grid[i][j] == '#') {
        return 0;
    }
    if (i == grid.size() - 1 && j == grid[0].size() - 1 ) {
        return 1;
    }
    //debug(dp);
    if (dp[i][j] != -1) return dp[i][j];
    int cnt1 = solve(i + 1, j, grid, dp);
    int cnt2 = solve(i, j + 1, grid, dp);

    return dp[i][j] = (cnt1 + cnt2) % MOD;
}
void solve()
{
    int h, w;
    cin >> h >> w;
    vector<string>grid(h);
    for (int i = 0; i < h; i++) {
        cin >> grid[i];
    }
    vector<vector<int>>dp(h + 1, vector<int>(w + 1, -1));

    cout << solve(0, 0, grid, dp) << nline;

}
signed main()
{
    make_fast();
    // int t;
    // cin >> t;
    // while (t--)
    // {
    //     solve();
    // }
    solve();
    return 0;
}
