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
const int mxN = 5e4 + 7;
vector<int> order;
int vis[mxN];
vector<int> adj[mxN];
vector<int> radj[mxN];
int timer = 0;
vector<int> new_adj[mxN];
vector<ar<int,2>> edg;
int comp[mxN];
int ans[mxN];
int a[mxN];
bitset<mxN> st[mxN];
void dfs1(int pos)
{
	for(auto it : adj[pos])
	{
		if(!vis[it]) vis[it] = 1, dfs1(it);
	}
	order.push_back(pos);
}
void dfs2(int pos)
{
	ans[pos] = timer;
	comp[timer] += a[pos];

	for(auto it : radj[pos])
	{
		if(!vis[it]) vis[it] = 1, dfs2(it);
	}
}
void dfs3(int pos)
{
	for(auto it : new_adj[pos])
	{
		if(!vis[it]) vis[it] = 1, dfs3(it);
	}
	order.push_back(pos);
}
void solve()
{
   	int n,m,q;
   	cin >> n >> m >> q;
   	while(m--)
   	{
   		int x,y;
   		cin >> x >> y;
   		adj[x].push_back(y);
   		radj[y].push_back(x);
   		edg.push_back({x,y});
   	}
   	for(int i = 1;n >= i;i++)
   	{
   		if(!vis[i]) dfs1(i);
   	}
   	reverse(all(order));
   	memset(vis,0,sizeof(vis));
   	int cnt = 0;
  
   	for(auto it : order)
   	{
   		if(!vis[it]) vis[it] = 1,timer++,dfs2(it);
   	}
   	for(auto [x,y] : edg)
   	{
   		if(ans[x] != ans[y]) new_adj[ans[y]].push_back(ans[x]);
   	}
   	order.clear();
   	memset(vis,0,sizeof(vis));
   	for(int i = 1;timer >= i;i++)
   	{
   		if(!vis[i]) vis[i] = 1, dfs3(i);
   	}
   	for(auto i : order)
   	{
   		st[i][i] = 1;
   		for(auto j : new_adj[i]) st[i] |= st[j];
   	}
   	while(q--)
   	{
   		int a,b;
   		cin >> a >> b;
   		a = ans[a];
   		b = ans[b];
   		
   		if(st[b][a]) cout << "YES" << endl;
   		else cout << "NO" << endl;
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
