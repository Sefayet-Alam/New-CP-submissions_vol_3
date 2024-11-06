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
const ll N = 3e5 + 10;
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

ll GCD2(ll a, ll b)
{
    while (b)
    {
        a %= b;
        swap(a, b);
    }
    return a;
}

ll table[N][19], ar[N];
void build(ll n)
{

    for (ll i = 1; i <= n; ++i)
        table[i][0] = ar[i];

    for (ll k = 1; k < 19; ++k)
    {
        for (ll i = 1; i + (1LL << k) - 1 <= n; ++i)
        {
            table[i][k] = GCD2(table[i][k - 1], table[i + (1LL << (k - 1))][k - 1]);
        }
    }
}

ll query(ll l, ll r)
{
    ll k = 31 - __builtin_clz(r - l + 1);
    return GCD2(table[l][k], table[r - (1 << k) + 1][k]);
}

int main()
{
    fast;
    ll n;
    cin >> n;
    for (ll i = 1; i <= n; i++)
    {
        cin >> ar[i];
    }
    build(n);

    for (ll i = 1; i <= n; i++)
    {
        if (ar[i] == 1)
        {
            cout << 0 << " ";
            continue;
        }

        ll b = 0;
        ll l = 0, r = min(i - 1, n - i);
        while (l <= r)
        {
            ll mid = l + (r - l) / 2;
            if (query(i - mid, i + mid) > 1)
            {
                b = mid;
                l = mid + 1;
            }
            else
            {
                r = mid - 1;
            }
        }
        ll left = i;
        l = 1, r = i;
        while (l <= r)
        {
            ll midl = l + (r - l) / 2;
            if (query(midl, i) > 1)
            {
                left = midl;
                r = midl - 1;
            }
            else
            {
                l = midl + 1;
            }
        }
        ll leftr = i;
        l = i, r = n;
        while (l <= r)
        {
            ll midl = l + (r - l) / 2;
            if (query(left, midl) > 1)
            {
                leftr = midl;
                l = midl + 1;
            }
            else
            {
                r = midl - 1;
            }
        }
        // deb2(left, leftr);
        ll ans1 = max(0LL, leftr - left + 1);

        leftr = i;
        l = i, r = n;
        while (l <= r)
        {
            ll midl = l + (r - l) / 2;
            if (query(i - b, midl) > 1)
            {
                leftr = midl;
                l = midl + 1;
            }
            else
            {
                r = midl - 1;
            }
        }
        // deb2(left, leftr);
        ll ans3 = max(0LL, leftr - (i - b) + 1);

        ll right = i;
        l = i, r = n;
        while (l <= r)
        {
            ll midr = l + (r - l) / 2;
            if (query(i, midr) > 1)
            {
                right = midr;
                l = midr + 1;
            }
            else
            {
                r = midr - 1;
            }
        }
        ll rightl = i;
        l = 1, r = i;
        while (l <= r)
        {
            ll midr = l + (r - l) / 2;
            if (query(midr, right) > 1)
            {
                rightl = midr;
                r = midr - 1;
            }
            else
            {
                l = midr + 1;
            }
        }
        // deb2(rightl,right);
        ll ans2 = max(0LL, right - rightl + 1);

        rightl = i;
        l = 1, r = i;
        while (l <= r)
        {
            ll midr = l + (r - l) / 2;
            if (query(midr, i + b) > 1)
            {
                rightl = midr;
                r = midr - 1;
            }
            else
            {
                l = midr + 1;
            }
        }
        // deb2(rightl,right);
        ll ans4 = max(0LL, (i + b) - rightl + 1);
        ll ans = max({ans1, ans2, ans3, ans4});
        cout << ans << " ";
    }
    cout << nn;
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
