#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define ll long long
#define MOD 1000000007
using namespace std;
int main()
{
    ll t;
    cin >> t;
    while (t--)
    {
        string a;
        ll x, y, run = 0, wi = 0;
        cin >> a;
        for (ll i = 0; i < a.size(); i++)
        {
            if (a[i] == 'W')
                wi++;
            else
                run += a[i] - '0';
        }
        x = a.size() / 6;
        y = a.size() % 6;
        cout << x << "." << y << " ";
        if (x > 1 || (x==1 && y>0)){
            
            cout << "Overs ";
        }
        else
            cout << "Over ";
        cout << run << " ";
        if (run > 1)
            cout << "Runs ";
        else
            cout << "Run ";
        cout << wi << " ";
        if (wi > 1)
            cout << "Wickets";
        else
            cout << "Wicket";
        cout<<"." << endl;
    }
    return 0;
}