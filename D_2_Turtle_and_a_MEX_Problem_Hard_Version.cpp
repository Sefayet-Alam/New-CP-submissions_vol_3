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

#define ll long long
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


const ll N = 1e6 + 10;


vector<ll> g[N];

bool vis[N];
vector<ll> val(N);

ll dfs(ll node)
{
    if (vis[node])
        return val[node];
    val[node] = node;
    vis[node] = 1;
    for (int a : g[node])
    {
        val[node] = max(val[node], dfs(a));
    }
    return val[node];
}

ll reset(ll n)
{
    for (ll i = 0; i <= n; i++)
    {
        val[i] = 0;
        g[i].clear();
        vis[i] = 0;
    }
}


ll sum(ll n)
{
    return n * (n + 1) / 2;
}

ll ltor(ll l, ll r)
{
    return sum(r) - sum(l - 1);
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
        ll maximex = 0;
        ll maxsz = 0;

        for (ll i = 0; i < n; i++)
        {
            ll sz;
            cin >> sz;
            unordered_map<ll,bool>freq;
            maxsz = max(maxsz, sz);
            for(ll j=0;j<sz;j++){
                ll x;
                cin>>x;
                freq[x]=1;
            }
            ll mex = 0;
            while(freq[mex]) mex++;
            maximex = max(maximex, mex);
            freq[mex]=1;
            ll nxtmex = mex;
            while(freq[nxtmex]) nxtmex++;
            g[mex].push_back(nxtmex);
        }
        ll ans = 0;
        
        for (ll i = 0; i < maxsz+3; i++)
        {
            if (g[i].size()>1)
            {
                maximex = max(maximex, dfs(i));
            }
        }
        ll lim = min(m+1, maxsz+3);
        for (ll i = 0; i < lim; i++)
        {
            ans += max({i, maximex, dfs(i)});
        }
        if (m > maxsz+2)
        {
            ans += ltor(maxsz + 3, m);
            // cout << ans << nn;
        }
        cout << ans << nn;
        reset(maxsz+2);
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
