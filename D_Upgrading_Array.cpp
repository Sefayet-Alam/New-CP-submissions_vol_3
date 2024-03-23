#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef unsigned long long ull;
typedef double dd;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> ii;
typedef pair<ll, int> li;
typedef pair<int, ll> il;
typedef pair<ll , ll> lli;
typedef vector<ii> vii;
typedef vector<il> vil;
typedef vector<li> vli;
typedef vector<lli> vlli;
typedef pair < ll , pair < ll , ll > > cm;
 
#define ff first
#define ss second
#define pb push_back
#define in insert
#define f0(b) for(int i=0;i<(b);i++)
#define f00(b) for(int j=0;j<(b);j++)
#define f1(b) for(int i=1;i<=(b);i++)
#define f11(b) for(int j=1;j<=(b);j++)
#define f2(a,b) for(int i=(a);i<=(b);i++)
#define f22(a,b) for(int j=(a);j<=(b);j++)
#define sf(a) scanf("%lld",&a)
#define sff(a,b) scanf("%lld %lld", &a , &b)
#define pf(a) printf("%lld\n",a)
#define pff(a,b) printf("%lld %lld\n", a , b)
#define PI 3.14159265359
#define bug printf("**!\n")
#define mem(a , b) memset(a, b ,sizeof(a))
#define front_zero(n) __builtin_clzll(n)
#define back_zero(n) __builtin_ctzll(n)
#define total_one(n) __builtin_popcountll(n)
#define clean cout.flush()
 
const ll mod = (ll)1e9+7;
const ll maxn = (ll)5e3+10;
const int nnn = 664579+500;
const int inf = numeric_limits<int>::max()-1;
//const ll INF = numeric_limits<ll>::max()-1;
const ll INF = 1e18;
 
ll dx[]={0,1,0,-1};
ll dy[]={1,0,-1,0};
ll dxx[]={0,1,0,-1,1,1,-1,-1};
ll dyy[]={1,0,-1,0,1,-1,1,-1};
 
//ofstream wr ("txt.txt");
//ifstream rr ("input.txt");
 
set < ll > s;
ll a[maxn];
vector < ll > prime;
bitset<100005>vis;
void work(){
	vis.set();
	for(ll i = 2; i <= 1e5;i++ ){
		if(vis[i]){
			prime.pb(i);
			for(ll j = i; j <= 1e5; j+=i) vis[j] =0;
		}
	}
	return;
}
 
ll get(ll x){
	ll res = 0;
	for(ll i = 0; prime[i]*prime[i] <= x; i++){
		if(x%prime[i] == 0){
			ll cnt = 0;
			while(x%prime[i] == 0) x/=prime[i] , cnt++;
			if(s.count(prime[i])) res -= cnt;
			else res += cnt;
		}
	}
	if(x!=1){
		if(s.count(x)) res -= 1;
			else res += 1;
	}
	return res;
}
 
void solve(){
	
	ll n, m;
	cin >> n >> m;
	ll ans =0 ;
	f1(n) cin >> a[i];
	ll b;
	f1(m) cin >> b , s.in(b);
	ll  g[n+5];
	f1(n) ans += get(a[i]);
	ll res = ans;
	g[0] = 0;
	f1(n){
		g[i] = __gcd(g[i-1], a[i]);
	    
	}
	ll taken = 1;
	for(ll i = n ; i >= 1; i--){
		ll k = get(g[i]/taken);
		if(k < 0){
			ans -= (k*i);
			taken = g[i];
		}
	}
	cout << ans;
 	return;
}
int main(){
    work();
    solve();
}
