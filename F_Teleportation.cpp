#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;
/*
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<class T> using ordered_set =tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>;
// ordered_set.find_by_order(k) returns the iterator to kth element
// ordered_set.order_of_key(k) returns the number of elements strictly less than k */
#define watch(x) cerr << "\n" << (#x) << " is " << (x) << endl
#define fastio ios_base::sync_with_stdio(0)
#define flush_off cin.tie(0)

const int mod = 998244353;


// VVI
#define fast                      \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);
#define pb push_back
#define ll long long



struct item{
    ll value;//current value
    ll lazy;//value to be lazyed 
    ll assign;//value to be assigned
};

struct segment_tree{
    ll size;
    vector<item>tree;
    ll neutral=0;
    ll no_op=LLONG_MIN;
    
    //General operations : O(1)

    ll merge(ll a,ll b){
       if(a==no_op) return b;
        return (a+b);
    }
    ll addnodes(ll a,ll b){
        return a+b;
    }

   
    //INITIALIZATION: O(log2 n)

    void init(ll n){
        size=1;
        while(size<n) size*=2;
        tree.resize(2*size);
        tree.assign(2*size,{0,no_op,no_op});
    }
    
    ///BUILD
    void build(vector<ll> &a,ll x,ll lx,ll rx){
        if(rx-lx==1){
            if(lx<a.size()){
                tree[x]={a[lx],no_op,no_op};
            }
            return;
        }
        ll m=(lx+rx)/2;
        build(a,2*x+1,lx,m);
        build(a,2*x+2,m,rx);
        tree[x]={ tree[x].value=addnodes(tree[2*x+1].value,tree[2*x+2].value),no_op,no_op};
    }

    void build(vector<ll> &a){
        //linear time
        build(a,0,0,size);
    }

    ///LAZY PROPAGATION
    
    //throws lazy values to its children nodes 
     //updates values to children nodes
        item propagate_op(item par,item child,ll len){
        item ret=child;
        if(par.assign!=no_op)
        {
            ret.assign=par.assign;
            ret.lazy=no_op;
            ret.value=len*(par.assign);
        }
 
        if(par.lazy!=no_op){
            ret.lazy=merge(ret.lazy,par.lazy);
            ret.value+=len*par.lazy;
        }
 
        return ret;
    }
 
    void propagate(ll x,ll lx,ll rx){
        if(rx-lx==1 || (tree[x].assign==no_op && tree[x].lazy==no_op)){
            return;
        }
        ll m=(rx+lx)/2;
        tree[2*x+1]=propagate_op(tree[x],tree[2*x+1],m-lx);
        tree[2*x+2]=propagate_op(tree[x],tree[2*x+2],rx-m);
        tree[x].lazy=tree[x].assign=no_op;
    }



    ///RANGE SUM
    ll sum(ll l,ll r,ll x,ll lx,ll rx){
        propagate(x,lx,rx);
        if(lx>=r || l>=rx){
            return 0;
        }
        if(lx>=l && rx<=r){
            return tree[x].value;
        }
        ll m=(lx+rx)/2;
        ll s1=sum(l,r,2*x+1,lx,m);
        ll s2=sum(l,r,2*x+2,m,rx);
        return  addnodes(s1,s2);
    }

    
    ll sum(ll l,ll r){
        //returns sum from l to r
       
        return sum(l,r,0,0,size);
    }

    //RANGE operation
    
    void RangeUpdate(ll l,ll r,ll v,ll x,ll lx,ll rx){
        propagate(x,lx,rx);
        if(lx>=r || l>=rx){
            return;
        }
        if(lx>=l && rx<=r){
            tree[x].lazy=merge(tree[x].lazy,v);
            tree[x].value+=(rx-lx)*v;
            return;
        }
        ll m=(lx+rx)/2;
        RangeUpdate(l,r,v,2*x+1,lx,m);
        RangeUpdate(l,r,v,2*x+2,m,rx);  
         tree[x].value=addnodes(tree[2*x+1].value,tree[2*x+2].value);
    }
    

    void RangeUpdate(ll l,ll r,ll v){
        //multipliess v from l to r
        RangeUpdate(l,r,v,0,0,size);
    }
    ///RANGE ASSIGN
     void RangeAssign(ll l,ll r,ll v,ll x,ll lx,ll rx){
        propagate(x,lx,rx);
        if(lx>=r || l>=rx){
            return;
        }
        if(lx>=l && rx<=r){
            tree[x].assign=v;
            tree[x].lazy=no_op;
            tree[x].value=(rx-lx)*v;
            
            return;
        }
        ll m=(lx+rx)/2;
        RangeAssign(l,r,v,2*x+1,lx,m);
        RangeAssign(l,r,v,2*x+2,m,rx);  
        tree[x].value=addnodes(tree[2*x+1].value,tree[2*x+2].value);
    }
    
    void RangeAssign(ll l,ll r,ll v){
        //multipliess v from l to r
      RangeAssign(l,r,v,0,0,size);
    }   
};


const int N = 3e5+5;  // limit for array size
int n;  // array size
int t[2 * N];

void build() {  // build the tree
  for (int i = n - 1; i > 0; --i) t[i] = t[i<<1] + t[i<<1|1];
}

void modify(int p, int value) {  // set value at position p
  for (t[p += n] = value; p > 1; p >>= 1) t[p>>1] = t[p] + t[p^1];
}
int query(int l, int r) {  // sum on interval [l, r)
  int res = 0;
  for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
    if (l&1) res += t[l++];
    if (r&1) res += t[--r];
  }
  return res;
}



ll npr(ll n, ll r)
{
    ll res = 1;
    for(ll i=n-r+1; i<=n; ++i)
    {
        res *= i;
        res %= mod;
    }
    return res;
}



void solve()
{
    int k; cin>>n>>k;
    int p[k]; for(auto &i:p) cin>>i;

    segment_tree SG;
    SG.init(n+5);
    vector<ll>tmp(n+5,0);
    SG.build(tmp);
    
    build();

    ll avail[k];
    for(int i=0; i<k; ++i)
    {
        avail[k] = query(1,p[i]);
        modify(p[i],1);
    }

    for(int i=0; i<k; ++i)
    {
        int leftl = i, rightl = k-i-1;
        

        ll num = (npr(n-k+rightl-1,rightl-1)*rightl)%mod;

        ll val1 = avail[i]*num;
        val1 %= mod;


        ll val2 = (avail[i]-1) * num;
        val2 %= mod;

        val2 += npr(n-k+rightl,rightl);
        val2 %= mod;


        SG.RangeUpdate(p[i],n+1,val1);
        SG.RangeUpdate(1,p[i],val2);

    }


    for(int i=1; i<=n; ++i)
    {
        cout<<SG.sum(i,i+1)<<'\n';
    }


}

int main()
{
    fastio;
    flush_off; //turn this off if cout needs to be flushed
    #ifndef ONLINE_JUDGE
        freopen("Error.txt", "w", stderr);
    #endif
    int t=1;
    // cin>>t;
    while(t--) solve();
}