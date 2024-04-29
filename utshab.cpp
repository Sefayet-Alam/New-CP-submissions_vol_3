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


#define nn '\n'
#define Setpre(n) cout << fixed << setprecision(n)


#define mem(a, b) memset(a, b, sizeof(a))
#define all(x) x.begin(), x.end()
#define rev(x) reverse(all(x))

// CONSTANTS
#define md 10000007
#define PI 3.1415926535897932384626
const double EPS = 1e-9;
const ll N = 2e5 + 10;
const ll M = 1e9 + 7;


double euclidean_distance(ll x1, ll y1, ll x2, ll y2)
{
    double a = (x2 - x1) * (x2 - x1);
    double b = (y2 - y1) * (y2 - y1);
    double c = (double)sqrt(a + b);
    return c;
}


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


vector<pll> points;
vector<pll> final_points;
ll n, x, y;
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

vector<pll> convex_hull_graham()
{
    cin >> n;
    for (ll i = 0; i < n; i++)
    {
        cin >> x >> y;
        points.push_back({x, y});
    }
    ll ymin = points[0].second, min = 0;
    for (ll i = 1; i < n; i++)
    {
        if (ymin > points[i].second || (ymin == points[i].second && (points[min].first < points[i].first)))
        {
            ymin = points[i].second;
            min = i;
        }
    }
    swap(points[0], points[min]);
    p0 = points[0];
    sort(points.begin() + 1, points.end(), cmp2); // sort by p0 according to angles

    for (ll i = 1; i < n; i++)
    {
        while (i < n - 1 && angle(p0, points[i], points[i + 1]) == 0)
            i++;
        final_points.push_back(points[i]);
    }
    // final_points.resize(n);
    // final_points=points;
    ll m = final_points.size();
    if (m < 3)
    {
        // HERE NO CONVEX HULL
        vector<pll> tmp;
        return tmp;
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

    while (t--)
    {
    }

    return 0;
}
