#pragma GCC optimize(2)
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline","fast-math","unroll-loops","no-stack-protector")
#pragma GCC diagnostic error "-fwhole-program"
#pragma GCC diagnostic error "-fcse-skip-blocks"
#pragma GCC diagnostic error "-funsafe-loop-optimizations"
#pragma GCC optimize("O3")

//use before include

#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define pf push_front
#define pob pop_back
#define pof pop_front
#define ff first
#define ss second
#define PLL pair<ll,ll>
#define pii pair<int,int>
#define SetBit(x, k) (x |= (1LL << k))
#define ClearBit(x, k) (x &= ~(1LL << k))
#define CheckBit(x, k) (x & (1LL << k))
#define scn(n) scanf("%d",&n)
#define scnll(n) scanf("%lld",&n)
#define nl cout<<"\n"
#define YES cout<<"YES\n"
#define Yes cout<<"Yes\n"
#define yes cout<<"yes\n"
#define NO cout<<"NO\n"
#define No cout<<"No\n"
#define no cout<<"no\n"
#define mod 1000000007LL
#define mod1 1000000007LL
#define mod2 1000000009LL
#define inf 1000000000000000LL
#define N 200000

#define fastio std::ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;


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
    fastio;
    int t,ts=1;cin>>t;
    while(t--){
        ll n;
        string s;cin>>s;
        n=s.size();
        unordered_map<ll,ll,custom_hash> num,tmp,tmp_mx,pre,pre_mx,num2;
        num[1]=1;
        pre[1]=1;
        pre_mx[1]=1;
        if(n==1){
            cout<<s<<"\n";
            continue;
        }
        for(ll i=1;i<n;i++){
            tmp.clear();
            for(ll j=0;j<10;j++){
                for(auto [x,y]:pre){
                    tmp[x*j]=1;
                    num[x*j]=1;
                } 
            }
            swap(pre,tmp);
            ///cout<<i<<" -> "<<num.size()<<"\n";
        }
        pre.clear();
        pre_mx.clear();
        pre_mx[1]=1;
        num2.clear();
        for(ll i=0;i<n;i++){
            tmp.clear();
            tmp_mx.clear();
            
            ll mx=s[i]-'0';
            for(auto [x,y]:pre){
                for(ll j=0;j<=9;j++){
                    tmp[x*j];
                    num[x*j];
                }
            }
            for(auto [x,y]:pre_mx){
                for(ll j=0;j<=mx;j++){
                    if(j<mx){
                        tmp[x*j];
                        num[x*j];
                    }
                    else if(j==mx){
                        tmp_mx[x*j];
                        num[x*j];
                    }
                }
            }
            swap(pre,tmp);
            swap(pre_mx,tmp_mx);
            ///cout<<i<<" -> "<<num.size()<<"\n";
        }
        cout<<num.size()<<"\n";
    }
}