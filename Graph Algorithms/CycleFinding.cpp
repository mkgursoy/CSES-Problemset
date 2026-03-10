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
const int mxN = 2507;
vector<int> adj[mxN];
vector<int> rev_adj[mxN];
vector<ar<int,3>> edg;
int reach_start[mxN];
int reach_end[mxN];
int dist[mxN];
int pre[mxN];
void dfs_st(int pos)
{
    reach_start[pos] = 1;
    for(auto it : adj[pos])
    {
        if(!reach_start[it]) dfs_st(it);
    }
}
void dfs_en(int pos)
{
    reach_end[pos] = 1;
    for(auto it : rev_adj[pos])
    {
        if(!reach_end[it]) dfs_en(it);
    }
}
void solve()
{
    int n,m;
    cin >> n >> m;
    while(m--)
    {
        int x,y,z;
        cin >> x >> y >> z;
        x--,y--;
        edg.push_back({x,y,z});
        adj[x].push_back(y);
        rev_adj[y].push_back(x);
    }
    dfs_st(0),dfs_en(n - 1);
    fill(dist,dist+n,INF);
    memset(pre,-1,sizeof(pre));
    dist[0] = 0;
    int x = -1;
    for(int i = 0;n > i;i++)
    {
        x = -1;
        for(auto [pos,it,d] : edg)
        {
            if(dist[pos] + d < dist[it]) dist[it] = dist[pos] + d, pre[it] = pos, x = it;
        }
    }
    if(x == -1)
    {
        cout << "NO" << endl;
    }
    else
    {
        for(int i = 0;n > i;i++) x = pre[x];
        int v = x;
        vector<int> cyc;
        while(!(v == x && cyc.size() > 0)) cyc.push_back(x),x = pre[x];
        cyc.push_back(x);
        reverse(all(cyc));
        cout << "YES" << endl;
        for(auto it : cyc) cout << it + 1 << " ";
        cout << endl;
    }
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