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
int k1, k2;
int sz[mxN];
vector<int> adj[mxN];
bool rem[mxN];
long long cnt[mxN];
long long cur[mxN];
long long tree[mxN];
long long ans = 0;
int mx = 0;
int n;
int x,y;
vector<int> changed;
void upd(int a,int add = 1)
{
    a++;
    for( ;n >= a;a += a & -a) tree[a] += add;
}
int quer(int a)
{
    int res = 0;
    a++;
    for( ;a > 0;a -= a & -a) res += tree[a];
    return res;
}
int find_size(int pos, int par = -1)
{
    sz[pos] = 1;
    for(auto it : adj[pos])
    {
        if(it != par && !rem[it])
        {
            sz[pos] += find_size(it, pos);
        }
    }
    return sz[pos];
}
int find_centroid(int pos,int siz,int par = -1)
{
    for(auto it : adj[pos])
    {
        if(it != par && !rem[it] && sz[it] >= siz / 2)
        {
            return find_centroid(it,siz,pos);
        }
    }
    return pos;
}
void update_dists(int pos,int par,int depth = 1)
{
    if(depth > k2) return;
    mx = max(mx, depth);
    cnt[depth]++;
    ans += quer(k2 - depth) - quer(k1 - depth - 1);
    for(auto it : adj[pos])
    {
        if(it != par && !rem[it])
        {
            update_dists(it,pos,depth + 1);
        }
    }
}
void build_decomp(int pos)
{
    int centroid = find_centroid(pos,find_size(pos));
    rem[centroid] = 1;
    int mx1 = 0;
    for(auto it : adj[centroid])
    {
        if(!rem[it])
        {
            mx = 0;
            update_dists(it, centroid);
            for(int i = 1;mx >= i;i++) upd(i, cnt[i]), cur[i] += cnt[i], cnt[i] = 0;
            mx1 = max(mx1, mx);
        } 
    }
    for(int i = 1;mx1 >= i;i++) upd(i, -cur[i]), cur[i] = 0;
    for(auto it : adj[centroid])
    {
        if(!rem[it]) build_decomp(it);
    }
}
void solve()
{
    cin >> n;
    cin >> k1 >> k2;
    for(int i = 0;n - 1 > i;i++)
    {
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    upd(0);
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