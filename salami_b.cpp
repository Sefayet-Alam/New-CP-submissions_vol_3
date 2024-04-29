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
const ll N = 1e2 + 10;
const ll M = 1e9 + 9;

ll FM[N];
ll nrm[N][N];
int is_initialized = 0;
ll factorialMod(ll n, ll x){
    if (!is_initialized){
        FM[0] = 1 % x;
        for (int i = 1; i < N; i++)
            FM[i] = (FM[i - 1] * i) % x;
        is_initialized = 1;
    }
    return FM[n];
}

ll powerMod(ll x, ll y, ll p){
    ll res = 1 % p;
    x = x % p;
    while (y > 0){
        if (y & 1) res = (res * x) % p;
        y = y >> 1;
        x = (x * x) % p;
    }
    return res;
}

ll inverseMod(ll a, ll x){
    return powerMod(a, x - 2, x);
}

ll nCrMod(ll n, ll r, ll x){
    if (r == 0) return 1;
    if (r > n) return 0;
    ll res = factorialMod(n, x);
    ll fr = factorialMod(r, x);
    ll zr = factorialMod(n - r, x);
    res = (res * inverseMod((fr * zr) % x, x)) % x;
    return res;
}

ll n,k;
ll dp[105][105];

ll func(ll i,ll curr){
    if(i==k){
        if(curr==n) return 1;
        else return 0;
    }
    if(curr==n) return dp[i][curr]=1;
    if(dp[i][curr]!=-1) return dp[i][curr];
    ll ans=0;
    for(ll j=1;j+curr<=n;j++){
        ans=(ans+(nrm[n-curr][j]*func(i+1,curr+j)));
    }
    return dp[i][curr]=ans%M;
}

int main()
{
    fast;
    ll t;
    // setIO();
    // ll tno=1;;
    t = 1;
    cin >> t;
    for(ll i=0;i<=105;i++){
        for(ll j=0;j<=105;j++){
            nrm[i][j]=nCrMod(i,j,M);
        }
    }
    while (t--)
    {
      cin>>n>>k;
      for(ll i=0;i<=k+2;i++){
        for(ll j=0;j<=n+2;j++) dp[i][j]=-1;
      }
      ll ans=func(0,0);
      cout<<ans<<nn;
    }

    return 0;
}
