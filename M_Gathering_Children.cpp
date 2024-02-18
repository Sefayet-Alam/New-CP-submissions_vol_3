///********************** بِسْمِ ٱللَّهِ ٱلرَّحْمَـٰنِ ٱلرَّحِيمِ **********************///

/**
 *     author: Shefat Hossen Shoikat
 *     date  : 2024-02-13 15:39:53
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
#define btod(bin) stoi(bin, nullptr, 2)
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
    string s;
    cin >> s;
    ll n = s.size();
    ll a[n + 5] = {};
    ll cnt = 0;
    for (ll i = 0; i < s.size(); i++)
    {
        if (s[i] == 'R')
            cnt++;
        else
        {
            a[i] = cnt;
            cnt = 0;
        }
    }
    for (ll i = s.size() - 1; i >= 0; i--)
    {
        if (s[i] == 'L')
            cnt++;
        else
        {
            a[i] = cnt;
            cnt = 0;
        }
    }
    for (ll i = 1; i < s.size(); i++)
    {
        if (s[i - 1] == 'R' && s[i] == 'L')
        {
            if ((a[i] + a[i - 1]) % 2 == 0)
            {
                ll tmp = (a[i] + a[i - 1]) / 2;
                a[i - 1] = tmp;
                a[i] = tmp;
            }
            else
            {
                ll tmp = abs(a[i] - a[i - 1]);
                ll tm = a[i - 1] + a[i];
                if (a[i - 1] > a[i] && a[i - 1] % 2 == 0)
                {
                    a[i - 1] = tm / 2 + 1;
                    a[i] = tm / 2;
                }
                else if (a[i - 1] > a[i] && a[i - 1] % 2 != 0)
                {
                    a[i - 1] = tm / 2;
                    a[i] = tm / 2 + 1;
                }
                else if (a[i - 1] < a[i] && a[i] % 2 == 0)
                {
                    a[i - 1] = tm / 2;
                    a[i] = tm / 2 + 1;
                }
                else if (a[i - 1] < a[i] && a[i] % 2 != 0)
                {
                    a[i - 1] = (tm / 2) + 1;
                    a[i] = tm / 2;
                }
            }
        }
    }
    for (ll i = 0; i < s.size(); i++)
        cout << a[i] << " ";
    cout << nl;
    return SH;
}