#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

#define ll long long
ll getbill(ll collectedWaste,ll RequiredWaste,ll Paymentperton, ll finePerTon){
    ll basicPay=collectedWaste*Paymentperton;
    ll Deficit=max(0LL,RequiredWaste-collectedWaste);
    ll fine=Deficit*finePerTon;
    ll totalBill=basicPay-fine;
    return totalBill;

}
int main()
{
   

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
