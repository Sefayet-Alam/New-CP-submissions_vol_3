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


// Printings & debugging
#define nn '\n'


const double EPS = 1e-9;
const ll N = 5e5 + 3;

/// INLINE FUNCTIONS
inline ll GCD(ll a, ll b) { return b == 0 ? a : GCD(b, a % b); }
inline ll LCM(ll a, ll b) { return a * b / GCD(a, b); }
inline double logb(ll base, ll num) { return (double)log(num) / (double)log(base); }

/// Data structures
typedef unsigned long long ull;
typedef pair<ll, ll> pll;
typedef vector<ll> vl;

vl divisors[N];

void divisor_store()
{
    for (int i = 1; i < N; i++)
    {
        for (int j = i; j < N; j += i)
        {
            divisors[j].push_back(i);
        }
    }
}

int main()
{
    fast;
    ll t;
    // setIO();
    // ll tno=1;;
    t = 1;
    cin >> t;
    divisor_store();
    // deb(divisors[4]);
    while (t--)
    {
        ll n;
        cin >> n;
        map<pll, ll> mpp;
        ll ans = 0;
        for (ll i = 1; i <= n; i++)
        {
            ll x;
            cin >> x;
            // deb(x);
            ll g = GCD(x, i);
            x = x / g;
            ll d = i / g;
            for (auto it : divisors[x])
            {
                if(mpp.count({d,it})) ans += mpp[{d, it}];
                mpp[{it, d}]++;
            }
        }
        //   deb(vec);
        cout << ans << nn;
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
