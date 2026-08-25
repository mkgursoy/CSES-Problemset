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
const int mxN = 501;
int fact[mxN], inv_fact[mxN];
void fp()
{
	fact[0] = 1;
	for(int i = 1;mxN > i;i++) fact[i] = mul(i, fact[i - 1]);
	inv_fact[mxN - 1] = inv(fact[mxN - 1]);
	for(int i = mxN - 2;i >= 0;i--) inv_fact[i] = mul(i + 1, inv_fact[i + 1]);
}
int comb(int a,int b)
{
	return mul(fact[a], mul(inv_fact[b], inv_fact[a - b]));
}
void solve()
{
    string s;
    cin >> s;
    int n = s.size();
    int dp[n + 1][n + 1];
    memset(dp,0,sizeof(dp));
  	for(int i = 0;n > i;i++) dp[i + 1][i] = 1;
    for(int sz = 2;n >= sz;sz += 2)
    {
    	for(int i = 0;n > i + sz - 1;i++)
    	{
    		int j = i + sz - 1;
    		
    		for(int k = i + 1;j >= k;k += 2)
    		{
    			if(s[i] == s[k])
    			dp[i][j] = sum(dp[i][j], mul(mul(dp[i + 1][k - 1],dp[k + 1][j]), comb((j - i + 1) / 2, (k - i + 1) / 2)));
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
   
    fp();
    while(tt--) solve();
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
}
