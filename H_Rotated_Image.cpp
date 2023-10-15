///********************** بِسْمِ ٱللَّهِ ٱلرَّحْمَـٰنِ ٱلرَّحِيمِ **********************///

/**
 *     author: Shefat Hossen Shoikat
 *     date  : 2023-10-11 17:04:12
 **/

#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define mod 1000000007
#define inf 1e18
#define all(x) x.begin(), x.end()
#define eb emplace_back
#define ff first
#define ss second
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
#define dtob(p, n) bitset<p>(n).to_string()
#define btod(bin) stoi(bin, nullptr, 2)
#define ok cout << "Eureka" << nl
#define nl '\n'
#define SH 0
typedef long long ll;
typedef pair<ll, ll> pll;
typedef vector<ll> vl;
typedef vector<pll> vpll;


 ll height, width;
 ll a, b, n, m, theta;
 ll h,w;

bool func(ll pos){
    return (m*pos>=h && n*pos>=w);
}
ll bs(ll low,ll high){
    ll mid;
    ll ans=0;
    while(low<=high){
        mid=low+(high-low)/2;
        //cout<<mid<<" "<<func(mid)<<endl;
        if(func(mid)){
            ans=mid;
            high=mid-1;
        }
        else{
            low=mid+1;
        }
    }
    return ans;
}

int main()
{
    fastio;
    ll t;
    cin >> t;
    while (t--)
    {
      
        bool flag = true, fun = false, f = false;
       
        cin >> a >> b >> m >> n >> theta;

        height = ceil(a * cos(theta * acos(-1) / 180)+b * sin(theta * acos(-1) / 180));
        width = ceil(a * sin(theta * acos(-1) / 180)+b * cos(theta * acos(-1) / 180));
        h=(ll) height;
        w=(ll) width;
        
        // cout << height << " " << width << nl;
       ll l=1,r=1e9+10;
       ll ans=bs(l,r);
       cout<<m*ans<<" "<<n*ans<<endl;
    }
    return SH;
}