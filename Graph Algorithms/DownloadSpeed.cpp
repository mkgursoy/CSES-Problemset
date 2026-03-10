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
const int mxN = 5e2 + 7;
vector<int> adj[mxN];
int cap[mxN][mxN];
int par[mxN];
void solve()
{
    int n, m;
    cin >> n >> m;
    while(m--)
    {
        int x,y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
        int z;
        cin >> z;
        cap[x][y] += z;
    }
    auto canGo = [&]() -> bool
    {
        memset(par,-1,sizeof(par));
        queue<int> q;
        q.push(1);
        while(q.size())
        {
            int p = q.front(); q.pop();
            for(auto it : adj[p])
            {
                if(cap[p][it] > 0 && par[it] == -1)
                {
                    par[it] = p;
                    q.push(it);
                }
            }
        }
        if(par[n] != -1)
            return true;
        else
            return false;
    };
    int flow = 0;
    while(canGo())
    {
        int mn = INF;
        for(int i = n;i != 1;i = par[i])
        {
            mn = min(mn, cap[par[i]][i]);
        }
        for(int i = n;i != 1;i = par[i])
        {
            cap[i][par[i]] += mn;
            cap[par[i]][i] -= mn;
        }
        flow += mn;
    }
    cout << flow << endl;
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