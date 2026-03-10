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
const int mxN = 2e5 + 7;
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
    int n,m;
    cin >> n >> m;
    for(int i = 1;n >= i;i++) cin >> a[i];
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
    int dp[timer + 1];
    memset(dp,0,sizeof(dp));
    for(auto it : order)
    {
        dp[it] = 0;
        for(auto it1 : new_adj[it])
        {
            dp[it] = max(dp[it], dp[it1]);
        }
        dp[it] += comp[it];
    }
    cout << *max_element(dp,dp + timer + 1) << endl; 
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