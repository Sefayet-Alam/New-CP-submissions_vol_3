#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define pb push_back
#define pf push_front
#define clean cout.flush()
using namespace std;
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef map<int,int> mii;
typedef map<ll,ll> mll;
typedef tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;

const ll N=2e5+7, mod=1e9+7;
ll factorial[N];
void fact()
{
    factorial[0]=1;
    for(int i=1; i<N; i++){ factorial[i]=(i*factorial[i-1])%mod; }
}
ll factorialMod(ll a){
    return factorial[a];
}

ll power(ll a,ll n)
{
    ll ans=1;
    while(n>0){
        if(n&1){ ans*=a; ans%=mod; }
        n>>=1;
        ll b=(a*a)%mod;
        a=b;
    }
    
    return ans;
}
ll modinverse(int a)
{
    return power(a,mod-2);
}
ll combination(int n, int r)
{
    
    if (r == 0) return 1;
    if (r<0 || r > n) return 0;
    ll a = factorial[n];;
    ll b = (factorial[r]*factorial[n-r])%mod;
    ll ans = (a * modinverse((b) % mod)) % mod;
    return ans;
}

void solve()
{
    int n, k; 
    cin>>n>>k;
    int r=k/2;
    vector<int> vec(n);
    for(int i=0; i<n; i++){ cin>>vec[i]; }
    sort(vec.begin(),vec.end());
    ll ans=0;
    
    for(int i=0; i<n; i++){
        if(vec[i]==1){
            ll x=combination(i,r);
            ll y=combination(n-i-1,r);
            ans+=((x*y)%mod);
            ans%=mod;
        }
        
    }
    
    cout<<ans<<"\n";
}
int main()
{
    fast;
    fact();
    int tc=1;
    cin>>tc;
    for(int i=1; i<=tc; i++){ 
        //cout<<"Case "<<i<<": "; 
        solve(); 
    }
    return 0;
}

