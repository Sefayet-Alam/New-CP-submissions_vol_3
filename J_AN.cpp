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
#define pb push_back
#define ll long long

#define SZ(a) (int)a.size()
#define UNIQUE(a) (a).erase(unique(all(a)), (a).end())
#define eb emplace_back
#define mp make_pair

/// BIT MANIPULATION

#define Set(x, k) (x |= (1LL << k))
#define Unset(x, k) (x &= ~(1LL << k))
#define Check(x, k) (x & (1LL << k))
#define Toggle(x, k) (x ^ (1LL << k))

// LOOPS

#define scl(n) scanf("%lld", &n)
#define fr(i, n) for (ll i = 0; i < n; i++)
#define fr1(i, n) for (ll i = 1; i <= n; i++)
#define Fo(i, k, n) for (i = k; k < n ? i < n : i > n; k < n ? i += 1 : i -= 1)

/// PRINTING

#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl
#define nn '\n'
#define pfl(x) printf("%lld\n", x)
#define pcas(i) printf("Case %lld: ", i)
#define Setpre(n) cout << fixed << setprecision(n)
#define itr(it, a) for (auto it = a.begin(); it != a.end(); it++)
#define debug printf("I am here\n")

/// SORTING AND FILLING

#define asort(a) sort(a, a + n)
#define dsort(a) sort(a, a + n, greater<int>())
#define vasort(v) sort(v.begin(), v.end());
#define vdsort(v) sort(v.begin(), v.end(), greater<ll>());
#define rev(x) reverse(all(x))
#define sortall(x) sort(all(x))
#define mem(a, b) memset(a, b, sizeof(a))
#define all(x) x.begin(), x.end()
#define rev(x) reverse(all(x))

// CONSTANTS
#define md 10000007
#define PI 3.1415926535897932384626
const double EPS = 1e-9;
const ll N = 2e5 + 10;
const ll M = 1e9 + 7;

/// INLINE FUNCTIONS
inline ll GCD(ll a, ll b) { return b == 0 ? a : GCD(b, a % b); }
inline ll LCM(ll a, ll b) { return a * b / GCD(a, b); }
inline ll Ceil(ll p, ll q) { return p < 0 ? p / q : p / q + !!(p % q); }
inline ll Floor(ll p, ll q) { return p > 0 ? p / q : p / q - !!(p % q); }
inline double logb(ll base, ll num) { return (double)log(num) / (double)log(base); }
inline bool isPerfectSquare(long double x)
{
    if (x >= 0)
    {
        long long sr = sqrt(x);
        return (sr * sr == x);
    }
    return false;
}
double euclidean_distance(ll x1, ll y1, ll x2, ll y2)
{
    double a = (x2 - x1) * (x2 - x1);
    double b = (y2 - y1) * (y2 - y1);
    double c = (double)sqrt(a + b);
    return c;
}
int popcount(ll x) { return __builtin_popcountll(x); };
int poplow(ll x) { return __builtin_ctzll(x); };
int pophigh(ll x) { return 63 - __builtin_clzll(x); };

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

void setIO()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);

    freopen("output.txt", "w", stdout);
#endif // ONLINE_JUDGE
}

