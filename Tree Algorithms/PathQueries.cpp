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
int heavy[mxN];
int tree[1LL << 21];
int head[mxN];
int sz[mxN];
int ind[mxN];
int a[mxN];
int depth[mxN];
int p[mxN];
int t = 1;
int n;
void upd(int pos,int val)
{
    tree[pos += n] = val;
    for(pos /= 2;pos;pos /= 2)
    {
        tree[pos] = tree[pos * 2] + tree[pos * 2 + 1];
    }
}
int que(int l,int r)
{
    int l_ans = 0,r_ans = 0;
    for(l += n,r += n + 1;r > l;l /= 2,r /= 2)
    {
        if(l % 2 == 1) l_ans += tree[l++];
        if(r % 2 == 1) r_ans += tree[--r];
    }
    return l_ans + r_ans;
}
void dfs(int pos,int par = -1)
{
    sz[pos] = 1;
    p[pos] = par;
    depth[pos] = depth[par] + 1;
    int mx_sz = 0;
    for(auto it : adj[pos])
    {
        if(it != par)
        {
            dfs(it,pos);
            sz[pos] += sz[it];
            if(mx_sz < sz[it])
            {
                heavy[pos] = it;
                mx_sz = sz[it];
            }
        }
    }
}
void decomp(int pos,int he,int par = -1)
{
    ind[pos] = t++;
    upd(ind[pos], a[pos]);
    head[pos] = he;
    if(heavy[pos] != -1) decomp(heavy[pos], he, pos);
    for(auto it : adj[pos])
    {
        if(it != par && it != heavy[pos]) decomp(it,it, pos);
    }
}
int findAns(int l,int r)
{
    int ans = 0;
    while(head[l] != head[r])
    {
        if(depth[head[l]] < depth[head[r]]) swap(l,r);
        ans += que(ind[head[l]], ind[l]);
        l = p[head[l]];
    }
    if(depth[l] > depth[r]) swap(l,r);
    ans += que(ind[l], ind[r]);
    return ans;
}
void solve()
{
    memset(heavy,-1,sizeof(heavy));
    depth[0] = 0;
    int q;
    cin >> n >> q;
    for(int i = 0;n > i;i++) cin >> a[i];
    for(int i = 0;n - 1 > i;i++)
    {
        int x,y;
        cin >> x >> y;
        x--,y--;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    dfs(0);
    decomp(0,0);
    while(q--)
    {
        int op;
        cin >> op;
        if(op == 1)
        {
            int s, x;
            cin >> s >> x;
            s--;
            a[s] = x;
            upd(ind[s], x);
        }
        else
        {
            int a,b;
            cin >> b;
            b--;
            a = 0;
            cout << findAns(a, b) << " ";
        }
    }
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