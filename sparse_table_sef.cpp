ll table[N][19], ar[N];//note: ar is 1 based
void build(ll n) {
    for(ll i = 1; i <= n; ++i) table[i][0] = ar[i];
    for(ll k = 1; k < 19; ++k) {
        for(ll i = 1; i + (1 << k) - 1 <= n; ++i) {
            table[i][k] = GCD(table[i][k - 1], table[i + (1 << (k - 1))][k - 1]);
        }
    }
}
ll query(ll l, ll r) {
    ll k = 31 - __builtin_clz(r - l + 1);
    return GCD(table[l][k], table[r - (1 << k) + 1][k]);
}
