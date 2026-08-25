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
int mn[mxN];
int tout[mxN];
int vis[mxN];
int p[mxN];
vector<int> adj[mxN];
map<int,int> arp;
int timer = 0;
vector<int> new_adj[mxN];
int depth[mxN];
void dfs(int pos,int par = -1)
{
	tin[pos] = timer++;
	mn[pos] = pos;
	if(par != -1) depth[pos] = depth[par] + 1;
	p[pos] = par;
	for(auto it : adj[pos])
	{
		if(it == par) continue;
		if(!vis[it])
		{
			vis[it] = 1;
			new_adj[pos].push_back(it);
			dfs(it, pos);
			if(tin[mn[it]] >= tin[pos] && par != -1) arp[pos]++;
			if(tin[mn[pos]] > tin[mn[it]]) mn[pos] = mn[it];
		}
		else
		{
			if(tin[mn[pos]] > tin[it]) mn[pos] = it;
		}
	}
	if(par == -1 && new_adj[pos].size() > 1) arp[pos]++;
	tout[pos] = timer++;
}
bool is_anc(int a,int b)
{
	return (tin[a] <= tin[b] && tout[b] <= tout[a]);
}
void solve()
{
   	int n,m,q;
   	cin >> n >> m >> q;
   	while(m--)
   	{
   		int x,y;
   		cin >> x >> y;
   		x--,y--;
   		adj[x].push_back(y), adj[y].push_back(x);
   	}
   	for(int i = 0;n > i;i++)
   	{
   		if(!vis[i]) vis[i] = 1, dfs(i);
   	}
   	while(q--)
   	{
   		int a,b,c;
   		cin >> a >> b >> c;
   		a--,b--,c--;
   	
   		if(a == c || b == c)
   		{
   			cout << "NO" << endl;
   			continue;
   		}
   		if(depth[a] > depth[b]) swap(a, b);
   		if(!is_anc(c, a) && is_anc(c, b))
   		{
   			int ind_b = 0;
   			int l = 1, r = new_adj[c].size();
	   		while(r > l)
	   		{
	   			int mid = (l + r) / 2;
	   			if(tin[new_adj[c][mid]] > tin[b]) r = mid;
	   			else l = mid + 1;
	   		}
	   		ind_b = l - 1;
	   		if(!is_anc(c, mn[new_adj[c][ind_b]])) cout << "YES" << endl;
	   		else cout << "NO" << endl;
	   		continue;
   		}
   		if(!is_anc(c, b) && is_anc(c, a))
   		{
   			int ind_a = 0;
   			int l = 1, r = new_adj[c].size();
	   		while(r > l)
	   		{
	   			int mid = (l + r) / 2;
	   			if(tin[new_adj[c][mid]] > tin[a]) r = mid;
	   			else l = mid + 1;
	   		}
	   		ind_a = l - 1;
	   		if(!is_anc(c, mn[new_adj[c][ind_a]])) cout << "YES" << endl;
	   		else cout << "NO" << endl;
	   		continue;
   		}
   		if(!is_anc(c, a) && !is_anc(c, b))
   		{
   			cout << "YES" << endl;
   			continue;
   		}
   		if(is_anc(c, a) && is_anc(c, b))
   		{
   			int ind_a = 0, ind_b = 0;
	   		int l = 1, r = new_adj[c].size();
	   		while(r > l)
	   		{
	   			int mid = (l + r) / 2;
	   			if(tin[new_adj[c][mid]] > tin[a]) r = mid;
	   			else l = mid + 1;
	   		}
	   		ind_a = l - 1;
	   		l = 1, r = new_adj[c].size();
	   		while(r > l)
	   		{
	   			int mid = (l + r) / 2;
	   			if(tin[new_adj[c][mid]] > tin[b]) r = mid;
	   			else l = mid + 1;
	   		}
	   		ind_b = l - 1;
	   		
	   		if(ind_a == ind_b)
	   		{
	   			cout << "YES" << endl;
	   		} 
	   		else if(!is_anc(c, mn[new_adj[c][ind_a]]) && !is_anc(c, mn[new_adj[c][ind_b]]))
	   		{
	   			cout << "YES" << endl;
	   		}
	   		else cout << "NO" << endl;
   		}
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
