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

int main()
{
    fast;
    ll t;
    // setIO();
    // ll tno=1;;
    t = 1;
    // cin >> t;

    while (t--)
    {
        ll n;
        cin >> n;
        ll ar[n + 1][n + 1];
        if (n == 2)
        {
            for (ll i = 1; i <= n; i++)
            {
                for (ll j = 1; j <= n; j++)
                {
                    cin >> ar[i][j];
                }
            }
            cout << 0 << " " << 0 << nn;
            cout << 0 << " " << 0 << nn;
            continue;
        }
        map<ll, ll> diag1, diag2;
        for (ll i = 1; i <= n; i++)
        {
            for (ll j = 1; j <= n; j++)
            {
                cin >> ar[i][j];
                diag1[i - j] = 1;
                diag2[i + j] = 1;
            }
        }
        for (ll i = 1; i <= n; i++)
        {
            for (ll j = 1; j <= n; j++)
            {
                diag1[i - j] = (diag1[i - j] * ar[i][j]);
                diag2[i + j] = (diag2[i + j] * ar[i][j]);
            }
        }

        for (ll i = 1; i <= n; i++)
        {
            for (ll j = 1; j <= n; j++)
            {
                ll curans = 0;
                map<ll, ll> diag2x, diag1x;
                for (auto it : diag1)
                {
                    diag1x[it.first] = it.second;
                }
                for (auto it : diag2)
                {
                    diag2x[it.first] = it.second;
                }

                for (auto it : diag1x)
                {
                    ll j1 = -(it.first - i);
                    // diag1 matches i,j1 in row i
                    if (j1 >= 1 && j1 <= n)
                    {
                        ll div = inverseMod(ar[i][j1], M);
                        diag1x[i - j1] = (diag1x[i - j1] * div) % M;
                    }
                    ll i1 = it.first + j;
                    // diag1 matches i1,j in col j
                    if (i1 >= 1 && i1 <= n)
                    {
                        ll div = inverseMod(ar[i1][j], M);
                        diag1x[i1 - j] = (diag1x[i1 - j] * div) % M;
                    }
                }
                diag1x[i - j] = (ar[i][j] * diag1x[i - j]) % M;
                for (auto it : diag2x)
                {
                    ll j1 = it.first - i;
                    if (j1 >= 1 && j1 <= n)
                    {
                        ll div = inverseMod(ar[i][j1], M);
                        diag2x[i + j1] = (diag2x[i + j1] * div) % M;
                    }
                    ll i1 = it.first - j;
                    if (i1 >= 1 && i1 <= n)
                    {
                        ll div = inverseMod(ar[i1][j], M);
                        diag2x[i1 + j] = (diag2x[i1 + j] * div) % M;
                    }
                }
                diag2x[i + j] = (ar[i][j] * diag2x[i + j]) % M;

                
                ll curdiag1=i+j;

                ll n2=n-1;
                for(ll i=0;i<n;i++){
                    if(i>curdiag1){
                        diag1x[i-1]=(diag1x[i-1]*diag1x[i])%M;
                        diag1x[i]=1;
                    }
                }
                ll a = 0;
                ll b = 0;
                for (auto it : diag1x)
                {

                    ll cur = it.second;
                    if (it.first < 0)
                    {
                        ll idx = n + it.first;
                        cur = (cur * diag1x[idx]) % M;
                        a = (a + cur);
                    }
                    else if (it.first == 0)
                    {
                        a = (a + cur);
                    }
                }
                for (auto it : diag2x)
                {

                    ll cur = it.second;
                    if (it.first < n + 1)
                    {
                        ll idx = n + it.first;
                        cur = (cur * diag2x[idx]) % M;
                        b = (b + cur);
                        // deb2(it.first,idx);
                        // deb(cur);
                    }
                    else if (it.first == n + 1)
                    {
                        b = (b + cur);
                    }
                }
                curans = a - b;
                deb(curans);
                // cout << curans << " ";
            }
            cout << nn;
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
