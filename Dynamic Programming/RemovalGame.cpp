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
const int mxN = 5e3 + 5;
int dp[mxN][mxN];
void solve()
{
    int n;
    cin >> n;
    int a[n];
    for(int i = 0;n > i;i++) cin >> a[i];
    for(int i = 0;n >= i;i++)
    {
        for(int j = i;n >= j;j++)
        {
            int new_i = j - i;
            int pos_1 = 0,pos_2 = 0,pos_3 = 0;

            if(new_i + 1 <= j - 1) pos_1 = dp[new_i + 1][j - 1];
            if(new_i + 2 <= j) pos_2 = dp[new_i + 2][j];
            if(new_i <= j - 2) pos_3 = dp[new_i][j - 2];

            int l = a[new_i-1] + min(pos_1,pos_2);
            int r = a[j-1] + min(pos_1,pos_3);
 
            dp[new_i][j] = max(l,r);
        }
    }
    cout << dp[1][n] << endl;
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