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
const ll N = 2e5+10;
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

int main()
{
    fast;
     ll t;
    //setIO();
     //ll tno=1;;
     t=1;
    cin>>t;

    while(t--){
        string s;
        cin>>s;
        string s2;
        cin>>s2;
        string dt=s.substr(0,2);
        
        string mon=s.substr(3,3);

        string yr=s.substr(6,7);
       
        mon.pop_back();
        ll date=stoi(dt);
       
        ll month=stoi(mon);

        ll year=stoi(yr);
         deb(date);
        deb(year);
        deb(month);
        cout<<"|---------------------------|"<<nn<<"|Sun|Mon|Tue|Wed|Thu|Fri|Sat|"<<nn;
        cout<<"|---------------------------|"<<nn;
        vector<string>ups,downs;


        ll dayno=-1;
        if(s2=="Sun") dayno=0;
        else if(s2=="Mon") dayno=1;
        else if(s2=="Tue") dayno=2;
        else if(s2=="Wed") dayno=3;
        else if(s2=="Thu") dayno=4;
        else if(s2=="Fri") dayno=5;
        else if(s2=="Sat") dayno=6;
        ll dayno2=dayno;
        ll date2=date;
        // deb(dayno);
        // deb(date2);
        // ll dayno2=dayno+1;
        ll stdayno=dayno;
        while(date2){
        string currstr="";
        ll cdt=date2;
        
        while(dayno>=0){
            if(cdt==0) break;
            dayno--;
            string currdate="|";
            string tmp=to_string(cdt);
            if(tmp.size()==1) tmp="  "+tmp;
            else tmp=" "+tmp;
            // deb(tmp);
            currdate+=tmp;
            currstr=currdate+currstr;
            cdt--;
        }
        while(cdt==0 && dayno>=0){
            currstr="| - "+currstr;
            dayno--;
        }
       
        if(date2!=date) currstr+="|";
        else if(date2==date && stdayno==6) currstr+="|";
        dayno=6;
        date2=cdt;
        ups.push_back(currstr);

        }
        reverse(all(ups));
        vector<string> ans;

        
        
        ll totday=0;

        
        ll totdays=0;
        if(month==1) totdays=31;
        else if(month==2){
         if (year % 400 == 0) totdays=29;
         else if (year % 100 == 0) totdays=28;
         else if (year % 4 == 0) totdays=29;
         else totdays=28;
        }
        else if(month==3)totdays=31;
        else if(month==4)totdays=30;
        else if(month==5)totdays=31;
        else if(month==6)totdays=30;
        else if(month==7)totdays=31;
        else if(month==8)totdays=31;
        else if(month==9)totdays=30;
        else if(month==10)totdays=31;
        else if(month==11)totdays=30;
        else if(month==12)totdays=31;
        // deb(totdays);
        dayno=dayno2+1;
        if(dayno>6) dayno=0;
        date2=date+1;
        // deb(dayno);
        // deb(date2);
        
        vector<string>ups2;
        
        
        while(date2<=totdays){
        string currstr="";
        
        while(dayno<=6){
            // if(date2==totdays) break;
            string currdate="|";
            string tmp=to_string(date2);
            if(tmp.size()==1) tmp="  "+tmp;
            else tmp=" "+tmp;
        
            currdate+=tmp;
            // deb(currdate);
            currstr=currstr+currdate;
            dayno++;
            date2++;
            if(date2==totdays+1) break;
        }
        ll cdt=date2;
        while(cdt==totdays && dayno<=6){
            currstr=currstr+"| - ";
            dayno++;
        }
        dayno=0;
        currstr+="|";
        // deb(currstr);
        ups2.push_back(currstr);
        }
        
        if(ups.back().size()!=29 && ups2[0].size()!=29){
            
            string p=ups.back();
            ups.pop_back();
            ups2[0]=p+ups2[0];
        }
        if(ups2.back().size()<29){
            string p=ups2.back();
            while(p.size()<29){
                p+=" - |";
            }
            ups2.pop_back();
            ups2.push_back(p);
        }


        for(auto it:ups){
            ans.push_back(it);
        }
        for(auto it:ups2){
            ans.push_back(it);
        }


        for(auto it:ans){
            cout<<it<<nn;
        }
        
         cout<<"|---------------------------|"<<nn;
    }


    return 0;
}

