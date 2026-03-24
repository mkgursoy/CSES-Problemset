/*
    Author: Matkap (prefix_sum)
*/

#include <bits/stdc++.h>
#include <array>

using namespace std;

#define int __int128
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
struct LazySegmentTree
{
    struct Node
    {
        int increment;
        int sett;
        Node()
        {
            sett = 0;
            increment = 0;
        }
    };
    vector<int> tree;
    vector<Node> lazy;
    int n;
    LazySegmentTree(int _n)
    {
        lazy.resize(4 * _n + 1);
        tree.resize(4 * _n + 7);
        n = _n;
    }
    void Update_Set(int tl,int tr,int val){Upd_Set(tl,tr,val,0,n-1);}
    void Update_Add(int tl,int tr,int val){Upd_Add(tl,tr,val,0,n-1);}
    int Query(int tl,int tr){return Q(tl,tr,0,n-1);}
    void Upd_Set(int tl,int tr,int val,int l,int r,int pos = 1)
    {
        if(lazy[pos].sett != 0)
        {
            tree[pos] = (r - l + 1) * lazy[pos].sett;
            if(l != r)
            {
                lazy[pos * 2].sett = lazy[pos].sett;
                lazy[pos * 2 + 1].sett = lazy[pos].sett;
                lazy[pos * 2].increment = 0;
                lazy[pos * 2 + 1].increment = 0;
            }
            lazy[pos].sett = 0;
        }
        tree[pos] += lazy[pos].increment * (r - l + 1);
        if(l != r)
        {
            lazy[pos * 2].increment += lazy[pos].increment;
            lazy[pos * 2 + 1].increment += lazy[pos].increment;
        }
        lazy[pos].increment = 0;
        if(l > r || tl > r || l > tr) return;
        if(tr >= r && l >= tl)
        {
            tree[pos] = val * (r - l + 1);
            if(l != r)
            {
                lazy[pos * 2].sett = val;
                lazy[pos * 2 + 1].sett = val;
                lazy[pos * 2].increment = 0;
                lazy[pos * 2 + 1].increment = 0;
            }
            return;
        }
        int mid = (l + r) / 2;
        Upd_Set(tl,tr,val,l,mid,pos * 2);
        Upd_Set(tl,tr,val,mid + 1,r,pos * 2 + 1);
        tree[pos] = tree[pos * 2] + tree[pos * 2 + 1];
    }
    void Upd_Add(int tl,int tr,int val,int l,int r,int pos = 1)
    {
        if(lazy[pos].sett != 0)
        {
            tree[pos] = (r - l + 1) * lazy[pos].sett;
            if(l != r)
            {
                lazy[pos * 2].sett = lazy[pos].sett;
                lazy[pos * 2 + 1].sett = lazy[pos].sett;
                lazy[pos * 2 + 1].increment = 0;
                lazy[pos * 2].increment = 0;
            }
            lazy[pos].sett = 0;
        }
        tree[pos] += lazy[pos].increment * (r - l + 1);
        if(l != r)
        {
            lazy[pos * 2].increment += lazy[pos].increment;
            lazy[pos * 2 + 1].increment += lazy[pos].increment;
        }
        lazy[pos].increment = 0;
        if(l > r || tl > r || l > tr) return;
        if(tr >= r && l >= tl)
        {
            tree[pos] += val * (r - l + 1);
            if(l != r)
            {
                lazy[pos * 2].increment += val;
                lazy[pos * 2 + 1].increment += val;
            }
            return;
        }
        int mid = (l + r) / 2;
        Upd_Add(tl,tr,val,l,mid,pos * 2);
        Upd_Add(tl,tr,val,mid + 1,r,pos * 2 + 1);
        tree[pos] = tree[pos * 2] + tree[pos * 2 + 1];
    }
    int Q(int tl,int tr,int l,int r,int pos = 1)
    {
        if(lazy[pos].sett != 0)
        {
            tree[pos] = (r - l + 1) * lazy[pos].sett;
            if(l != r)
            {
                lazy[pos * 2].sett = lazy[pos].sett;
                lazy[pos * 2 + 1].sett = lazy[pos].sett;
                lazy[pos * 2 + 1].increment = 0;
                lazy[pos * 2].increment = 0;
            }
            lazy[pos].sett = 0;
        }
        tree[pos] += lazy[pos].increment * (r - l + 1);
        if(l != r)
        {
            lazy[pos * 2].increment += lazy[pos].increment;
            lazy[pos * 2 + 1].increment += lazy[pos].increment;
        }
        lazy[pos].increment = 0;
        if(l > r || tl > r || l > tr) return 0;
        if(tr >= r && l >= tl) return tree[pos];
        int mid = (l + r)/2;
        return Q(tl,tr,l,mid,pos * 2) + Q(tl,tr,mid + 1,r,pos * 2 + 1);
    }
};
void solve()
{
    int64_t n,q;
    cin >> n >> q;
    LazySegmentTree lst(n);
    int64_t a[n];
    for(int i = 0;n > i;i++) cin >> a[i],lst.Update_Set(i,i,a[i]);
    while(q--)
    {
        int64_t op;
        cin >> op;
        if(op == 1)
        {
            int64_t x,y,z;
            cin >> x >> y >> z;
            x--,y--;
            lst.Update_Add(x,y,z);
        }
        if(op == 2)
        {
            int64_t x,y,z;
            cin >> x >> y >> z;
            x--,y--;
            lst.Update_Set(x,y,z);
        }
        if(op == 3)
        {
            int64_t x,y;
            cin >> x >> y;
            x--,y--;
            cout << (int64_t)lst.Query(x,y) << endl;
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