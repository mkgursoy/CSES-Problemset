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
int par[mxN];
int sz[mxN];
int mx = 0;
int cnt;
int find(int a)
{
    if(par[a] == a) return a;
    return par[a] = find(par[a]);
}
bool union_sets(int a,int b)
{
    a = find(a);
    b = find(b);
    if(a == b) return false;
    if(sz[a] > sz[b]) swap(a, b);
    par[a] = b;
    sz[b] += sz[a];
    mx = max(mx, sz[b]);
    cnt--;
    return true;
}
void solve()
{
    int n, m;
    cin >> n >> m;
    cnt = n;
    iota(par,par + mxN, 0);
    fill(sz,sz + mxN, 1);
    vector<ar<int,3>> edg;
    while(m--)
    {
        int x,y;
        cin >> x >> y;
        union_sets(x, y);
        cout << cnt << " " << mx << endl;
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