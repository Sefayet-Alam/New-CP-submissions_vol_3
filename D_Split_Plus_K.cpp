#include <iostream>
#include <vector>
#include <algorithm>

long long min_operations_to_equalize(std::vector<long long>& arr, long long k) {
    long long min_val = *std::min_element(arr.begin(), arr.end());
    long long max_val = *std::max_element(arr.begin(), arr.end());

    if (max_val - min_val > k * 2) {
        return -1;  // It is not possible to make all numbers equal
    }

    return k + (max_val - min_val + k) / 2;
}

int main() {
    int t;
    std::cin >> t;

    while (t--) {
        int n;
        long long k;
        std::cin >> n >> k;

        std::vector<long long> arr(n);
        for (int i = 0; i < n; ++i) {
            std::cin >> arr[i];
        }

        long long result = min_operations_to_equalize(arr, k);

        if (result == -1) {
            std::cout << "NO" << std::endl;
        } else {
            std::cout << "YES " << result << std::endl;
        }
    }

    return 0;
}
