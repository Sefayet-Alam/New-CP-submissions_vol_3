#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

// VVI
#define fast                      \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);
#define pb push_back
#define ll long long

struct item
{
    ll value;  // current value
    ll lazy;   // value to be lazyed
    ll assign; // value to be assigned
};

struct segment_tree
{
    ll size;
    vector<item> tree;
    ll neutral = 0;
    ll no_op = LLONG_MIN;

    // General operations : O(1)

    ll merge(ll a, ll b)
    {
        if (a == no_op)
            return b;
        return (a + b);
    }
    ll addnodes(ll a, ll b)
    {
        return a + b;
    }

    // INITIALIZATION: O(log2 n)

    void init(ll n)
    {
        size = 1;
        while (size < n)
            size *= 2;
        tree.resize(2 * size);
        tree.assign(2 * size, {0, no_op, no_op});
    }

    /// BUILD
    void build(vector<ll> &a, ll x, ll lx, ll rx)
    {
        if (rx - lx == 1)
        {
            if (lx < a.size())
            {
                tree[x] = {a[lx], no_op, no_op};
            }
            return;
        }
        ll m = (lx + rx) / 2;
        build(a, 2 * x + 1, lx, m);
        build(a, 2 * x + 2, m, rx);
        tree[x] = {tree[x].value = addnodes(tree[2 * x + 1].value, tree[2 * x + 2].value), no_op, no_op};
    }

    void build(vector<ll> &a)
    {
        // linear time
        build(a, 0, 0, size);
    }

    /// LAZY PROPAGATION

    // throws lazy values to its children nodes
    // updates values to children nodes
    item propagate_op(item par, item child, ll len)
    {
        item ret = child;
        if (par.assign != no_op)
        {
            ret.assign = par.assign;
            ret.lazy = no_op;
            ret.value = len * (par.assign);
        }

        if (par.lazy != no_op)
        {
            ret.lazy = merge(ret.lazy, par.lazy);
            ret.value += len * par.lazy;
        }

        return ret;
    }

    void propagate(ll x, ll lx, ll rx)
    {
        if (rx - lx == 1 || (tree[x].assign == no_op && tree[x].lazy == no_op))
        {
            return;
        }
        ll m = (rx + lx) / 2;
        tree[2 * x + 1] = propagate_op(tree[x], tree[2 * x + 1], m - lx);
        tree[2 * x + 2] = propagate_op(tree[x], tree[2 * x + 2], rx - m);
        tree[x].lazy = tree[x].assign = no_op;
    }

    /// RANGE SUM
    ll sum(ll l, ll r, ll x, ll lx, ll rx)
    {
        propagate(x, lx, rx);
        if (lx >= r || l >= rx)
        {
            return 0;
        }
        if (lx >= l && rx <= r)
        {
            return tree[x].value;
        }
        ll m = (lx + rx) / 2;
        ll s1 = sum(l, r, 2 * x + 1, lx, m);
        ll s2 = sum(l, r, 2 * x + 2, m, rx);
        return addnodes(s1, s2);
    }

    ll sum(ll l, ll r)
    {
        // returns sum from l to r

        return sum(l, r, 0, 0, size);
    }

    // RANGE operation

    void RangeUpdate(ll l, ll r, ll v, ll x, ll lx, ll rx)
    {
        propagate(x, lx, rx);
        if (lx >= r || l >= rx)
        {
            return;
        }
        if (lx >= l && rx <= r)
        {
            tree[x].lazy = merge(tree[x].lazy, v);
            tree[x].value += (rx - lx) * v;
            return;
        }
        ll m = (lx + rx) / 2;
        RangeUpdate(l, r, v, 2 * x + 1, lx, m);
        RangeUpdate(l, r, v, 2 * x + 2, m, rx);
        tree[x].value = addnodes(tree[2 * x + 1].value, tree[2 * x + 2].value);
    }

    void RangeUpdate(ll l, ll r, ll v)
    {
        // add v from l to r
        RangeUpdate(l, r, v, 0, 0, size);
    }
    /// RANGE ASSIGN
    void RangeAssign(ll l, ll r, ll v, ll x, ll lx, ll rx)
    {
        propagate(x, lx, rx);
        if (lx >= r || l >= rx)
        {
            return;
        }
        if (lx >= l && rx <= r)
        {
            tree[x].assign = v;
            tree[x].lazy = no_op;
            tree[x].value = (rx - lx) * v;

            return;
        }
        ll m = (lx + rx) / 2;
        RangeAssign(l, r, v, 2 * x + 1, lx, m);
        RangeAssign(l, r, v, 2 * x + 2, m, rx);
        tree[x].value = addnodes(tree[2 * x + 1].value, tree[2 * x + 2].value);
    }

    void RangeAssign(ll l, ll r, ll v)
    {
        // multipliess v from l to r
        RangeAssign(l, r, v, 0, 0, size);
    }
};

int main()
{
    fast;
    ll t;
    // setIO();
    // ll tno=1;;
    t = 1;
    // cin >> t;

    while (t--)
    {
        ll n;
        cin>>n;
        vector<ll>vec(n);
        for(ll i=0;i<n;i++) cin>>vec[i];
        segment_tree sg;
        sg.init(n);
        sg.build(vec);
        ll l=0,r=5;
        sg.RangeUpdate(l,r,1);
        cout<<sg.sum(l,r)<<endl;
    }

    return 0;
}
