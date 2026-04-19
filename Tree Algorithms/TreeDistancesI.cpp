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
int best_dist = 0,right_side = 0;
int dist_left[mxN],dist_right[mxN];
bool lefty = true;
void dfs(int pos,int par = -1,int dist = 0)
{
    if(dist > best_dist) best_dist = dist,right_side = pos;
    if(lefty) dist_left[pos] = dist;
    else dist_right[pos] = dist;
    for(auto it : adj[pos])
    {
        if(it != par)
        {
            dfs(it,pos,dist + 1);
        }
    }
}
void solve()
{
    int n;
    cin >> n;
    for(int i = 0;n - 1 > i;i++)
    {
        int x,y;
        cin >> x >> y;
        x--,y--;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    dfs(0);
    best_dist = 0;
    dfs(right_side);
    best_dist = 0;
    lefty = false;
    dfs(right_side);
    for(int i = 0;n > i;i++) cout << max(dist_left[i], dist_right[i]) << " ";
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