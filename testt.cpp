#include <bits/stdc++.h>
#include <fstream>
using namespace std;

void decode_secret(string s)
{
    // must include header file '#include <fstream>'
    ifstream myfile;
    myfile.open(s);
    int n;
    string p;
    vector<pair<int, string>> vec;
    std::string myline;
    if (myfile.is_open())
    {
        while (myfile)
        { // equivalent to myfile.good()
            std::getline(myfile, myline);
            std::cout << myline << '\n';
        }
    }
    // while (cin >> n >> p)
    // {
    //     vec.push_back({n, p});
    // }
    // sort(vec.begin(), vec.end());
    // for (auto it : vec)
    // {
    //     cout << it.first << " " << it.second << endl;
    // }
    // int i = 0;
    // int diff = 1;
    // int sz = vec.size();
    // string ans = "";
    // while (i < sz)
    // {
    //     ans += vec[i].second;
    //     ans += " ";
    //     diff++;
    //     i += diff;
    // }
    // if (ans.size())
    //     ans.pop_back(); // removing the last empty (" ") part
    // cout << ans << endl;
}

int main()
{
    decode_secret("E:\GitHub\New-CP-submissions_vol_3\input_dataset.txt");
    return 0;
}

/* Points tO CONSIDER
    # RTE? -> check array bounds and constraints
    #TLE? -> thinks about binary search/ dp / optimization techniques
    # WA?
    -> overflow,reset global variables
    -> Check corner cases
    -> think from different approaches
    -> bruteforce to find pattern
    -> use Setpre for precision problems
*/
