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
const ll N = 3e3 + 10;
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

const ll INF = (ll)1e18;

int pref[2][N][N];
int suf[2][N][N];
ll mx[N];

void solve()
{

    ll n, k;
    cin >> n >> k;

    ll ans = 0;

    for (ll i = 0; i <= n; i++)
        mx[i] = -INF;

    string s;
    cin >> s;

    s = '0' + s;

    for (ll itr = 0; itr < 2; itr++)
    {

        for (ll j = 0; j <= k; j++)
        {
            pref[itr][0][j] = 0;
            ll bad_cnt = 0, l = 1;
            for (ll i = 1; i <= n; i++)
            {
                if (s[i] - '0' != itr)
                    bad_cnt++;
                while (bad_cnt > j)
                {
                    l++;
                    if (s[l - 1] - '0' != itr)
                    {
                        bad_cnt--;
                    }
                }
                pref[itr][i][j] = max({pref[itr][i - 1][j], (int)(i - l + 1)});
            }
        }
    }
    for (ll itr = 0; itr < 2; itr++)
    {
        for (ll j = 0; j <= k; j++)
        {
            suf[itr][n + 1][j] = 0;
            ll bad_cnt = 0, l = n;
            for (ll i = n; i >= 1; i--)
            {
                if (s[i] - '0' != itr)
                    bad_cnt++;
                while (bad_cnt > j)
                {
                    l--;
                    if (s[l + 1] - '0' != itr)
                    {
                        bad_cnt--;
                    }
                }
                suf[itr][i][j] = max(suf[itr][i + 1][j], (int)(l - i + 1));
            }
        }
    }

    for (ll l = 1; l <= n; l++)
    {
        ll c[2] = {0, 0};
        for (ll r = l; r <= n; r++)
        {
            c[s[r] - '0']++;
            if (c[0] <= k)
            {
                ll l0 = max(pref[0][l - 1][k - c[0]], suf[0][r + 1][k - c[0]]);
                ll l1 = r - l + 1;
                mx[l0] = max(mx[l0], l1);
            }
            if (c[1] <= k)
            {
                ll l0 = r - l + 1;
                ll l1 = max({pref[1][l - 1][k - c[1]], suf[1][r + 1][k - c[1]]});
                mx[l0] = max(mx[l0], l1);
            }
        }
    }
    mx[pref[0][n][0]] = max(mx[pref[0][n][0]], 1LL * (pref[1][n][0]));

    for (ll i = 1; i <= n; i++)
    {
        ll ans = -INF;
        for (ll j = 0; j <= n; j++)
        {
            ans = max(ans, i * j + mx[j]);
        }
        cout << ans << ' ';
    }
    cout << '\n';

    return;
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
        solve();
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
