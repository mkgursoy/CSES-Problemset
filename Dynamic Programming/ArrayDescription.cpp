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
const int mxM = 107;
vector<int> dp(mxM);
void solve()
{
    int n, m;
    cin >> n >> m;
    int a[n];
    for(int i = 0;n > i;i++) cin >> a[i];
    if(a[0])
    {
        dp[a[0]] = 1;
    }
    else
    {
        for(int i = 1;m >= i;i++) dp[i] = 1;
    }
    for(int i = 1;n > i;i++)
    {
        vector<int> ndp(mxM);
        if(a[i])
        {
            ndp[a[i]] = sum(ndp[a[i]], dp[a[i] + 1]);
            ndp[a[i]] = sum(ndp[a[i]], dp[a[i] - 1]);
            ndp[a[i]] = sum(ndp[a[i]], dp[a[i]]);
        }
        else
        {
            for(int j = 1;m >= j;j++)
            {
                ndp[j] = sum(ndp[j], dp[j + 1]);
                ndp[j] = sum(ndp[j], dp[j - 1]);
                ndp[j] = sum(ndp[j], dp[j]);
            }
        }
        swap(dp, ndp);
    }
    int sm = 0;
    for(auto it : dp) sm = sum(sm, it);
    cout << sm << endl;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int tt;
    tt=1; 
  //  cin >> tt;
    while(tt--) solve();
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
}