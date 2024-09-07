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
#define Setpre(n) cout << fixed << setprecision(n)
#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl
#define debug printf("I am here\n")

// CONSTANTS
#define md 10000007
#define PI acos(-1)
const double EPS = 1e-9;
const ll N = 1e6 + 10;
const ll M = 1e9 + 7;

/// INLINE FUNCTIONS
inline ll GCD(ll a, ll b) { return b == 0 ? a : GCD(b, a % b); }
inline ll LCM(ll a, ll b) { return a * b / GCD(a, b); }
inline double logb(ll base, ll num) { return (double)log(num) / (double)log(base); }

/// Data structures
typedef unsigned long long ull;
typedef pair<ll, ll> pll;
typedef vector<ll> vl;
typedef vector<pll> vpll;
typedef vector<vl> vvl;
template <typename T>
using PQ = priority_queue<T>;
template <typename T>
using QP = priority_queue<T, vector<T>, greater<T>>;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <typename T>
using ordered_multiset = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <typename T, typename R>
using ordered_map = tree<T, R, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <typename T, typename R>
using ordered_multimap = tree<T, R, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;
namespace io
{
    template <typename First, typename Second>
    ostream &operator<<(ostream &os, const pair<First, Second> &p) { return os << p.first << " " << p.second; }
    template <typename First, typename Second>
    ostream &operator<<(ostream &os, const map<First, Second> &mp)
    {
        for (auto it : mp)
        {
            os << it << endl;
        }
        return os;
    }
    template <typename First>
    ostream &operator<<(ostream &os, const vector<First> &v)
    {
        bool space = false;
        for (First x : v)
        {
            if (space)
                os << " ";
            space = true;
            os << x;
        }
        return os;
    }
    template <typename First>
    ostream &operator<<(ostream &os, const set<First> &st)
    {
        bool space = false;
        for (First x : st)
        {
            if (space)
                os << " ";
            space = true;
            os << x;
        }
        return os;
    }
    template <typename First>
    ostream &operator<<(ostream &os, const multiset<First> &st)
    {
        bool space = false;
        for (First x : st)
        {
            if (space)
                os << " ";
            space = true;
            os << x;
        }
        return os;
    }
    template <typename First, typename Second>
    istream &operator>>(istream &is, pair<First, Second> &p) { return is >> p.first >> p.second; }
    template <typename First>
    istream &operator>>(istream &is, vector<First> &v)
    {
        for (First &x : v)
        {
            is >> x;
        }
        return is;
    }

    long long fastread()
    {
        char c;
        long long d = 1, x = 0;
        do
            c = getchar();
        while (c == ' ' || c == '\n');
        if (c == '-')
            c = getchar(), d = -1;
        while (isdigit(c))
        {
            x = x * 10 + c - '0';
            c = getchar();
        }
        return d * x;
    }
    static bool sep = false;
    using std::to_string;
    string to_string(bool x) { return (x ? "true" : "false"); }
    string to_string(const string &s) { return "\"" + s + "\""; }
    string to_string(const char *s) { return "\"" + string(s) + "\""; }
    string to_string(const char &c)
    {
        string s;
        s += c;
        return "\'" + s + "\'";
    }
    template <typename Type>
    string to_string(vector<Type>);
    template <typename First, typename Second>
    string to_string(pair<First, Second>);
    template <typename Collection>
    string to_string(Collection);
    template <typename First, typename Second>
    string to_string(pair<First, Second> p) { return "{" + to_string(p.first) + ", " + to_string(p.second) + "}"; }
    template <typename Type>
    string to_string(vector<Type> v)
    {
        bool sep = false;
        string s = "[";
        for (Type x : v)
        {
            if (sep)
                s += ", ";
            sep = true;
            s += to_string(x);
        }
        s += "]";
        return s;
    }
    template <typename Collection>
    string to_string(Collection collection)
    {
        bool sep = false;
        string s = "{";
        for (auto x : collection)
        {
            if (sep)
                s += ", ";
            sep = true;
            s += to_string(x);
        }
        s += "}";
        return s;
    }
    void print()
    {
        cerr << endl;
        sep = false;
    }
    template <typename First, typename... Other>
    void print(First first, Other... other)
    {
        if (sep)
            cerr << " | ";
        sep = true;
        cerr << to_string(first);
        print(other...);
    }
}
using namespace io;


vector<ll> g(N);

vector<ll> smallest_factor;
vector<bool> prime;
vector<ll> primes;

void sieve(ll maximum)
{
    maximum = max(maximum, 2LL);
    smallest_factor.assign(maximum + 1, 0LL);
    prime.assign(maximum + 1, true);
    prime[0] = prime[1] = false;
    primes = {2};

    for (ll p = 2; p <= maximum; p += 2)
    {
        prime[p] = p == 2;
        smallest_factor[p] = 2;
    }

    for (int p = 3; p * p <= maximum; p += 2)
        if (prime[p])
            for (int i = p * p; i <= maximum; i += 2 * p)
                if (prime[i])
                {
                    prime[i] = false;
                    smallest_factor[i] = p;
                }

    for (ll p = 3; p <= maximum; p += 2)
        if (prime[p])
        {
            smallest_factor[p] = p;
            primes.push_back(p);
        }
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

int main()
{
    fast;
    ll t;
    // setIO();
    // ll tno=1;;
    t = 1;
    // cin >> t;
    sieve(N);
    ll lim = 1e3;
    while (t--)
    {
        ll n;
        cin >> n;
        vector<ll> vec(n);
        cin>>vec;
        for (ll i = 0; i < n; i++)
        {
            // cin >> vec[i];
            ll curr=vec[i];
            for (ll j = 1; j * j <= curr; j++)
            {
                if (vec[i] % j == 0)
                {
                    g[j]++;
                    ll oth = curr / j;
                    if (oth != j)
                    {
                        g[oth]++;
                    }
                }
            }
        }
        ll q;
        cin >> q;
        while (q--)
        {
            ll x;
            cin >> x;
            vector<ll> tmp;
            while (x > 1)
            {
                tmp.push_back(smallest_factor[x]);
                ll now = smallest_factor[x];
                while (x % now == 0)
                {
                    x /= now;
                }
            }
            // deb(tmp);
            ll k = 0;
            if (tmp.size() == 0)
            {
                k = n;
            }
            else
            {
                // UNIQUE(tmp);
                k = g[tmp[0]];
                vector<ll>prev[20];
                prev[0].push_back(tmp[0]);
                for (ll i = 1; i < tmp.size(); i++)
                {
                    k+=g[tmp[i]];
                    for(ll j=i-1;j>=0;j--){
                        ll ex=0;
                        for(auto it:prev[j]){
                            ll lc=tmp[i]*it;
                            ex+=g[lc];
                            prev[j+1].push_back(lc);
                        }
                        if(j%2==0) k-=ex;
                        else k+=ex;
                    }
                    prev[0].push_back(tmp[i]);
                }
                // deb(k);
                k = max(0LL,n - k);
            }
            // deb(k);
            ll ans = powerMod(2LL, k, M);
            cout << ans << nn;
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
