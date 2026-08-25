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
int tin[mxN];
vector<int> adj[mxN];
int vis[mxN];
int mn[mxN];
int timer = 0;
set<int> ans;
void dfs(int pos,int from = -1)
{
	
	tin[pos] = ++timer;
	int c = 0;
	for(auto it : adj[pos])
	{
		if(it == from) continue;
		if(!vis[it])
		{
			c++;
			vis[it] = 1;
			dfs(it, pos);
			
			mn[pos] = min(mn[pos], mn[it]);
			if(mn[it] >= tin[pos] && from != -1)
			{
				ans.insert(pos);	
			}
		}
		else
		{
			mn[pos] = min(mn[pos], tin[it]);
		}
	}
	if(from == -1 && c > 1) ans.insert(pos);
	
}
void solve()
{
   	int n,m;
   	cin >> n >> m;
   	fill(mn, mn + mxN, INF);
   	while(m--)
   	{
   		int x,y;
   		cin >> x >> y;
   		x--,y--;
   		adj[x].push_back(y);
   		adj[y].push_back(x);
   	}
   	for(int i = 0;n > i;i++)
   	{
   		if(!vis[i]) vis[i] = 1, dfs(i);
   	}
   	cout << ans.size() << endl;
   	for(auto it : ans) cout << it + 1 << " ";
}
int32_t main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	int tt;
	tt=1; 
	
	while(tt--) solve();

}
