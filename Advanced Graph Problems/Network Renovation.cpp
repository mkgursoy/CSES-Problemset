#include <bits/stdc++.h>
#include <array>

using namespace std;

#define int long long
#define endl "\n"
#define ar array
#define all(x) x.begin(),x.end()

const int INF = 1e17 , MOD = 998244353LL;

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
vector<int> leaves;
void dfs(int pos,int par = -1)
{
	for(auto it : adj[pos])
	{
		if(it != par)
		{
			dfs(it,pos);
		}
	}
	if(adj[pos].size() == 1)
	{
		leaves.push_back(pos);
	}
}
void solve()
{
    int n;
    cin >> n;
   	int deg[n];
   	memset(deg,0,sizeof(deg));
   	int rt = 0;
   	for(int i = 0;n - 1 > i;i++)
   	{
   		int x,y;
   		cin >> x >> y;
   		x--,y--;
   		adj[x].push_back(y);
   		adj[y].push_back(x);
   		deg[x]++;
   		deg[y]++;
   	}
   	dfs(0);
   	if(leaves.size() % 2 == 1) leaves.push_back(rt);
   	cout << leaves.size() / 2 << endl;
   	for(int i = 0;leaves.size() / 2 > i;i++) cout << leaves[i] + 1 << " " << leaves[leaves.size() / 2 + i] + 1 << endl;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int tt;
    tt=1; 
  
    while(tt--) solve();

}
