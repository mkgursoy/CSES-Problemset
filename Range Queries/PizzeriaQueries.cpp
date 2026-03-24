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
struct SegmentTree
{
    int sz;
    vector<int> tree;
    SegmentTree(int _sz) : sz(_sz) 
    {
        tree.resize(_sz * 4 + 7);
        fill(all(tree),INF);
    }
    void Update(int val_pos,int val,int l,int r,int pos = 1)
    {
        if(l > r) return;
        if(l == r)
        {
            tree[pos] = val;
            return;
        }
        int mid = (l + r) / 2;
 
        if(mid >= val_pos)
            Update(val_pos,val,l,mid,pos * 2);
        else
            Update(val_pos,val,mid + 1,r,pos * 2 + 1);
 
        tree[pos] = min(tree[pos * 2 + 1],tree[pos * 2]);
    }
    int Query(int l1,int r1,int l,int r,int pos = 1)
    {
        if(l > r || l1 > r || l > r1) return INF;
        if(r1 >= r && l >= l1)
        {
            return tree[pos];
        }
        int mid = (l + r) / 2;
        return min(Query(l1,r1,l,mid,pos * 2),Query(l1,r1,mid + 1,r,pos * 2 + 1));
    }
 
};
void solve()
{
    int n,q;
    cin >> n >> q;
    int a[n];
    for(int i = 0;n > i;i++)
    {
        cin >> a[i];
    }
    SegmentTree up(n + 4);
    SegmentTree down(n + 4);
    for(int i = 0;n > i;i++)
    {
        up.Update(i,a[i] + i,0,n-1);
        down.Update(i,a[i] - i,0,n-1);
    }
    while(q--)
    {
        int op;
        cin >> op;
        if(op == 1)
        {
            int i,b;
            cin >> i >> b;
            i--;
            a[i] = b;
            up.Update(i,a[i] + i,0,n - 1);
            down.Update(i,a[i] - i,0,n - 1);
        }
        if(op == 2)
        {
            int i;
            cin >> i;
            i--;
            int u = INF;
            int d = INF;
            u = up.Query(i,n - 1,0,n - 1) - i;
            d = i + down.Query(0, i,0,n - 1);
            cout << min(u,d) << endl;
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