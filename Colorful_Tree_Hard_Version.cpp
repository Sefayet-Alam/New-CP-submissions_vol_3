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


vl adjlst[200005];


ll dp[200005][4][4][4];


ll mod = 1e9 + 7;

ll dfs(int u , int p , int r1 , int r2 , int r3)
{
	if(adjlst[u].size() == 1)
	{
		if(r2 != r3) return 1;
		return 0;
	}

		if(dp[u][r1][r2][r3]  != -1) 
		{
			return dp[u][r1][r2][r3];
		}

		int sz = adjlst[u].size();
		if(p) sz--;

		ll rr[sz] = {0};
		ll gg[sz] = {0};
		ll bb[sz] = {0};
		
		ll rg[sz] = {0};
		ll gb[sz] = {0};
		ll br[sz] = {0};
		
		ll tot[sz] = {0};

		int cnt = 0;
		for(int v : adjlst[u])
		{
			if(v != p)
			{
				rr[cnt] = dfs(v , u , r2 , r3 , 1);
				gg[cnt] = dfs(v , u , r2 , r3 , 2);
				bb[cnt] = dfs(v , u , r2 , r3 , 3);

				tot[cnt] = rr[cnt] + gg[cnt] + bb[cnt];
				tot[cnt] %= mod;

				rg[cnt] = rr[cnt] + gg[cnt];
				rg[cnt] %= mod;

				gb[cnt] = gg[cnt] + bb[cnt];
				gb[cnt] %= mod;
				
				br[cnt] = bb[cnt] + rr[cnt];
				br[cnt] %= mod;

				cnt++;
			}
		}


		for(int i = 1 ; i < sz; i ++)
		{
			tot[i] *= tot[i-1];
			rr[i] *= rr[i-1];
			gg[i] *= gg[i-1];
			bb[i] *= bb[i-1];
			
			rg[i] *= rg[i-1];
			gb[i] *= gb[i-1];
			br[i] *= br[i-1];

			rr[i] %= mod;
			gg[i] %= mod;
			bb[i] %= mod;
			rg[i] %= mod;
			gb[i] %= mod;
			br[i] %= mod;
			tot[i] %= mod;
		}

	ll ans = 0;

	if(r2 == r3 || r2 == 0)
	{
		// 
		
		ans = tot[sz - 1];
		ans -= rg[sz-1];
		ans -= gb[sz-1];
		ans -= br[sz-1];
        
		if(r3 == 1) ans += gb[sz-1];
		if(r3 == 2) ans += br[sz-1];
		if(r3 == 3) ans += rg[sz-1];

		if(r3 == 1) ans += rr[sz-1];
		if(r3 == 2) ans += gg[sz-1];
		if(r3 == 3) ans += bb[sz-1];

		ans %= mod;
		if(ans < 0) ans += mod;
	}
	else
	{
		ans = tot[sz - 1];

		if((r2 == 1 && r3 == 2) || (r2 == 2 && r3 == 1)) ans -= rg[sz-1];
		if((r2 == 1 && r3 == 3) || (r2 == 3 && r3 == 1)) ans -= br[sz-1];
		if((r2 == 3 && r3 == 2) || (r2 == 2 && r3 == 3)) ans -= gb[sz-1];

		ans %= mod;
		if(ans < 0) ans += mod;
	}

	//cout << u << " : " << r1 << r2<< r3 << " = " << ans << endl; 

	return dp[u][r1][r2][r3] = ans;
}


void solve()
{
	ll n;
	cin >> n;

	for(int i = 0 ; i <= n;  i ++)
	{
		adjlst[i].clear();
	}

	for(int i = 0 ; i < n-1 ; i ++)
	{
		int u  ,v;
		cin >> u >> v;
		adjlst[u].push_back(v);
		adjlst[v].push_back(u);
	}

	int root = 0;

	for(int i = 1 ; i <= n;  i ++)
	{
		if(adjlst[i].size() >= 2)
		{
			root =  i;
			break;
		}
	}

	// yes;
	// cout << root << endl;


	for(int i = 0 ; i <= n ; i ++)
	{
		for(int x = 0 ; x < 4 ; x ++)
		{
			for(int y = 0 ; y < 4 ; y ++)
			{	
				for(int z = 0 ; z < 4 ; z ++)
				{
					dp[i][x][y][z] = -1;	
				}	
			}	
		}
	}

	
	ll ans =  0;
	ans += dfs(root , 0 , 0 , 0 , 1);
	ans %= mod;
	ans += dfs(root , 0 , 0 , 0 , 2);
	ans %= mod;
	ans += dfs(root , 0 , 0 , 0 , 3);
	ans %= mod;
	cout << ans << endl;

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