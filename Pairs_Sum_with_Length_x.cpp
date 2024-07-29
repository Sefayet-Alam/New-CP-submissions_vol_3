#include <bits/stdc++.h>
using namespace std;
#define int long long
class SGTree{
    vector<int> seg;
    public:
    // segment tree constructor for defining the size
    SGTree(int n){
        seg.assign(4 * n + 1, 0);
    }
    // operation function
    int comp(int a, int b){
        return a + b;
    }
    // for building the segment tree
    void build(int ind, int left, int right, vector<int>& arr){
        // when on the leaf node, add the value to the segment
        if(left == right){
            seg[ind] = arr[left];
            return;
        }
        // now go on the build the left and right subtree
        int mid = left + (right - left) / 2;
        // left subtree
        build(2 * ind + 1, left, mid, arr);
        // right subtree
        build(2 * ind + 2, mid + 1, right, arr);
        // operation which you need to perform on the subtree
        seg[ind] = comp(seg[2 * ind + 1], seg[2 * ind + 2]);
    }
    // for the query of the data
    int query(int ind, int left, int right, int l, int r){
        // when the segment is not in the range (disjoint)
        if(r < left || l > right) return 0;
        // when fully in the range 
        if(l <= left && right <= r){
            return seg[ind];
        }
        // partial overlapping
        int mid = left + (right - left) / 2;
        int leftC = query(2 * ind + 1, left, mid, l, r);
        int rightC = query(2 * ind + 2, mid + 1, right, l, r);
        // operation which you need to perform on the subtree
        return comp(leftC , rightC);
    }
    // point update for the tree
    void update(int ind, int left, int right, int pos, int val){
        // when on the leaf node, update the value
        if(left == right){
            seg[ind] += val;
            return;
        }
        // now check on the left and right
        int mid = left + (right - left) / 2;
        // when the position which need to be update is in left
        if(left <= pos && pos <= mid){
            update(2 * ind + 1, left, mid, pos, val);
        }else update(2 * ind + 2, mid + 1, right, pos, val);
        // operation which you need to perform on the tree
        seg[ind] = comp(seg[2 * ind + 1], seg[2 * ind + 2]);
    }
 
};

int minDigit(int x){
    int num = 1;
    x--;
    while(x){
        num = num * 10 + 0;
        x--;
    }
    return num;
}

int maxDigit(int x){
    if(x == 19) return 2e18 + 5;
    int num = 0;
    while(x){
        num = num * 10 + 9;
        x--;
    }
    return num;
}

void solve(){
    int n, x;
    cin >> n >> x;
    vector<int> arr(n);
    for(int i=0; i<n; i++) cin >> arr[i];
    int cnt = 0;
    map<int,int> mp;
    vector<int> tmp = arr;
    sort(tmp.begin(), tmp.end());
    for(auto &it: tmp){
        mp[it] = cnt++;
    }
    SGTree seg(cnt+10);
    vector<int> dp(n+1);
    for(int i=1; i<=n; i++){
        int mini = minDigit(x);
        int maxi = maxDigit(x);
        int left = mini - arr[i-1];
        int right = maxi - arr[i-1];
        int ldx = lower_bound(tmp.begin(), tmp.end(), left) - tmp.begin();
        int rdx = upper_bound(tmp.begin(), tmp.end(), right) - tmp.begin();
        rdx--;
        dp[i] = seg.query(0, 0, cnt-1, ldx, rdx);
        dp[i] += dp[i-1];
        seg.update(0, 0, cnt - 1, mp[arr[i-1]], i);
    }
    int ans = accumulate(dp.begin(), dp.end(), 0LL);
    cout << ans << endl;
}

int32_t main() {
	int t;
	cin >> t;
	while(t--){
	    solve();
	}
    return 0;
}