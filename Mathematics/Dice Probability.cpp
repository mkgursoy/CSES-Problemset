#include <bits/stdc++.h>
#include <array>

using namespace std;

#define int long long
#define endl "\n"
#define ar array
#define all(x) x.begin(),x.end()

const int INF = 1e17 , MOD = 1e9 + 7;

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
    
	if(power%2==1)
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
double dp[607][107];
void solve()
{
   	int n;
   	cin >> n;
   	int a,b;
   	cin >> a >> b;
   	dp[0][0] = 1.0;
   	for(int i = 1;607 >= i;i++)
   	{
   		for(int j = 1;n >= j;j++)
   		{
   			for(int k = 1;min(i,6LL) >= k;k++)
   			{
   				dp[i][j] += dp[i - k][j - 1] * (1.0 / 6.0L);
   			}
   		}
   	}
   	double ans = 0;
   	for(int i = a;b >= i;i++) ans += dp[i][n]; 
   	cout << fixed << setprecision(6) << ans << endl;
}
int32_t main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	int tt;
	tt=1; 
	
	while(tt--) solve();

}
