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
const int mxM = 1e6 + 5;
int dp[mxM]; 
void solve()
{
    int n,m;
    cin >> n >> m;
    int a[n];
    for(int i = 0;n > i;i++) cin >> a[i];
    sort(a,a + n);
    dp[0] = 0;
    for(int i = 1;m >= i;i++)
    {   
        dp[i] = INF;    
        for(int j = 0;n > j;j++)
        {
            if(i < a[j]) break;
            dp[i] = min(1 + dp[i - a[j]], dp[i]);
        }
    }
    if(dp[m] == INF)
    {
        cout << "-1" << endl;
    }
    else
    {
        cout << dp[m] << endl;
    }   
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