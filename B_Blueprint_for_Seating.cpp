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

#define ll unsigned long long
#define SZ(a) (int)a.size()
#define UNIQUE(a) (a).erase(unique(all(a)), (a).end())
#define mp make_pair
#define mem(a, b) memset(a, b, sizeof(a))
#define all(x) x.begin(), x.end()

// Printings & debugging
#define nn '\n'
#define Setpre(n) cout << fixed << setprecision(n)
#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl
#define debug printf("I am here\n")

// CONSTANTS
#define md 10000007
#define PI acos(-1)
const double EPS = 1e-9;
const ll N = 1e5 + 10;
const ll M = 998244353;

/// INLINE FUNCTIONS
inline ll GCD(ll a, ll b) { return b == 0 ? a : GCD(b, a % b); }
inline ll LCM(ll a, ll b) { return a * b / GCD(a, b); }
inline double logb(ll base, ll num) { return (double)log(num) / (double)log(base); }

ll FM[N];
int is_initialized = 0;
ll factorialMod(ll n, ll x)
{
    if (!is_initialized)
    {
        FM[0] = 1 % x;
        for (int i = 1; i < N; i++)
            FM[i] = (FM[i - 1] * i) % x;
        is_initialized = 1;
    }
    return FM[n];
}

ll powerMod(ll x, ll y, ll p)
{
    ll res = 1 % p;
    x = x % p;
    while (y > 0)
    {
        if (y & 1)
            res = (res * x) % p;
        y = y >> 1;
        x = (x * x) % p;
    }
    return res;
}

ll inverseMod(ll a, ll x)
{
    return powerMod(a, x - 2, x);
}

ll nCrMod(ll n, ll r, ll x)
{
    if (r == 0)
        return 1;
    if (r > n)
        return 0;
    ll res = factorialMod(n, x);
    ll fr = factorialMod(r, x);
    ll zr = factorialMod(n - r, x);
    res = (res * inverseMod((fr * zr) % x, x)) % x;
    return res;
}

ll n, k;

bool func(ll pos)
{
    ll curr = max(k + 1, 2 * pos * k);
    return curr <= n;
}
ll bs(ll low, ll high)
{
    ll mid;
    ll ans = 0;
    while (low <= high)
    {
        mid = low + (high - low) / 2;
        // cout<<mid<<" "<<func(mid)<<endl;
        if (func(mid))
        {
            ans = mid;
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return ans;
}

int main()
{
    fast;
    ll t;
    // setIO();
    // ll tno=1;;
    t = 1;
    cin >> t;

    while (t--)
    {
        cin >> n >> k;
        ll seats = bs(0, n + 2);
        ll rest = n - max(k + 1, 2 * seats * k);
        if (seats == 0)
        {
           
            ll ans = nCrMod(k - 1, rest, M);
            cout << 0 << " " << ans % M << nn;
        }
        else
        {
            ll ans = 0;
            for (ll i = 0; i <= k - 1; i++)
            {
                ll ex = (nCrMod(k - 1, i, M) * nCrMod(k + 1 - i, rest - 2 * i, M)) ;
                ans = (ans + ex) % M;
            }
            ll cost = seats * (seats - 1) * k + rest * seats;
            ans%=M;
            cout << cost << " " << ans % M << nn;
        }
    }

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
