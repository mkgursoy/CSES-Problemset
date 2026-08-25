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
const int mxN = 2507;
vector<int> adj[mxN];
void solve()
{
   int n;
   cin >> n;
   int m;
   cin >> m;
   vector<ar<int,2>> edg;
   while(m--)
   {
   	int x,y;
   	cin >> x >> y;
   	x--,y--;
   	adj[x].push_back(y);
   	adj[y].push_back(x);
   	edg.push_back({y, x});
   }
  	queue<ar<int,3>> q;
  	int vis[n];
  	int pre[n];
  	int ans = INF;
  	for(int i = 0;n > i;i++)
  	{
  		fill(vis, vis + n, INF);
  		memset(pre, -1, sizeof(pre));
  		q.push({-1, i, 0});
  		while(q.size())
  		{
  			auto [v, p, d] = q.front();
  			q.pop();
  			if(vis[p] != INF) continue;
  			vis[p] = d;
  			pre[p] = v;
  			for(auto it : adj[p])
  			{
  				if(vis[it] == INF) q.push({p, it, d + 1});
  			}
  		}
  		for(auto [x, y] : edg)
  		{
  			if(x != i && y != i && pre[x] != y && pre[y] != x)
  				ans = min(ans, vis[x] + vis[y] + 1);
  		}
  	}
  	if(ans == INF) cout << "-1" << endl;
  	else cout << ans << endl;
}
int32_t main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	int tt;
	tt=1; 
	
	while(tt--) solve();

}
