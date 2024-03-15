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
#define ll long long int
#define nn "\n"

struct custom_hash
{
    static uint64_t splitmix64(uint64_t x)
    {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }
    size_t operator()(uint64_t x) const
    {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

const ll mod = (1e9 + 181)*1LL;
const ll M = 1e9+1011;


ll power(ll a,ll b,ll mod)
{   
    ll res = 1;   
    a=a%mod; 
    if (a==0) return 0; 
    while (b>0)
    {
        if (b&1) res=(res*a)%mod;
        b /=2;
        a=(a*a)%mod;
    }
    return res;
}

int main()
{
    fast;
    ll t;
    // setIO();
    // ll tno=1;;
    t = 1;
    // cin>>t;
    while (t--)
    {
        string s, p;
        cin >> s >> p;
        ll n = s.size();
        ll m = p.size();

        ll ans = 0;
        for (ll i = 1; i <= n; i++)
        {
            ll curr = 0;
            unordered_map<ll, bool> mpp;
            vector<ll> hashes(n + 1, 0), hashes2(m + 1, 0);

            for (ll j = 0; j < n; j++)
            {
                ll aa = s[j] - 'a' + 1;
                curr = ((aa)*power(mod, aa,M));
                hashes[j + 1] = curr;

                hashes[j + 1] = (hashes[j + 1] + hashes[j]);
                if (j + 1 - i >= 0)
                {
                    ll val = (hashes[j + 1] - hashes[j + 1 - i]);
                    mpp[val] = 1;
                }
            }
            curr = 0;
            for (ll j = 0; j < m; j++)
            {
                ll aa = p[j] - 'a' + 1;
                // curr = ((aa)*power(mod, aa, M));
                 curr = ((aa)*power(mod, aa,M));
                hashes2[j + 1] = curr;

                hashes2[j + 1] = (hashes2[j + 1] + hashes2[j]);
                if (j + 1 - i >= 0)
                {
                    ll val = (hashes2[j + 1] - hashes2[j + 1 - i]);
                    if (mpp[val])
                    {
                        ans = max(ans, i);
                    }
                }
            }
        }

        cout << ans << nn;
    }
    return 0;
}