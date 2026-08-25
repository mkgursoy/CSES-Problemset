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
	return (a * 1LL * b) % mod;
}
int sum(int a,int b,int mod = MOD)
{
	a %= mod;
	b %= mod;
	return (a + b + mod) % mod;
}
int binpow(int base,int power,int mod = MOD)
{
	if(power == 1) return base % MOD;
	if(power == 0) return 1LL;
	if(power%2==1)
	{
 		int a;	
 		a = binpow(base,(power - 1)/2) % MOD;
		return mul(base, mul(a, a, mod), mod);
	} 
	else
 	{
		int a;
		a = binpow(base,power/2) % MOD;
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
   	ar<int,2> a[n];
   	for(int i = 0;n > i;i++) cin >> a[i][0] >> a[i][1];
   	int num = 1, sum = 1, prod = 1,num_dif_mod = 1;
   	for(int i = 0;n > i;i++)
   	{
   		num = mul(num, a[i][1] + 1);
   		sum = mul(sum, mul(binpow(a[i][0], a[i][1] + 1) - 1LL,inv(a[i][0] - 1)));
   		prod = mul(binpow(prod, a[i][1] + 1),binpow(binpow(a[i][0], a[i][1] * (a[i][1] + 1) / 2) % MOD, num_dif_mod));
   		num_dif_mod = mul(num_dif_mod, a[i][1] + 1, MOD - 1);
   	}
   	cout << num << " " << sum << " " << prod << endl;
}

int32_t main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	int tt;
	tt=1; 
	
	while(tt--) solve();

}
