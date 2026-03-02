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
const int mxN = 1e5 + 5;
int n,m,vis[mxN];
vector<int> adj[mxN];
int pre[mxN];
void dfs(int pos,int from)
{
    vis[pos] = 1;
    for(auto it : adj[pos])
    {
        if(it == from) continue;
        if(vis[it] != 0)
        {
            vector<int> ans;
            ans.push_back(it + 1);
            while(pos != it && pos != -1)
            {           
                ans.push_back(pos + 1);
                pos = pre[pos];
            }
            ans.push_back(it + 1);
            cout << ans.size() << endl;
            for(auto it : ans) cout << it << " ";
            exit(0);
        }
        else
        {
            vis[it] = 1;
            pre[it] = pos;
            dfs(it,pos);
        }
    }
}
void solve()
{
    cin >> n >> m;
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
        if(!vis[i]) dfs(i,-1),pre[i] = -1;
    }
    cout << "IMPOSSIBLE" << endl;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int tt;
    tt=1; 
  //  cin >> tt;
    while(tt--) solve();
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
}