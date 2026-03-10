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
int nxt[mxN];
vector<int> rnxt[mxN];
int vis[mxN];
int pre[mxN];
int ord[mxN];
int dist[mxN];
int comp[mxN];
int p[mxN][20];
int par[mxN];
vector<vector<int>> cyc;
void dfs(int pos)
{
    vis[pos] = 1;
    if(vis[nxt[pos]] == 1)
    {
        vector<int> ans;
        ans.push_back(pos);
        pre[nxt[pos]] = pos;
        int x = pre[pos];
        while(x != -1 && x != pos) ans.push_back(x), x = pre[x];
        reverse(all(ans));
        cyc.push_back(ans);
    }
    else if(vis[nxt[pos]] == 0)
    {
        pre[nxt[pos]] = pos;
        dfs(nxt[pos]);
    }
    vis[pos] = -1;
}
void solve()
{
    int n, q;
    cin >> n;
    memset(ord,-1,sizeof(ord));
    memset(pre,-1,sizeof(pre));
    for(int i = 0;n > i;i++)
    {
        int x;
        cin >> x;
        x--;
        nxt[i] = x;
        p[i][0] = nxt[i];
        rnxt[x].push_back(i);
    }
    for(int j = 1;20 > j;j++)
    {
        for(int i = 0;n > i;i++)
        {
            p[i][j] = p[p[i][j - 1]][j - 1];
        }
    }
    for(int i = 0;n > i;i++)
    {
        if(!vis[i]) dfs(i);
    }
    memset(vis,0,sizeof(vis));
    int timer = 0;
    for(auto cur : cyc)
    {
        comp[timer] = cur.size();
        queue<int> bfs;
        for(int i = 0;cur.size() > i;i++)
        {
            ord[cur[i]] = i;
            bfs.push(cur[i]);
            vis[cur[i]] = 1;
            par[cur[i]] = timer;
        }
        while(bfs.size())
        {
            int p = bfs.front();
            bfs.pop();
            for(auto it : rnxt[p])
            {
                if(vis[it]) continue;
                vis[it] = 1;
                bfs.push(it);
                dist[it] = dist[p] + 1;
                par[it] = timer;
            }
        }
        timer++;
    }
    for(int i = 0;n > i;i++) cout << dist[i] + comp[par[i]] << endl;
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