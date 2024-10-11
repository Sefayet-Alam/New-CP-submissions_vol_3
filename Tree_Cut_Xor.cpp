#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define int ll
#define vl vector <ll>
#define vll vector <vector <ll>>
#define pll pair<ll,ll>
#define mll  map<long long,long long> 
#define pb push_back
#define full(x)  x.begin(),x.end()
#define w(t) while(t--)
#define in(n)  ll n; \
               cin>>n;
#define dfor(i,a,b) for(ll i=a;i<b;i++)
#define inf = 1e18
#define inar(a, n)             \
    ll n;                      \
    cin >> n;                  \
    long long a[n];            \
    for (ll i = 0; i < n; i++) \
    cin >> a[i]
#define setbit(x) __builtin_popcountll(x)
const ll mod = 1e9+7;
vector<vector<ll>> ans;
ll flag=-1;
ll child =0;
void dfs(ll node,ll par,vector<ll>v[]){
    for(auto b:v[node]){
        if(b!=par){
            dfs(b,node,v);
        }
    }
    if(par!=0)
    ans.push_back({par,node,node});
}
int32_t main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
ll t;
cin>>t;
while(t--){
    ll n;
    cin>>n;
    vector<ll>v[n+1];
    ans.clear();
    dfor(i,1,n){
        ll a,b;
        cin>>a>>b;
        v[a].pb(b);
        v[b].pb(a);
    }
    flag=-1;
    dfs(1,0,v);
    ll an = 1-n%2;
    if(n%2==0 && n>2){
        vector<int> a = ans.back();
        ans.pop_back();
        vector<int> b= ans.back();
        ans.pop_back();
        vector<int> c= ans.back();
        ans.pop_back();
        ans.push_back({c[0],c[1],c[0]});
        ans.push_back({b[0],b[1],b[0]});
        ans.push_back({a[0],a[1],a[0]});
        an =0;
    }
    cout<<an<<endl;
    for(auto b:ans){
    cout<<b[0]<<" "<<b[1]<<" "<<b[2]<<endl;
    }
    
}

return 0;
}