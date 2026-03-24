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
int a[mxN];
int tree[4 * mxN];
int lazy[4 * mxN];
int n,q;
void build(int pos = 1,int l = 1,int r = n)
{
    if(l > r) return;
    if(l == r)
    {
        tree[pos] = a[l-1];
        return;
    } 
    int mid = (l + r) / 2;
    build(pos * 2,l,mid);
    build(pos * 2 + 1,mid+1,r);
    tree[pos] = tree[pos * 2] + tree[pos * 2 + 1];
}
void update(int il,int ir,int val,int pos = 1,int l = 1,int r = n)
{
    int mid = (l + r)/2;
    if(lazy[pos] > 0)
    {
        tree[pos] += lazy[pos] * (r - l + 1);
        if(l != r)
        {
            lazy[pos * 2] += lazy[pos];
            lazy[pos * 2 + 1] += lazy[pos];
        }   
        lazy[pos] = 0;
    }
    if(l > r || il > r || l > ir) return;

    if(ir >= r && l >= il)
    {
        lazy[pos] += val;
        return;
    }   
    update(il,ir,val,pos * 2,l,mid);
    update(il,ir,val,pos * 2 + 1,mid + 1,r);
    tree[pos] = tree[pos * 2] + tree[pos * 2 + 1];
}
int query(int tl,int tr,int pos = 1,int l = 1,int r = n)
{
    if(lazy[pos] > 0)
    {
        tree[pos] += lazy[pos] * (r - l + 1);   
        if(l != r)
        {
            lazy[pos * 2] += lazy[pos];
            lazy[pos * 2 + 1] += lazy[pos];
        }   
        lazy[pos] = 0;
    }
    if(l > r || tl > r || l > tr) return 0;
    if(tl <= l && r <= tr)
    {
        return tree[pos];
    } 
    int mid = (l + r) / 2;
    return query(tl,tr,pos * 2,l,mid) + query(tl,tr,pos * 2 + 1,mid + 1,r);
}
void solve()
{
    cin >> n >> q;
    for(int i = 0;n > i;i++) cin >> a[i];
    build();
    while(q--)
    {
        int x;
        cin >> x;
        if(x == 1)
        {
            int l,r,x;
            cin >> l >> r >> x;
            update(l,r,x);
        }
        if(x == 2)
        {
            int l;
            cin >> l;
            cout << query(l,l) << endl;
        }
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