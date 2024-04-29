#include <bits/stdc++.h>
using namespace std;

#define zedanov                   \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);
#define ll long long
#define el "\n"

const int LCM = 2520;
ll mem[19][2][2][(1 << 9) + 5][LCM];

string a, b;
int k;
ll solve(int i, bool canDown, bool canExceed, int msk, int rem)
{
    if (i == a.size())
    {
        int cnt = 0;
        for (int d = 1; d <= 9; d++)
        {
            if (msk & (1 << (d - 1)))
            {
                cnt += (rem % d == 0);
            }
        }
        return cnt >= k;
    }

    ll &ret = mem[i][canDown][canExceed][msk][rem];
    if (~ret)
        return ret;
    ret = 0;
    int l = a[i] - '0', r = b[i] - '0';
    for (int d = 0; d <= 9; d++)
    {
        if (!canDown && d < l)
            continue;
        if (!canExceed && d > r)
            continue;
        if (d)
            ret += solve(i + 1, canDown | (d > l), canExceed | (d < r), msk | (1 << (d - 1)), (rem * 10 + d) % LCM);
        else
            ret += solve(i + 1, canDown | (d > l), canExceed | (d < r), msk, (rem * 10 + d) % LCM);
    }
    return ret;
}
void doWork()
{
    cin >> a >> b >> k;
    while (a.size() != b.size())
        a = '0' + a;
    memset(mem, -1, sizeof mem);
    cout << solve(0, 0, 0, 0, 0) << el;
}

signed main()
{
    zedanov int t = 1;
    cin >> t;
    while (t--)
        doWork();

    return 0;
}