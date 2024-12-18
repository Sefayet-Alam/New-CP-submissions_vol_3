const ll N=1e5+10;
const ll INF=1e16+9;
vector<pair<ll,ll> > g[N];
vector<ll> dist(N,INF);
ll vis[N];
vector<ll>ans;
vector<ll>par(N);
ll n,m,k;
void dijkstra(int source){
    priority_queue<pair<ll,ll> > pq;
    pq.push({source,0});
    dist[source]=0;
    vis[source]=1;
    while(pq.size()){
        ll v=pq.top().first;
        ll v_dist=pq.top().second;
        pq.pop();
        if(v_dist>dist[v]) continue;
        vis[v]=1;
        for(auto &child:g[v]){
            ll child_v=child.first;
            ll wt=child.second;
          if(vis[child_v] && dist[v]+wt>dist[child_v]) continue;
            if(dist[v]+wt<dist[child_v]){
                dist[child_v]=dist[v]+wt;
                par[child_v]=v;
                pq.push({child_v,dist[child_v]});
            }
        }
    }
}
void reset(ll n){
    for(ll i=0;i<=n;i++){
        g[i].clear();
        dist[i]=INF;
    }
}
void func(ll vertex){
   ans.push_back(vertex);
   if(vertex==1) return;
    func(par[vertex]);
}
