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

#define mem(a,b) memset(a,b,sizeof(a))
#define all(x) x.begin(), x.end()

const double EPS = 1e-9;
const ll N = 2e5+10;
const ll M = 1e9+7;


vector<ll>g[N];
bool vis[N];


ll dfs(ll vertex){
    //take action on vertex after entering the vertex
    vis[vertex]=true;
    // cout<<vertex<<endl;
    ll ans=1;
    for(ll child:g[vertex]){
        // cout<<"par:"<<vertex<<" "<<"child:"<<child<<endl;
        if(vis[child]) continue;
        //take action on the node before entering the child
        ans=ans+dfs(child);
        //take action on the node after exiting the child
    }
    //take action on the vertex after exiting the node
    return ans;
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
      ll n,p;
      cin>>n>>p;
      ll x,y;
      for(ll i=0;i<p;i++){
        cin>>x>>y;
        g[x].push_back(y);
        g[y].push_back(x);
      }
      vector<ll>cnts;
      ll tot=0;
      for(ll i=0;i<n;i++){
        if(!vis[i]){
            ll g=dfs(i);
            // cout<<i<<" "<<g<<nn;
            cnts.push_back(g);
            tot+=g;
        }
      }
      ll ans=0;
      for(ll i=0;i<cnts.size();i++){
        ans+=(tot-cnts[i])*cnts[i];
      }
      cout<<ans/2<<nn;

      
    }


    return 0;
}

