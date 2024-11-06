#include <bits/stdc++.h>
#define int long long int
using namespace std;

#ifndef ONLINE_JUDGE
// #include "debug.h"
#endif
const int mod = 1e9 + 7, inf = 1e18, N = 3e5 + 5;

int add(int a, int b)
{
    a %= mod, b %= mod;
    a += b;
    return a % mod;
}

struct dt
{
    int val, cnt;
    dt()
    {
        val = inf, cnt = 0;
    }
};

dt marge(dt a, dt b)
{
    dt res;
    if (a.val < b.val)
    {
        res.val = a.val;
        res.cnt = a.cnt;
    }
    else if (a.val > b.val)
    {
        res.val = b.val;
        res.cnt = b.cnt;
    }
    else
    {
        res.val = a.val;
        res.cnt = add(a.cnt, b.cnt);
    }
    return res;
}
dt tree[4 * N];
int a[N], b[N];

void build(int node, int st, int en)
{
    if (st == en)
    {
        if (st == 0)
        {
            tree[node].val = 0;
            tree[node].cnt = 1;
        }
        else
        {
            tree[node].val = inf;
            tree[node].cnt = 0;
        }
        return;
    }
    int mid = (st + en) / 2;
    build(2 * node, st, mid);
    build(2 * node + 1, mid + 1, en);
}

void update(int node, int st, int en, int i, dt val)
{
    if (st == en)
    {
        tree[node] = marge(tree[node], val);
        return;
    }
    int mid = (st + en) / 2;
    if (i <= mid)
    {
        update(2 * node, st, mid, i, val);
    }
    else
    {
        update(2 * node + 1, mid + 1, en, i, val);
    }
    tree[node] = marge(tree[2 * node], tree[2 * node + 1]);
}

dt query(int node, int st, int en, int l, int r)
{
    if (st > r || en < l)
    {
        dt res;
        res.val = inf;
        res.cnt = 0;
        return res;
    }
    if (st >= l && en <= r)
    {
        return tree[node];
    }
    int mid = (st + en) / 2;
    return marge(query(2 * node, st, mid, l, r), query(2 * node + 1, mid + 1, en, l, r));
}

void solve()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        a[i] += a[i - 1];
    }
    for (int i = 1; i <= m; i++)
        cin >> b[i];

    build(1, 0, n);
    for (int j = 1; j <= m; j++)
    {
        int l = 1;
        for (int i = 1; i <= n; i++)
        {
            while (a[i] - a[l - 1] > b[j])
            {
                l++;
            }
            dt res = query(1, 0, n, l - 1, i - 1);
            res.val += m - j;
            update(1, 0, n, i, res);
        }
    }
    dt res = query(1, 0, n, n, n);
    if (res.val == inf)
    {
        cout << "-1\n";
        return;
    }
    cout << res.val << " " << res.cnt << '\n';
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    cin >> t;
    for (int cs = 1; cs <= t; cs++)
    {
        // cout << "Case " << cs << ": ";
        solve();
    }
    return 0;
}