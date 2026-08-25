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
const int mxN = 1e5 + 7;
int depth[mxN];
vector<int> adj[mxN];
int vis[mxN];
void dfs(int pos)
{
	for(auto it : adj[pos])
	{
		if(!vis[it]) vis[it] = 1, depth[it] = depth[pos] + 1, dfs(it);
	}
}
void solve()
{
   	int n;
   	cin >> n;
   	int m;
   	cin >> m;
   	vector<ar<int,2>> edg;
   	for(int i = 0;m > i;i++)
   	{
   		int x,y;
   		cin >> x >> y;
   		adj[x].push_back(y);
   		adj[y].push_back(x);
   		edg.push_back({x, y});
   	}
   	for(int i = 1;n >= i;i++)
   	{
   		if(!vis[i]) vis[i] = 1, dfs(i);
   	}
   	for(auto [x, y] : edg)
   	{
   		
   		if(depth[x] < depth[y])
   		{
   			cout << x << " " << y << endl;
   		}
   		else 
   			cout << y << " " << x << endl;
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
