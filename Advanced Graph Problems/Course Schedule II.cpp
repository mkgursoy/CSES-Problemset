#include <bits/stdc++.h>
#include <array>

using namespace std;

#define int long long
#define endl "\n"
#define ar array
#define all(x) x.begin(),x.end()

const int INF = 1e17 , MOD = 1e9 + 7;

int mul(int a,int b,int mod = MOD)
{
    a %= mod;
    b %= mod;
    return a * 1LL * b % mod;
}
int sum(int a,int b,int mod = MOD)
{
    a %= mod;
    b %= mod;
    return (a + b + mod) % mod;
}
int binpow(int base,int power,int mod = MOD)
{
    if(power == 1) return base;
    if(power == 0) return 1;
    
    if(power%2==1)
    {
         int a;    
         a = binpow(base,(power - 1)/2);
        return mul(base, mul(a, a, mod), mod);
    } 
    else
     {
        int a;
        a = binpow(base,power/2);
        return mul(a, a, mod);
    } 

}
int inv(int a,int mod = MOD)
{
    a %= mod;
    return binpow(a, mod - 2) % mod;
}
void solve()
{
    int n,m;
    cin >> n >> m;
    vector<int> adj[n];
    int deg[n];
    memset(deg,0,sizeof(deg));
    for(int i = 0;m > i;i++)
    {
        int x,y;
        cin >> x >> y;
        x--,y--;
        adj[y].push_back(x);
        deg[x]++;
    }
    priority_queue<int> pq;
    for(int i = 0;n > i;i++)
    {
        if(deg[i] == 0) pq.push(i);
    }
    vector<int> ans;
    while(pq.size())
    {
        int p = pq.top();
        pq.pop();
        ans.push_back(p + 1);
      
        for(auto it : adj[p])
        {
           
            deg[it]--;
            if(deg[it] == 0)
            {
                pq.push(it);
            }
        }
    }
    reverse(all(ans));
    for(auto it : ans) cout << it << endl;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int tt;
    tt=1; 
    
    while(tt--) solve();

}
