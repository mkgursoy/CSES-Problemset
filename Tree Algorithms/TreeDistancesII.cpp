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
int dp[mxN];
int dp_subtree[mxN];
int sub_size[mxN];
vector<int> adj[mxN];
int n;
void dfs1(int pos,int par = -1)
{
    int sum = 0;
    sub_size[pos] = 1;
    for(auto it : adj[pos])
    {
        if(it != par)
        {
            dfs1(it, pos);
            sub_size[pos] += sub_size[it];
            dp_subtree[pos] += dp_subtree[it] + sub_size[it];
        }
    }
}
void dfs2(int pos,int par = -1)
{
    if(par != -1) dp[pos] = dp[par] + (n - sub_size[pos]) - (sub_size[pos] + dp_subtree[pos]);
    dp[pos] += dp_subtree[pos];
    for(auto it : adj[pos])
    {
        if(it != par)
        {
            dfs2(it, pos);
        }
    }
}
void solve()
{
    cin >> n;
    for(int i = 0;n - 1 > i;i++)
    {
        int x,y;
        cin >> x >> y;
        x--,y--;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    dfs1(0);
    dfs2(0);
    for(int i = 0;n > i;i++) cout << dp[i] << endl;
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