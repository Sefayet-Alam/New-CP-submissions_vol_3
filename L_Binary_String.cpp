///********************** بِسْمِ ٱللَّهِ ٱلرَّحْمَـٰنِ ٱلرَّحِيمِ **********************///

/**
 *     author: Shefat Hossen Shoikat
 *     date  : 2024-02-27 11:37:28
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
#define dtob(p, n) bitset<p>(n).to_string()
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
    ll n;
    cin >> n;
    string bin;
    cin >> bin;
    ll num = btod(bin);
    ll cnt = 0;
    while (num > n)
    {
        bool f1 = true, f2 = true, f3 = true;
        bin = dtob(62, num);
        ll res = num;
        ll tmp = 0;
        while (bin[tmp] == '0')
            tmp++;
        for (ll i = tmp; i < bin.size(); i++)
        {
            string s;
            for (ll j = tmp; j < bin.size(); j++)
            {
                if (i != j)
                    s.push_back(bin[j]);
            }
            // cout << s << nl;
            if (s[0] != '0')
            {
                ll p = btod(s);
                res = min(p, res);
            }
        }
        if (num == res)
            break;
        cnt++;
        num = res;
    }
    cout << cnt << nl;

    return SH;
}