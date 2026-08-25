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
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<int> ind[26];
    vector<int> non_ind[26];
    int m = s.size();
    int gel[m][26];
    memset(gel,0,sizeof(gel));
    int dp[n + 1][m];
    memset(dp,0,sizeof(dp));
    dp[0][0] = 1;
    string suan = "";
    for(int i = 0;m > i;i++)
    {
        for(int j = 0;26 > j;j++)
        {
            string new_s = suan + (char)('A' + j);
            for(int k = 0;min(m, (int)new_s.size()) > k;k++)
            {
                bool b = true;
                for(int l = 0;k >= l;l++)
                {
                    if(new_s[i - l] != s[k - l])
                    {
                        b = false;
                        break;
                    }
                }
                gel[i][j] = max(gel[i][j], b * (k + 1));
                
            }
        }
        if(i == m) break;
        suan += s[i];
    }
    for(int i = 1;n >= i;i++)
    {
        for(int j = 0;26 > j;j++)
        {
            for(int k = 0;m > k;k++)
            {
               
                if(gel[k][j] != m) dp[i][gel[k][j]] = sum(dp[i][gel[k][j]], dp[i - 1][k]);
            }
        }
        
    }
    int ans = binpow(26LL, n);
    for(int i = 0;m > i;i++) ans = sum(ans, -dp[n][i]);
    cout << ans << endl;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int tt;
    tt=1; 
    
    while(tt--) solve();
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
}
