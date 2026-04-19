/*
    Author: Matkap (prefix_sum)
*/

#include <bits/stdc++.h>
#include <array>

using namespace std;

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
int k;
int sz[mxN];
vector<int> adj[mxN];
int rem[mxN];
long long cnt[mxN];
long long ans = 0;
int mx = 0;
void find_size(int pos, int par = -1)
{
    sz[pos] = 1;
    for(auto it : adj[pos])
    {
        if(it != par && !rem[it])
        {
            find_size(it, pos);
            sz[pos] += sz[it];
        }
    }
}
int find_centroid(int pos,int siz,int par = -1)
{
    for(auto it : adj[pos])
    {
        if(it != par && !rem[it])
        {
            if(sz[it] >= siz / 2) return find_centroid(it,siz,pos);
        }
    }
    return pos;
}
void update_dists(int pos,int par,bool mode, int depth = 1)
{
    if(depth > k) return;
    mx = max(mx, depth);
    if(mode) cnt[depth] += 1;
    else ans += cnt[k - depth];
    for(auto it : adj[pos])
    {
        if(it != par && !rem[it])
        {
            update_dists(it,pos,mode,depth + 1);
        }
    }
}
void build_decomp(int pos)
{
    find_size(pos);
    int centroid = find_centroid(pos,sz[pos]);
    rem[centroid] = 1;
    mx = 0;
    for(auto it : adj[centroid])
    {
        if(!rem[it]) update_dists(it, centroid, false), update_dists(it, centroid, true);
    }
    ans += cnt[k];
    fill(cnt, cnt + mx + 1, 0);
    for(auto it : adj[centroid])
    {
        if(!rem[it]) build_decomp(it);
    }
}
void solve()
{
    int n;
    cin >> n;
    cin >> k;
    for(int i = 0;n - 1 > i;i++)
    {
        int x,y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    build_decomp(1);
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