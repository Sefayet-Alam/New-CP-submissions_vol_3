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

ll calcrange(vector<ll> &vec, ll r, ll l)
{
    ll ans = vec[r];
    if (l)
        ans -= vec[l - 1];
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

    for (ll j = 1; j <= t; j++)
    {
        ll n;
        cin >> n;
        vector<ll> vec(n);
        cin >> vec;

        
        vector<ll> tws;
        vector<ll> pref(n, 0), zrs(n, 0);
        ll z = 0;
        for (ll i = 0; i < n; i++)
        {
            if (vec[i] == 0)
            {
                zrs[i] = 1;
                z++;
            }
            else if (vec[i] == 1 || vec[i] == 2)
                tws.push_back(i);
            else if (vec[i] > 4)
            {
                pref[i] = 1;
            }
        }
        for (ll i = 1; i < n; i++)
        {
            pref[i] += pref[i - 1];
            zrs[i] += zrs[i - 1];
        }

        ll ans = n - z;

        ll r = 0;
        ll ans2 = LLONG_MAX;
        ll sz = tws.size();
        // deb2(tws, pref);
        if (sz > 1)
        {
            ll posl = 0;
            ll posr = tws[0];
            ll tomin = calcrange(zrs, posr, posl);
            ll curr = max(0LL, posr - tomin);
            // deb(curr);
            ll r = 1;
            ll l = 0;
            while (r < sz)
            {
                posl = tws[l];
                posr = tws[r];
                ll pr = calcrange(pref, posr, posl) + calcrange(zrs,posr,posl);
                if (pr == 0 && posl % 2 != posr % 2)
                {
                    // deb2(l,r);
                    // deb2(posl,posr);
                    curr += posr - posl;
                    // deb(curr);
                    if (r + 1 < sz)
                    {
                        posl = tws[r];
                        posr = tws[r + 1];
                        tomin = calcrange(zrs, posr, posl);
                        curr += max(0LL, posr - posl - 1LL - tomin);
                    }
                    else
                    {
                        posl = tws[r];
                        posr = n - 1;
                        tomin = calcrange(zrs, posr, posl);
                        // deb2(posl,posr);
                        curr += max(0LL, posr - posl - tomin);
                    }
                    // deb(curr);
                    l = r + 1;
                    r = l + 1;
                }
                else
                {
                    if (l + 1 < sz)
                    {
                        posl = tws[l];
                        posr = tws[l + 1];
                        tomin = calcrange(zrs, posr, posl);
                        curr += max(0LL, posr - posl - tomin);
                    }
                    else
                    {
                        posl = tws[l];
                        posr = n;
                        tomin = calcrange(zrs, n - 1, posl);
                        curr += max(0LL, posr - posl - tomin);
                    }
                    l++;
                    r++;
                }
            }
            // deb2(l,r);
            if (l < sz)
            {
                posl = tws[l];
                posr = n;
                tomin = calcrange(zrs, n - 1, posl);
                curr += max(0LL, posr - posl - tomin);
            }
            ans2 = curr;
        }
        ans = min(ans, ans2);
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