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
int par[mxN][32];
vector<int> adj[mxN];
int n;
int tin[mxN], tout[mxN];
int pref[mxN];
int timer = 0;
int dist[mxN];
void dfs(int pos,int par1 = -1)
{
    if(par1 != -1)
    {
        par[pos][0] = par1;
    }
    dist[pos] = dist[par1] + 1;
    tin[pos] = ++timer;
    for(auto it : adj[pos])
    {
        if(it != par1)
        {
            dfs(it,pos);
            pref[pos] += pref[it];
        }
        
    } 
    tout[pos] = ++timer;
}
void solve()
{
    int q;
    cin >> n >> q;
    for(int i = 0;n - 1 > i;i++)
    {
        int x,y;
        cin >> x >> y;
        x--,y--;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    dfs(0);
    for(int j = 1;32 > j;j++)
    {
        for(int i = 0;n > i;i++) par[i][j] = par[par[i][j - 1]][j - 1];
    }
    auto is_anc = [&](int a,int b) -> bool
    {
        if(tin[a] <= tin[b] && tout[b] <= tout[a]) return true;
        return false;
    };
    auto jump = [&](int a,int b) -> int
    {
        for(int i = 31;i >= 0;i--)
        {
            if(b >= (1LL << i)) b -= (1LL << i), a = par[a][i];
        }
        return a;
    };
    auto lca = [&](int a,int b) -> int
    {
        if(is_anc(a, b)) return a;
        if(is_anc(b, a)) return b;
        for(int i = 31;i >= 0;i--)
        {
            if(!is_anc(par[a][i], b)) a = par[a][i];
        }
        return par[a][0];
    };
    while(q--)
    {
        int a,b;
        cin >> a >> b;
        a--,b--;
        if(is_anc(a, b))
        {
            if(a != 0) pref[par[a][0]]--;
            pref[b]++;
        }
        else if(is_anc(b, a))
        {
            if(b != 0) pref[par[b][0]]--;
            pref[a]++;
        }
        else
        {
            pref[a]++;
            pref[b]++;
            if(lca(a, b) != 0) pref[par[lca(a, b)][0]]--;
            pref[lca(a, b)]--;
        }
    }
    dfs(0);
    for(int i = 0;n > i;i++) cout << pref[i] << endl;
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