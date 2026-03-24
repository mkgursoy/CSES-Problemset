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
    struct Node
    {
        int subarray_sum;
        int left_sum;
        int right_sum;
        int whole_sum;
    };
    vector<Node> tree;
    SegmentTree(int _sz)
    {
        tree.resize(_sz * 8 + 7);
    }   
    Node F(Node l,Node r)
    {
        Node n;
        n.subarray_sum = max({l.subarray_sum,r.subarray_sum,l.right_sum + r.left_sum});
        n.left_sum = max(l.left_sum,l.whole_sum + r.left_sum);
        n.right_sum = max(r.right_sum,r.whole_sum + l.right_sum);
        n.whole_sum = l.whole_sum + r.whole_sum;
        return n;
    }
    void update(int pos1,int val,int l,int r,int pos = 1)
    {
        if(l > r) return;
        if(l == r)
        {
            tree[pos].subarray_sum = max(0ll,val);
            tree[pos].left_sum = max(0ll,val);
            tree[pos].whole_sum = val;
            tree[pos].right_sum = max(0ll,val);
            return;
        }
        int mid = (l + r) / 2;
        if(mid >= pos1)
        {
            update(pos1,val,l,mid,pos * 2);
        }
        else
        {
            update(pos1,val,mid + 1,r,pos * 2 + 1);
        }
        tree[pos] = F(tree[pos * 2], tree[pos * 2 + 1]);
    }
    int query()
    {
        return tree[1].subarray_sum;
    }
};
void solve()
{
    int n,q;
    cin >> n >> q;
    int a[n];
    SegmentTree st(n);
    for(int i = 0;n > i;i++) cin >> a[i],st.update(i,a[i],0,n - 1);
    while(q--)
    {
        int x,y;
        cin >> x >> y;
        x--;
        st.update(x,-a[x],0,n - 1);
        a[x] = y;
        st.update(x,a[x],0,n - 1);
        cout << st.query() << endl;
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