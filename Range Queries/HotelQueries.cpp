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
int hotel[mxN] , group[mxN];
int n,m;
int tree[4 * mxN];
void build(int pos,int l,int r)
{
    if(l > r) return;
    if(l == r)
    {
        tree[pos] = hotel[l-1];
        return;
    }
    int mid = (l + r) / 2;
    build(pos * 2,l,mid);
    build(pos * 2 + 1,mid + 1,r);
    tree[pos] = max(tree[pos * 2],tree[pos * 2 + 1]);
}
void ans(int x,int pos,int l,int r)
{
    if(l > r) return;
    if(l == r)
    {
        cout << l << endl;
        tree[pos] -= x;
        return;
    } 
    int mid = (l + r) / 2;
    if(tree[pos * 2] >= x) ans(x,pos * 2,l,mid);
    else ans(x,pos * 2 + 1,mid + 1,r);
    tree[pos] = max(tree[pos * 2] , tree[pos * 2 + 1]);
}
void solve()
{
    cin >> n >> m;
    for(int i = 0;n > i;i++) cin >> hotel[i];
    for(int i = 0;m > i;i++) cin >> group[i];
    build(1,1,n);
    
    for(int i = 0;m > i;i++)
    {
        if(tree[1] < group[i]) cout << "0" << endl;
        else ans(group[i] , 1 , 1 ,n);
    }
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