/*
    Author: Matkap (prefix_sum)
*/

#include <bits/stdc++.h>
#include <array>

using namespace std;

#define int long long
#define ar array
#define all(x) x.begin(),x.end()

const int INF = 1e17 , MOD = 1e9 + 7;

int mul(int a,int b,int mod = MOD)
{
    return a * 1LL * b % mod;
}
int sum(int a,int b,int mod = MOD)
{
    return (a + b + mod) % mod;
}
int binpow(int base,int power,int mod = MOD)
{
    if(power == 1) return base;
    if(power == 0) return 1LL;
    
    if(power % 2 == 1)
    {
        int a;    
        a = binpow(base,power / 2,mod);
        return mul(base, mul(a, a, mod), mod);
    } 
    else
    {
        int a;
        a = binpow(base,power / 2,mod);
        return mul(a, a, mod);
    }
}
int inv(int a,int mod = MOD)
{
    return binpow(a, mod - 2, mod) % mod;
}
const int mxN = 2e5 + 7;
int tree[4 * mxN + 7];
int n;
void upd(int tx,int val,int l = 0,int r = n - 1,int pos = 1)
{
    if(l > r) return;
    if(l == r)
    {
        tree[pos] = val;
        return;
    }
    int mid = (l + r) / 2;
    if(tx > mid)
    {
        upd(tx, val, mid + 1, r, pos * 2 + 1);
    }
    else
    {
        upd(tx, val, l, mid, pos * 2);
    }
    tree[pos] = max(tree[pos * 2], tree[pos * 2 + 1]);
}
int q(int tl,int tr,int l = 0,int r = n - 1,int pos = 1)
{
    if(tl > tr || tl > r || l > tr || l > r) return 0LL;
    if(tr >= r && l >= tl)
    {
        return tree[pos];
    }
    int mid = (l + r) / 2;
    return max(q(tl, tr, l, mid, pos * 2), q(tl, tr, mid + 1, r, pos * 2 + 1));
}
void solve()
{
    cin >> n;
    int a[n];
    int dp[n];
    fill(dp, dp + n, -INF);
    fill(tree,tree + 4 * mxN + 7, -INF);
    for(int i = 0;n > i;i++)
    {
        cin >> a[i];
    }   
    int l[n], r[n];
    l[0] = -1;
    r[n - 1] = n;
    for(int i = 1;n > i;i++)
    {
        int tl = i - 1;
        while(tl != -1 && a[tl] < a[i]) tl = l[tl];
        l[i] = tl;
    }
    for(int i = n - 2;i >= 0;i--)
    {
        int tl = i + 1;
        while(tl != n && a[tl] < a[i]) tl = r[tl];
        r[i] = tl;
    }
    int ind[n];
    iota(ind, ind + n, 0LL);
    sort(ind,ind + n, [&](int x,int y)
    {
        return a[x] < a[y];
    });
    for(auto i : ind)
    {
        dp[i] = max(1LL, q(l[i] + 1, r[i] - 1) + 1);
        upd(i, dp[i]);
    }
    cout << *max_element(dp,dp + n) << endl;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int tt;
    tt=1; 
   // cin >> tt;
    while(tt--) solve();
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
}