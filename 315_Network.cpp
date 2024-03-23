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
#define mem(a, b) memset(a, b, sizeof(a))

void setIO()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);

    freopen("output.txt", "w", stdout);
#endif // ONLINE_JUDGE
}

/* For multiple edges between 2 nodes, this code needs modifications for articulation bridge*/
/* Modification area: if(v == p) continue; */
/* Modification Suggestion: Number the edges and use the numbers for pointing edges */


const ll sz = 109;
vector<ll> g[sz];
ll low[sz], start[sz], TM = 1, root = 1;
bool artPoint[sz], vis[sz];

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

        if (vis[v])
            low[u] = min(low[u], start[v]);
        else
        {
            artdfs(v, u);
            low[u] = min(low[u], low[v]);

            if (start[u] <= low[v] && u != root)
            {                       /// For articulation bridge: if(start[u] < low[v])
                artPoint[u] = true; /// the edge between u and v is an articulation bridge
            }
            child++;
        }
    }

    if (child > 1 && u == root) /// For articulation bridge: this
        artPoint[u] = true;     /// and this line have no need
}

// artdfs(root, -1)
int main()
{
    int N;
    while (cin >> N, N != 0)
    {
        cin.ignore();
        for (ll i = 0; i <= N + 2; i++)
        {
            g[i].clear();
        }
        // network.resize(N + 1);
        mem(vis, 0);
        mem(low, 0);
        mem(start, 0);
        mem(artPoint,0);

        string s;
        while (getline(cin, s), s != "0")
        {
            stringstream ss(s);
            int u, v;
            ss >> u;
            while (ss >> v)
            {
                g[u].push_back(v);
                g[v].push_back(u);
            }
        }
        // Loop over all places.
        for (ll p = 1; p <= N; ++p)
        {
            if (!vis[p])
            {
                artdfs(p,-1);
            }
        }
        ll ans=0;
        for(ll i=1;i<=N;i++){
            if(artPoint[i]) ans++;
        }
        cout<<ans<<endl;
    }
    return 0;
}
