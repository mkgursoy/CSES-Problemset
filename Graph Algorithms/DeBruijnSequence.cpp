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
const int mxN = 17;
vector<int> adj[(1LL << mxN)];
vector<int> order;
void dfs(int pos)
{
    while(adj[pos].size())
    {
        auto k = adj[pos].back();
        adj[pos].pop_back();
        dfs(k);
    }
    order.push_back(pos % 2);
}
void solve()
{
    int n;
    cin >> n;
    if(n == 1)
    {
        cout << "10" << endl;
        return;
    }
    vector<ar<int,2>> edg;
    for(int i = 0;(1LL << (n - 1)) > i;i++)
    {
        edg.push_back({i, ((i >> 1LL) | (1LL << (n - 2)))});
        edg.push_back({i, (i >> 1LL)});
    }
    for(auto [x, y] : edg)
    {
        adj[x].push_back({y});
    }
    for(int i = 0;n - 2 > i;i++) order.push_back(0);
    dfs(0);
    for(auto it : order) cout << it;
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