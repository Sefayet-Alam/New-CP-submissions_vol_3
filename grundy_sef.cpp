ll dp[N];
// A Function to calculate Mex of all the values in that set
ll calculateMex(unordered_set<ll> Set){
    ll Mex = 0;
    while (Set.find(Mex) != Set.end()) Mex++;
    return Mex;
}

// A function to Compute Grundy Number of 'n'
ll calculateGrundy(ll n){
    if(n<=3) return dp[n]=n;
    ll &ret=dp[n];
    if(ret!=-1) return ret;
    unordered_set<ll> Set; // A Hash Table

    for (ll i=1; i<=3; i++) Set.insert (calculateGrundy (n-i));
    // Store the result
    return ret = calculateMex (Set);
}
// A function to declare the winner of the game
bool declareWinner(vl &piles, ll n){
    ll xorValue = dp[piles[0]];
    for(int i=1; i<=n-1; i++) xorValue = xorValue ^ dp[piles[i]];
    return (xorValue!=0);
}
