#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;



vector<int> vis(105, 0); // we'int gather which area belongs to which contractor

int cnt, n, m; // must be global variables

// this has capacity of the contractors i.e total van capacity

double getdist(double x1, double y1, double x2, double y2)
{
    double ret = (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
    ret = sqrt(ret);
    return ret;
}

void dfs(int i, int curr, int &total, vector<pair<pair<double, double>, int>> &point)
{
    if (curr >= total)
        return;
    double minm = 100009.999;
    vis[i] = cnt;
    int next = -1;
    double ret = 0;
    for (int j = 0; j < n; j++)
    {
        if (i == j || vis[j])
            continue;
        double now = getdist(point[i].first.first, point[i].first.second, point[j].first.first, point[j].first.second);
        if (now < minm)
        {
            minm = now;
            next = j;
        }
    }

    if (next != -1)
        dfs(next, curr + point[i].second, total, point);
    return;
}

map<pair<double, double>, int> calc(vector<pair<pair<double, double>, int>> &oldpoint, vector<int> &contractors)
{
    n = oldpoint.size();
    m = contractors.size();
    // lets say that the contractors are sorted by capacity
    cnt = 1;
    for (auto it : contractors)
    {
        for (int i = 0; i < n; i++)
        {
            if (vis[i])
                continue;
            dfs(i, 0, it, oldpoint);
            break;
        }
        cnt++;
    }
    map<pair<double, double>, int> ret;
    for (int i = 0; i < n; i++)
    {
        pair<double, double> noww = oldpoint[i].first;
        ret[noww] = vis[i];
    }
    return ret;
}

int main()
{
    vector<pair<pair<double, double>, int>> oldpoints;
    oldpoints.push_back({{1.02, 1.33}, 100});
    oldpoints.push_back({{2.02, 3.33}, 100});
    oldpoints.push_back({{-3.55, -4.33}, 100});
    oldpoints.push_back({{3.55, 4.33}, 100});
    oldpoints.push_back({{4.55, -6.33}, 100});
    oldpoints.push_back({{13.55, -14.33}, 100});
    oldpoints.push_back({{53.55, 64.33}, 100});
    oldpoints.push_back({{-3.55, 43.3}, 100});
    oldpoints.push_back({{35.5, 42.33}, 100});
    oldpoints.push_back({{-3.55, 4.33}, 100});
    oldpoints.push_back({{32.55, 42.33}, 100});
    oldpoints.push_back({{-34.55, 44.33}, 100});
    vector<int> contractor;
    contractor.push_back(300);
    contractor.push_back(400);
    contractor.push_back(500);
    contractor.push_back(600);
    contractor.push_back(700);
    calc(oldpoints, contractor);
    

    return 0;
}
