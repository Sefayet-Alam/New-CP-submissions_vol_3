#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ld long double
int32_t main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int nc;
    cin >> nc;
    vector<pair<int, int>> g[nc], cm[nc];
    int a[nc];
    for (int i = 0; i < nc; i++)
    {
        int p;
        cin >> p;
        int sum = 0;
        for (int mon = 1; mon <= p; mon++)
        {
            int day;
            cin >> day;
            for (int d = 1; d <= day; d++)
            {
                g[i].push_back({d, mon});
            }
        }
    }

    int q;
    cin >> q;
    for (int qc = 1; qc <= q; qc++)
    {
        int c1, c2;
        cin >> c1 >> c2;
        c1--, c2--;
        int d, m, yr;
        cin >> d >> m >> yr;

        int dayinyr = g[c1].size();
        int totday = (yr - 1) * dayinyr;
        for (int i = 0; i < g[c1].size(); i++)
        {
            if (g[c1][i].first == d && g[c1][i].second == m)
            {
                totday += (i + 1);
                break;
            }
        }

        int fullyrday = g[c2].size();
        int ansyr = totday / fullyrday;
        int bakiday = totday % fullyrday;
        int ansday = 0, ansmon = 0;
        if (bakiday == 0)
        {
            int last = g[c2].size();
            last--;
            ansday = g[c2][last].first;
            ansmon = g[c2][last].second;
        }
        else
        {
            ansyr++;
            bakiday--;
            ansday = g[c2][bakiday].first;
            ansmon = g[c2][bakiday].second;
            // cout<<ansyr<<endl;
        }

        cout << "Query " << qc << ": " << ansday << " " << ansmon << " " << ansyr << endl;
    }

    return 0;
}