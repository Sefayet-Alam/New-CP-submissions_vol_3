#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
int T, n, m, dfn[N], dp[N], low[N], st[N], tp, fa[N][18], up[N];
char c[N];
vector<int> e[N];
vector<pair<int, int>> E;
int lca(int x, int y)
{
    if (dp[x] < dp[y])
        swap(x, y);
    for (int i = 17; ~i; --i)
        if (dp[fa[x][i]] >= dp[y])
            x = fa[x][i];
    if (x == y)
        return x;
    for (int i = 17; ~i; --i)
        if (fa[x][i] != fa[y][i])
            x = fa[x][i], y = fa[y][i];
    return fa[x][0];
}
void tarjan(int x)
{
    dfn[x] = low[x] = ++dfn[0], st[++tp] = x, up[x] = dp[x] = dp[fa[x][0]] + 1;
    for (int i = 1; i < 18; ++i)
        fa[x][i] = fa[fa[x][i - 1]][i - 1];
    for (auto v : e[x])
    {
        if (!dfn[v])
        {
            fa[v][0] = x;
            tarjan(v);
            low[x] = min(low[x], low[v]);
            if (low[v] < dfn[x])
                continue;
            do
            {
                up[st[tp--]] = dp[x];
            } while (st[tp + 1] != v);
        }
        else
            low[x] = min(low[x], dfn[v]);
    }
}
void solve()
{
    scanf("%d%d%s", &n, &m, c + 1);
    for (int i = 1; i <= n; ++i)
        e[i].clear(), dfn[i] = low[i] = 0;
    E.clear(), dfn[0] = tp = 0;
    for (int i = 1, x, y; i <= m; ++i)
    {
        scanf("%d%d", &x, &y);
        ++x, ++y;
        if (c[x] == c[y])
            E.emplace_back(x, y);
        else
            e[x].push_back(y), e[y].push_back(x);
    }
    tarjan(1);
    for (auto [x, y] : E)
        if (dfn[x] && dfn[y])
        {
            int z = lca(x, y);
            if (z == x || z == y || up[x] < dp[z] || up[y] < dp[z])
                return puts("yes"), void();
        }
    puts("no");
}
int main()
{
    scanf("%d", &T);
    while (T--)
        solve();
    return 0;
}