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
    vector<int> tree,lazy;
    SegmentTree(int _sz) : sz(_sz) 
    {
        tree.resize(_sz * 4 + 7);
        lazy.resize(_sz * 4 + 7);
    }
    void Update(int l1,int r1,int val,int l,int r,int pos = 1)
    {
        tree[pos] += lazy[pos];
        if(l != r)
        {
            lazy[pos * 2] += lazy[pos];
            lazy[pos * 2 + 1] += lazy[pos];
        }
        lazy[pos] = 0;
        if(l > r || l1 > r || l > r1) return;
        if(r1 >= r && l >= l1)
        {
            tree[pos] += val;
            if(l != r)
            {
                lazy[pos * 2] += val;
                lazy[pos * 2 + 1] += val;
            }
            return;
        }
        int mid = (l + r) / 2;
        Update(l1,r1,val,l,mid,pos * 2);
        Update(l1,r1,val,mid + 1,r,pos * 2 + 1);
        tree[pos] = max(tree[pos * 2 + 1],tree[pos * 2]);
    }
    int Query(int l1,int r1,int l,int r,int pos = 1)
    {
        tree[pos] += lazy[pos];
        if(l != r)
        {
            lazy[pos * 2] += lazy[pos];
            lazy[pos * 2 + 1] += lazy[pos];
        }
        lazy[pos] = 0;
        if(l > r || l1 > r || l > r1) return -INF;
        if(r1 >= r && l >= l1)
        {
            return tree[pos];
        }
        int mid = (l + r) / 2;
        return max(Query(l1,r1,l,mid,pos * 2),Query(l1,r1,mid + 1,r,pos * 2 + 1));
    }
 
};
struct FenwickTree
{
    vector<int> tree;
    FenwickTree(int _sz)
    {
        tree.resize(_sz * 2);
    }
    void Update(int pos,int n,int val)
    {
        for(pos++;n >= pos;pos += pos&-pos) tree[pos] += val;
    }
    int Query(int pos)
    {
        int res = 0;
        for(pos++;pos > 0;pos -= pos&-pos) res += tree[pos];
        return res;
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
    SegmentTree st(n);
    FenwickTree ft(n);
    for(int i = 0;n > i;i++)
    {
        st.Update(i,n - 1,a[i],0,n - 1);
        ft.Update(i,n,a[i]);
    }
    while(q--)
    {
        int op;
        cin >> op;
        if(op == 1)
        {
            int k,u;
            cin >> k >> u;
            k--;
            st.Update(k,n - 1,-a[k],0,n - 1);
            ft.Update(k,n,-a[k]);
            a[k] = u;
            ft.Update(k,n,a[k]);
            st.Update(k,n - 1,a[k],0,n - 1);
        }
        if(op == 2)
        {
            int a,b;
            cin >> a >> b;
            a--,b--;
            cout << max(0LL,st.Query(a,b,0,n - 1) - ft.Query(a - 1)) << endl;
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