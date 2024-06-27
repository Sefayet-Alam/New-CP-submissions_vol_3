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

#define ll int

const int N=5010;
// Divide 1,2,3...n people in k consecutive parts so that sum of cost of each individual part is minimum
ll a[N][N], c[N][N], dp[810][N]; // dp[i][j]=minimum cost for dividing [1...j] into i parts
ll cost(int i, int j)
{
    if (i > j)
        return 0;
    return c[j][j] - c[i - 1][j] - c[j][i - 1] + c[i - 1][i - 1];
}
void DivideConquer(ll i, ll l, ll r, ll optl, ll optr)
{
    if (l > r)
        return;
    ll mid = (l + r) / 2;
    dp[i][mid] = 0; // for maximum cost change it to 0
    ll opt = -1;
    for (ll k = optl; k <= min(mid, optr); k++)
    {
        ll c = dp[i - 1][k] + cost(k + 1, mid);
        if (c > dp[i][mid])
        { // for maximum cost just change < to > only and rest of the algo should not be changed
            dp[i][mid] = c;
            opt = k;
        }
    }
    // for opt[1..j]<=opt[1...j+1] i.e. cost(1,j)<=cost(1,j+1)
    DivideConquer(i, l, mid - 1, optl, opt);
    DivideConquer(i, mid + 1, r, opt, optr);
    // for opt[1...j]>=opt[1...j+1] i.e. cost(1,j)>=cost(1,j+1)
    // yo(i,l,mid-1,opt,optr);
    // yo(i,mid+1,r,optl,opt);
}

int main()
{
    fast;
    ll n, k;
    cin >> n >> k;
    for (ll i = 1; i <= n; i++)
        for (ll j = 1; j <= n; j++)
            cin >> a[i][j];
    for (ll i = 1; i <= n; i++)
    {
        
        for (ll j = 1; j <= n; j++)
        {
            c[i][j] = a[i][j] + c[i - 1][j] + c[i][j - 1] - c[i - 1][j - 1];
        }
    }
    for (ll i = 1; i <= n; i++)
        dp[1][i] = cost(1, i);
    for (ll i = 2; i <= k; i++)
        DivideConquer(i, 1, n, 1, n);
    cout << dp[k][n] / 2 << endl;

    return 0;
}

/* Points tO CONSIDER
    # RTE? -> check array bounds and constraints
    #TLE? -> thinks about binary search/ dp / optimization techniques
    # WA?
    -> overflow,reset global variables
    -> Check corner cases
    -> think from different approaches
    -> bruteforce to find pattern
    -> use Setpre for precision problems
*/
