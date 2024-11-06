int Tree[4*N],a[N],lazy[4*N];
void pushh(int idx,int l,int r,int x){
lazy[idx]+=x;
Tree[idx]+=x*(r-l+1);
}
void push(int idx,int l,int r){
int mid=(l+r)/2,lft=idx*2,rgt=idx*2+1;
pushh(lft,l,mid,lazy[idx]);
pushh(rgt,mid+1,r,lazy[idx]);
lazy[idx]=0;
}
void build(int node,int st,int ed){
if (st==ed){
Tree[node]=a[st];
return;
}
int lft=node*2,rgt=(node*2)+1,mid=(st+ed)/2;
build(lft,st,mid);
build(rgt,mid+1,ed);
Tree[node]=Tree[lft]+Tree[rgt];
}
void range_update(int idx,int l,int r,int s,int e,int x){
int mid=(l+r)/2,lft=idx*2,rgt=idx*2+1;
if (l==s && r==e){
pushh(idx,l,r,x);
return;
}
if (lazy[idx]) push(idx,l,r);
if (e<=mid) range_update(lft,l,mid,s,e,x);
else if (s>mid) range_update(rgt,mid+1,r,s,e,x);
else{
range_update(lft,l,mid,s,mid,x);
range_update(rgt,mid+1,r,mid+1,e,x);
}
Tree[idx]=Tree[lft]+Tree[rgt];
}
int range_query(int idx,int l,int r,int s,int e){
int mid=(l+r)/2,lft=idx*2,rgt=idx*2+1;
if (l==s && r==e){
return Tree[idx];
}
if (lazy[idx]) push(idx,l,r);
if (e<=mid) return range_query(lft,l,mid,s,e);
else if (s>mid) return range_query(rgt,mid+1,r,s,e);
else{
int ans1=range_query(lft,l,mid,s,mid);
int ans2=range_query(rgt,mid+1,r,mid+1,e);
return ans1+ans2;
}
}
