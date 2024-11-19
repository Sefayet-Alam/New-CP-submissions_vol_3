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
const int N = 1e4 + 7, M = 1e9 + 7;
const double pi = acos(-1.0);
int zero(int n)
{
    int bit = -1;
    for (int i = 0; i < 20; i++)
    {
        if ((n >> i) & 1)
        {
            bit = i;
            break;
        }
    }
    return bit;
}
int a[N], pos[N];
vector<pair<int, int>> ans;
void Swap(int x, int y)
{
    ans.push_back({x, y});
    swap(a[x], a[y]);
    swap(pos[a[x]], pos[a[y]]);
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
    cin >> t;
    for (int tc = 1; tc <= t; tc++)
    {
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
            pos[a[i]] = i;
        }
        ans.clear();
        if (n & (n + 1))
        {
            cout << 0 << nl;
        }
        else
        {
            if (pos[n] == n)
                cout << 0 << nl;
            else
            {
                cout << 1 << nl;
                int st = zero(pos[n]);
                Swap(pos[n], 1 << st);
                if (st == 0)
                    Swap(1, n);
                else
                {
                    Swap(1 << st, 1);
                    Swap(1, n);
                }
            }
        }

        for (int i = n; i >= 1; i--)
        {
            if (pos[i] == i)
                continue;
            if (!(i & (i - 1)))
                continue;

            int st = zero(pos[i]);
            int ed = zero(i);

            if (st == ed)
            {
                if (pos[i] != 1 << st)
                    Swap(pos[i], 1 << st);
                Swap(1 << st, i);
            }
            else
            {
                if (pos[i] != 1 << st)
                    Swap(pos[i], 1 << st);
                Swap(1 << st, 1 << ed);
                Swap(1 << ed, i);
            }
        }
        for (int i = n; i >= 1; i--)
        {
            if (!(i & (i - 1)))
            {
                if (pos[i] != i)
                {
                    Swap(pos[i], i);
                }
            }
        }
        cout << ans.size() << nl;
        for (auto i : ans)
        {
            cout << i.ff << " " << i.ss << nl;
        }
    }
}