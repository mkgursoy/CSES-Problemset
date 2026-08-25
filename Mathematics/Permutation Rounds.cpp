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
const int mxN = 2e5 + 7;
vector<int> adj[mxN];
vector<int> sz;
int vis[mxN];
int t = 0;
vector<int> primes;
int sieve[mxN];
int pr[mxN];
void calc()
{
	sieve[1] = 1;
	for(int i = 2;mxN > i;i++)
	{
		if(!sieve[i])
		{
			for(int j = 2 * i;mxN > j;j += i)
			{
				sieve[j] = 1;
			}
		}
	}
	for(int i = 2;mxN > i;i++)
	{
		if(!sieve[i]) primes.push_back(i);
	}
}
void dfs(int pos)
{
	
	t++;
	for(auto it : adj[pos])
	{
		if(!vis[it])
		{
			vis[it] = 1;
			dfs(it);
		}
	}
}
void solve()
{
	calc();
   	int n;
   	cin >> n;
   	for(int i = 0;n > i;i++)
   	{
   		int x;
   		cin >> x;
   		x--;
   		adj[i].push_back(x);
   	}
   	for(int i = 0;n > i;i++)
   	{
   		if(!vis[i])
   		{
   			vis[i] = 1;
   			t = 0;
   			dfs(i);
   			
   			sz.push_back(t);
   		}
   	}
   	for(auto i : sz)
   	{
   		for(auto j : primes)
   		{
   			if(j > i) break;
   			int t = 0;
   			while(i % j == 0)
   			{
   				t++;
   				i /= j;
   			}
   			pr[j] = max(pr[j], t);
   		}
   	
   	}
   	int res = 1;
   	for(int i = 0;mxN > i;i++)
   	{
   		int j = pr[i];
   		res = mul(res, binpow(i, j));
   	}
   	cout << res << endl;
}
int32_t main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	int tt;
	tt=1; 
	
	while(tt--) solve();

}
