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

double headProbability(vector<double>& p, int idx, int n, int head, vector<vector<double>>&dp) {
    if (idx >= n) {
        int tails = n - head;
        if (head > tails) {
            return 1.0;
        }
        else
            return 0.0;
    }
    if (dp[idx][head] != -1.0) {
        return dp[idx][head];
    }
    double probability = 0;
    probability += (p[idx]) * headProbability(p, idx + 1, n, head + 1, dp);
    probability += (1.0 - p[idx]) * headProbability(p, idx + 1, n, head, dp); //tail probability

    return dp[idx][head] = probability;
}

void solve()
{
    int n;
    cin >> n;
    vector<double>p(n);
    for (int i = 0; i < n; i++) {
        cin >> p[i];
    }
    double res = 0.0;
    vector<vector<double>>dp(n + 1, vector<double>(n + 1, -1.0));
    cout << fixed << setprecision(10) << headProbability(p, 0, n, 0, dp) << nline;

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
