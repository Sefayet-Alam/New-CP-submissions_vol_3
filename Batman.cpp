#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define ld long double
int n,m;
int dp[55][55][55];

int32_t main()
{
   
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t,tc=1; cin>>t;
    while(t--)
    {
        string a,b,c;
        cin>>a>>b>>c;
     n=a.size();
     m=b.size();
    int p=c.size();
    
    for(int i=0;i<=n;i++)
    {
        dp[i][0][0]=0;
    }
    for(int j=0;j<=m;j++)
    {
        dp[0][j][0]=0;
    }
    for(int k=0;k<=p;k++)
    {
        dp[0][0][k]=0;
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            for(int k=1;k<=p;k++)
            {
                if(a[i-1]==b[j-1] && b[j-1]==c[k-1])
                {
                    dp[i][j][k]=1+dp[i-1][j-1][k-1];
                }
                else
                {
                    dp[i][j][k]=max({dp[i-1][j][k],dp[i][j-1][k],dp[i][j][k-1]});
                }
            }
        }
    }
   
    
    cout<<"Case "<<tc++<<": "<<dp[n][m][p]<<endl;

    }
    
    
return 0;
}