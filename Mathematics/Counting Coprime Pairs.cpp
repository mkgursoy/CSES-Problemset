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
const int mxV = 1e6 + 7;
int sieve[mxV];
int cnt[mxV];
void findPrimes()
{
	for(int i = 2;mxV > i;i++)
	{
		if(!sieve[i])
		{
			for(int j = i * 2;mxV > j;j += i) sieve[j] = 1;
		}
	}
	sieve[1] = 1;
}
void solve()
{
	findPrimes();
   	int n;
   	cin >> n;
   	int ans = n * (n - 1) / 2;
   	while(n--)
   	{
   		int x;
   		cin >> x;
   		vector<int> div;
   		if(x % 2 == 0)
   		{
   			while(x % 2 == 0) x /= 2;
   			div.push_back(2);
   		}
   		for(int i = 3;x >= i * i;i += 2)
   		{
   			if(x % i == 0)
   			{
   				while(x % i == 0) x /= i;
   				div.push_back(i);
   			}
   		}
   		if(x != 1)
   		div.push_back(x);
   		int sz = div.size();
   		for(int i = 1;(1LL << sz) > i;i++)
   		{
   			int mul = 1;
   			int bt = 0;
   			for(int j = 0;sz > j;j++)
   			{
   				if((1LL << j) & i)
   				{
   					mul *= div[j];
   					bt++;
   				}
   			}
   			int coef = 1;
   			if(bt % 2 == 1) coef = -1;
   			if(mul != 1) ans += coef * cnt[mul];
   			
   			cnt[mul]++;
   		}
   	}
   	cout << ans << endl;
}
int32_t main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	int tt;
	tt=1; 
	
	while(tt--) solve();

}
