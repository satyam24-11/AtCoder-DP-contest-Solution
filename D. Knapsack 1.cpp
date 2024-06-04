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
int solve(int days, int last, vector<int>&a, vector<int>&b, vector<int>&c, vector<vector<int>>&dp) {
    if (days == a.size()) {
        return 0;
    }

    if (last != -1 && dp[days][last] != -1) {
        return dp[days][last];
    }
    int happiness = 0;
    if (last != 0) {
        happiness = max(happiness, a[days] + solve(days + 1, 0, a, b, c, dp));
    }
    if (last != 1) {
        happiness = max(happiness, b[days] + solve(days + 1, 1, a, b, c, dp));
    }
    if (last != 2) {
        happiness = max(happiness, c[days] + solve(days + 1, 2, a, b, c, dp));
    }
    if (last != -1) {
        dp[days][last] = happiness;
    }
    return  happiness;
}
void answer()
{
    int n;
    cin >> n;
    vector<int>a(n), b(n), c(n);
    vector<vector<int>>dp(n, vector<int>(3, -1));
    for (int i = 0; i < n; i++) {
        cin >> a[i] >> b[i] >> c[i];
    }

    cout << solve(0, -1, a, b, c, dp) << endl;
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
