#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 2e6 + 10;
ll n, l, r;
ll dis[N], ans = 0;
vector<ll> e[N];
queue<int> q;
void bfs(int s)
{
    memset(dis, 0x3f, sizeof(dis));
    q.push(s);
    dis[s] = 0;
    while (!q.empty())
    {
        ll x = q.front();
        q.pop();
        for (auto y : e[x])
        {
            if (dis[y] > dis[x] + 1)
            {
                dis[y] = dis[x] + 1;
                q.push(y);
            }
        }
    }
}
ll ask(ll l, ll r)
{
    ll tmp = 1, sum = 0;
    if (l > r)
    {
        swap(l, r);
        tmp = -1;
    }
    ll i = log2(r - l), j = (l >> i);
    cout << "? " << i << ' ' << j << '\n';
    cout.flush();
    cin >> sum;
    return (sum % 100) * tmp;
}
int main()
{
    cin >> n >> l >> r;
    r++;
    for (ll i = 0; i <= n; i++)
    {
        for (ll j = 0; j < (1 << n); j += (1 << i))
        {
            e[j].push_back(j + (1 << i));
            e[j + (1 << i)].push_back(j);
        }
    }
    bfs(l);
    while (r != l)
    {
        for (auto v : e[r])
        {
            if (dis[r] == dis[v] + 1)
            {
                ans = (ans + ask(v, r) + 100) % 100;

                r = v;
                break;
            }
        }
    }
    cout << "! " << ans;
    return 0;
}
//seff