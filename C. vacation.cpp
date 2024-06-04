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
int solve(vector<int>&height, int n, int k, int idx, vector<int>&dp) {
    if (idx == 0) {
        return 0;
    }
    if (dp[idx] != -1) return dp[idx];
    int min_steps = INT_MAX;
    // int jump = 0;
    for (int j = 1; j <= k; j++) {
        if ((idx - j) >= 0) {
            int jump = solve(height, n, k, idx - j, dp) + abs(height[idx] - height[idx - j]);
            min_steps = min(min_steps, jump);
        }

    }
    return dp[idx] = min_steps;
}
void answer()
{
    int n, k;
    cin >> n >> k;
    vector<int>height(n);
    vector<int>dp(n + 1, -1);
    for (int i = 0; i < n; i++) {
        cin >> height[i];
    }
    cout << solve(height, n, k, n - 1, dp) << endl;;
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
