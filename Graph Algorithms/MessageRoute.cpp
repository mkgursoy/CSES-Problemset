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
    vector<int> adj[n];
    int dist[n];
    int prev[n];
    int vis[n];
    memset(vis,0,sizeof(vis));
    vis[0] = 1;
    for(int i = 0;n > i;i++) dist[i] = INF;
    for(int i = 0;m > i;i++)
    {
        int x,y;
        cin >> x >> y;
        x--,y--;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    priority_queue<ar<int,2>,vector<ar<int,2>>,greater<ar<int,2>>> pq;
    pq.push({0,0});
    dist[0] = 0;
    prev[0] = -1;
    while(pq.size())
    {
        ar<int,2> piv = pq.top();
        pq.pop();
        for(auto it : adj[piv[1]])
        {
            if(dist[it] > piv[1] + 1)
            {
                prev[it] = piv[1];
                dist[it] = piv[0] + 1;
                if(vis[it] == 0)
                {
                    pq.push({dist[it],it}) , vis[it] = 1;
                } 
            }
        }
    }
    if(dist[n-1] == INF)
    {
        cout << "IMPOSSIBLE" << endl;
        return;
    }
    vector<int> ans;
    for(int i = n - 1;i >= 0;i = prev[i])
    {
        ans.push_back(i + 1);
    }
    reverse(all(ans));
    cout << ans.size() << endl;
    for(auto it : ans) cout << it << " ";
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int tt;
    tt=1; 
  //  cin >> tt;
    while(tt--) solve();
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
}