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

struct segment_tree
{
    ll size;
    vector<ll> tree;
    // INITIALIZATION
    void init(ll n)
    {
        size = 1;
        while (size < n)
            size *= 2;
        tree.assign(2 * size, 0LL);
    }
    ll merge(ll a, ll b)
    {
        return a + b;
    }

    void build(vector<ll> &a, ll x, ll lx, ll rx)
    {
        // linear time
        if (rx - lx == 1)
        {
            if (lx < a.size())
            {
                tree[x] = a[lx];
            }
            return;
        }
        ll m = (lx + rx) / 2;
        build(a, 2 * x + 1, lx, m);
        build(a, 2 * x + 2, m, rx);
        tree[x] = merge(tree[2 * x + 1], tree[2 * x + 2]);
    }
    void build(vector<ll> &a)
    {
        // linear time
        build(a, 0, 0, size);
    }
    /// RANGE SUM
    ll sum(ll l, ll r, ll x, ll lx, ll rx)
    {
        if (lx >= r || l >= rx)
        {
            return 0;
        }
        if (lx >= l && rx <= r)
        {
            return tree[x];
        }
        ll m = (lx + rx) / 2;
        ll s1 = sum(l, r, 2 * x + 1, lx, m);
        ll s2 = sum(l, r, 2 * x + 2, m, rx);
        return merge(s1, s2);
    }
    ll sum(ll l, ll r)
    {
        // returns sum from l to r
        return sum(l, r, 0, 0, size);
    }
};

bool func(ll pos)
{
}
ll bs(ll low, ll high)
{
    ll mid;
    ll ans = 0;
    while (low <= high)
    {
        mid = low + (high - low) / 2;
        // cout<<mid<<" "<<func(mid)<<endl;
        if (func(mid))
        {
            ans = mid;
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return ans;
}

int main()
{
    fast;
    ll t;
    // setIO();
    ll tno=1;;
    t = 1;
    cin >> t;

    while (t--)
    {
        ll n;
        cin >> n;
        vector<ll> vec(n);
        cin >> vec;

        segment_tree sg;
        sg.init(n);
        sg.build(vec);

        vector<ll> pref(n, 0), suff(n, 0);
        for (ll i = 0; i < n - 1; i++)
        {
            if (vec[i] != vec[i + 1])
                pref[i+1]++;
        }
        for (ll i = n - 1; i > 0; i--)
        {
            if (vec[i] != vec[i - 1])
                suff[i-1]++;
        }
        for(ll i=1;i<n;i++) pref[i]+=pref[i-1];
        for(ll i=n-2;i>=0;i--) suff[i]+=suff[i+1];
        // deb2(pref,suff);
        for (ll i = 0; i < n; i++)
        {
            // left;
            ll ans=M;
            if (i)
            {
                ll r = i - 1, l = 0;
                ll cur = M;
                while (l <= r)
                {
                    ll mid = l + (r - l) / 2;
                    // cout<<mid<<" "<<func(mid)<<endl;
                    ll ok=suff[mid];
                    ok-=suff[i-1]; 
                    ll sum=sg.sum(mid,i);
                    // deb2(i,mid);
                    // deb2(ok,sum);
                    if(ok==0){
                        if(vec[i-1]>vec[i])ok=1;
                    }
                    if (!ok || sum<=vec[i])
                    {
                        r = mid - 1;
                    }
                    else
                    {
                        cur = mid;
                        l = mid + 1;
                    }
                }
                if(cur!=M) ans=min(ans,(i-cur));
            }
            if(i<n-1){
                ll l=i+1,r=n-1;
                ll cur=M;
                while (l <= r)
                {
                    ll mid = l + (r - l) / 2;
                    // cout<<mid<<" "<<func(mid)<<endl;
                    ll ok=pref[mid];
                    ok-=pref[i+1]; 
                    ll sum=sg.sum(i+1,mid+1);
                    // deb2(i,mid);
                    // deb2(ok,sum);
                    if(ok==0){
                        if(vec[i+1]>vec[i])ok=1;
                    }
                    if (!ok || sum<=vec[i])
                    {
                        l = mid + 1;
                    }
                    else
                    {
                        cur = mid;
                        r = mid - 1;
                    }
                }
                // deb(cur);
                if(cur!=M) ans=min(ans,(cur-i));
            }

            // deb(ans);
            if(ans>=M/2) cout<<-1<<" ";
            else cout<<ans<<" ";
            // tno++;
        }
        cout<<nn;
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
