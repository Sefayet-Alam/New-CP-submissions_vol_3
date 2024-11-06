struct item{
    ll value;//current value
    ll lazy;//value to be lazyed 
    ll assign;//value to be assigned
};
struct segment_tree{
    ll size;
    vector<item>tree;
    ll neutral=0;
    ll no_op=0;
    ll merge(ll a,ll b){
        //    if(a==no_op) return b;
        //    if(b==no_op) return a;
        return (a+b);
    }
    void init(ll n){
        size=1;
        while(size<n) size*=2;
        tree.resize(2*size);
        tree.assign(2*size,{neutral,no_op,no_op});
    }
    void build(vector<ll>&a,ll x,ll lx,ll rx){
        if(rx-lx==1){if(lx<a.size()){tree[x]={a[lx],no_op,no_op};}return;}
        ll m=(lx+rx)/2;
        build(a,2*x+1,lx,m);
        build(a,2*x+2,m,rx);
        tree[x]={tree[x].value=merge(tree[2*x+1].value,tree[2*x+2].value),no_op,no_op};
    }
    void build(vector<ll>&a){
        //linear time
        build(a,0,0,size);
    }
    item propagate_op(item par,item child,ll len){
        //throws lazy values to its children nodes 
        //updates values to children nodes
        item ret=child;
        if(par.assign!=no_op){
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
        if(rx-lx==1||(tree[x].assign==no_op&&tree[x].lazy==no_op)){return;}
        ll m=(rx+lx)/2;
        tree[2*x+1]=propagate_op(tree[x],tree[2*x+1],m-lx);
        tree[2*x+2]=propagate_op(tree[x],tree[2*x+2],rx-m);
        tree[x].lazy=tree[x].assign=no_op;
    }
    ll RangeQuery(ll l,ll r,ll x,ll lx,ll rx){
        propagate(x,lx,rx);
        if(lx>=r||l>=rx){return(-M);}
        if(lx>=l&&rx<=r){return tree[x].value;}
        ll m=(lx+rx)/2;
        ll s1=RangeQuery(l,r,2*x+1,lx,m);
        ll s2=RangeQuery(l,r,2*x+2,m,rx);
        return max(s1,s2);
    }
    ll RangeQuery(ll l,ll r){
        //returns sum from l to r
        return RangeQuery(l,r,0,0,size);
    }
    void RangeUpdate(ll l,ll r,ll v,ll x,ll lx,ll rx){
        //adds v from l to r-1
        propagate(x,lx,rx);
        if(lx>=r||l>=rx){return;}
        if(lx>=l&&rx<=r){
            tree[x].lazy=merge(tree[x].lazy,v);
            tree[x].value+=(rx-lx)*v;
            return;
        }
        ll m=(lx+rx)/2;
        RangeUpdate(l,r,v,2*x+1,lx,m);
        RangeUpdate(l,r,v,2*x+2,m,rx);  
        tree[x].value=merge(tree[2*x+1].value,tree[2*x+2].value);
    }
    void RangeUpdate(ll l,ll r,ll v){
        //adds v from l to r-1
        RangeUpdate(l,r,v,0,0,size);
    }
    void RangeAssign(ll l,ll r,ll v,ll x,ll lx,ll rx){
        //assigns v from l to r-1
        propagate(x,lx,rx);
        if(lx>=r||l>=rx){return;}
        if(lx>=l&&rx<=r){
            tree[x].assign=v;
            tree[x].lazy=no_op;
            tree[x].value=(rx-lx)*v;
            return;
        }
        ll m=(lx+rx)/2;
        RangeAssign(l,r,v,2*x+1,lx,m);
        RangeAssign(l,r,v,2*x+2,m,rx);  
        tree[x].value=merge(tree[2*x+1].value,tree[2*x+2].value);
    }
    void RangeAssign(ll l,ll r,ll v){
        //assigns v from l to r-1;
        RangeAssign(l,r,v,0,0,size);
    }
};
