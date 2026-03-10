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
void solve()
{
    int n,m;
    cin >> n >> m;
    vector<ar<int,2>> adj[n];
    vector<ar<int,2>> rev_adj[n];
    vector<ar<int,3>> edg;
    for(int i = 0;m > i;i++)
    {
        int x,y,z;
        cin >> x >> y >> z;
        x--,y--;
        adj[x].push_back({y,z});
        rev_adj[y].push_back({x,z});
        edg.push_back({x,y,z});
    }
    int dist_st[n],dist_en[n];
    fill(dist_en,dist_en + n,INF);
    fill(dist_st,dist_st + n,INF);
    dist_en[n - 1] = 0;
    dist_st[0] = 0;
    priority_queue<ar<int,2>,vector<ar<int,2>>,greater<ar<int,2>>> pq;
    pq.push({0,0});
    int sz = 1;
    while(pq.size() && n > sz)
    {
        auto [dist,pos] = pq.top();
        pq.pop();
        for(auto it : adj[pos])
        {
            if(dist_st[it[0]] > dist + it[1])
            {
                dist_st[it[0]] = dist + it[1];
                pq.push({dist_st[it[0]], it[0]});
                sz++;
            }
        }
    }
    priority_queue<ar<int,2>,vector<ar<int,2>>,greater<ar<int,2>>> pq1;
    pq1.push({0,n - 1});
    sz = 1;
    while(pq1.size() && n > sz)
    {
        auto [dist, pos] = pq1.top();
        pq1.pop();
        for(auto it : rev_adj[pos])
        {
            if(dist_en[it[0]] > dist + it[1])
            {
                dist_en[it[0]] = dist + it[1];
                pq1.push({dist_en[it[0]], it[0]});
                sz++;
            }
        }
    }
    int ans = INF;
    for(auto [u,v,z] : edg)
    {
        if(dist_st[u] != INF && dist_en[v] != INF)
        {
            ans = min(ans, dist_st[u] + dist_en[v] + (int)(z / 2));
        }
    }
    cout << ans << endl;
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