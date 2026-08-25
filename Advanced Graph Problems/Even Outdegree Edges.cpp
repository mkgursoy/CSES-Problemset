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
const int mxN = 2e5 + 7;
vector<int> adj[mxN];
int num[mxN];
int tin[mxN];
int timer = 1;
vector<ar<int,2>> edg;
void dfs(int pos,int par = -1)
{
	tin[pos] = timer++;
	for(auto it : adj[pos])
	{
		if(it != par)
		{
			if(tin[it] < tin[pos])
			{
				edg.push_back({pos, it});
				num[pos] ^= 1;
			}
			else if(tin[it] == INF)
			{
				dfs(it,pos);
				if(!num[it])
				{
					edg.push_back({pos, it});
					num[pos] ^= 1;
				}
				else
				{
					edg.push_back({it, pos});
					num[it] ^= 1;
				}
			}
		}
	}
}
void solve()
{
   	int n, m;
   	cin >> n >> m;
   	fill(tin,tin + n + 1, INF);
   	while(m--)
   	{
   		int x,y;
   		cin >> x >> y;
   		adj[x].push_back(y);
   		adj[y].push_back(x);
   	}
   	if(m % 2 == 1)
   	{
   		cout << "IMPOSSIBLE" << endl;
   		return;
   	}
   	for(int i = 1;n >= i;i++)
   	{
   		if(tin[i] == INF)
   		{
   			dfs(i);
   		}
   	}
   	
   	for(int i = 1;n >= i;i++)
   	{
   		if(num[i] == 1)
   		{
   			
   			cout << "IMPOSSIBLE" << endl;
   			return;
   		}
   	}
 
   	for(auto [x, y] : edg) cout << x << " " << y << endl;
}
int32_t main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	int tt;
	tt=1; 
	
	while(tt--) solve();

}
