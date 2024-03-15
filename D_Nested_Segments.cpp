#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>


using namespace std;
using namespace __gnu_pbds;


#define ll                  long long

template <typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <typename T,typename R> using ordered_map = tree<T, R , less<T>, rb_tree_tag, tree_order_statistics_node_update>;

int main()
{
   
     ll t;
    //setIO();
     //ll tno=1;;
     t=1;
    // cin>>t;

    while(t--){
      
      ll n;
      cin>>n;

      vector<pair<pair<ll,ll>,ll>>vec(n);
      
      for(ll i=0;i<n;i++){
        cin>>vec[i].first.first>>vec[i].first.second;
        vec[i].second=i;
      }

      sort(vec.begin(),vec.end());

      ordered_set<ll>os;
      map<ll,ll>freq;
      vector<ll>ans(n);
      
      for(ll i=0;i<n;i++){
        os.insert(vec[i].first.second);
        freq[vec[i].first.second]++;
      }

      for(ll i=0;i<n;i++){
        ll k=os.order_of_key(vec[i].first.second);
        ans[vec[i].second]=k;
        freq[vec[i].first.second]--;
        if(freq[vec[i].first.second]==0){
            os.erase(os.find(vec[i].first.second));
        }
      }
      for(ll i=0;i<n;i++){
        cout<<ans[i]<<endl;
      }
    
    }


    return 0;
}