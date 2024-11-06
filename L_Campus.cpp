// Problem: L. Campus
// Contest: Codeforces - 2024 (ICPC) Jiangxi Provincial Contest -- Official Contest
// URL: https://codeforces.com/gym/105231/problem/L
// Memory Limit: 1024 MB
// Time Limit: 2000 ms
//
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
#define fastread() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define nl "\n"
#define ll long long
#define all(x) x.begin(), x.end()
#define ff first
#define ss second
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <typename T>
using ordered_multiset = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;
const int N = 1e5 + 7, M = 1e9 + 7;
const double pi = acos(-1.0);
int n, m, k, T, a[N];
ll ans[N];
map<int, set<int>> suru, ses;

vector<pair<int, int>> g[N];
int dist[N];
void dijkstra(set<int> source)
{
    set<pair<int, int>> st;
    for (auto i : source)
    {
        st.insert({0, i});
        dist[i] = 0;
    }

    while (st.size() > 0)
    {
        auto node = *st.begin();
        int v = node.second;
        int v_dist = node.first;
        st.erase(st.begin());
        if (dist[v] < v_dist)
            continue;
        for (auto child : g[v])
        {
            int child_v = child.first;
            int wt = child.second;
            if (dist[v] + wt < dist[child_v])
            {
                dist[child_v] = dist[v] + wt;
                st.insert({dist[child_v], child_v});
            }
        }
    }
}

int main()
{
    fastread();
    if (fopen("input.in", "r"))
    {
        freopen("input.in", "r", stdin);
        freopen("output.out", "w", stdout);
    }
    int t = 1;
    // cin>>t;
    for (int tc = 1; tc <= t; tc++)
    {
        cin >> n >> m >> k >> T;
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
        }
        for (int i = 1; i <= k; i++)
        {
            int p, l, r;
            cin >> p >> l >> r;
            suru[l].insert(p);
            ses[r + 1].insert(p);
        }
        for (int i = 1; i <= m; i++)
        {
            int u, v, w;
            cin >> u >> v >> w;
            g[u].push_back({v, w});
            g[v].push_back({u, w});
        }

        set<int> cur;

        ans[0] = -1;
        for (int i = 1; i <= T; i++)
        {
            if (suru.find(i) != suru.end())
            {
                for (auto j : suru[i])
                    cur.insert(j);
                for (auto j : ses[i])
                    cur.erase(j);

                for (int j = 1; j <= n; j++)
                    dist[j] = INT_MAX;
                dijkstra(cur);

                for (int j = 1; j <= n; j++)
                {
                    if (dist[j] == INT_MAX)
                    {
                        ans[i] = -1;
                        break;
                    }
                    ans[i] += ((ll)dist[j] * a[j]);
                }
            }
            else
            {
                if (ses.find(i) != ses.end())
                {
                    for (auto j : ses[i])
                        cur.erase(j);
                    for (int j = 1; j <= n; j++)
                        dist[j] = INT_MAX;
                    dijkstra(cur);

                    for (int j = 1; j <= n; j++)
                    {
                        if (dist[j] == INT_MAX)
                        {
                            ans[i] = -1;
                            break;
                        }
                        ans[i] += ((ll)dist[j] * a[j]);
                    }
                }
                else
                    ans[i] = ans[i - 1];
            }
        }
        for (int i = 1; i <= T; i++)
            cout << ans[i] << nl;
    }
}