#include <bits/stdc++.h>
#include <array>

using namespace std;

#define int long long
#define endl "\n"
#define ar array
#define all(x) x.begin(),x.end()
#define double long double
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
void solve()
{
   	int n;
   	double k;
   	cin >> n >> k;
   	double ans = 0;
   	for(int i = 1;k >= i;i++)
   	{
   		double new_all_not_max = 1.0L, new_maybe_not_all_max = 1.0L;
   		for(int j = 1;n >= j;j++)
   		{
   			new_all_not_max *= ((double)i - 1.0) / (double)k;
   			new_maybe_not_all_max *= ((double)i - 0.0) / (double)k;
   		}
   		ans += (new_maybe_not_all_max - new_all_not_max) * (double)i;
   	}
   	
   	ans *= 1000000.0L;
   	double r = round(ans);
   	if((r - ans == -0.5L) || (r - ans == 0.5L))
   		ans = round(ans / 2) * 2;
   	else
   		ans = round(ans);
   
   	ans /= 1000000.0L;
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
