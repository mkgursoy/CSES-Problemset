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
vector<int> child[mxN];
int n;
int tin[mxN], tout[mxN];
int timer = 0;
void dfs(int pos)
{
    tin[pos] = ++timer;
    for(auto it : child[pos]) dfs(it);
    tout[pos] = ++timer;
}
void solve()
{
    int q;
    cin >> n >> q;
    memset(par,-1,sizeof(par));
    for(int i = 2;n >= i;i++) cin >> par[i][0],child[par[i][0]].push_back(i);
    dfs(1);
    for(int j = 1;32 > j;j++)
    {
        for(int i = 0;n > i;i++)
        {
            if(par[i + 1][j - 1] != -1)
            par[i + 1][j] = par[par[i + 1][j - 1]][j - 1];
        } 
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
            if(a == -1) break;
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
        cout << jump(a, b) << endl;
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