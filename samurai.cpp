#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

//VVI
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define pb                  push_back
#define ll                  long long
#define ff first
#define ss second
#define SZ(a) (int)a.size()
#define UNIQUE(a) (a).erase(unique(all(a)),(a).end())
#define eb emplace_back
#define mp make_pair


///BIT MANIPULATION

#define Set(x, k) (x |= (1LL << k))
#define Unset(x, k) (x &= ~(1LL << k))
#define Check(x, k) (x & (1LL << k))
#define Toggle(x, k) (x ^ (1LL << k))

//LOOPS

#define scl(n)              scanf("%lld", &n)
#define fr(i,n)             for (ll i=0;i<n;i++)
#define fr1(i,n)            for(ll i=1;i<=n;i++)
#define Fo(i,k,n) for(i=k;k<n?i<n:i>n;k<n?i+=1:i-=1)

///PRINTING

#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl
#define nn '\n'
#define pfl(x)              printf("%lld\n",x)
#define pcas(i)                printf("Case %lld: ",i)
#define Setpre(n) cout<<fixed<<setprecision(n)
#define itr(it, a) for(auto it = a.begin(); it != a.end(); it++)
#define debug               printf("I am here\n")

///SORTING AND FILLING

#define asort(a)            sort(a,a+n)
#define dsort(a)            sort(a,a+n,greater<int>())
#define vasort(v)         sort(v.begin(), v.end());
#define vdsort(v)         sort(v.begin(), v.end(),greater<ll>());
#define rev(x) reverse(all(x))
#define sortall(x) sort(all(x))
#define mem(a,b) memset(a,b,sizeof(a))
#define all(x) x.begin(), x.end()
#define rev(x) reverse(all(x))

//CONSTANTS
#define md                  10000007
#define PI 3.1415926535897932384626
const double EPS = 1e-9;
const ll M = 1e9+7;


///INLINE FUNCTIONS
inline ll GCD(ll a, ll b) { return b == 0 ? a : GCD(b, a % b); }
inline ll LCM(ll a, ll b) { return a * b / GCD(a, b); }
inline ll Ceil(ll p, ll q)  {return p < 0 ? p / q : p / q + !!(p % q);}
inline ll Floor(ll p, ll q) {return p > 0 ? p / q : p / q - !!(p % q);}
inline double logb(ll base,ll num){ return (double)log(num)/(double)log(base);}
inline bool isPerfectSquare(long double x){ if (x >= 0) { long long sr = sqrt(x);return (sr * sr == x); }return false; }
double euclidean_distance(ll x1,ll y1,ll x2,ll y2){double a=(x2-x1)*(x2-x1);double b=(y2-y1)*(y2-y1);double c=(double)sqrt(a+b);return c;}
int popcount(ll x){return __builtin_popcountll(x);};
int poplow(ll x){return __builtin_ctzll(x);};
int pophigh(ll x){return 63 - __builtin_clzll(x);};


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

 
namespace io{
    template<typename First, typename Second> ostream& operator << ( ostream &os, const pair<First, Second> &p ) { return os << p.first << " " << p.second; }
    template<typename First, typename Second> ostream& operator << ( ostream &os, const map<First, Second> &mp ) { for( auto it : mp ) { os << it << endl;  } return os; }
    template<typename First> ostream& operator << ( ostream &os, const vector<First> &v ) { bool space = false; for( First x : v ) { if( space ) os << " "; space = true; os << x; } return os; }
    template<typename First> ostream& operator << ( ostream &os, const set<First> &st ) { bool space = false; for( First x : st ) { if( space ) os << " "; space = true; os << x; } return os; }
    template<typename First> ostream& operator << ( ostream &os, const multiset<First> &st ) { bool space = false; for( First x : st ) { if( space ) os << " "; space = true; os << x; } return os; }
 
    template<typename First, typename Second> istream& operator >> ( istream &is, pair<First, Second> &p ) { return is >> p.first >> p.second; }
    template<typename First> istream& operator >> ( istream &is, vector<First> &v ) { for( First &x : v ) { is >> x; } return is; }
    
