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
#define rev(x) reverse(all(x))

//CONSTANTS
#define md                  10000007
#define PI 3.1415926535897932384626
const double EPS = 1e-9;
const ll N = 2e5+10;
const ll M = 1e9+7;



/// Data structures
typedef unsigned long long ull;
typedef pair<ll, ll>    pll;
typedef vector<ll>      vl;
typedef vector<pll>     vpll;
typedef vector<vl>      vvl;
template <typename T> using PQ = priority_queue<T>;
template <typename T> using QP = priority_queue<T,vector<T>,greater<T>>;

template <typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <typename T,typename R> using ordered_map = tree<T, R , less<T>, rb_tree_tag, tree_order_statistics_node_update>;
;



vpll g[N];
vl dist(N,LLONG_MAX);
vl par(N,-1);
ll n,m,x,y,k;
void dijkstra(ll source){
    QP<pll> pq;
    pq.push({0,source});
    dist[source]=0;
    while(pq.size()){
        ll v=pq.top().second;
        ll v_dist=pq.top().first;
        pq.pop();
        if(dist[v]<v_dist) continue;
        for(auto &child:g[v]){
            ll child_v=child.first;
            ll wt=child.second;
            if(dist[v]+wt<dist[child_v]){
                dist[child_v]=dist[v]+wt;
                par[child_v]=v;
                pq.push({dist[child_v],child_v});
            }
        }
    }
}
void reset(){
        for(ll i=0;i<=n+10;i++){
            g[i].clear();
            par[i]=-1;
            dist[i]=LLONG_MAX;
        }
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
        
        cin>>n>>m;
        reset();
        for(ll i=0;i<m;i++){
            cin>>x>>y>>k;
            g[x].push_back({y,k});
            g[y].push_back({x,k});
        }
        ll src;
        cin>>src;
        dijkstra(src);
        for(ll i=1;i<=n;i++){
            if(i==src) continue;
            if(dist[i]==LLONG_MAX) cout<<-1<<" ";
            else cout<<dist[i]<<" ";
        }
        cout<<nn;
    }


    return 0;
}

