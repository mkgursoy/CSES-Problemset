/*
    Author: Matkap (prefix_sum)
*/

#include <bits/stdc++.h>
#include <array>

using namespace std;

#define int long long
#define ar array
#define all(x) x.begin(),x.end()

const int INF = 1e17 , MOD = 1e9 + 7;

int mul(int a,int b,int mod = MOD)
{
    return a * 1LL * b % mod;
}
int sum(int a,int b,int mod = MOD)
{
    return (a + b + mod) % mod;
}
int binpow(int base,int power,int mod = MOD)
{
    if(power == 1) return base;
    if(power == 0) return 1LL;
    
    if(power % 2 == 1)
    {
        int a;    
        a = binpow(base,power / 2,mod);
        return mul(base, mul(a, a, mod), mod);
    } 
    else
    {
        int a;
        a = binpow(base,power / 2,mod);
        return mul(a, a, mod);
    }
}
int inv(int a,int mod = MOD)
{
    return binpow(a, mod - 2, mod) % mod;
}
const int mxN = 1e5 + 7;
vector<int> adj[mxN];
bitset<mxN> bt;
int vis[mxN];
int timer = 0;
void dfs(int pos)
{
	timer++;
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
   	int n,m;
   	cin >> n >> m;
   	while(m--)
   	{
   		int x,y;
   		cin >> x >> y;
   		adj[x].push_back(y), adj[y].push_back(x);
   	}
   	vector<int> comp;
   	for(int i = 1;n >= i;i++)
   	{
   		if(!vis[i])
   		{
   			vis[i] = 1;
   			timer = 0;
   			dfs(i);
   			comp.push_back(timer);
   		}
   	}
   	bt[0] = 1;
   	for(auto it : comp) bt |= (bt << it);
   	for(int i = 1;n >= i;i++) cout << bt[i];
   	cout << endl;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int tt;
    tt=1; 
   // cin >> tt;
    while(tt--) solve();
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
}