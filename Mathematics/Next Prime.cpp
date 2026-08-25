#include <bits/stdc++.h>
#include <array>

using namespace std;

#define int long long
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
void solve()
{
   	int n;
   	cin >> n;
   	n++;
   	bool f = true;
   	while(f)
   	{
   		if(n % 2 == 0 && n != 2)
   		{
   			n++;
   			continue;
   		}
   		else if(9 > n)
   		{
   			break;
   		}
   		for(int i = 3;n >= i * i;i += 2)
   		{
   			if(n % i == 0)
   			{
   				break;
   			}
   			else
   			{
   				if(n < (i + 2) * (i + 2))
   				{
   					f = false;
   					break;
   				}
   			}
   		}
   		if(f) n++;
   	}
   	cout << n << endl;
}
int32_t main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	int tt;
	tt=1; 
	cin >> tt;
	while(tt--) solve();

}
