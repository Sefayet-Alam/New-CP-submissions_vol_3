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
#define mp make_pair


#define nn '\n'

#define mem(a, b) memset(a, b, sizeof(a))
#define all(x) x.begin(), x.end()
#define rev(x) reverse(all(x))

// CONSTANTS
#define md 10000007
#define PI 3.1415926535897932384626
const double EPS = 1e-9;
const ll N = 2e3 + 10;
const ll M = 1e9 + 7;



/// Data structures
typedef unsigned long long ull;
typedef pair<ll, ll> pll;
typedef vector<ll> vl;
typedef vector<pll> vpll;
typedef vector<vl> vvl;
template <typename T>
using PQ = priority_queue<T>;
template <typename T>
using QP = priority_queue<T, vector<T>, greater<T>>;

template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <typename T, typename R>
using ordered_map = tree<T, R, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
;



vpll g[N];
ll dist[N][1024];
vl musk(N, 0);
ll n, m, x, y, k, w;

void dijkstra(ll source)
{
    QP<pair<ll, pll>> pq;
    ll srcmsk = musk[source];
    
    pq.push({0, {source, srcmsk}});

    dist[source][srcmsk] = 0;
    while (pq.size())
    {
        
        auto currr=pq.top();
        
        ll v = currr.second.first;
        ll v_dist = currr.first;
        ll currmsk = currr.second.second;
        // cout<<v_dist<<" "<<currmsk<<" "<<v<<nn;
        pq.pop();
        // if (dist[v][currmsk] < v_dist)
        //     continue;
        for (auto &child : g[v])
        {
            ll child_v = child.first;
            ll wt = child.second;
            ll childmsk = currmsk | musk[child_v];
            if (v_dist + wt < dist[child_v][childmsk])
            {
                dist[child_v][childmsk] = v_dist + wt;
                pq.push({dist[child_v][childmsk], {child_v, childmsk}});
            }
        }
    }
}

void reset()
{
    for (ll i = 0; i <= n + 10; i++)
    {
        g[i].clear();
        musk[i]=0;
        for (ll j = 0; j < 1024; j++)
            dist[i][j] = LLONG_MAX;
    }
}

int main()
{
    fast;
    ll t;
    // setIO();
    // ll tno=1;;
    t = 1;
    // cin>>t;

    while (t--)
    {
        cin >> n >> m >> k;
        ll totmsk = ((1LL << k) - 1);
        reset();
        for (ll i = 1; i <= n; i++)
        {
            cin >> x;
            for (ll j = 0; j < x; j++)
            {
                cin >> y;
                y--;
                musk[i] |= (1<<y);
            }
        }
        for (ll i = 0; i < m; i++)
        {
            cin >> x >> y >> w;
            g[x].push_back({y, w});
            g[y].push_back({x, w});
        }
        dist[1][musk[1]]=0;
        dijkstra(1);
        // for(ll i=1;i<=n;i++) cout<<g[i]<<nn;
        
        ll ans = LLONG_MAX;
        for(ll i=0;i<=totmsk;i++){
            for(ll j=0;j<=totmsk;j++){
                if( (i | j ) == totmsk){
                    ll curr=max(dist[n][i],dist[n][j]);
                    // cout<<curr<<nn;
                    ans=min(ans,curr);
                }
            }
        }
        // cout<<dist[n][totmsk]<<nn;
        cout << ans << nn;
    }

    return 0;
}
