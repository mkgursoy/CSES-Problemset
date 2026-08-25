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
   	int n,k;
   	cin >> n >> k;
   	int a[k];
   	for(int i = 0;k > i;i++)
   	{
   		cin >> a[i];
   	}
   	__int128 ans = 0;
   	for(int i = 1;(1LL << k) > i;i++)
   	{
   		bool b = true;
   		__int128 cnt = 0,mul = 1;
   		for(int j = 0;k > j;j++)
   		{
   			if((1LL << j) & i)
   			{
   				cnt++;
   				mul *= a[j];
   				if(mul > n) break;
   			}
   		}
   		int coef = 1;
   		if(cnt % 2 == 0) coef = -1;
   		ans += coef * (int)(n / mul);
   	}
   	cout << (int)ans << endl;
}
int32_t main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	int tt;
	tt=1; 
	
	while(tt--) solve();

}
