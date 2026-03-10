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
vector<int> order;
void dfs(int pos)
{
    while(adj[pos].size())
    {
        int k = adj[pos].back();
        adj[pos].pop_back();
        dfs(k);
    }
    order.push_back(pos);
}
void solve()
{
    int n;
    cin >> n;
    int m;
    cin >> m;
    int in[n + 1];
    int out[n + 1];
    memset(in,0,sizeof(in)), memset(out,0,sizeof(out));
    for(int i = 0;m > i;i++)
    {
        int x,y;
        cin >> x >> y;
        adj[x].push_back(y);
        in[y]++;
        out[x]++;
    }
    for(int i = 2;n > i;i++)
    {
        if(out[i] != in[i])
        {
            cout << "IMPOSSIBLE" << endl;
            return;
        }
    }
    if(out[1] != in[1] + 1 || out[n] + 1 != in[n])
    {
        cout << "IMPOSSIBLE" << endl;
        return;
    }
    dfs(1);
    if(order.size() != m + 1 || order[0] != n)
        cout << "IMPOSSIBLE" << endl;
    else
    {
        reverse(all(order));
        for(auto it : order) cout << it << " ";
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