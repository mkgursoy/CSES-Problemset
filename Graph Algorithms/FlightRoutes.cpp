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
priority_queue<int> dist[mxN];
vector<ar<int,2>> adj[mxN];
void solve()
{
    int n,m,k;
    cin >> n >> m >> k;
    priority_queue<ar<int,2>,vector<ar<int,2>>,greater<ar<int,2>>> pq;
    for(int i = 0;m > i;i++)
    {
        int x,y,z;
        cin >> x >> y >> z;
        x--,y--;
        adj[x].push_back({y, z});
    }
    dist[0].push(0);
    pq.push({0, 0});
    while(pq.size())
    {
        auto [dist_piv, piv] = pq.top();
        pq.pop();
        if(dist_piv > dist[piv].top()) continue;
        for(auto [it, dist_it] : adj[piv])
        {
            if(dist[it].size() < k)
            {
                pq.push({dist_it + dist_piv, it});
                dist[it].push(dist_it + dist_piv);
            }
            else
            {
                if((dist[it].top()) > dist_it + dist_piv)
                {
                    dist[it].pop();
                    dist[it].push(dist_it + dist_piv);
                    pq.push({dist_it + dist_piv, it});
                }
            }
        }
    }
    vector<int> vec;
    while(dist[n - 1].size())
    {
        vec.push_back(dist[n - 1].top());
        dist[n - 1].pop();
    }
    reverse(all(vec));
    for(auto it : vec) cout << it << " ";
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