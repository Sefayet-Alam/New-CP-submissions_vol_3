#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

// VVI
#define fast                      \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);
#define pb push_back
#define ll int

int main()
{
    fast;
    ll t;
    // setIO();
    // ll tno=1;;
    t = 1;
    cin >> t;
   
    // for(int i=1;i<=1e3+2;i++) sqs.push_back(i*i);
    while (t--)
    {
      ll n;
      cin>>n;
      
      vector<pair<int,int>>ans2;
      for(ll i=1;i*i<=n;i++){
        ans2.push_back({1,i*i});
      }
      for(ll i=2;i*i<=n;i++){
        for(ll j=i;i*j<=n;j*=j){
            ans2.push_back({i,j});
        }
      }
      cout<<ans2.size()<<endl;
      sort(ans2.begin(),ans2.end());
      for(auto it:ans2){
        cout<<it.first<<" "<<it.second<<endl;
      }
    }

    return 0;
}
