///********************** بِسْمِ ٱللَّهِ ٱلرَّحْمَـٰنِ ٱلرَّحِيمِ **********************///

/**
 *     author: Shefat Hossen Shoikat
 *     date  : 2024-02-29 16:30:01
 **/

#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define mod 1000000007
#define inf (1LL << 62)
#define all(x) x.begin(), x.end()
#define eb emplace_back
#define ff first
#define ss second
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
#define dtob(bits, n) bitset<bits>(n).to_string()
#define btod(bin) stoll(bin, nullptr, 2)
#define ok cout << "Eureka" << nl
#define nl '\n'
#define SH 0
typedef long long ll;
typedef pair<ll, ll> pll;
typedef vector<ll> vl;
typedef vector<pll> vpll;

int main()
{
    fastio;
    ll t;
    ll a, b, c, d, e, f, g, h, r1, r2;
    cin >> a >> b >> c >> d >> g >> h >> r2 >> e >> f >> r1;
    double AO, BO, AC, BD, AB;
    AB = sqrt((a - c) * (a - c) + (b - d) * (b - d));
    AO = sqrt((a - e) * (a - e) + (b - f) * (b - f));
    BO = sqrt((c - e) * (c - e) + (d - f) * (d - f));
    AC = sqrt(AO * AO - r1 * r1);
    BD = sqrt(BO * BO - r1 * r1);
    double theta1, theta2, alpha, theta;
    theta = acos(((AO * AO) + (BO * BO) - (AB * AB)) / (2 * AO * BO));
    theta1 = acos(r1 / AO);
    theta2 = acos(r1 / BO);
    alpha = theta - theta1 - theta2;
    double cir = r1 * alpha;
    double total = AC + BD + cir;
    cout << fixed << setprecision(10) << total << nl;
    return SH;
}