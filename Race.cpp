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
#define ff first

#define nn '\n'
#define mem(a, b) memset(a, b, sizeof(a))
// CONSTANTS
#define md 10000007
#define PI 3.1415926535897932384626
const double EPS = 1e-9;
const ll N = 1e3 + 10;

const ll M = 10056;


ll n, k;
ll dp[N][N];

int main()
{
    fast;
    ll t;
    // setIO();
    ll tno = 1;
    ;
    t = 1;
    cin >> t;

    dp[1][1] = 1;
    for (ll i = 2; i < N; i++)
    {
        for (ll j = 1; j <= i; j++)
        {
            dp[i][j] = (dp[i - 1][j] * j + j*dp[i - 1][j - 1]) % M;
        }
    }
    while (t--)
    {
        cout << "Case " << tno++ << ": ";
        cin >> n;
        ll ans = 0;
        for (ll i = 1; i <= n; i++)
            ans = (ans + dp[n][i]) % M;
        cout << ans << nn;
    }

    return 0;
}
