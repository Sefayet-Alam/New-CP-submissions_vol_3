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

//Printings & debugging
#define nn '\n'
#define Setpre(n) cout << fixed << setprecision(n)
#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl
#define debug printf("I am here\n")

// CONSTANTS
#define md 10000007
#define PI acos(-1)
const double EPS = 1e-9;
const ll N = 25;
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
namespace io{
    template<typename First, typename Second> ostream& operator << ( ostream &os, const pair<First, Second> &p ) { return os << p.first << " " << p.second; }
    template<typename First, typename Second> ostream& operator << ( ostream &os, const map<First, Second> &mp ) { for( auto it : mp ) { os << it << endl;  } return os; }
    template<typename First> ostream& operator << ( ostream &os, const vector<First> &v ) { bool space = false; for( First x : v ) { if( space ) os << " "; space = true; os << x; } return os; }
    template<typename First> ostream& operator << ( ostream &os, const set<First> &st ) { bool space = false; for( First x : st ) { if( space ) os << " "; space = true; os << x; } return os; }
    template<typename First> ostream& operator << ( ostream &os, const multiset<First> &st ) { bool space = false; for( First x : st ) { if( space ) os << " "; space = true; os << x; } return os; }
    template<typename First, typename Second> istream& operator >> ( istream &is, pair<First, Second> &p ) { return is >> p.first >> p.second; }
    template<typename First> istream& operator >> ( istream &is, vector<First> &v ) { for( First &x : v ) { is >> x; } return is; }
    
    long long fastread(){ char c; long long d = 1, x = 0; do c = getchar(); while( c == ' ' || c == '\n' ); if( c == '-' ) c = getchar(), d = -1; while( isdigit( c ) ){ x = x * 10 + c - '0'; c = getchar(); } return d * x; }
    static bool sep = false;
    using std::to_string;
    string to_string( bool x ){ return ( x ? "true" : "false" ); }
    string to_string( const string & s ){ return "\"" + s + "\""; }
    string to_string( const char * s ){ return "\"" + string( s ) + "\""; }
    string to_string ( const char & c ) { string s; s += c; return "\'" + s + "\'"; }
    template<typename Type> string to_string( vector<Type> );
    template<typename First, typename Second> string to_string( pair<First, Second> );
    template<typename Collection> string to_string( Collection );
    template<typename First, typename Second> string to_string( pair<First, Second> p ){ return "{" + to_string( p.first ) + ", " + to_string( p.second ) + "}"; }
    template<typename Type> string to_string( vector<Type> v ) { bool sep = false; string s = "["; for( Type x: v ){ if( sep ) s += ", "; sep = true; s += to_string( x ); } s += "]"; return s; }
    template<typename Collection> string to_string( Collection collection ) { bool sep = false; string s = "{"; for( auto x: collection ){ if( sep ) s += ", "; sep = true; s += to_string( x ); } s += "}"; return s; }
    void print() { cerr << endl; sep = false; }
    template <typename First, typename... Other> void print( First first, Other... other ) { if( sep ) cerr << " | "; sep = true; cerr << to_string( first ); print( other... ); }
} using namespace io;

// Complexity: O(n^3) but slower when the graph is dense
// It finds maximum cost matching on a general graph, not necessarily with maximum matching
// for mincost set initial weights to -inf and do the same on the 72nd line too
// and add -weight and return -maxmatch()
// 1-indexed
struct RandomizedMatching
{
    long long G[N][N], dis[N];
    int match[N];
    int mat[N], stk[N], id[N], vis[N];
    int n, top;
    const long long inf = 1e18;
    RandomizedMatching() {}
    RandomizedMatching(int _n)
    {
        n = _n;
        top = 0;
        memset(match, 0, sizeof match);
        for (int i = 1; i <= n + 1; i++)
        {
            for (int j = 1; j <= n + 1; j++)
            {
                G[i][j] = -inf;
            }
        }
    }
    void add_edge(int u, int v, long long w)
    {
        G[u][v] = max(G[u][v], w);
        G[v][u] = max(G[v][u], w);
    }
    bool spfa(int u)
    {
        stk[top++] = u;
        if (vis[u])
            return true;
        vis[u] = true;
        for (int i = 1; i <= n; ++i)
        {
            if (i != u && i != mat[u] && !vis[i])
            {
                int v = mat[i];
                if (dis[v] < dis[u] + G[u][i] - G[i][v])
                {
                    dis[v] = dis[u] + G[u][i] - G[i][v];
                    if (spfa(v))
                        return true;
                }
            }
        }
        top--;
        vis[u] = false;
        return false;
    }
    long long maximum_matching()
    {
        for (int i = 1; i <= n; ++i)
            id[i] = i;
        for (int i = 1; i <= n; i += 2)
            mat[i] = i + 1, mat[i + 1] = i;
        for (int times = 0, flag; times < 3;)
        { // increase the iteration value for higher probability
            memset(dis, 0, sizeof(dis));
            memset(vis, 0, sizeof(vis));
            top = 0;
            flag = 0;
            for (int i = 1; i <= n; ++i)
            {
                if (spfa(id[i]))
                {
                    flag = 1;
                    int t = mat[stk[top - 1]], j = top - 2;
                    while (stk[j] != stk[top - 1])
                    {
                        mat[t] = stk[j];
                        swap(t, mat[stk[j]]);
                        --j;
                    }
                    mat[t] = stk[j];
                    mat[stk[j]] = t;
                    break;
                }
            }
            if (!flag)
                times++;
            if (!flag)
                random_shuffle(id + 1, id + n + 1);
        }
        long long ans = 0;
        for (int i = 1; i <= n; ++i)
        {
            if (mat[i] <= n && i < mat[i])
            {
                if (G[i][mat[i]] != -inf)
                    ans += G[i][mat[i]], match[i] = mat[i], match[mat[i]] = i;
            }
        }
        return ans;
    }
};
long long w[N][N];
int deg[N];
const long long inf = 1e18;
// if the graph is not connected then answer is not possible
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    int t;
    cin>>t;
    int tno=1;
    while (t--)
    {
        cout<<"Case "<<tno++<<": ";
        cin >> n>> m;
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                w[i][j] = inf;
        long long ans = 0;
        memset(deg, 0, sizeof deg);
        for (int i = 1; i <= m; i++)
        {
            int u, v;
            long long we;
            cin >> u >> v >> we;
            w[u][v] = min(w[u][v], we);
            w[v][u] = min(w[v][u], we);
            ans += we;
            deg[u]++;
            deg[v]++;
        }
        vector<int> odd;
        for (int k = 1; k <= n; k++)
        {
            for (int i = 1; i <= n; i++)
            {
                for (int j = 1; j <= n; j++)
                    w[i][j] = min(w[i][j], w[i][k] + w[k][j]);
            }
        }
        for (int i = 1; i <= n; i++)
            if (deg[i] & 1)
                odd.push_back(i);
        int k = odd.size();
        assert(k % 2 == 0); // there are even number of vertices having odd degree
        RandomizedMatching M(k);
        for (int i = 1; i <= k; i++)
        {
            for (int j = 1; j <= k; j++)
            {
                if (i == j || w[odd[i - 1]][odd[j - 1]] == inf)
                    M.add_edge(i, j, -M.inf);
                else
                    M.add_edge(i, j, -w[odd[i - 1]][odd[j - 1]]);
            }
        }
        ans += -M.maximum_matching();
        cout << ans << '\n';
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

