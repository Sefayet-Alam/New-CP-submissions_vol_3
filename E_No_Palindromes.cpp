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
#define ss second
#define SZ(a) (int)a.size()
#define UNIQUE(a) (a).erase(unique(all(a)), (a).end())
#define eb emplace_back
#define mp make_pair

/// BIT MANIPULATION

#define Set(x, k) (x |= (1LL << k))
#define Unset(x, k) (x &= ~(1LL << k))
#define Check(x, k) (x & (1LL << k))
#define Toggle(x, k) (x ^ (1LL << k))

// LOOPS

#define scl(n) scanf("%lld", &n)
#define fr(i, n) for (ll i = 0; i < n; i++)
#define fr1(i, n) for (ll i = 1; i <= n; i++)
#define Fo(i, k, n) for (i = k; k < n ? i < n : i > n; k < n ? i += 1 : i -= 1)

/// PRINTING

#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl
#define nn '\n'
#define pfl(x) printf("%lld\n", x)
#define pcas(i) printf("Case %lld: ", i)
#define Setpre(n) cout << fixed << setprecision(n)
#define itr(it, a) for (auto it = a.begin(); it != a.end(); it++)
#define debug printf("I am here\n")

/// SORTING AND FILLING

#define asort(a) sort(a, a + n)
#define dsort(a) sort(a, a + n, greater<int>())
#define vasort(v) sort(v.begin(), v.end());
#define vdsort(v) sort(v.begin(), v.end(), greater<ll>());
#define rev(x) reverse(all(x))
#define sortall(x) sort(all(x))
#define mem(a, b) memset(a, b, sizeof(a))
#define all(x) x.begin(), x.end()
#define rev(x) reverse(all(x))

// CONSTANTS
#define md 10000007
#define PI 3.1415926535897932384626
const double EPS = 1e-9;
const ll N = 2e5 + 10;
const ll M = 1e9 + 7;

/// INLINE FUNCTIONS
inline ll GCD(ll a, ll b) { return b == 0 ? a : GCD(b, a % b); }
inline ll LCM(ll a, ll b) { return a * b / GCD(a, b); }
inline ll Ceil(ll p, ll q) { return p < 0 ? p / q : p / q + !!(p % q); }
inline ll Floor(ll p, ll q) { return p > 0 ? p / q : p / q - !!(p % q); }
inline double logb(ll base, ll num) { return (double)log(num) / (double)log(base); }
inline bool isPerfectSquare(long double x)
{
    if (x >= 0)
    {
        long long sr = sqrt(x);
        return (sr * sr == x);
    }
    return false;
}
double euclidean_distance(ll x1, ll y1, ll x2, ll y2)
{
    double a = (x2 - x1) * (x2 - x1);
    double b = (y2 - y1) * (y2 - y1);
    double c = (double)sqrt(a + b);
    return c;
}
int popcount(ll x) { return __builtin_popcountll(x); };
int poplow(ll x) { return __builtin_ctzll(x); };
int pophigh(ll x) { return 63 - __builtin_clzll(x); };

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

/*===================================================================//

        ░█▀▀▀█ ░█▀▀▀ ░█▀▀▀ ─█▀▀█ ░█──░█ ░█▀▀▀ ▀▀█▀▀
        ─▀▀▀▄▄ ░█▀▀▀ ░█▀▀▀ ░█▄▄█ ░█▄▄▄█ ░█▀▀▀ ─░█──
        ░█▄▄▄█ ░█▄▄▄ ░█─── ░█─░█ ──░█── ░█▄▄▄ ─░█──
//====================================================================*/

void setIO()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);

    freopen("output.txt", "w", stdout);
#endif // ONLINE_JUDGE
}

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
/***
 *
 * 64-bit hashing for vectors or strings
 * Get the forward and reverse hash of any segment
 * Base is chosen randomly to prevent anti-hash cases from being constructed
 *
 * Complexity - O(n) to build, O(1) for each hash query
 *
 ***/

#define MAXLEN 1000010
constexpr uint64_t mod = (1ULL << 61) - 1;

const uint64_t seed = chrono::system_clock::now().time_since_epoch().count();
const uint64_t base = mt19937_64(seed)() % (mod / 3) + (mod / 3);

uint64_t base_pow[MAXLEN];

int64_t modmul(uint64_t a, uint64_t b)
{
    uint64_t l1 = (uint32_t)a, h1 = a >> 32, l2 = (uint32_t)b, h2 = b >> 32;
    uint64_t l = l1 * l2, m = l1 * h2 + l2 * h1, h = h1 * h2;
    uint64_t ret = (l & mod) + (l >> 61) + (h << 3) + (m >> 29) + (m << 35 >> 3) + 1;
    ret = (ret & mod) + (ret >> 61);
    ret = (ret & mod) + (ret >> 61);
    return ret - 1;
}

