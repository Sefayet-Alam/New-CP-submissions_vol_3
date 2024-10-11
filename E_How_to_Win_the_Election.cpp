#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
    int n, m;
    ll k;
    cin >> n >> m >> k;
    vector<ll> a(n);
    for (auto& e : a) cin >> e;
    const ll rem = k - accumulate(a.begin(), a.end(), 0LL);

    if (n == m) {
        for (int i = 0; i < n; ++i) cout << 0 << " \n"[i == n - 1];
        return 0;
    }

    vector<int> ord(n);
    iota(ord.begin(), ord.end(), 0);
    sort(ord.begin(), ord.end(), [&](int i, int j) { return a[i] < a[j]; });
    auto b = a;
    sort(b.begin(), b.end());
    vector<ll> sumb(n + 1);  // Cumulative sum of A sorted in ascending order
    for (int i = 0; i < n; ++i) sumb[i + 1] = sumb[i] + b[i];

    vector<ll> ans(n, -1);
    for (int i = 0; i < n; ++i) {
        ll l = -1, r = rem + 1;
        while (r - l > 1) {
            ll mid = (l + r) / 2;
            ll rid = lower_bound(b.begin(), b.end(), b[i] + mid + 1) - b.begin();  // Finds the maximum rid with b[rid]<b[i]+mid+1
            ll lid = n - m - (i >= n - m ? 1 : 0);  // If i < n-m, the top m candidates are n-m,...,n; if i >= n-m, the top m candidates are n-m-1,...,i-1,i+1,..,n.
            ll cnt = 0;
            if (rid > lid) cnt += (rid - lid) * (b[i] + mid + 1) - (sumb[rid] - sumb[lid]);
            if (lid <= i && i < rid)
                cnt--;  // In this case, candidate i already have b[i]+mid+1 votes, so decrement the count
            else
                cnt += mid;  // Add the number of votes that candidate i needs
            if (cnt > rem)
                r = mid;
            else
                l = mid;
        }
        if (l == rem)
            ans[ord[i]] = -1;
        else
            ans[ord[i]] = r;
    }

    for (int i = 0; i < n; ++i) cout << ans[i] << " \n"[i == n - 1];
}
