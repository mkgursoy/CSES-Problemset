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
const int mxN = 1e5 + 7;
int dist[mxN];
int vis[mxN];
void solve()
{
    int n,m;
    cin >> n >> m;
    vector<ar<int,2>> adj[n+1];
    while(m--)
    {
        int x,y,z;
        cin >> x >> y >> z;
        adj[x].push_back({y,z});
    }
    priority_queue<ar<int,2>,vector<ar<int,2>>,greater<ar<int,2>>> pq;
    pq.push({0,1});
    for(int i = 2;n >= i;i++) dist[i] = INF;
    dist[1] = 0;
    vis[1] = 0;     
    while(pq.size())
    {
        int piv = pq.top()[1]; 
        pq.pop();       
        if(vis[piv]) continue;
        vis[piv] = 1;
        for(auto it : adj[piv])
        {
            if(dist[it[0]] > dist[piv] + it[1])
            {
                dist[it[0]] = dist[piv] + it[1];
                pq.push({dist[it[0]],it[0]});
            }
        }
    }
    for(int i = 1;n >= i;i++) cout << dist[i] << " ";
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