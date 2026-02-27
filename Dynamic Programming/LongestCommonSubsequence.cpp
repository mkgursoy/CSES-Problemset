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
    int n,m;
    cin >> n >> m;
    n++, m++;
    int a[n], b[m];
    for(int i = 1;n > i;i++) cin >> a[i];
    for(int i = 1;m > i;i++) cin >> b[i];
    a[0] = '-';
    b[0] = '-';
    int dp[n][m];
    for(int i = 0;n > i;i++) dp[i][0] = 0;
    for(int i = 0;m > i;i++) dp[0][i] = 0;
    for(int i = 1;n > i;i++)
    {
        for(int j = 1;m > j;j++)
        {
            dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            if(a[i] == b[j]) dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + 1);
        }
    }
    vector<int> ans;
    int lb = n - 1,rb = m - 1;
    while(lb > 0 && rb > 0)
    {
        if(a[lb] == b[rb])
        {
            ans.push_back(a[lb]);
            lb--;
            rb--;
        } 
        else
        {   
            if(dp[lb-1][rb] == dp[lb][rb]) lb--;
            else rb--;
        }
    }
    reverse(all(ans));
    cout << ans.size() << endl;
    for(auto it : ans) cout << it << " ";
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