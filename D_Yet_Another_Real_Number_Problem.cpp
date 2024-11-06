#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 9, inf = 1e9, mod = 1e9 + 7;
using ll = long long;
using T = pair<int, int>;

T t[N][19];
int a[N];
void build(int n)
{
    for (int i = 1; i <= n; ++i)
        t[i][0] = T(a[i], i);
    for (int k = 1; k < 19; ++k)
    {
        for (int i = 1; i + (1 << k) - 1 <= n; ++i)
        {
            t[i][k] = max(t[i][k - 1], t[i + (1 << (k - 1))][k - 1]);
        }
    }
}

T query(int l, int r)
{
    int k = 31 - __builtin_clz(r - l + 1);
    return max(t[l][k], t[r - (1 << k) + 1][k]);
}

int sum[N], pw[N], x[N];
void solve()
{
    int n;
    cin >> n;
    sum[0] = 0;
    pw[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        x[i] = 0;
        while (a[i] % 2 == 0)
        {
            a[i] /= 2;
            x[i]++;
        }
        sum[i] = (sum[i - 1] + a[i]) % mod;
        pw[i] = 1LL * pw[i - 1] * (1 << x[i]) % mod;
    }
    build(n);
    vector<int> v;
    for (int i = 1; i <= n; i++)
    {
        if (x[i])
        {
            v.push_back(i);
        }
        ll cur = 0;
        int j = i + 1;
        int ans = sum[i];
        for (int k = (int)v.size() - 1; k >= 0; k--)
        {
            int id = v[k];
            if (id + 1 < j)
            {
                auto [x, y] = query(id + 1, j - 1);
                if (x > cur)
                {
                    ans = (ans + cur % mod) % mod;
                    cur = x;
                    j = y;
                    ans = (ans - a[j] + mod) % mod;
                }
            }

            if (a[id] <= cur)
            {
                cur *= 1 << x[id];
            }
            else
            {
                ans = (ans + cur % mod) % mod;
                cur = a[id] * (1LL << x[id]);
                j = id;
                ans = (ans - a[j] + mod) % mod;
            }

            if (cur > inf)
            {
                cur = cur % mod * pw[id - 1] % mod;
                ans = (ans + cur) % mod;
                cur = 0;
                break;
            }
        }
        ans = (ans + cur % mod) % mod;
        cout << ans << ' ';
    }
    cout << '\n';
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}