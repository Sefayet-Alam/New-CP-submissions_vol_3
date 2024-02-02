#include<stdio.h>
#define ll long long

int main(){
      ll n;
      scanf(" %lld",&n);
      ll arr[n];
      ll x;
      for(ll i=0;i<n;i++){
        scanf(" %lld",&x);
        arr[i]=x;
        ll f=0;
        for(ll j=0;j<i;j++){
            if(arr[j]==x){f=1;break;}
        }
        if(!f) printf("%lld ",arr[i]);
      }
      printf("\n");
}