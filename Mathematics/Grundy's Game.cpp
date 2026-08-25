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

const int mxN = 2000 + 7;
int dp[mxN];
void findDp()
{
	dp[1] = 0;
	dp[2] = 0;
	for(int i = 3;mxN > i;i++)
	{
		set<int> mex;
		for(int j = 1;(i + 1) / 2 > j;j++)
		{
			mex.insert(dp[j] ^ dp[i - j]);
		}	
		int prev = -1;
		for(auto it : mex)
		{
			if(it != prev + 1)
			{
				dp[i] = prev + 1;
				prev = -23;
				break;
			}
			prev = it;
		}
		if(prev != -23)
		{
			dp[i] = prev + 1;
		}
	}
}
void solve()
{
   	int n;
   	cin >> n;
   	if(n >= mxN)
   	{
   		cout << "first" << endl;
   	}
   	else
   	{
   		if(dp[n] > 0)
   		{
   			cout << "first" << endl;
   		}
   		else
   			cout << "second" << endl;
   	}
}
int32_t main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	int tt;
	tt=1; 
	cin >> tt;
	findDp();
	while(tt--) solve();

}
