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

/*1 6 8 12
6 = 2^1 * 3^1 * 5^0 * 7^0 * ...
number of prime divisors of X is log(X)
(N+Q)*log(X) nonzeros in total
 
                   v
exponents[2] = {0, 1, 3, 2}
     1) 1:1, 2:3, 3:2
     2) sorted DS to get minimum
exponents[3] = {0, 1, 0, 0}  1:1
exponents[5] = {0, 0, 0, 0}
 
 
exponents[2] = map(position -> exponent)*/

const int MAX = 2e5 + 5;
int n;
map<int,int> exponents[MAX];
multiset<int> ms[MAX];
bool is_prime[MAX];
int prime_divisor[MAX];

void sieve() {
	for(int p = 2; p < MAX; ++p) {
		is_prime[p] = true;
	}
	for(int p = 2; p < MAX; ++p) {
		if(is_prime[p]) {
			prime_divisor[p] = p;
			for(int a = 2 * p; a < MAX; a += p) {
				prime_divisor[a] = p;
				is_prime[a] = false;
			}
		}
	}
	// for(int p = 2; p < 20; ++p) {
	// 	debug() << imie(p) imie(prime_divisor[p]);
	// }
}

int get_minimum(int p) {
	if((int) ms[p].size() == n) {
		return *ms[p].begin();
	}
	else {
		return 0;
	}
}

// 1600 -> 2^6 * 5^2
// factorization:
// 1) O(sqrt(X))
// 2) prime sieve in advance in O(MAX*log(MAX))
// 3) Pollard's Rho O(X^0.25)

vector<pair<int,int>> factorization(int x) {
	vector<pair<int,int>> v;
	while(x != 1) {
		int cnt = 0;
		int p = prime_divisor[x];
		while(x % p == 0) {
			x /= p;
			cnt++;
		}
		v.emplace_back(p, cnt);
	}
	return v;
}

int answer = 1;
void query(int i, int x) {
	for(pair<int,int> pair : factorization(x)) {
		int p = pair.first;
		int e = pair.second;
		int old_minimum = get_minimum(p);
		
		int& tmp = exponents[p][i];
		if(tmp != 0) {
			ms[p].erase(ms[p].find(tmp));
		}
		tmp += e;
		ms[p].insert(tmp);
		
		int new_minimum = get_minimum(p);
		for(int rep = 0; rep < new_minimum - old_minimum; ++rep) {
			answer = (long long) answer * p % 1'000'000'007;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	sieve();
	int q;
	cin >> n >> q;
	// vector<int> a(n, 1);
	for(int i = 0; i < n; ++i) {
		int x;
		cin >> x;
		query(i, x);
	}
	while(q--) {
		int i, x;
		cin >> i >> x;
		i--; // we use indices in [0, n-1]
		query(i, x);
		cout << answer << "\n";
	}
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
