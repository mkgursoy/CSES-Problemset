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
const int mxA = 505,mxB = 505;
int dp[mxA][mxB];
void solve()
{
    int a,b;
    cin >> a >> b;
    for(int i = 1;a >= i;i++)
    {
        for(int j = 1; b >= j; j++)
        {
            if(i == j)
            {
                dp[i][j] = 1;               
                continue;
            }
            dp[i][j] = INF;
            for(int k = 1;i >= k;k++)
            {
                dp[i][j] = min(dp[i][j],dp[i - k][j] + dp[k][j]);
            }
            for(int k = 0;j >= k;k++)
            {
                dp[i][j] = min(dp[i][j],dp[i][j - k] + dp[i][k]);
            }
        }
    }
    cout << dp[a][b] - 1 << endl;
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