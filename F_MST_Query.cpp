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

// can be used as online minimum spanning tree
// dynamic add edge & cut edge
// check the size of connected component
// check whether two node is connected
const int MAXN = 200005;
const int MAXM = 600005;

struct node {
    node *l, *r, *p, *m; int f, v, w, s, id;
    node(int v, int w, int id) : l(), r(), p(),
    m(this), f(), v(v), w(w), s(w), id(id) {}
};

inline bool is_root(node *n){return n->p==NULL||n->p->l!=n&&n->p->r!=n;}
inline bool left(node *n){return n == n -> p -> l;}
inline int sum(node *n){return n ? n -> s : 0;}
inline node* max(node *n){return n ? n -> m : NULL;}
inline node* max(node *a, node *b) {
    if(a == NULL || b == NULL) return a ? a : b;
    return a -> v > b -> v ? a : b;
}
inline void push(node *n) {
    if(!n -> f) return;n -> f = 0;swap(n -> l, n -> r);
    if(n -> l) n -> l -> f ^= 1;if(n -> r) n -> r -> f ^= 1;
}
inline void pull(node *n) {
    n -> m = max(max(max(n -> l), max(n -> r)), n);
    n -> s = sum(n -> l) + sum(n -> r) + n -> w;
}
inline void connect(node *n, node *p, bool l) {
    (l ? p -> l : p -> r) = n; if(n) n -> p = p;
}
inline void rotate(node *n) {
    node *p = n -> p, *g = p -> p; bool l = left(n);
    connect(l ? n -> r : n -> l, p, l);
    if(!is_root(p)) connect(n, g, left(p)); else n -> p = g;
    connect(p, n, !l);pull(p), pull(n);
}
inline void splay(node *n) {
    while(!is_root(n)) {
        node *p = n -> p;
        if(!is_root(p)) push(p -> p);
        push(p), push(n);
        if(!is_root(p)) rotate(left(n) ^ left(p) ? n : p);
        rotate(n);
    }
    push(n);
}
inline void expose(node *n) {
    node *last = NULL;
    for(node *m = n; m; m = m -> p) {
        splay(m);
        m -> w -= sum(last); m -> w += sum(m -> r);
        m -> r = last; last = m; pull(m);
    }
    splay(n);
}
inline void evert(node *n){expose(n);n -> f ^= 1;}
inline void link(node *m,node *n){evert(m);expose(n);m->p=n;n->w+=sum(m);}
inline void cut(node *m,node *n){evert(m);expose(n);n->l=n->l->p=NULL;}
inline node* path_max(node *m,node *n){evert(m);expose(n);return n->m;}
inline int size(node *n){evert(n);return sum(n);}
bool connected(node *m,node *n){expose(m);expose(n);return m->p!=NULL;}
struct edge {
    int a, b, w, id;
    bool operator<(const edge e) const {return w != e.w ? w > e.w : id > e.id;}
};
int n, m, o;
node *v[MAXN],*ev[MAXM];
vector<edge> ed;
set<edge> s;
int ans = 0;
void delete_edge(edge e){cut(v[e.a],ev[e.id]);cut(v[e.b],ev[e.id]);}
void add_edge(edge e) {link(v[e.a],ev[e.id]);link(v[e.b],ev[e.id]);}
void new_edge(int a, int b, int w) {
    int id = ed.size();
    edge e = {a, b, w, id};
    ed.push_back(e);
    ev[id] = new node(w, 0, id);
    if(connected(v[a], v[b])) {
        node* m = path_max(v[a], v[b]);
        if(m -> v <= w) return;
        delete_edge(ed[m -> id]);
        s.erase(ed[m -> id]);
        ans -= ed[m -> id].w;
    }
    add_edge(e);
    s.insert(e);
    ans += e.w; //
}

void init(){for(int i=1;i<=n;i++){v[i]=new node(0,1,-i);}}

int main()
{
    fast;
    ll t;
    // setIO();
    // ll tno=1;;
    int q;
    cin >> n >> q;
    m = 0;
    init();
    for (int e = 0; e < n - 1; ++e) {
    int u, v, w;  cin >> u >> v >> w;
    new_edge(u, v, w);
    }

    while (q--) {
    int u, v, w;  cin >> u >> v >> w;
    new_edge(u, v, w);
    cout << ans << "\n";
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
