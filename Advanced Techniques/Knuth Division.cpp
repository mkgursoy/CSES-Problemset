#include <bits/stdc++.h>
#include <array>

using namespace std;

#define int long long
#define endl "\n"
#define ar array
#define all(x) x.begin(),x.end()

const int INF = 1e17 , MOD = 998244353LL;

int mul(int a,int b,int mod = MOD)
{
    a %= mod;
    b %= mod;
    return a * 1LL * b % mod;
}
int sum(int a,int b,int mod = MOD)
{
    a %= mod;
    b %= mod;
    return (a + b + mod) % mod;
}
int binpow(int base,int power,int mod = MOD)
{
    if(power == 1) return base;
    if(power == 0) return 1;
    
    if(power % 2 == 1)
    {
         int a;    
         a = binpow(base,(power - 1)/2);
        return mul(base, mul(a, a, mod), mod);
    } 
    else
    {
        int a;
        a = binpow(base,power/2);
        return mul(a, a, mod);
    } 

}
int inv(int a,int mod = MOD)
{
    a %= mod;
    return binpow(a, mod - 2) % mod;
}
const int mxN = 5e3 + 7;
int dp[mxN][mxN];
int a[mxN];
int pref[mxN];
void solve()
{
    int n;
    cin >> n;
    for(int i = 0;n > i;i++) cin >> a[i], pref[i] = (i ? a[i] + pref[i - 1] : a[i]);
    auto cost = [&](int i,int j) -> int
	{
		return pref[j] - (i ? pref[i - 1] : 0LL);
	};
	for(int i = 0;n > i;i++) dp[i][i] = 0;
	for(int len = 2;n >= len;len++)
	{
		int spl = 0;
		for(int i = 0;i + len - 1 < n;i++)
		{
			int j = i + len - 1;
			dp[i][j] = INF;
		
			int st = max(spl, i);
			for(int k = st;((st == 0) ? j : min(st + 10, j)) > k;k++)
			{
				if(dp[i][k] + dp[k + 1][j] + cost(i, j) < dp[i][j]) spl = k;
				dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j] + cost(i, j));
			}
		}
	}
	cout << dp[0][n - 1] << endl;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int tt;
    tt=1; 
  
    while(tt--) solve();

}
