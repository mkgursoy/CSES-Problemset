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
void solve()
{
    auto calc = [&](int num) -> int
    {
        if(num < 10) return num;
        vector<int> a;
        while(num) a.push_back(num % 10), num /= 10;
        reverse(all(a));
        int n = a.size();
        bool flag = true;
        int dp[n][10];
        memset(dp,0,sizeof(dp));
        for(int i = 1;a[0] > i;i++) dp[0][i]++;
        for(int i = 1;n > i;i++)
        {
            for(int j = 1;10 > j;j++)
            {
                dp[i][j]++;
            }
            for(int j = 0;10 > j;j++)
            {
                for(int k = 0;10 > k;k++)
                {
                    if(j != k)
                    {
                        dp[i][j] += dp[i - 1][k];
                    }
                }
            }
            if(flag)
            {
                for(int j = 0;a[i] > j;j++)
                {
                    if(j != a[i - 1])
                    {
                        dp[i][j]++;
                    }
                }
            }
            if(a[i] == a[i - 1]) flag = false;
        }
        int ans = flag;
        for(int i = 0;10 > i;i++)
        {
            ans += dp[n - 1][i];
        }
        return ans;
    };
    int a,b;
    cin >> a >> b;
    cout << calc(b) - calc(a - 1);
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