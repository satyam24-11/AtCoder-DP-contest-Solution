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
int solve(vector<int>&h, int n, int idx, vector<int>&dp) {
    if (idx >= n - 1) {
        return 0;
    }
    if (dp[idx] != -1) return dp[idx];
    int path1 = INT_MAX;
    int path2 = INT_MAX;
    if (idx + 1 < n)
        path1 = solve(h, n, idx + 1, dp) + abs(h[idx] - h[idx + 1]);
    if (idx + 2 < n)
        path2 = solve(h, n, idx + 2, dp) + abs(h[idx] - h[idx + 2]);
    return dp[idx] = min(path1, path2);

}
void answer()
{
    int n;
    cin >> n;
    vector<int>h(n);
    vector<int>dp(n + 1, -1);
    for (int i = 0; i < n; i++) {
        cin >> h[i];
    }
    cout << solve(h, n, 0, dp) << endl;;
}
signed main()
{
    make_fast();
    // ll t;
    // cin >> t;
    // while (t--)
    // {
    //     answer();
    // }
    answer();
    return 0;
}
