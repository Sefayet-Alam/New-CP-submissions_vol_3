#include <bits/stdc++.h>
using namespace std;
#define debug(a) cerr << #a << " = " << (a) << nl;
#define ll long long
#define int long long
#define nl '\n'

vector<int> mp[3];

bool ok(int n, int lo, int hi){
    auto fi = lower_bound(mp[1].begin(), mp[1].end(), lo) - mp[1].begin();
    if(fi+n-1<mp[1].size() and mp[1][fi+n-1] <= hi) fi = mp[1][fi+n-1];
    else return false;
    auto sl = lower_bound(mp[0].begin(), mp[0].end(), fi) - mp[0].begin();
    if(sl<mp[0].size() and mp[0][sl] <= hi) sl = mp[0][sl];
    else return false;
    auto ed = lower_bound(mp[2].begin(), mp[2].end(), sl) - mp[2].begin();
    return (ed+n-1<mp[2].size() and mp[2][ed+n-1] <= hi);
}

void jAVA()
{
    int n, q; string s; cin >> n >> q >> s;
    for (int i = 0; i < n; i++){
        if(s[i] == '/') mp[0].push_back(i);
        else mp[s[i]-'0'].push_back(i);
    }
    while(q--){
        int l,r; cin >> l >> r;
        int lo = 1;
        int hi = (r-l+1)/2;
        // debug(hi);
        int ans = 0;
        auto it = lower_bound(mp[0].begin(), mp[0].end(), l-1);
        if(it == mp[0].end() or *it >= r) {
            cout << 0 << nl;
            continue;
        }
        ans++;
        while(lo<=hi){
            int mid = (lo+hi)/2;
            if(ok(mid, l-1, r-1)) ans = mid*2+1, lo = mid + 1;
            else hi = mid - 1;
        }
        cout << ans << nl;
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int t = 1, cs = 0;
    // cin >> t;
    while (t--){
        // cout << "Case " << ++cs << ": ";
        jAVA();
    }
    return 0;
}