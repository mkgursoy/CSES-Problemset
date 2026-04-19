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
int tree[4 * mxN];
int n;
int tin[mxN], tout[mxN];
int timer = 0;
void upd(int x,int s)
{
    for( ;4 * mxN > x;x += x & -x) tree[x] += s;
}
int que(int a,int b)
{
    int res = 0;
    for( ;a ;a -= a & -a) res -= tree[a];
    a = b;
    for( ;a ;a -= a & -a) res += tree[a];   
    return res;
}
void dfs(int pos,int par1 = -1)
{
    tin[pos] = ++timer;
    for(auto it : adj[pos])
    {
        if(it != par1)
        {
            dfs(it,pos);
        }
    } 
    tout[pos] = ++timer;
}
void solve()
{
    int q;
    cin >> n >> q;
    int a[n];
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
    for(int i = 0;n > i;i++) upd(tin[i], a[i]);
    while(q--)
    {
        int op;
        cin >> op;
        if(op == 1)
        {
            int a1,b;
            cin >> a1 >> b;
            a1--;
            upd(tin[a1], -a[a1]);
            a[a1] = b;
            upd(tin[a1], a[a1]);
        }
        else
        {
            int c;
            cin >> c;
            c--;
            cout << que(tin[c] - 1, tout[c]) << endl;
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