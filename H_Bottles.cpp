#include <bits/stdc++.h>
#define fastread() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define nl "\n"
//#define int long long
#define all(x) x.begin(), x.end()
using namespace std;
const int M=1e9+7;
int x=0;
int sum=0;
int dp[101][101][10002];
int a[101];
int c[101];
int n;

int rec(int i,int k,int j)
{
	if(i==n)
	{
		if(j<=0 && k==x)return 0;
		else return M;
	}
	if(dp[i][k][j]!=-1)return dp[i][k][j];
	int ans=rec(i+1,k+1,j-c[i]);
	ans=min(ans,a[i]+rec(i+1,k,j));
	return dp[i][k][j]=ans;
}


int main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    
    	
    	cin>>n;
    	
    	vector<int> b(n);
    	
    	for(int i=0;i<n;i++)cin>>a[i];
    	for(int i=0;i<n;i++)
    	{
    		cin>>b[i];
    		c[i]=b[i];
    	}
    	
    	
    	for(int i=0;i<n;i++)sum+=a[i];
    	sort(all(b));
    	reverse(all(b));
    	int ps[n];
    	ps[0]=b[0];
    	for(int i=1;i<n;i++)ps[i]=ps[i-1]+b[i];
    	
    	for(int i=0;i<n;i++)
    	{
    		if(sum<=ps[i])
    		{
    			x=i+1;
    			
    			break;
    		}
    	}
    	memset(dp,-1,sizeof(dp));
    	int res=rec(0,0,sum);
    	cout<<x<<" "<<res<<nl;

}