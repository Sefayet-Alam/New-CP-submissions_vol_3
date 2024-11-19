#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <algorithm>

using namespace std;
using ll = long long;
const ll MOD = 1e9 + 7;

int M, K;
map<vector<int>, int> normalize_map; // Maps normalized patterns to unique indices

// Matrix multiplication under modulo
vector<vector<ll>> multiply(const vector<vector<ll>>& A, const vector<vector<ll>>& B) {
    int n = A.size();
    vector<vector<ll>> C(n, vector<ll>(n, 0));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            for (int k = 0; k < n; ++k)
                C[i][j] = (C[i][j] + A[i][k] * B[k][j]) % MOD;
    return C;
}

// Matrix exponentiation
vector<vector<ll>> matrixExpo(vector<vector<ll>> base, ll exp) {
    int n = base.size();
    vector<vector<ll>> result(n, vector<ll>(n, 0));
    for (int i = 0; i < n; ++i) result[i][i] = 1;
    while (exp > 0) {
        if (exp % 2 == 1)
            result = multiply(result, base);
        base = multiply(base, base);
        exp /= 2;
    }
    return result;
}

// Normalize a row pattern
vector<int> normalizePattern(const vector<int>& row) {
    unordered_map<int, int> mapping;
    vector<int> normalized;
    int nextId = 1;
    for (int color : row) {
        if (mapping.find(color) == mapping.end())
            mapping[color] = nextId++;
        normalized.push_back(mapping[color]);
    }
    return normalized;
}

// Generate all valid row patterns of length M with K colors
void generatePatterns(int m, vector<int>& current, vector<vector<int>>& validPatterns) {
    if (m == 0) {
        vector<int> normalized = normalizePattern(current);
        if (normalize_map.find(normalized) == normalize_map.end())
            normalize_map[normalized] = normalize_map.size();
        validPatterns.push_back(normalized);
        return;
    }
    for (int color = 1; color <= K; ++color) {
        if (current.empty() || current.back() != color) {
            current.push_back(color);
            generatePatterns(m - 1, current, validPatterns);
            current.pop_back();
        }
    }
}

// Check if two normalized patterns are compatible row-to-row
bool canTransition(const vector<int>& row1, const vector<int>& row2) {
    for (int i = 0; i < M; ++i)
        if (row1[i] == row2[i])
            return false;
    return true;
}

// Count valid colorings for the N * M matrix
ll countColorings(int N) {
    vector<vector<int>> validPatterns;
    vector<int> current;
    generatePatterns(M, current, validPatterns);

    int numPatterns = normalize_map.size();
    vector<vector<ll>> transition(numPatterns, vector<ll>(numPatterns, 0));

    // Populate transition matrix based on compatibility of normalized patterns
    for (int i = 0; i < validPatterns.size(); ++i) {
        for (int j = 0; j < validPatterns.size(); ++j) {
            if (canTransition(validPatterns[i], validPatterns[j])) {
                transition[normalize_map[validPatterns[i]]][normalize_map[validPatterns[j]]] += 1;
            }
        }
    }

    // Matrix exponentiation of the transition matrix
    vector<vector<ll>> T = matrixExpo(transition, N - 1);

    // Summing up all paths starting from any valid pattern
    ll result = 0;
    for (int i = 0; i < numPatterns; ++i)
        for (int j = 0; j < numPatterns; ++j)
            result = (result + T[i][j]) % MOD;

    return result;
}

int main() {
    int N;
    // cout << "Enter N (rows), M (cols), and K (colors): ";
    cin >> N >> M >> K;

    cout << "Number of ways to color the matrix: " << countColorings(N) << endl;
    return 0;
}