    long long fastread(){ char c; long long d = 1, x = 0; do c = getchar(); while( c == ' ' || c == '\n' ); if( c == '-' ) c = getchar(), d = -1; while( isdigit( c ) ){ x = x * 10 + c - '0'; c = getchar(); } return d * x; }
    
    static bool sep = false;
 
    using std::to_string;
 
    string to_string( bool x ){ return ( x ? "true" : "false" ); }
    string to_string( const string & s ){ return "\"" + s + "\""; }
    string to_string( const char * s ){ return "\"" + string( s ) + "\""; }
    string to_string ( const char & c ) { string s; s += c; return "\'" + s + "\'"; }
 
    template<typename Type> string to_string( vector<Type> );
    template<typename First, typename Second> string to_string( pair<First, Second> );
    template<typename Collection> string to_string( Collection );
 
    template<typename First, typename Second> string to_string( pair<First, Second> p ){ return "{" + to_string( p.first ) + ", " + to_string( p.second ) + "}"; }
    template<typename Type> string to_string( vector<Type> v ) { bool sep = false; string s = "["; for( Type x: v ){ if( sep ) s += ", "; sep = true; s += to_string( x ); } s += "]"; return s; }
    template<typename Collection> string to_string( Collection collection ) { bool sep = false; string s = "{"; for( auto x: collection ){ if( sep ) s += ", "; sep = true; s += to_string( x ); } s += "}"; return s; }
 
    void print() { cerr << endl; sep = false; }
    template <typename First, typename... Other> void print( First first, Other... other ) { if( sep ) cerr << " | "; sep = true; cerr << to_string( first ); print( other... ); }
    
} using namespace io;
 

/*===================================================================//
            
        ░█▀▀▀█ ░█▀▀▀ ░█▀▀▀ ─█▀▀█ ░█──░█ ░█▀▀▀ ▀▀█▀▀ 
        ─▀▀▀▄▄ ░█▀▀▀ ░█▀▀▀ ░█▄▄█ ░█▄▄▄█ ░█▀▀▀ ─░█── 
        ░█▄▄▄█ ░█▄▄▄ ░█─── ░█─░█ ──░█── ░█▄▄▄ ─░█──
//====================================================================*/

void setIO(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);

    freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

}


struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }
    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};
const ll N = 100;

vpll g[N];
vl dist(N,LLONG_MAX);
vl par(N,-1);

vpll g2[N];
vl par2(N,-1);
vl cost(N,LLONG_MAX);

void dijkstra(int source){
    QP<pll> pq;
    pq.push(mp(0,source));
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
                cost[child_v]=cost[v]+wt;
                par[child_v]=v;
                pq.push(mp(dist[child_v],child_v));
            }
        }
    }
}

void dijkstra2(int source){
    QP<pll> pq;
    pq.push(mp(0,source));
    cost[source]=0;
    while(pq.size()){
        ll v=pq.top().second;
        ll v_dist=pq.top().first;
        pq.pop();
        if(cost[v]<v_dist) continue;
        for(auto &child:g2[v]){
            ll child_v=child.first;
            ll wt=child.second;
            if(cost[v]+wt<cost[child_v]){
                cost[child_v]=cost[v]+wt;
                
                par2[child_v]=v;
                pq.push(mp(cost[child_v],child_v));
            }
        }
    }
}

void graph_create(){
    int totst=5;
    g[1].push_back({3,50});
    g[3].push_back({1,50});
    g2[1].push_back({3,100});
    g2[3].push_back({1,100});

     g[1].push_back({2,20});
    g[2].push_back({1,20});
    g2[1].push_back({2,500});
    g2[2].push_back({1,500});


     g[1].push_back({4,30});
    g[4].push_back({1,30});
    g2[1].push_back({4,100});
    g2[4].push_back({1,100});


 
     g[2].push_back({5,20});
    g[5].push_back({2,20});
    g2[2].push_back({5,500});
    g2[5].push_back({2,500});

     g[4].push_back({5,50});
    g[5].push_back({4,50});
    g2[4].push_back({5,100});
    g2[5].push_back({4,100});
}

