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

void topo(int v, vector<bool>&vis, stack<int>&st, vector<vector<int>>&adj) {
    vis[v] = true;
    for (auto &it : adj[v]) {
        if (!vis[it]) {
            topo(it, vis, st, adj);
        }
    }
    st.push(v);
}
void solve()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>>adj(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u - 1].push_back(v - 1);
    }
    debug(adj);
    stack<int>st;
    vector<int>dist(n, 0);
    vector<bool>vis(n, false);
    for (int i = 0; i < n; i++) {
        if (!vis[i]) {
            topo(i, vis, st, adj);
        }
    }
    while (!st.empty()) {
        int u = st.top();
        st.pop();
        for (auto i : adj[u]) {
            if (dist[i] < dist[u] + 1) {
                dist[i] = dist[u] + 1;
            }
        }
    }
    cout << *max_element(dist.begin(), dist.end()) << nline;
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
