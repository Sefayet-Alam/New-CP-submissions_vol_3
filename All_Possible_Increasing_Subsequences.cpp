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
struct item{
    ll value;//current value
    ll lazy;//value to be lazyed 
    ll assign;//value to be assigned
};

struct segment_tree{
    ll size;
    vector<item>tree;
    ll neutral=0;
    ll no_op=0;
    
    //General operations : O(1)

    ll merge(ll a,ll b){
    //    if(a==no_op) return b;
    //    if(b==no_op) return a;
       return (a+b)%M;
    }
    //INITIALIZATION: O(log2 n)

    void init(ll n){
        size=1;
        while(size<n) size*=2;
        tree.resize(2*size);
        tree.assign(2*size,{neutral,no_op,no_op});
    }
    
    ///BUILD
    void build(vector<ll> &a,ll x,ll lx,ll rx){
        if(rx-lx==1){
            if(lx<a.size()){
                tree[x]={a[lx],no_op,no_op};
            }
            return;
        }
        ll m=(lx+rx)/2;
        build(a,2*x+1,lx,m);
        build(a,2*x+2,m,rx);
        tree[x]={ tree[x].value=merge(tree[2*x+1].value,tree[2*x+2].value),no_op,no_op};
    }

    void build(vector<ll> &a){
        //linear time
        build(a,0,0,size);
    }

    ///LAZY PROPAGATION
    
    //throws lazy values to its children nodes 
     //updates values to children nodes
        item propagate_op(item par,item child,ll len){
        item ret=child;
        if(par.assign!=no_op)
        {
            ret.assign=par.assign;
            ret.lazy=no_op;
            ret.value=len*(par.assign);
        }
 
        if(par.lazy!=no_op){
            ret.lazy=merge(ret.lazy,par.lazy);
            ret.value+=len*par.lazy;
            ret.value%=M;
        }
 
        return ret;
    }
 
    void propagate(ll x,ll lx,ll rx){
        if(rx-lx==1 || (tree[x].assign==no_op && tree[x].lazy==no_op)){
            return;
        }
        ll m=(rx+lx)/2;
        tree[2*x+1]=propagate_op(tree[x],tree[2*x+1],m-lx);
        tree[2*x+2]=propagate_op(tree[x],tree[2*x+2],rx-m);
        tree[x].lazy=tree[x].assign=no_op;
    }


    ///RANGE QUERY
    ll RangeQuery(ll l,ll r,ll x,ll lx,ll rx){
        propagate(x,lx,rx);
        if(lx>=r || l>=rx){
            return 0;
        }
        if(lx>=l && rx<=r){
            return tree[x].value;
        }
        ll m=(lx+rx)/2;
        ll s1=RangeQuery(l,r,2*x+1,lx,m);
        ll s2=RangeQuery(l,r,2*x+2,m,rx);
        return  merge(s1,s2);
    }

    
    ll RangeQuery(ll l,ll r){
        //returns sum from l to r
       
        return RangeQuery(l,r,0,0,size);
    }

    //RANGE operation
    
    void RangeUpdate(ll l,ll r,ll v,ll x,ll lx,ll rx){
        propagate(x,lx,rx);
        if(lx>=r || l>=rx){
            return;
        }
        if(lx>=l && rx<=r){
            tree[x].lazy=merge(tree[x].lazy,v);
            tree[x].value+=(rx-lx)*v;
            return;
        }
        ll m=(lx+rx)/2;
        RangeUpdate(l,r,v,2*x+1,lx,m);
        RangeUpdate(l,r,v,2*x+2,m,rx);  
         tree[x].value=merge(tree[2*x+1].value,tree[2*x+2].value);
    }
    

    void RangeUpdate(ll l,ll r,ll v){
        //adds v from l to r-1
        RangeUpdate(l,r,v,0,0,size);
    }
};


int main()
{
    fast;
    ll t;
    // setIO();
    ll tno = 1;
    ;
    t = 1;
    cin >> t;

    while (t--)
    {
        cout << "Case " << tno++ << ": ";
        ll n;
        cin >> n;
        vector<ll> vec(n);
        cin >> vec;
        vector<ll> vec2 = vec;
        sort(all(vec2));
        UNIQUE(vec2);
        map<ll, ll> cor;
        for (ll i = 0; i < vec2.size(); i++)
        {
            cor[vec2[i]] = i+1;
        }
        for (ll i = 0; i < n; i++)
        {
            vec[i] = cor[vec[i]];
        }
        // deb(vec);
        ll maxm = *max_element(all(vec));
        vector<ll> dp(maxm + 10, 0);
        segment_tree sg;
        sg.init(maxm + 10);
        sg.build(dp);
        ll ans = 0;
        for (ll i = 0; i < n; i++)
        {
            ll cur = vec[i];

            ll curans = sg.RangeQuery(0, cur)+1;
            ans = (ans + curans) % M;
            // deb2(i,curans);
            sg.RangeUpdate(cur, cur + 1, curans);
        }
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