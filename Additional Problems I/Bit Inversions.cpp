#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) x.begin(), x.end()
#define ar array

const int MOD = 1e9 + 7, INF = 1e17;

int sum(int x,int y,int mod = MOD)
{
    return (x + y + mod) % mod;
}

int mul(int x,int y,int mod = MOD)
{
    return x * 1LL * y % mod;
}

int binpow(int x,int y,int mod = MOD)
{
    int res = 1;

    while (y)
    {
        if (y & 1) res = mul(res, x, mod), y--;
        else x = mul(x, x, mod), y >>= 1;
    }

    return res;
}

int inv(int x,int mod = MOD)
{
    return binpow(x, mod - 2, mod);
}
struct Node
{
    int lft, rgt, mx, l, r;
    Node()
    {
        lft = rgt = mx = 1;
        l = r = 0;
    }
    Node(int _lft, int _rgt, int _mx, int _l,int _r)
    {
        lft = _lft;
        rgt = _rgt;
        mx = _mx;
        l = _l;
        r = _r;
    }
};

const int mxN = 2e5 + 7;
Node tree[mxN * 4];
string a;
Node F(Node L, Node R)
{
    Node A;
    if(L.lft == L.r - L.l + 1 && a[L.r] == a[R.l]) A.lft = L.lft + R.lft;
    else A.lft = L.lft;

    if(R.rgt == R.r - R.l + 1 && a[L.r] == a[R.l]) A.rgt = R.rgt + L.rgt;
    else A.rgt = R.rgt;

    A.mx = max(L.mx, R.mx);

    if(a[L.r] == a[R.l]) A.mx = max(A.mx, L.rgt + R.lft);

    A.l = L.l, A.r = R.r;

    return A;
}
void update(int pos1,int l,int r,int pos = 1)
{
    if(l > r) return;
    if(l == r)
    {
        tree[pos] = Node(1, 1, 1, l, r);
        return;
    }
    int mid = (l + r) / 2;
    if(pos1 > mid) update(pos1, mid + 1, r, pos * 2 + 1);
    else update(pos1, l, mid, pos * 2);

    tree[pos] = F(tree[pos * 2], tree[pos * 2 + 1]);
}
int query()
{
    return tree[1].mx;
}
void solve()
{
    cin >> a;
    int n = a.size();
    for(int i = 0;n > i;i++) 
    {
        update(i, 0, n - 1);
    }
    int q;
    cin >> q;
    while(q--)
    {
        int x;
        cin >> x;
        x--;
        a[x] = '0' + ((a[x] - '0') ^ 1);
        update(x, 0, n - 1);
        cout << query() << " ";
    }
    cout << endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    
    int tt = 1;
    
    while(tt--) solve();

    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
}
