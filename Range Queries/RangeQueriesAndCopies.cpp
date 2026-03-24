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
struct PersistentSegTree
{
    struct Node
    {
        int val;
        Node *left, *right;
        Node() : val(0), left(nullptr), right(nullptr) {}
        Node(Node* l,Node* r)
        {
            val = 0;
            left = l;
            right = r;
            if(l) val += l->val;
            if(r) val += r->val;
        }
        Node(Node* old_root) 
        {
            left = old_root->left;
            right = old_root->right;
            val = old_root->val;
        }
        Node(int _val) : val(_val) {}
    };
    vector<Node*> tree;
    PersistentSegTree()
    {
        tree.resize(200007);
    }
    Node* Build(int l,int r,int* a)
    {
        if(l == r) return new Node(a[l]);
        int mid = (l + r) / 2;
        return new Node(Build(l,mid,a),Build(mid + 1,r,a));
    }
    Node* Update(int pl,int value,int l,int r,Node* pos)
    {
        if(l == r) return new Node(value);
        int mid = (l + r) / 2;
        if(pl > mid) return new Node(pos->left,Update(pl,value,mid + 1,r,pos->right));
        else return new Node(Update(pl,value,l,mid,pos->left),pos->right);
    }
    int Query(int tl,int tr,int l,int r,Node* pos)
    {
        if(l > r || tl > tr || tl > r || l > tr) return 0;
        if(tr >= r && l >= tl) return pos->val;
        int mid = (l + r) / 2;
        return Query(tl,tr,l,mid,pos->left) + Query(tl,tr,mid + 1,r,pos->right);
    }
    Node* Set(Node* val)
    {
        return new Node(val);
    }
};
void solve()
{
    int n,q;
    cin >> n >> q;
    PersistentSegTree pst;
    int a[n];
    int sz = 0;
    for(int i = 0;n > i;i++)
    {
        cin >> a[i];
    }
    pst.tree[++sz] = pst.Build(0,n - 1,a);
    while(q--)
    {
        int op;
        cin >> op;
        //op = 4;
        if(op == 1)
        {
            int i,l,r;
            cin >> i >> l >> r;
            l--;
            pst.tree[i] = pst.Update(l,r,0,n - 1,pst.tree[i]);
        }
        if(op == 2)
        {
            int i,l,r;
            cin >> i >> l >> r;
            l--,r--;
            cout << pst.Query(l,r,0,n-1,pst.tree[i]) << endl;
        }
        if(op == 3)
        {
            int k;
            cin >> k;
            pst.tree[++sz] = pst.Set(pst.tree[k]);
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