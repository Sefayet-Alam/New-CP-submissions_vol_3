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

ll n, m;

/// calc calculates maximum subsegment sum from l to r
struct item
{
    ll val, aj;
};

struct segment_tree
{
    ll size;
    ll modd;
    vector<item> tree;
    ll neutral = M;
    ll no_op = M ;

    // General operations : O(1)

    item merge(item a, item b)
    {
        
        ll aval=(a.val + a.aj);
        ll bval=(b.val + b.aj);
        if(a.val<M) {aval%=m;
        if(b.val<M) bval%=m;
        if (aval < bval)
            return a;
        else
            return b;
    }

    // INITIALIZATION: O(log2 n)

    void init(ll n)
    {
        size = 1;
        while (size < n)
            size *= 2;
        tree.resize(2 * size);
        tree.assign(2 * size, {M, M});
    }

    /// BUILD
    void build(vector<pll> &a, ll x, ll lx, ll rx)
    {
        if (rx - lx == 1)
        {
            if (lx < a.size())
            {
                tree[x] = {a[lx].first, a[lx].second};
            }
            return;
        }
        ll m = (lx + rx) / 2;
        build(a, 2 * x + 1, lx, m);
        build(a, 2 * x + 2, m, rx);
        tree[x] = merge(tree[2 * x + 1], tree[2 * x + 2]);
    }

    void build(vector<pll> &a)
    {
        // linear time
        build(a, 0, 0, size);
    }

    /// RANGE QUERY
    item RangeQuery(ll l, ll r, ll x, ll lx, ll rx)
    {
        if (lx >= r || l >= rx)
        {
            return {M, M};
        }
        if (lx >= l && rx <= r)
        {
            return tree[x];
        }
        ll m = (lx + rx) / 2;
        item s1 = RangeQuery(l, r, 2 * x + 1, lx, m);
        item s2 = RangeQuery(l, r, 2 * x + 2, m, rx);
        return merge(s1, s2);
    }

    item RangeQuery(ll l, ll r)
    {
        // returns sum from l to r
        item p=RangeQuery(l, r, 0, 0, size);
        return p;
    }

    /// RANGE ASSIGN
    void RangeAssign(ll l, ll r, pll v, ll x, ll lx, ll rx)
    {
        if (lx >= r || l >= rx)
        {
            return;
        }
        if (lx >= l && rx <= r)
        {
            tree[x].val = v.first;
            tree[x].aj = v.second;
            return;
        }
        ll m = (lx + rx) / 2;
        RangeAssign(l, r, v, 2 * x + 1, lx, m);
        RangeAssign(l, r, v, 2 * x + 2, m, rx);
        tree[x] = merge(tree[2 * x + 1], tree[2 * x + 2]);
    }

    void RangeAssign(ll l, ll r, pll v)
    {
        // assigns v from l to r-1;
        RangeAssign(l, r, v, 0, 0, size);
    }
};

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

        cin >> n >> m;
        vector<ll> vec(n);
        cin >> vec;
        vector<ll> b(n);
        cin >> b;
        vector<ll> dp(n, M);
        dp[0] = 0;
        // deb(dp);
        segment_tree sg;
        sg.modd=m;
        sg.init(n);
        vector<pll> sgt;
        for (ll i = 0; i < n; i++)
        {
            sgt.push_back({dp[i], vec[i]});
        }
        // for(auto it:sgt) deb(it);
        sg.build(sgt);

        for(ll j=0;j<10;j++){
        for (ll i = 0; i < n; i++)
        {
            ll now = ((sg.RangeQuery(i, i + 1)).val) ;
            item qry={M,M};
            item qry2={M,M};
            if(i) qry=(sg.RangeQuery(0, i));
            if(i<n-1) qry2=(sg.RangeQuery(i+1,n));

            // deb2(qry.val,qry.aj);
            // deb2(qry2.val,qry2.aj);
            // deb(now);
            ll curr1 = (qry.val + (b[i]+qry.aj)%m) ;
            ll curr2 = (qry2.val + (b[i]+qry2.aj)%m) ;
            ll curr=min({curr1,curr2,now});
            sg.RangeAssign(i, i + 1, {curr, vec[i]});
        }
        }
        ll ans = sg.RangeQuery(n - 1, n).val;
        cout << ans%m << nn;
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
