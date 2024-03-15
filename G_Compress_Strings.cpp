#include <bits/stdc++.h>
using namespace std;
 
int tsp(int city, int mask, vector<vector<int>> &distance, vector<vector<int>> &dp, vector<vector<int>> &path, int n) {
    if (mask == (1 << n) - 1) return 0;
 
    if (dp[mask][city] != -1) {
        return dp[mask][city];
    }
 
    int ans = INT_MAX;
    int nextCity = -1;
 
    for (int i = 0; i < n; i++) {
        if ((mask & (1 << i)) == 0) {
            int dis = distance[city][i] + tsp(i, (mask | (1 << i)), distance, dp, path, n);
            if (dis < ans) {
                ans = dis;
                nextCity = i;
            }
        }
    }
 
    path[mask][city] = nextCity;
    dp[mask][city] = ans;
    return ans;
}
 
string createPath(vector<string> &words, int start, vector<vector<int>> &distance, vector<vector<int>> &path) {
    int c = start;
    string result = words[start];
    int mask = (1 << start);
    int x = path[mask][start];
 
    while (x != -1) {
        result += words[x].substr(distance[x]);
        mask |= (1 << x);
        c = x;
        x = path[mask][x];
    }
 
    return result;
}
 
string shortestSuperstring(vector<string> words) {
    int n = words.size();
    vector<vector<int>> distance(n, vector<int>(n, 0));
 
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int minLen = min(words[i].length(), words[j].length());
            for (int k = minLen; k >= 0; k--) {
                if (words[i].substr(words[i].length() - k) == words[j].substr(0, k)) {
                    distance[i][j] = words[j].length() - k;
                    break;
                }
            }
        }
    }
 
    vector<vector<int>> dp(1 << n, vector<int>(n, -1));
    vector<vector<int>> path(1 << n, vector<int>(n, -1));
    string ans = "";
    int len = INT_MAX;
 
    for (int i = 0; i < n; i++) {
        int tspResult = tsp(i, 0, distance, dp, path, n);
        string str = createPath(words, i, distance, path);
        if (str.length() < len) {
            ans = str;
            len = str.length();
        }
    }
 
    return ans;
}
 
int main() {
    vector<string> vec;
    int n;
    cin>>n;
    vector<string>vec;
    for(int i=0;i<n;i++){
        string s;
        cin>>s;
        vec.push_back(s);
    }
    string ans=shortestSuperstring(vec);
    deb(ans);
    cout<<ans.size()<<nn;
 
    return 0;
}