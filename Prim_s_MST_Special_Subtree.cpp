#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

//VVI
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define pb                  push_back
#define ll                  long long


///PRINTING

#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl
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


bool visit[N];
vector <pll > g[N];
ll n,m;
int prims_mst (ll src) {
   QP<pair<ll,pll>> pq;
   memset (visit, 0, sizeof (visit));
   visit[src] = 1;
   for (auto child:g[src]) {
      ll curr_v = child.first;
      ll curr_w = child.second;
      pq.push({curr_w,{src,curr_v}});
   }
   ll cnt = 0;
   while (!pq.empty()) {
      auto a = pq.top(); 
      pq.pop();
      ll from, to, w;
      from = a.second.first; 
      to = a.second.second; 
      w = a.first;
      //printf ("%d %d %d\n", u, v, w);
      if (!visit[to]) {
         visit[to] = 1;
        //  cout<<from<<" "<<to<<nn; //prints added edges
         cnt += w;
         from = to;
         for (auto child: g[from]) {
            to = child.first;
            w = child.second;
            if (!visit[to]) pq.push({w,{from,to}});
         }
      }
   }
   return cnt;
}
void reset(){
    for(ll i=0;i<=n;i++){
        g[i].clear();
        visit[i]=0;
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
      cin>>n>>m;
      ll x,y,w;
      for(ll i=0;i<m;i++){
        cin>>x>>y>>w;
        g[x].push_back({y,w});
        g[y].push_back({x,w});
      }

      ll src;
      cin>>src;
      ll ans=prims_mst(src);
      cout<<ans<<nn;
    }


    return 0;
}