ll time(string s){
    ll ret=((s[0]-'0')*10+(s[1]-'0'))*60+((s[3]-'0')*10+s[4]-'0');
    return ret;
}

void reset(){
    for(ll i=0;i<=N;i++){
        par[i]=-1;
        par2[i]=-1;
        dist[i]=10000000;
        cost[i]=10000000;
    }
}
string tostr(ll n){
    ll hrs=n/60;
    string a=to_string(hrs);
    if(a.size()==1){
        a='0'+a;
    }
    string b=to_string(n%60);
    if(b.size()==1){
        b='0'+b;
    }
    string ret=a+":"+b;
    return ret;
}

void optimize_by_cost(ll from,ll to,ll sttime){
    //optimize by cost
        cout<<"Optimize by cost"<<nn;
        reset();
        dijkstra2(from);
        cout<<"Total cost= "<<cost[to]<<" Total dist: "<<dist[to]<<nn;
        if(par2[to]==-1){
        cout<<"no routes available from station:"<<from<<"to station: "<<to<<nn;
        return;
        }
        vector<ll>path;
        while(par2[to]!=-1){
        path.push_back(to);
        to=par2[to];
        }
        path.push_back(from);
        reverse(all(path));
        cout<<"Station no: "<<from<<nn;
        cout<<"Trainid: "<<1+(rand()%4)<<nn;
        cout<<"Arrival time: "<<tostr(sttime)<<nn;
        cout<<"departure time: "<<tostr(sttime+1)<<nn;
        ll last=sttime+1;
        for(ll i=1;i<path.size();i++){
            cout<<"Station no: "<<path[i]<<nn;
            cout<<"Trainid: "<<1+(rand()%4)<<nn;
            cout<<"Arrival time: "<<tostr(last+dist[path[i]]-dist[path[i-1]])<<nn;
            cout<<"departure time: "<<tostr(last+dist[path[i]]-dist[path[i-1]]+1)<<nn;
            last+=dist[path[i]]-dist[path[i-1]];
        }
}

void optimize_by_dist(ll from,ll to,ll sttime){
    cout<<"Optimize by dist"<<nn;

        reset();
        dijkstra(from);
        cout<<"Total cost= "<<cost[to]<<" Total dist: "<<dist[to]<<nn;
        
        if(par[to]==-1){
        cout<<"no routes available from station:"<<from<<"to station: "<<to<<nn;
        return;
        }
        vector<ll>path;
        while(par[to]!=-1){
        path.push_back(to);
        to=par[to];
        }
        path.push_back(from);
        reverse(all(path));


        cout<<"Station no: "<<from<<nn;
        cout<<"Trainid: "<<1+(rand()%4)<<nn;
        cout<<"Arrival time: "<<tostr(sttime)<<nn;
        cout<<"departure time: "<<tostr(sttime+1)<<nn;
        
        ll last=sttime+1;
        
        for(ll i=1;i<path.size();i++){
            cout<<"Station no: "<<path[i]<<nn;
            cout<<"Trainid: "<<1+(rand()%4)<<nn;
            cout<<"Arrival time: "<<tostr(last+dist[path[i]]-dist[path[i-1]])<<nn;
            cout<<"departure time: "<<tostr(last+dist[path[i]]-dist[path[i-1]]+1)<<nn;
            last+=dist[path[i]]-dist[path[i-1]];
        }  
}
int main()
{
   
     ll t;
    //setIO();
     //ll tno=1;;
     t=1;
    //cin>>t;

    
    int from,to,walletid;
    string starttime;
    cout<<"from"<<" "<<"to "<<" "<<"starttime"<<nn;

    cin>>from>>to>>starttime;
    // bool f=transactiondone(walletid);
    graph_create();
    bool f=1;
    ll sttime=time(starttime);
    if(f){
       //optimize by dist
        optimize_by_dist(from,to,sttime);
        //optimize by cost
        optimize_by_cost(from,to,sttime);    

    }

    
    return 0;
}

