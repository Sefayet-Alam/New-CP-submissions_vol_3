#include<bits/stdc++.h>
using namespace std;


//VVI
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define pb                  push_back
#define ll                  long long

ll ask(ll x,ll y){
    cout<<"?"<<" "<<x<<" "<<y<<endl;
    ll x;
    cin>>x;
    return x;
}
void ans(ll x,ll y){
    cout<<"!"<<" "<<x<<" "<<y<<endl;

}
int main()
{
    // fast;
     ll t;
    //setIO();
     //ll tno=1;;
     t=1;
    cin>>t;

    while(t--){
        ll n,m;
        cin>>n>>m;
        ll k=ask(1,1);
        if(k==0){ans(1,1);continue;}
        ll k1=ask(n,1);
        if(k1==0){ans(n,1);continue;}
        ll k2=ask(n,m);
        if(k2==0){ans(n,m);continue;}

        ll y1=(k+k1+3)/2;
        ll x1=k+2-y1;

        ll x2=(2*n-k1-k2-1+m)/2;
        ll y2=(k1+1-n+x2);

        ll f=ask(x1,y1);
        if(f==0){ans(x1,y1);}
        else ans(x2,y2);

        

    }


    return 0;
}

