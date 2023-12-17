#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define fr(m) for(int i=0; i<m; i++)
#define fro(m) for(int i=1; i<m; i++)
#define frj(m) for(int j=0; j<m; j++)
#define frr(n) for(int i=n; i>=0; i--)
#define pb push_back
#define pf push_front
#define orr ||
#define nl '\n'
#define nll cout<<'\n'
#define mod 1000000007
#define inf (1LL<<61)
#define inff (1<<30)
#define yes cout<<"YES"<<nl
#define no cout<<"NO"<<nl
#define ff first
#define ss second
#define all(v) v.begin(), v.end()
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL)
#define mxn changeit

int main()
{
    fastio;
    int t, cnt=1;
    cin>>t;
    while(t--){
        ll a, b;
        ll xk, yk, xq, yq;
        cin>>a>>b;
        cin>>xk>>yk;
        cin>>xq>>yq;
        ll dx[]={a,-a,a,-a,b,b,-b,-b};
        ll dy[]={b,b,-b,-b,a,-a,a,-a};
        map<pair<ll,ll>,int>p,q;
        fr(8){
            p[{xk+dx[i],yk+dy[i]}]=1;
            q[{xq+dx[i],yq+dy[i]}]=1;
        }
        ll ans=0;
        for(pair<pair<ll,ll>,int>c : p){
            if(q[c.ff]) ans++;
        }
        cout<<ans<<nl;
    }
    return 0;
}