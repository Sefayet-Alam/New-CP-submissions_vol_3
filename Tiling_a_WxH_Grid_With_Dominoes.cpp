#include <bits/stdc++.h>
using namespace std;
#define fast                      \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);
#define ll long long

int main() {
    ll t;
    cin>>t;
    while(t--){
	ll n, m;
	cin >> n >> m;
    ll dp[(1LL << (m+1))+2][2];
    memset(dp,0,sizeof(dp));
    dp[0][0] = 1;
	for (int j = 0; j < m; j++)
		for (int i = 0; i < n; i++) {
			for (int mask = 0; mask < (1 << n); mask++) {
				dp[mask][1] = dp[mask ^ (1 << i)][0];  // Horizontal or no tile
				if (i && !(mask & (1 << i)) &&
				    !(mask & (1 << i - 1)))  // Vertical tile
					dp[mask][1] += dp[mask ^ (1 << i - 1)][0];
			}
			for (int mask = 0; mask < (1 << n); mask++)
				dp[mask][0] = dp[mask][1];
		}
	cout << dp[0][0] << '\n';
    }
}