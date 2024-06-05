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

#define ll int
#define SZ(a) (int)a.size()
#define UNIQUE(a) (a).erase(unique(all(a)), (a).end())
#define mp make_pair
#define mem(a, b) memset(a, b, sizeof(a))
#define all(x) x.begin(), x.end()

// Printings & debugging
#define nn '\n'
#define Setpre(n) cout << fixed << setprecision(n)
#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl
#define debug printf("I am here\n")

const int LG = 20;
const int N = 1e6 + 2;

vector<ll> g[N];
vector<bool> vis(N, 0);

ll par[N][LG + 1];
vector<ll> dep(N, 0);
void dfs(int u, int p = 0)
{
    par[u][0] = p;
    dep[u] = dep[p] + 1;
    for (int i = 1; i <= LG; i++)
        par[u][i] = par[par[u][i - 1]][i - 1];
    for (auto v : g[u])
        if (v != p)
        {
            dfs(v, u);
        }
}
ll nowpar;
int kth(int u)
{
    // assert(k >= 0);
    while (u != 1)
    {
        ll curru = u;
        for (int i = 0; i <= LG; i++)
        {
            if(par[u][i]==0) break;
            if (vis[par[u][i]])
                break;
            else
                curru = par[u][i];
        }
        if(curru==u) break;
        u=curru;
    }
    return u;
}

void reset(ll n)
{
    for (ll i = 0; i <= n; i++)
    {
        g[i].clear();
        mem(par[i], 0);
        dep[i] = 0;
        vis[i] = 0;
    }
}

int main()
{
    fast;
    ll t;
    // setIO();
    // ll tno=1;;
    t = 1;
    cin >> t;

    while (t--)
    {
        ll n, m;
        cin >> n >> m;
        vis.resize(n + 2);
        dep.resize(n + 2);
        reset(n);
        for (ll i = 0; i < n - 1; i++)
        {
            ll x, y;
            cin >> x >> y;
            g[x].push_back(y);
            g[y].push_back(x);
        }
        dfs(1);
        vector<ll> ans(m, -1);
        for (ll i = 0; i < m; i++)
        {
            ll x;
            cin >> x;
            if (vis[x])
                ans[i] = -1;
            else
            {
                ll curr = kth(x);
                ans[i] = curr;
                vis[curr] = 1;
            }
        }
        for (ll i = 0; i < m; i++)
            cout << ans[i] << " ";
        cout << nn;
    }

    return 0;
}

/* Points tO CONSIDER
    # RTE? -> check array bounds and constraints
    #TLE? -> thinks about binary search/ dp / optimization techniques
    # WA?
    -> overflow,reset global variables
    -> Check corner cases
    -> think from different approaches
    -> bruteforce to find pattern
    -> use Setpre for precision problems
*/