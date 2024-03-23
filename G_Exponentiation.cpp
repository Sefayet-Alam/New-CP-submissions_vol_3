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
#define ull unsigned long long
#define nn "\n"

struct custom_hash
{
    static uint64_t splitmix64(uint64_t x)
    {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }
    size_t operator()(uint64_t x) const
    {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

#define REP(i, n) for (int i = 0; i < (n); i++)
ull a1, b1, m1;
__uint128_t a, b, m;

struct Matrix
{

    __uint128_t arr[2][2] = {{0, 0}, {0, 0}};
    Matrix operator*(const Matrix &other)
    {
        Matrix product;
        REP(i, 2)
        REP(j, 2)
        REP(k, 2)
        {

            __uint128_t tmp = (arr[i][j] * other.arr[j][k]) % m;
            if (tmp < 0)
                tmp += m;
            product.arr[i][k] = (product.arr[i][k] + tmp) % m;
            if (product.arr[i][k] < 0)
                product.arr[i][k] += m;
        }
        return product;
    }
};

Matrix expo_power(Matrix a, ull k)
{
    Matrix product;
    REP(i, 2)
    product.arr[i][i] = 1;
    while (k > 0)
    {
        if (k % 2)
        {
            product = product * a;
        }
        a = a * a;
        k /= 2;
    }
    return product;
}

int main()
{
    fast;
    ll t;
    // setIO();
    // ll tno=1;;
    t = 1;
    // cin >> t;

    while (t--)
    {

        cin >> a1 >> b1 >> m1;
        a = a1;
        b = b1;
        m = m1;
        a %= m;
        Matrix mat;
        mat.arr[0][0] = a;
        mat.arr[0][1] = m - 1;
        mat.arr[1][0] = 1;

        Matrix res = expo_power(mat, b);

        __uint128_t ans = (res.arr[0][0] + res.arr[1][1]) % m;
        ull ans2 = ans;
        cout << ans2 << nn;
    }

    return 0;
}