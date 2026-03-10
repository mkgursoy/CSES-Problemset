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
int num_ways[mxN], dist[mxN], max_edg[mxN], min_edg[mxN];
vector<ar<int,2>> adj[mxN];
void solve()
{
    int n,m;
    cin >> n >> m;
    priority_queue<ar<int,2>,vector<ar<int,2>>,greater<ar<int,2>>> pq;
    for(int i = 0;m > i;i++)
    {
        int x,y,z;
        cin >> x >> y >> z;
        x--,y--;
        adj[x].push_back({y, z});
    }
    dist[0] = 0;
    num_ways[0] = 1;
    min_edg[0] = 0;
    max_edg[0] = 0;
    for(int i = 1;n > i;i++) dist[i] = INF, num_ways[i] = 0, min_edg[i] = INF, max_edg[i] = -INF;
    pq.push({0, 0});
    while(pq.size())
    {
        auto [dist_piv, piv] = pq.top();
        pq.pop();
        for(auto [it, dist_it] : adj[piv])
        {
            if(dist_piv + dist_it < dist[it])
            {
                dist[it] = dist_piv + dist_it;
                pq.push({dist[it], it});
                num_ways[it] = num_ways[piv];
                min_edg[it] = min_edg[piv] + 1;
                max_edg[it] = max_edg[piv] + 1;
            }
            else if(dist_piv + dist_it == dist[it])
            {
                num_ways[it] = sum(num_ways[it], num_ways[piv]);
                min_edg[it] = min(min_edg[it],min_edg[piv] + 1);
                max_edg[it] = max(max_edg[it], max_edg[piv] + 1);
            }
        }
    }
    cout << dist[n - 1] << " " << num_ways[n - 1] << " " << min_edg[n - 1] << " " << max_edg[n - 1] << endl;
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