void init()
{
    base_pow[0] = 1;
    for (ll i = 1; i < MAXLEN; i++)
    {
        base_pow[i] = modmul(base_pow[i - 1], base);
    }
}

struct PolyHash
{
    /// Remove suff vector and usage if reverse hash is not required for more speed
    vector<int64_t> pref, suff;

    PolyHash() {}

    template <typename T>
    PolyHash(const vector<T> &ar)
    {
        if (!base_pow[0])
            init();

        ll n = ar.size();
        assert(n < MAXLEN);
        pref.resize(n + 3, 0), suff.resize(n + 3, 0);

        for (ll i = 1; i <= n; i++)
        {
            pref[i] = modmul(pref[i - 1], base) + ar[i - 1] + 997;
            if (pref[i] >= mod)
                pref[i] -= mod;
        }

        for (ll i = n; i >= 1; i--)
        {
            suff[i] = modmul(suff[i + 1], base) + ar[i - 1] + 997;
            if (suff[i] >= mod)
                suff[i] -= mod;
        }
    }

    PolyHash(const char *str)
        : PolyHash(vector<char>(str, str + strlen(str))) {}
    PolyHash(string str)
        : PolyHash(vector<char>(all(str))) {}
    uint64_t get_hash(int l, int r)
    {
        int64_t h = pref[r + 1] - modmul(base_pow[r - l + 1], pref[l]);
        return h < 0 ? h + mod : h;
    }

    uint64_t rev_hash(ll l, ll r)
    {
        int64_t h = suff[l + 1] - modmul(base_pow[r - l + 1], suff[r + 2]);
        return h < 0 ? h + mod : h;
    }
};
ll n;
void printans(vector<pll> ans, string s)
{
    for (auto it : ans)
    {
        string curr = "";
        for (ll i = it.first; i <= it.second; i++)
        {
            curr += s[i];
        }
        cout << curr << " ";
    }
    cout << nn;
}
int main()
{
    // fast;
    ll t;
    // setIO();
    // ll tno=1;;
    t = 1;
    cin >> t;

    while (t--)
    {
        string s;
        cin >> s;

        PolyHash pl(s);

        n = s.size();
        ll a = pl.get_hash(0, n - 1);
        ll b = pl.rev_hash(0, n - 1);
        if (a != b)
        {
            cout << "YES" << nn;
            cout << 1 << nn;
            cout << s << nn;
            continue;
        }
        bool fnd = 0;
        vector<pll> ans;
        for (ll i = 0; i < n - 1; i++)
        {
            ll l1 = 0;
            ll r1 = i;
            ll l2 = i + 1;
            ll r2 = n - 1;
            if (pl.get_hash(l1, r1) != pl.rev_hash(l1, r1) && pl.get_hash(l2, r2) != pl.rev_hash(l2, r2))
            {
                ans.push_back({l1,r1});
                ans.push_back({l2,r2});
                cout<<"YES"<<nn;
                cout<<ans.size()<<nn;
                printans(ans,s);
                fnd=1;
                break;
            }
        }
        if(fnd) continue;

        ll l = 0, r = 0;
        while (r < n)
        {
            if (pl.get_hash(l, r) == pl.rev_hash(l, r))
            {
                r++;
            }
            else
            {
                ans.push_back({l, r});
                r++;
                l = r;
            }
        }
        if (ans.size() == 0)
        {
            r--;
            ans.push_back({l, r});
        }

        pll lst = ans.back();

        if (lst.second != n - 1)
        {
            ans.pop_back();
            ans.push_back({lst.first, n - 1});
        }

        bool f = 0;
        while (ans.size() > 1)
        {
            lst = ans.back();
            ll x = lst.first;
            ll y = lst.second;
            if (pl.get_hash(x, y) == pl.rev_hash(x, y))
            {
                ans.pop_back();
                lst = ans.back();
                ans.pop_back();
                ans.push_back({lst.first, y});
            }
            else
                break;
        }

        for (auto it : ans)
        {
            ll x = it.first;
            ll y = it.second;
            if (pl.get_hash(x, y) == pl.rev_hash(x, y))
                f = 1;
        }

        if (f)
            cout << "NO" << nn;
        else
        {
            cout << "YES" << nn;
            cout << ans.size() << nn;
            printans(ans,s);
        }   
    }

    return 0;
}
