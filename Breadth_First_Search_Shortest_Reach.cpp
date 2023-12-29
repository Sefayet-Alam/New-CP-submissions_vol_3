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

//CONSTANTS
#define md                  10000007
#define PI 3.1415926535897932384626
const double EPS = 1e-9;
const ll N = 2e3+10;
const ll M = 1e9+7;




vector<ll>g[N];
bool vis[N];
ll level[N];


void bfs(ll source){
    queue<ll> q;
    q.push(source);
    vis[source]=1;
    level[source]=0;
    while(!q.empty()){
        ll curr_v=q.front();
        q.pop();
        // cout<<curr_v<<" ";
        for(ll child: g[curr_v]){
            if(!vis[child]){
                q.push(child);
                vis[child]=1;
                level[child]=level[curr_v]+1;
            }
        }
    }
    // cout<<endl;
}
int main()
{
    fast;
     ll t;
    //setIO();
     //ll tno=1;;
     t=1;
    cin>>t;

    while(t--){
      ll n,m;
      cin>>n>>m;
      for(ll i=0;i<=n+10;i++){
        g[i].clear();
        level[i]=LLONG_MAX;
        vis[i]=0;
      }
      ll x,y;
      for(ll i=0;i<m;i++){
        cin>>x>>y;
        g[x].push_back(y);
        g[y].push_back(x);
      }
      ll src;
      cin>>src;
      bfs(src);
      for(ll i=1;i<=n;i++){
        if(i==src) continue;
        if(level[i]==LLONG_MAX) cout<<-1<<" ";
        else cout<<(level[i])*6<<" ";
      }
      cout<<nn;
      
    }


    return 0;
}

