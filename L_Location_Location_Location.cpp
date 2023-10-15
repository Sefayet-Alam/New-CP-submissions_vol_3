#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define ll long long
#define MOD 1000000007
using namespace std;
int main()
{
   ll t=1;
while(t--){
    ll n, cou=0,x1,y1;
    
    cin >> n;
    vector<ll> x(n),y(n); 
    for(ll i=0;i<n;i++) cin >> x[i] >> y[i];

    sort(x.begin(),x.end());
    sort(y.begin(), y.end());

    x1=x[(n-1)/2], y1= y[(n-1)/2];
    cout << x1 <<" "<< y1  << endl;

    
    }
    return 0;
}