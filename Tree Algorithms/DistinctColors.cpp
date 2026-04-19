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
vector<int> adj[mxN];
int a[mxN];
int ans[mxN];
set<int> mp[mxN];
void dfs(int pos,int par = -1)
{
    mp[pos].insert(a[pos]);
    for(auto it : adj[pos])
    {
        if(it != par)
        {
            dfs(it, pos);
            if(mp[it].size() > mp[pos].size()) swap(mp[it], mp[pos]);
            for(auto x : mp[it])
            {
                mp[pos].insert(x);
            }
        }
    }
    ans[pos] = mp[pos].size();
}
void solve()
{
    int n;
    cin >> n;
    for(int i = 0;n > i;i++) cin >> a[i];
    for(int i = 0;n - 1 > i;i++)
    {
        int x,y;
        cin >> x >> y;
        x--,y--;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    dfs(0);
    for(int i = 0;n > i;i++) cout << ans[i] << endl;
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