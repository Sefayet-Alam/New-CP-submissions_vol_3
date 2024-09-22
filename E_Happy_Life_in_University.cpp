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

#define int long long
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

vector<int> adj[N];
int st[N], en[N];
int ara[N];
int tt;
int mx;

vector<int> last[N], nxt[N];

struct Segtree
{

    int segtree[4 * N], lazy[4 * N];
    // max Segtree with lazy updates
    // will find maximum of value in a range ,
    void build(int pos, int l, int r)
    {
        if (l == r)
        {
            segtree[pos] = 0;
            lazy[pos] = 0;
            return;
        }
        int mid = (l + r) / 2;
        build(pos * 2, l, mid);
        build(pos * 2 + 1, mid + 1, r);
        segtree[pos] = max(segtree[pos * 2], segtree[pos * 2 + 1]);
        lazy[pos] = 0;
    }

    void lazyUpdate(int pos, int l, int r)
    {
        if (lazy[pos])
        {
            segtree[pos] += lazy[pos];
            if (l != r)
            {
                lazy[pos * 2] += lazy[pos];
                lazy[pos * 2 + 1] += lazy[pos];
            }
            lazy[pos] = 0;
        }
    }

    void update(int pos, int l, int r, int L, int R, int val)
    {
        lazyUpdate(pos, l, r);
        if (l > r)
            return;
        if (l > R or r < L)
            return;
        if (l >= L and r <= R)
        {
            lazy[pos] += val;
            lazyUpdate(pos, l, r);
            return;
        }
        int mid = (l + r) / 2;
        update(pos * 2, l, mid, L, R, val);
        update(pos * 2 + 1, mid + 1, r, L, R, val);
        segtree[pos] = max(segtree[pos * 2 + 1], segtree[pos * 2]);
    }

    int query(int pos, int l, int r, int L, int R)
    {
        lazyUpdate(pos, l, r);
        if (l > r)
            return 0;
        if (l > R or r < L)
            return 0;
        if (l >= L and r <= R)
            return segtree[pos];
        int mid = (l + r) / 2;
        int val1 = query(pos * 2, l, mid, L, R);
        int val2 = query(pos * 2 + 1, mid + 1, r, L, R);
        return max(val1, val2);
    }

} segtree;

int n;
void dfsEuler(int u)
{
    if (last[ara[u]].size())
    {
        nxt[last[ara[u]].back()].push_back(u);
    }
    last[ara[u]].push_back(u);
    st[u] = tt + 1;
    if (adj[u].size() == 0)
        tt++;
    for (auto v : adj[u])
        dfsEuler(v);
    en[u] = tt;
    last[ara[u]].pop_back();

    segtree.update(1, 1, n, st[u], en[u], 1);
    for (auto v : nxt[u])
        segtree.update(1, 1, n, st[v], en[v], -1);

    if (adj[u].size() == 0)
        return;
    if (adj[u].size() == 1)
    {
        mx = max(mx, segtree.query(1, 1, n, st[u], en[u]));
        return;
    }
    vector<int> temp;
    for (auto v : adj[u])
    {
        int ret = segtree.query(1, 1, n, st[v], en[v]);
        temp.push_back(ret);
    }
    sort(temp.rbegin(), temp.rend());
    mx = max(mx, temp[0] * temp[1]);
}

void solve()
{

    cin >> n;
    segtree.build(1, 1, n);
    tt = 0;
    mx = 1;
    for (int i = 0; i <= n; i++)
    {
        adj[i].clear();
        last[i].clear();
        nxt[i].clear();
    }
    for (int i = 2; i <= n; i++)
    {
        int p;
        cin >> p;
        adj[p].push_back(i);
    }
    for (int i = 1; i <= n; i++)
        cin >> ara[i];
    dfsEuler(1);
    /* for(int i=1;i<=n;i++) cout<<i<<" "<<st[i]<<" "<<en[i]<<endl;
     cout<<endl;
     for(int i=1;i<=n;i++){
         cout<<i<<endl;
         for(auto n:nxt[i]) cout<<n<<" ";
         cout<<endl;
     }*/
    cout << mx << endl;
}

main()
{
    fast;
    int t;
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
