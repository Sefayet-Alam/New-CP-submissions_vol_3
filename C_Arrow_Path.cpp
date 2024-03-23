#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

// VVI
#define fast                      \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);
#define pb push_back
#define ll long long
#define nn "\n"

const ll N = 2e5 + 10;
char grid[2][N];
bool vis[2][N][2];
ll n;
bool isvalid(ll x, ll y, bool f)
{
    if (x >= 0 && x < 2 && y >= 0 && y < n)
    {
        if (!vis[x][y][f])
            return true;
    }
    return false;
}
bool func(ll i, ll j, bool f)
{
    // cout<<i<<" "<<j<<" "<<f<<nn;
    if(vis[i][j][f]) return 0;
    vis[i][j][f] = 1;
    if (i == 1 && j == n - 1)
    {
        if (f)
            return 1;
    }
    bool ret = 0;
    
    if (f == 0)
    {
        if (grid[i][j] == '<')
        {

            ret |= func(i, j - 1, 1);
        }
        else
        {

            ret |= func(i, j + 1, 1);
        }
    }
    else
    {
        if (isvalid(i - 1, j, f))
        {
            ret |= func(i - 1, j, 0);
        }
        if (isvalid(i + 1, j, f))
        {
            ret |= func(i + 1, j, 0);
        }
        if (isvalid(i, j - 1, f))
        {
            ret |= func(i, j - 1, 0);
        }
        if (isvalid(i, j + 1, f))
        {
            ret |= func(i, j + 1, 0);
        }
    }

    return ret;
}
int main()
{
    fast;
    ll t;
    // setIO();
    // ll tno=1;;
    t = 1;
    cin >> t;

    while (t--)
    {

        cin >> n;

        for (ll i = 0; i < 2; i++)
        {
            for (ll j = 0; j < n; j++)
            {
                cin >> grid[i][j];
            }
        }
        //   for(ll i=0;i<2;i++){
        //     for(ll j=0;j<n;j++){
        //         cout<<grid[i][j];
        //     }
        //     cout<<nn;
        //   }
        memset(vis, 0, sizeof(vis));
        
        bool ans=func(0,0,1);
        if(ans) cout<<"YES"<<nn;
        else cout<<"NO"<<nn;
    }

    return 0;
}
