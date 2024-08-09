#pragma GCC optimize(2)
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline","fast-math","unroll-loops","no-stack-protector")
#pragma GCC diagnostic error "-fwhole-program"
#pragma GCC diagnostic error "-fcse-skip-blocks"
#pragma GCC diagnostic error "-funsafe-loop-optimizations"
#pragma GCC optimize("O3")

#include <bits/stdc++.h>

using namespace std;


// VVI
#define fast                      \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);

#define ll int
#define SZ(a) (int)a.size()

// Printings & debugging
#define nn '\n'


const ll N = 2e5 + 10;

typedef pair<ll, ll> pll;

ll vis[N];
vector<pll> tims[N];
map<pair<int,int>, ll> dp;

int main()
{
    fast;
    ll t;
    // setIO();
    // ll tno=1;;
    ll n, m;
    cin >> n >> m;
    for (ll i = 1; i <= m; i++)
    {
        ll tt, j;
        cin >> tt >> j;
        if (vis[j] == 0)
        {
            vis[j] = tt;
        }
        else
        {
            if(vis[j]!=tt) tims[j].emplace_back(vis[j], tt);
            vis[j] = 0;
        }
    }
    // for(ll i=1;i<=n;i++) sort(all(tims[i]));
    ll q;
    cin >> q;
    while (q--)
    {
        int a, b;
        cin >> a >> b;
        if (dp.count({a, b}))
        {
            cout << dp[{a, b}] << nn;
            continue;
        }
        else if (dp.count({b,a}))
        {
            cout << dp[{b, a}] << nn;
            continue;
        }
        ll l = 0, r = 0;
        ll tot = 0;
        while (l < tims[a].size() && r < tims[b].size())
        {
            if (tims[a][l].second < tims[b][r].first)
                l++;
            else if (tims[b][r].second < tims[a][l].first)
                r++;
            else
            {
                ll st = max(tims[a][l].first, tims[b][r].first);
                ll en = min(tims[a][l].second, tims[b][r].second);
                tot += (en - st);
                if (tims[a][l].second < tims[b][r].second)
                    l++;
                else
                {
                    r++;
                }
            }
        }
        dp[{a, b}]=dp[{b,a}] = tot;
        cout << tot << nn;
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