struct custom_hash
{
    static uint64_t splitmix64(uint64_t x)
    {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }
    size_t operator()(uint64_t x) const
    {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};
vector<pll> points;
vector<pll> final_points;
ll n, x, y,rad;
pll p0;

pll nextToTop(stack<pll> &S)
{
    pll p = S.top();
    S.pop();
    pll res = S.top();
    S.push(p);
    return res;
}

ll getDist(pll a, pll b)
{
    return (a.first - b.first) * (a.first - b.first) +
           (a.second - b.second) * (a.second - b.second);
}
int angle(pll p, pll q, pll r)
{

    int val = (q.second - p.second) * (r.first - q.first) - (q.first - p.first) * (r.second - q.second);

    if (val == 0)
        return 0;             // collinear
    return (val > 0) ? 1 : 2; // clock or counterclock wise
}

bool cmp2(pll a, pll b)
{
    // if(getDist(a,p0)!=getDist(b,p0)) getDist(a,p0)<getDist(b,p0);
    if ((a.second - p0.second) * (b.first - p0.first) == (b.second - p0.second) * (a.first - p0.first))
        return getDist(a, p0) < getDist(b, p0);
    return (a.second - p0.second) * (b.first - p0.first) < (b.second - p0.second) * (a.first - p0.first);
}

double calctriangle(pll a,pll b){
    double ret=(0.5)*(abs(a.first*b.second-a.second*b.first));
    return ret;
}



double height(double x1, double y1, double x2, double y2, double R){
    double hh;
    if(x1==x2) return R-abs(x1);
    else if(y1==y2) return R-abs(y1);
    double dd= (y1-y2)/(x1-x2);
    double fs= (y1 - dd*x1)*(y1 - dd*x1), ss= dd*dd +1; 
    hh= fs/ss; hh= sqrt(hh);
    return 
    R-hh;
}
double func(pll a,pll b,ll rad){
    double area=(0.5)*(euclidean_distance(a.first,a.second,b.first,b.second))*height(a.first,a.second,b.first,b.second,rad);
    area=abs(area);
    return area;
}



void convex_hull_graham()
{
    cin >> n >> rad;
    for (ll i = 0; i < n; i++)
    {
        cin >> x >> y;
        points.push_back({x, y});
    }
    if(n==1){
        double ans=0.0000;
        Setpre(10)<<ans<<nn;
        return;
    }
    
    ll ymin = points[0].second, min = 0;
    ll ymax= points[0].second, maxm=0;
    for (ll i = 1; i < n; i++)
    {
        if (ymin > points[i].second || (ymin == points[i].second && (points[min].first < points[i].first)))
        {
            ymin = points[i].second;
            min = i;
        }
        if (ymax > points[i].second || (ymax == points[i].second && (points[maxm].first < points[i].first)))
        {
            ymax= points[i].second;
            maxm=i;
        }
    }
    swap(points[0], points[min]);
    p0 = points[0];
    sort(points.begin() + 1, points.end(), cmp2); // sort by p0 according to angles
    points.push_back(points[0]);
    // deb(points);
    map<pll,ll>pos;
    for(ll i=0;i<n;i++){
        pos[points[i]]=i;
    }
    vector<double>pref(n+1,0);
    pref[0]=0.00;
    for(ll i=1;i<=n;i++){
        pref[i]=calctriangle(points[i-1],points[i]);
        pref[i]+=pref[i-1];
    }
    points.pop_back();
    
    final_points.push_back(points[0]);
    for (ll i = 1; i < n; i++)
    {
        while (i < n - 1 && angle(p0, points[i], points[i + 1]) == 0)
            i++;
        final_points.push_back(points[i]);
    }

    ll m = final_points.size();
    if(m==1){
        double ret=func(points[min],points[maxm],rad);
        Setpre(10)<<ret<<nn;
        return;
    }
    if(m==2){
        double ret=func(final_points[0],final_points[1],2*rad);
        // ret+=calctriangle(final_points[0],final_points[1]);
        Setpre(10)<<ret<<nn;
        return;
    }
    stack<pll> S;
    S.push(final_points[0]);
    S.push(final_points[1]);
    S.push(final_points[2]);

    for (ll i = 3; i < m; i++)
    {
        while (S.size() > 1 && angle(nextToTop(S), S.top(), final_points[i]) != 2)
            S.pop();
        S.push(final_points[i]);
    }
    vector<pll> ans;
    while (!S.empty())
    {
        pll p = S.top();
        ans.push_back(p);
        S.pop();
    }
    
    double ret=0.000;
    double tot=pref.back();

    // deb(final_points);
    // deb(pref);
    // deb(tot);
    
    for(ll i=0;i<m;i++){
        for(ll j=0;j<m;j++){
            if(i==j) continue;
            ll l=pos[final_points[i]];
            ll r=pos[final_points[j]];
            
            double curr=tot-abs(pref[r]-pref[l]);
            curr=curr+func(final_points[i],final_points[j],rad);
            deb2(l,r);
            deb(curr);
            ret=max(ret,curr);
        }
    }
    Setpre(10)<<ret<<nn;
    return;
}

int main()
{
    fast;
    ll t;
    // setIO();
    // ll tno=1;;
    t = 1;
    convex_hull_graham();
    return 0;
}
