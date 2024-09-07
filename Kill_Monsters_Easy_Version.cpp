#include <bits/stdc++.h>
using namespace std;
#define fastio()                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
#define MOD 1000000007
#define MOD1 998244353
#define INF 1e18
#define PI 3.141592653589793238462
#define int long long
int pri[1000100];

vector<int> getdiv(int n)
{
    vector<int> ans;
    for (int i = 1; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            if (pri[i] == 1)
                ans.push_back(i);
            if (i != n / i && pri[n / i] == 1)
                ans.push_back(n / i);
        }
    }
    sort(ans.begin(), ans.end());
    ans.erase(unique(ans.begin(), ans.end()), ans.end());
    return ans;
}
void sieve()
{
    fill(pri + 2, pri + 1000100, 1);
    for (int i = 2; i * i <= 1e6; i++)
    {
        if (pri[i] == 1)
        {
            for (int j = i * i; j <= 1e6; j += i)
            {
                pri[j] = 0;
            }
        }
    }
}
bool check(vector<int> a, int mid, int x, int k)
{
    int cnt = 0, flag = 0;
    int n = a.size();
    for (int i = 0; i < n; i++)
    {
        if (x > a[i] && flag == 0)
            x = a[i], cnt++;
        else if (x > a[i] && flag == 1)
            x = a[i], cnt++;
        else if (x * k > a[i] && flag == 0)
        {
            flag = 1, x = a[i], cnt++;
        }
    }
    if (cnt >= mid)
        return true;
    else
        return false;
}

signed solve()
{
    int n, x, k;
    cin >> n >> x >> k;
    map<int, int> m;
    vector<int> s, ones;
    int y;
    for (int i = 0; i < n; i++)
    {
        cin >> y;
        m[y]++;
    }
    for (auto i : m)
    {
        if (i.second == 1)
            ones.push_back(i.first);
        s.push_back(i.first);
    }
    int ans = 0, cnt = 0;

    for (int i = s.size() - 1; i >= 0; i--)
    {
        if (s[i] < (x * k))
        {
            ans = (i + 1);
            break;
        }
    }

    for (int i = s.size() - 1; i >= 0; i--)
    {
        if (s[i] >= x)
            continue;

        cnt++;
        int tm = lower_bound(s.begin(), s.end(), s[i] * k) - s.begin();
        int mxR = min(x, s[i] * k);
        int sm = (lower_bound(ones.begin(), ones.end(), mxR)) - (lower_bound(ones.begin(), ones.end(), s[i]));
        ans = max(ans, cnt + tm - sm);
    }

    cout << ans << endl;
    return 0;
}

signed main()
{
    fastio();
    int testcase;
    cin >> testcase;
    while (testcase--)
    {
        solve();
    }
    return 0;
}