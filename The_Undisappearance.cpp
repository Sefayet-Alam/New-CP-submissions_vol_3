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

#define ll long long
#define int ll

int remov(vector<int> &v, int num)
{
    int n = v.size();
    int bad = num - 1;
    if (bad == 0)
        bad = 3;
    int l = -1, r = -1;
    for (int i = 0; i < n; i++)
    {
        if (v[i] == num)
        {
            l = i;
            break;
        }
    }
    for (int i = n - 1; i >= 0; i--)
    {
        if (v[i] == num)
        {
            r = i;
            break;
        }
    }
    for(int i=l;i<=r;i++){
        if(v[i]==bad){
            return 0*1ll;
        }
    }
    int newl = l, newr = r;
    while (newl > 0 && v[newl - 1] != bad)
    {
        newl--;
    }
    while (newr < n - 1 && v[newr + 1] != bad)
    {
        newr++;
    }
    int ans = (l - newl + 1) * (newr - r + 1);
    return ans;
}

void solution()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    int total = n * (n + 1) / 2;
    int ans = total - remov(v, 1) - remov(v, 2) - remov(v, 3);
    cout << ans << '\n';
}

main()
{
    fast;
    ll t;
    // setIO();
    // ll tno=1;;
    t = 1;
    cin >> t;

    while (t--)
    {
      solution();
    }

    return 0;
}

/* Points tO CONSIDER
    # RTE? -> check array bounds and constraints
    #TLE? -> thinks about binary search/ dp / optimization techniques
    # WA? 
    -> overflow,reset global variables
    -> Check corner cases
    -> think from different approaches
    -> bruteforce to find pattern
    -> use Setpre for precision problems
*/
