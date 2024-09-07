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

vector<int> adj[N];
bool visited[N];
bool color[N];
int parent[N];
int child_black[N];
int one = 0, two = 0, three = 0;
int parent_white = 0;
void dfs(int s, int p)
{
    if (visited[s])
        return;
    visited[s] = true;
    parent[s] = p;
    if (color[s])
    {
        child_black[p]++;
    }
    for (auto u : adj[s])
    {
        dfs(u, s);
    }
}
void clean(int n)
{
    for (int i = 0; i <= n; ++i)
    {
        adj[i].clear();
        visited[i] = 0;
        parent[i] = 0;
        child_black[i] = 0;
        color[i] = 0;
    }
}

void solve()
{
    int n, q;
    cin >> n >> q;
    clean(n);
    for (int i = 0; i < n; ++i)
    {
        int tmp;
        cin >> tmp;
        color[i + 1] = tmp;
    }
    for (int i = 1; i < n; ++i)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    one = 0, two = 0, three = 0;
    parent_white = 0;
    int tot = 0;
    set<int> node_two;
    dfs(1, 0);
    for (int i = 0; i <= n; ++i)
    {
        if (child_black[i] == 1)
            ++one;
        if (child_black[i] == 2)
        {
            ++two;
            node_two.insert(i);
        }
        if (child_black[i] >= 3)
            ++three;
        if (color[i] and color[parent[i]] == 0)
        {
            parent_white++;
        }
        if (color[i])
            ++tot;
    }
    while (q--)
    {
        int u;
        cin >> u;
        int p = parent[u];
        if (color[u])
        {
            if (child_black[p] == 1)
            {
                --one; //
            }
            else if (child_black[p] == 2)
            {
                --two;
                node_two.erase(p);
                ++one;
            }
            else if (child_black[p] == 3)
            {
                --three;
                ++two;
                node_two.insert(p);
            }
            child_black[p]--;
        }
        else
        {
            if (child_black[p] == 0)
            {
                ++one;
            }
            if (child_black[p] == 1)
            {
                --one;
                ++two;
                node_two.insert(p);
            }
            if (child_black[p] == 2)
            {
                --two;
                node_two.erase(p);
                ++three;
            }
            child_black[p]++;
        }
        color[u] ^= 1;
        if (color[u])
            ++tot;
        else
            --tot;
        if (color[u] and color[p] == 0)
            ++parent_white;
        else if (color[u] == 0 and color[p] == 0)
            --parent_white;

        if (color[u])
        {
            parent_white -= child_black[u];
        }
        else
        {
            parent_white += child_black[u];
        }

        if (three or two > 1 or !tot or parent_white > 1)
        {
            cout << "No" << endl;
        }
        else if (two == 0)
        {
            cout << "YES" << endl;
        }
        else // if(two==1)
        {
            if (color[parent[*node_two.begin()]] == 0 and color[*node_two.begin()])
            {
                cout << "YES" << endl;
            }
            else
                cout << "No" << endl;
        }
    }
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
