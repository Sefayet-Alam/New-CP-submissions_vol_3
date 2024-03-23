#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

// VVI
#define fast                      \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);
#define pb push_back
#define ll long long
#define nn "\n"
#define pll pair<long, long>

/* For multiple edges between 2 nodes, this code needs modifications for articulation bridge*/
/* Modification area: if(v == p) continue; */
/* Modification Suggestion: Number the edges and use the numbers for pointing edges */
template <typename T, typename R>
using ordered_map = tree<T, R, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
;
const ll sz = 1009;
vector<ll> g[sz];
ll low[sz], start[sz], TM = 1, root = 1;
bool artPoint[sz], vis[sz];
ordered_map<pll, ll> mpp;
vector<ll> par(sz, -1);
void artdfs(ll u, ll p)
{
    low[u] = start[u] = TM++;
    vis[u] = 1;
    ll child = 0; /// Counter of the children of u in dfs tree
    for (ll i = 0; i < g[u].size(); i++)
    {
        ll v = g[u][i];
        if (v == p)
            continue;

        if (!vis[v])
        {
            par[v] = u;
            artdfs(v, u);
            low[u] = min(low[u], low[v]);

            if (start[u] < low[v])
            {                       /// For articulation bridge: if(start[u] < low[v])
                artPoint[u] = true; /// the edge between u and v is an articulation bridge
                // if(u>v) swap(u,v);
                mpp[{u, v}] = mpp[{v, u}] = 1;
            }
            if (mpp.find({v, u}) == mpp.end())
                mpp[{u, v}] = 1; // add this to find minimum no of edges to keep the graph connected
            child++;
        }
        else if (par[u] != v)
        {
            low[u] = min(low[u], start[v]);
            if (mpp.find({v, u}) == mpp.end())
                mpp[{u, v}] = 1; // add this to find minimum no of edges to keep the graph connected
        }
    }
}

// artdfs(root, -1)
void reset(ll n)
{
    TM = 1, root = 1;
    for (ll i = 0; i <= n + 2; i++)
    {
        g[i].clear();
        vis[i] = artPoint[i] = 0;
        low[i] = start[i] = 0;
        par[i] = -1;
    }
    mpp.clear();
}
int main()
{
    fast;
    ll t;
    // setIO();
    ll tno = 1;
    ;
    t = 1;
    // cin >> t;
    ll n, m;

    while (cin >> n >> m)
    {
        if (n == 0)
            break;
        cout << tno++ << nn;
        cout << nn;
        reset(n);
        set<pll> edgs, edgs2;
        for (ll i = 0; i < m; i++)
        {
            ll u, v;
            cin >> u >> v;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        artdfs(1, -1);
        for (ll i = 1; i <= n; i++)
        {
            for (ll j = 1; j <= n; j++)
            {
                if (mpp.find({i, j}) != mpp.end())
                    cout << i << " " << j << nn;
            }
        }

        cout << "#" << nn;
    }

    return 0;
}
