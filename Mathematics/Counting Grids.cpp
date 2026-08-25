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

void solve()
{
   	int n;
   	cin >> n;
   	if(n == 1)
   	{
   		cout << "2" << endl;
   		return;
   	}
   	int ans = 0;
   	
   	if(n % 2 == 0) ans = sum(ans, binpow(2LL, n * n / 4 + 1LL));
   	else ans = sum(ans, binpow(2LL, (n * n - 1) / 4 + 2LL));
   	
   	if(n % 2 == 0) ans = sum(ans, binpow(2LL, n * n / 2));
   	else ans = sum(ans, binpow(2LL,(n * n - 1) / 2 + 1LL));
   	
   	ans = sum(ans,binpow(2LL,n * n));
   	cout << mul(ans, inv(4)) << endl;
}
int32_t main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	int tt;
	tt=1; 
	
	while(tt--) solve();

}
