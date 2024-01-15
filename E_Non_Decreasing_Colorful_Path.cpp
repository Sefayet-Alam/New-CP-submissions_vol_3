#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define N 200005
#define bug(a) cout<< #a << " : " << a <<endl;

vector<int> adj[N];
const int INF = INT_MIN;
vector<int> longestDistance(N, INF);

int par[N];
int sz[N];
int rep[N];

void make_set(int v){
    par[v] = v;
    sz[v] = 1;
}

int find_set(int v){
    if(v == par[v]) return v;
    return par[v] = find_set(par[v]);
}

void union_sets(int a, int b){
    a = find_set(a);
    b = find_set(b);
    if(a != b){
        if(sz[a] > sz[b]) swap(a, b);
        par[a] = b;
        sz[b] += sz[a];
    }
}

// void dijkstra(int src){
//     dist[src] = 0;
//     priority_queue<pair<int, int>> pq;
//     pq.push({0, src});
//     while(!pq.empty()){
//         int d = pq.top().first;
//         int node = pq.top().second;
//         pq.pop();
//         if(dist[node] > d) continue;
//         for(auto child : adj[node]){
//             if(dist[node] + 1 > dist[child]){
//                 dist[child] = dist[node] + 1;
//                 pq.push({dist[child], child});
//             }
//         }
//     }
// }

void dfs(int node, vector<bool>& visited, stack<int>& st) {
    visited[node] = true;
    for (int child : adj[node]) {
        if (!visited[child]) {
            dfs(child, visited, st);
        }
    }
    st.push(node);
}

void longestPathDAG(int src, int n) {
    vector<bool> visited(n, false);
    stack<int> st;

    for (int i = 1; i < n; ++i) {
        if (!visited[i]) {
            dfs(i, visited, st);
        }
    }

    longestDistance[src] = 0;

    while (!st.empty()) {
        int node = st.top();
        st.pop();

        if (longestDistance[node] != INF) {
            for (int child : adj[node]) {
                longestDistance[child] = max(longestDistance[child], longestDistance[node] + 1);
            }
        }
    }
}

void solve(int cs){
    int n, m;
    cin >> n >> m;
    int cost[n + 1];
    for(int i = 1;i <= n;i++){
        cin >> cost[i];
        make_set(i);
    }
    vector<pair<int, int>> edge;
    for(int i = 0;i < m;i++){
        int u, v;
        cin >> u >> v;
        if(cost[u] == cost[v]) union_sets(u, v);
        edge.push_back({u, v});
    }
    int r = 1;
    for(int i = 1;i <= n;i++){
        int a = find_set(i);
        if(rep[a] == 0) rep[a] = r++;
    }
    for(int i = 0;i < m;i++){
        int u = edge[i].first, v = edge[i].second;
        int a = find_set(u);
        int b = find_set(v);
        if(a == b) continue;
        else if(cost[u] < cost[v]) adj[rep[a]].push_back(rep[b]);
        else adj[rep[b]].push_back(rep[a]);
    }
    // for(int i = 1;i <= n;i++){
    //     bug(i);
    //     for(auto u : adj[i]) cout << u << " ";
    //     cout << endl;
    // }
    int src = rep[find_set(1)];
    int dest = rep[find_set(n)];
    // dijkstra(src);
    longestPathDAG(src, --r);
    // bug(dest);
    if(longestDistance[dest] == INF) cout << 0 << endl;
    else cout << longestDistance[dest] + 1 << endl;
}

int main(){
    ios_base::sync_with_stdio;cin.tie(0);
    cout.tie(0);

    int tc = 1;
    // cin >> tc;

    for(int cs = 1; cs <= tc; cs++){
        solve(cs);
    }
}
//bruh i copied coz my code doesnt work