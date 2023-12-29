#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define fr(m) for(int i=0; i<m; i++)
#define fro(m) for(int i=1; i<m; i++)
#define frj(m) for(int j=0; j<m; j++)
#define frr(n) for(int i=n; i>=0; i--)
#define pb push_back
#define pf push_front
#define orr ||
#define nl '\n'
#define nll cout<<'\n'
#define mod 1000000007
#define inf (1LL<<61)
#define inff (1<<30)
#define yes cout<<"YES"<<nl
#define no cout<<"NO"<<nl
#define ff first
#define ss second
#define all(v) v.begin(), v.end()
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL)
#define mxn changeit

ll n, l, r;

ll koyta(ll a){
    ll tmp=64-__builtin_clzll(a);
    return (1ll<<tmp)-1;
}

ll get(ll a, ll nowl, ll nowr){
    if(nowl>r || nowr<l) return 0;
    if(a<=1) return a;
    ll tmp=koyta(a/2);
    ll res=get(a/2,nowl,nowl+tmp-1)+get(a%2,nowl+tmp,nowl+tmp)+get(a/2,nowl+tmp+1,nowr);
    return res;
}

int main()
{
    fastio;
    cin>>n>>l>>r;
    ll nowl=1, nowr=koyta(n);
    ll ans=get(n,nowl,nowr);
    cout<<ans<<nl;
    return 0;
} 	   				   	  		  	  		