#include <bits/stdc++.h>
using namespace std;
const int MOD = 998244353;

// Function to calculate (base^exp) % MOD using binary exponentiation
long long modPow(long long base, long long exp, long long mod) {
    long long result = 1;
    while (exp > 0) {
        if (exp % 2 == 1) result = (result * base) % mod;
        base = (base * base) % mod;
        exp /= 2;
    }
    return result;
}

// Function to calculate the number of ways to create strings with w as LCS
long long countPairs(int n, int m, int k, const string& w) {
    // Calculate total positions where w can appear in s and t
    long long waysS = max(0, n - k + 1);
    long long waysT = max(0, m - k + 1);

    // Total ways to create valid s and t where w is embedded
    long long validS = (waysS * modPow(2, n - k, MOD)) % MOD;
    long long validT = (waysT * modPow(2, m - k, MOD)) % MOD;

    // Multiply valid configurations for s and t
    return (validS * validT) % MOD;
}

int main() {
    int n, m, k;
    string w;

    // Input: lengths of strings s, t, and w
    cin >> n >> m >> k >> w;

    // Compute the result and print
    long long result = countPairs(n, m, k, w);
    cout << result << endl;

    return 0;
}
