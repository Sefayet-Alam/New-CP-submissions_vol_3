#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve()
{
    ll n;
    cin >> n;
    ll mini=INT_MAX, maxi=INT_MIN, mn, mx, tmp;
    for(int i=0; i<n; i++)
    {
        cin >> tmp;
        if (tmp<=mini)
        {
            mini=tmp;
            mn=i;
        }
        if (tmp>=maxi)
        {
            maxi=tmp;
            mx=i;
        }
    }
    if (mx<mn)
    {
        cout << -1 << endl;
    }
    else
    {
        n-=2;
        cout << n << endl;
        for(int i=0; i<n; i++)
        {
            cout << 1 << " " << 3 << endl;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);    
    int tc=1;
    cin>>tc;
    while(tc--)
    {
        solve();
    }
    return 0;
}