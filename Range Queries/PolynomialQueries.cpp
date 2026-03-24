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
    vector<ar<int,2>> lazy;
    SegmentTree(int _sz) : sz(_sz) 
    {
        tree.resize(_sz * 4 + 7);
        lazy.resize(_sz * 4 + 7);
    }
    void Update(int l1,int r1,int l,int r,int pos = 1)
    {
        if(l != r)
        {
            lazy[pos * 2][0] += lazy[pos][0];
            lazy[pos * 2 + 1][0] += lazy[pos][0];
        }
        if(l != r)
        {
            lazy[pos * 2][1] += lazy[pos][1];
            lazy[pos * 2 + 1][1] += lazy[pos][1];
        }
        tree[pos] += (lazy[pos][1] * (r - l + 1) * (r + l + 2)) / 2 - (r - l + 1) * lazy[pos][0];
        lazy[pos][1] = lazy[pos][0] = 0;
        if(l > r || l1 > r || l > r1) return;
        if(r1 >= r && l >= l1)
        {
            tree[pos] += (1LL * (r - l + 1) * (r + l + 2)) / 2 - (r - l + 1) * l1;
            if(l != r)
            {
                lazy[pos * 2][0] += l1;
                lazy[pos * 2 + 1][0] += l1;
                lazy[pos * 2][1]++;
                lazy[pos * 2 + 1][1]++;
            }
            return;
        }
        int mid = (l + r) / 2;
        Update(l1,r1,l,mid,pos * 2);
        Update(l1,r1,mid + 1,r,pos * 2 + 1);
        tree[pos] = tree[pos * 2] + tree[pos * 2 + 1];
    }
    int Query(int l1,int r1,int l,int r,int pos = 1)
    {
        if(l != r)
        {
            lazy[pos * 2][0] += lazy[pos][0];
            lazy[pos * 2 + 1][0] += lazy[pos][0];
        }
        if(l != r)
        {
            lazy[pos * 2][1] += lazy[pos][1];
            lazy[pos * 2 + 1][1] += lazy[pos][1];
        }
        tree[pos] += (lazy[pos][1] * (r - l + 1) * (r + l + 2)) / 2 - (r - l + 1) * lazy[pos][0];
        lazy[pos][1] = lazy[pos][0] = 0;
        if(l > r || l1 > r || l > r1) return 0;
        if(r1 >= r && l >= l1)
        {
            return tree[pos];
        }
        int mid = (l + r) / 2;
        return (Query(l1,r1,l,mid,pos * 2) + Query(l1,r1,mid + 1,r,pos * 2 + 1));
    }
 
};
void solve()
{
    int n,q;
    cin >> n >> q;
    SegmentTree st(n);
    int a1[n];
    for(int i = 0;n > i;i++)
    {
        cin >> a1[i];
        if(i)
        a1[i] += a1[i - 1];
    }
    while(q--)
    {
        int op;
        cin >> op;
        if(op == 1)
        {
            int a,b;
            cin >> a >> b;
            a--,b--;
            st.Update(a,b,0,n - 1,1);
        }
        if(op == 2)
        {
            int a,b;
            cin >> a >> b;
            a--,b--;
            cout << st.Query(a,b,0,n - 1,1) + a1[b] - (a ? a1[a - 1] : 0) << endl;
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