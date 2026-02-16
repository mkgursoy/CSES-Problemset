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
const int mxN = 507;
const int mxK = mxN * (mxN - 1) / 2;
int dp[mxK];
int ndp[mxK];
void solve()
{
   	int n,k;
   	cin >> n >> k;
   	dp[0] = 1;
   	for(int i = 1;n >= i;i++)
	{
		for(int j = 0;mxK > j;j++)
		{
			ndp[j] = 0;
		}
		int sum1 = 0;
		for(int j = 0;mxK >= j;j++)
		{
			sum1 = sum(sum1, dp[j]);
			if(j >= i)
				sum1 = sum(sum1, -dp[j - i]);
			ndp[j] = sum(ndp[j], sum1);
		}
		for(int j = 0;mxK > j;j++)
		{
			dp[j] = ndp[j];
		}
   	}
   	cout << dp[k] << endl;
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