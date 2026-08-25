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
bitset<mxN> st[mxN];
int vis[mxN];
vector<int> order;
vector<int> adj[mxN];
int ans[mxN];
void dfs(int pos)
{
	for(auto it : adj[pos])
	{
		if(!vis[it])
		{
			vis[it] = 1;
			dfs(it);
		}
	}
	order.push_back(pos);
}
void solve()
{
   	int n,m;
   	cin >> n >> m;
   	for(int i = 0;m > i;i++)
   	{
   		int x,y;
   		cin >> x >> y;
   		x--,y--;
   		adj[x].push_back(y);
   	}
   	for(int i = 0;n > i;i++)
   	{
   		if(!vis[i]) vis[i] = 1, dfs(i);
   	}
   	for(int i = 0;n > i;i++) st[i][i] = 1;

   	for(auto i : order)
   	{
   		for(auto j : adj[i])
   		{
   			st[i] |= st[j];
   		}
   	}
   	for(int i = 0;n > i;i++) cout << st[i].count() << endl;
}
int32_t main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	int tt;
	tt=1; 
	
	while(tt--) solve();

}
