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

#define ll long long


ll ask(ll c,ll r){
    // if(c==0) return r;
    cout<<"?"<<" "<<c<<" "<<r<<endl;
    ll x;
    cin>>x;
    return x;
}

int main()
{
    fast;
    ll t;
    // setIO();
    ll n;
    cin>>n;
    
    ll node=ask(n,1);
    ll c=ask(n,node);
    if(n==c){
        cout<<"! "<<c<<" "<<node<<endl;
        return 0;
    }
    ll r=ask(n-c,node);
    cout<<"! "<<c<<" "<<r<<endl;

    return 0;
}

/* Points tO CONSIDER
    # RTE? -> check array bounds and constraints
    #TLE? -> thinks about binary search/ dp / optimization techniques
    # WA? 
    -> overflow,reset global variables
    -> Check corner cases
    -> think from different approaches
    -> bruteforce to find pattern
    -> use Setpre for precision problems
*/
