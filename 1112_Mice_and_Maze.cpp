#include <bits/stdc++.h>
#define fastread() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define nl "\n"
#define ll long long
#define all(x) x.begin(), x.end()
#define int long long
using namespace std;
int M=1e9+7;
const int N=4e5;
const int INF=1e11;
vector<pair<int,int>> g[N];
bool vis[N];
vector<int> dist(N,INF);


void dijkstra(int source)
{
    set<pair<int,int>> s;
    s.insert({0,source});
    dist[source]=0;
   // vis[source]=true;
    while(s.size()>0)
    {
        auto node=*s.begin();
        int v=node.second;
        int w=node.first;
        s.erase(s.begin());
        if(vis[v])continue;
        vis[v]=true;
        for(auto child:g[v])
        {
            int child_v=child.second;
            int wt=child.first;

            if(dist[v]+wt<dist[child_v])
            {

                dist[child_v]=dist[v]+wt;
                s.insert({dist[child_v],child_v});

            }


        }
    }
}



signed main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

   int tst;
   cin>>tst;
   while(tst--)
   {
        int n,m,t,e;
        //scanf("%d%d%d%d",&n,&e,&t,&m);
    cin>>n>>e>>t>>m;
    for(int i=0;i<m;i++)
    {
        int v1,v2,w;
        cin>>v1>>v2>>w;
        //g[v1].push_back({w,v2});
        g[v2].push_back({w,v1});
       // cout<<nl;

    }
    dijkstra(e);
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        if(dist[i]<=t)ans++;
    }
    cout<<ans<<nl;
    if (tst)puts("");
    for(int i=1;i<=n+10;i++)
    {
        dist[i]=INF;
        vis[i]=false;
        g[i].clear();
    }

   }
/// seff

}