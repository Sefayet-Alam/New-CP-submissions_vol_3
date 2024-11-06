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
const ll N = 2e5 + 10;
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

ll power(ll n, ll k, const ll mod)
{
    ll ans = 1 % mod;
    n %= mod;
    while (k)
    {
        if (k & 1)
            ans = __int128(ans) * n % mod;
        n = __int128(n) * n % mod;
        k >>= 1;
    }
    return ans;
}
namespace PollardRho
{
    mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
    const int P = 1e6 + 9;
    ll seq[P];
    int primes[P], spf[P];
    inline ll add_mod(ll x, ll y, ll m)
    {
        return (x += y) < m ? x : x - m;
    }
    inline ll mul_mod(ll x, ll y, ll m)
    {
        ll res = __int128(x) * y % m;
        return res;
        // ll res = x * y - (ll)((long double)x * y / m + 0.5) * m;
        // return res < 0 ? res + m : res;
    }
    inline ll pow_mod(ll x, ll n, ll m)
    {
        ll res = 1 % m;
        for (; n; n >>= 1)
        {
            if (n & 1)
                res = mul_mod(res, x, m);
            x = mul_mod(x, x, m);
        }
        return res;
    }
    // O(it * (logn)^3), it = number of rounds performed
    inline bool miller_rabin(ll n)
    {
        if (n <= 2 || (n & 1 ^ 1))
            return (n == 2);
        if (n < P)
            return spf[n] == n;
        ll c, d, s = 0, r = n - 1;
        for (; !(r & 1); r >>= 1, s++)
        {
        }
        // each iteration is a round
        for (int i = 0; primes[i] < n && primes[i] < 32; i++)
        {
            c = pow_mod(primes[i], r, n);
            for (int j = 0; j < s; j++)
            {
                d = mul_mod(c, c, n);
                if (d == 1 && c != 1 && c != (n - 1))
                    return false;
                c = d;
            }
            if (c != 1)
                return false;
        }
        return true;
    }
    void init()
    {
        int cnt = 0;
        for (int i = 2; i < P; i++)
        {
            if (!spf[i])
                primes[cnt++] = spf[i] = i;
            for (int j = 0, k; (k = i * primes[j]) < P; j++)
            {
                spf[k] = primes[j];
                if (spf[i] == spf[k])
                    break;
            }
        }
    }
    // returns O(n^(1/4))
    ll pollard_rho(ll n)
    {
        while (1)
        {
            ll x = rnd() % n, y = x, c = rnd() % n, u = 1, v, t = 0;
            ll *px = seq, *py = seq;
            while (1)
            {
                *py++ = y = add_mod(mul_mod(y, y, n), c, n);
                *py++ = y = add_mod(mul_mod(y, y, n), c, n);
                if ((x = *px++) == y)
                    break;
                v = u;
                u = mul_mod(u, abs(y - x), n);
                if (!u)
                    return __gcd(v, n);
                if (++t == 32)
                {
                    t = 0;
                    if ((u = __gcd(u, n)) > 1 && u < n)
                        return u;
                }
            }
            if (t && (u = __gcd(u, n)) > 1 && u < n)
                return u;
        }
    }
    vector<ll> factorize(ll n)
    {
        if (n == 1)
            return vector<ll>();
        if (miller_rabin(n))
            return vector<ll>{n};
        vector<ll> v, w;
        while (n > 1 && n < P)
        {
            v.push_back(spf[n]);
            n /= spf[n];
        }
        if (n >= P)
        {
            ll x = pollard_rho(n);
            v = factorize(x);
            w = factorize(n / x);
            v.insert(v.end(), w.begin(), w.end());
        }
        return v;
    }
}
ll fib(ll n, ll mod)
{
    if (n <= 1)
        return n;
    ll a = 0;
    ll b = 1;
    ll i = 1ll << (63 - __builtin_clzll(n) - 1);
    for (; i; i >>= 1)
    {
        ll na = (__int128(a) * a % mod + __int128(b) * b % mod) % mod;
        ll nb = __int128(2ll * a + b) * b % mod;
        a = na;
        b = nb;
        if (n & i)
        {
            ll c = a + b;
            if (c >= mod)
                c -= mod;
            a = b;
            b = c;
        }
    }
    return b;
}
ll pisano_period_prime(ll p)
{
    if (p == 2)
        return 3;
    if (p == 5)
        return 20;
    ll x = p % 5 == 1 or p % 5 == 4 ? p - 1 : 2 * p + 2;
    auto v = PollardRho::factorize(x);
    map<ll, int> mp;
    for (auto x : v)
    {
        mp[x]++;
    }
    vector<ll> d;
    d.push_back(1);
    for (auto [p, e] : mp)
    {
        ll cur = 1;
        int sz = d.size();
        for (int i = 0; i < e; i++)
        {
            cur *= p;
            for (int j = 0; j < sz; j++)
            {
                d.push_back(d[j] * cur);
            }
        }
    }
    sort(d.begin(), d.end());
    for (auto x : d)
    {
        if (fib(x, p) == 0 and fib(x + 1, p) == 1)
        {
            return x;
        }
    }
    assert(0);
    return -1;
}
// returns pisano period of n i.e. the period with which the sequence of Fibonacci numbers taken modulo n repeats
ll pisano_period(ll n)
{
    auto v = PollardRho::factorize(n);
    map<ll, int> mp;
    for (auto x : v)
    {
        mp[x]++;
    }
    ll ans = 1;
    for (auto [p, e] : mp)
    {
        ll cur = pisano_period_prime(p);
        for (int i = 1; i < e; i++)
        {
            cur *= p;
        }
        ans = ans / __gcd(ans, cur) * cur;
    }
    return ans;
}
//first fibonacci number position while is divisible by n..
//gap(7)=8....f(8)=21 which is divisible for n=7
ll divisor_gap(ll n)
{
    ll k = pisano_period(n);
    if (k % 4 == 0 and fib(k / 4, n) == 0)
        return k / 4;
    if (k % 2 == 0 and fib(k / 2, n) == 0)
        return k / 2;
    return k;
}

int main()
{
    fast;
    ll t;
    // setIO();
    // ll tno=1;;
    t = 1;
    cin >> t;
    PollardRho::init();
    while (t--)
    {
        ll n, k;
        cin >> n >> k;
        ll firstno=divisor_gap(k); //first fibonacci number position while is divisible by n..f(8)=21 which is divisible for n=7
        firstno%=M;
        n%=M;
        ll pos=(firstno*n)%M;
        cout<<pos<<nn;
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

