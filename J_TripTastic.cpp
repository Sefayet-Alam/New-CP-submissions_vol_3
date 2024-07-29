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

#define ll long long
#define SZ(a) (int)a.size()
#define UNIQUE(a) (a).erase(unique(all(a)), (a).end())
#define mp make_pair
#define mem(a, b) memset(a, b, sizeof(a))
#define all(x) x.begin(), x.end()

// Printings & debugging
#define nn '\n'




int main()
{
    fast;
    ll t;
    // setIO();
    // ll tno=1;
    t = 1;
    cin >> t;

    while (t--)
    {
        ll n, m, k;
        cin >> n >> m >> k;

        // Initialize arrays with extra space
        vector<vector<ll>> arr(n + 3, vector<ll>(m + 3, 0));
        vector<vector<ll>> pfsum(n + 3, vector<ll>(m + 3, 0));

        ll sum = 0;
        for (ll i = 1; i <= n; i++)
        {
            for (ll j = 1; j <= m; j++)
            {
                cin >> arr[i][j];
                sum += arr[i][j];
            }
        }

        if (sum < k + 1)
        {
            cout << -1 << nn;
            continue;
        }

        for (ll i = 1; i <= n; i++)
        {
            for (ll j = 1; j <= m; j++)
            {
                pfsum[i][j] = arr[i][j] + pfsum[i - 1][j] + pfsum[i][j - 1] - pfsum[i - 1][j - 1];
            }
        }

        auto getSum = [&](ll a, ll b, ll c, ll d) -> ll
        {
            return pfsum[c][d] - pfsum[a - 1][d] - pfsum[c][b - 1] + pfsum[a - 1][b - 1];
        };

        auto func = [&](ll pos) -> bool
        {
            for (ll i = 1; i <= n; i++)
            {
                for (ll j = 1; j <= m; j++)
                {
                    if (arr[i][j] == 0)
                        continue;
                    ll lfi = max(i - pos, 1LL);
                    ll lfj = max(j - pos, 1LL);
                    ll rgi = min(i + pos, n);
                    ll rgj = min(j + pos, m);

                    ll noww = getSum(lfi, lfj, rgi, rgj);
                    if (noww >= k + 1)
                        return true;
                }
            }
            return false;
        };

        auto bs = [&](ll low, ll high) -> ll
        {
            ll mid;
            ll ans = high;
            while (low <= high)
            {
                mid = low + (high - low) / 2;
                if (func(mid))
                {
                    ans = mid;
                    high = mid - 1;
                }
                else
                {
                    low = mid + 1;
                }
            }
            return ans;
        };

        ll l = 0, r = max(n, m) + 1;
        ll ans = bs(l, r);
        cout << ans << nn;
    }

    return 0;
}