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
const int mxV = 2e6 + 7;
int fact[mxV];
int inv_fact[mxV];
void findFactorial()
{
	fact[0] = 1;
	for(int i = 1;mxV > i;i++) fact[i] = mul(i, fact[i - 1]);
	inv_fact[mxV - 1] = inv(fact[mxV - 1]);
	for(int i = mxV - 2;i >= 0;i--) inv_fact[i] = mul(i + 1, inv_fact[i + 1]);
}
void solve()
{
	findFactorial();
   	int n;
   	cin >> n;
   	if(n % 2 == 1) cout << "0" << endl;
   	else
   	{
   		n /= 2;
   		string s;
   		cin >> s;
   		int op = 0, cl = 0;
   		for(auto it : s)
   		{
   			if(it == '(') op++;
   			else cl++;
   			if(cl > op || op > n || cl > n)
   			{
   				cout << "0" << endl;
   				return;
   			}
   		}
   		int badCase = 0;
   		if(op < n)
   		{
   			badCase = mul(fact[2 * n - op - cl], mul(inv_fact[n - op - 1], inv_fact[n - cl + 1]));
   		}
   		cout << (mul(fact[2 * n - op - cl], mul(inv_fact[n - op], inv_fact[n - cl])) - badCase + MOD) % MOD << endl;
   	}
}
int32_t main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	int tt;
	tt=1; 
	
	while(tt--) solve();

}
