#include <bits/stdc++.h>

using namespace std;

// VVI
#define fast                      \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);

#define ll int

ll ask(string s)
{
    cout << "1 " << s << endl;
    ll x;
    cin >> x;
    return x;
}

int main()
{
    fast;
    ll t;
    // setIO();
    // ll tno=1;;
    t = 1;
    cin >> t;

    while (t--)
    {
        int n;
        scanf("%d", &n);
        const int A = ask("0");
        const int B = ask("00");
        const int C = ask("01");
        printf("0 %d %d\n", n, (A == B + C) ? 1 : 0);
        fflush(stdout);
        scanf("%*d");
    }

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
