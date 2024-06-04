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

ll kanpsack1(vector<ll>&weight, vector<ll>&value, ll idx, ll total, ll n, vector<vector<ll>>&dp) {
    if (idx == n || total == 0) {
        return 0;
    }
    if (dp[idx][total] != -1) return dp[idx][total];
    ll ans1 = 0;
    if (weight[idx] <= total)
        ans1 = value[idx] + kanpsack1(weight, value, idx + 1, total - weight[idx], n, dp);
    ll ans2 = kanpsack1(weight, value, idx + 1, total, n, dp);
    return dp[idx][total] = max(ans1, ans2);
}
void answer()
{
    ll n, total;
    cin >> n >> total;
    vector<ll>weight(n);
    vector<ll>value(n);
    vector<vector<ll>>dp(n + 1, vector<ll>(total + 1, -1));
    for (ll i = 0; i < n; i++) {
        cin >> weight[i] >> value[i];
    }

    ll ans = kanpsack1(weight, value, 0, total, n, dp);
    cout << ans << endl;
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
