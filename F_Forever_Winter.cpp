#include<iostream>
using namespace std;int main(){int t,n,f,m,x;cin>>t;while(t--){cin>>n>>m;int k=n,p[201]={};m*=2;while(m--){cin>>x;k-=p[x]++==1;}f=n-1-k;cout<<f<<' '<<k/f<<' ';}}