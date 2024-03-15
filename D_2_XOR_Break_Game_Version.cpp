#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

//VVI
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define pb                  push_back
#define ll                  long long

int popcount(ll x){return __builtin_popcountll(x);};
int poplow(ll x){return __builtin_ctzll(x);};
int pophigh(ll x){return 63 - __builtin_clzll(x);};


int main()
{
    fast;
     ll t;
    //setIO();
     //ll tno=1;;
     t=1;
    cin>>t;

    while(t--){
      ll n;
      cin>>n;
      ll cnton=popcount(n);
      if(cnton%2==0){
        cout<<"first"<<endl;
        ll x=(1LL<<pophigh(n));
        cout<<x<<" "<<(n^x)<<endl;
      }
      else{
        cout<<"second"<<endl;
      }
      ll x,y;
      while(1){
        cin>>x>>y;
        if(x==0 && y==0) break;
        ll cnton2=popcount(x);
        if(cnton2%2==0){
            n=x;
        }
        else n=y;
        ll ret=(1LL<<pophigh(n));
        cout<<ret<<" "<<(n^ret)<<endl;
      }
    }
    return 0;
}

