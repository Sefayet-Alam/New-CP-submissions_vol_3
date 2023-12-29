#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

//VVI
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define pb                  push_back
#define ll                  long long


#define nn '\n'

#define all(x) x.begin(), x.end()
#define rev(x) reverse(all(x))

//CONSTANTS
#define md                  10000007
#define PI 3.1415926535897932384626
const double EPS = 1e-9;
const ll N = 2e5+10;
const ll M = 1e9+7;




int par[N];
int sz[N];
// multiset<int> sizes;

void make(int v){
    par[v]=v;
    sz[v]=1;
    // sizes.insert(1);
}

int find(int v){
    if(v==par[v]) return v;
    return par[v]=find(par[v]);
}

// void merge(int a,int b){
//     sizes.erase(sizes.find(sz[a]));
//     sizes.erase(sizes.find(sz[b]));
//     sizes.insert(sz[a]+sz[b]);
// }

void Union(int a,int b){
    a=find(a);
    b=find(b);
    if(a!=b){
        if(sz[a]<sz[b]) swap(a,b);
        par[b]=a;
        // merge(a,b);
        sz[a]+=sz[b];
    }
}
int main()
{
    fast;
     ll t;
    //setIO();
     //ll tno=1;;
     t=1;
    //cin>>t;

    while(t--){
      vector<pair<ll,pair<ll,ll>> >edges;
      ll n,m;
      cin>>n>>m;
      for(ll i=1;i<=n;i++){
        make(i);
      }
      ll u,v,w;
      while(m--){
        cin>>u>>v>>w;
        // Union(u,v);
        edges.push_back({w,{u,v}});
      }
      sort(all(edges));
      ll ans=0;
      for(auto it:edges){
        u=it.second.first;
        v=it.second.second;
        if(find(u)!=find(v)){
            Union(u,v);
            ans+=it.first;
        }
      }
      cout<<ans<<endl;
    }


    return 0;
}

