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
struct custom_hash
{
    size_t operator()(int x) const
    {
        static const int RAND = 2172636713672112389LL;
        return ((x ^ RAND) ^ (x >> 23LL));
    }
};
const int mxN = 2e5 + 7;
int tree[4 * mxN];
void upd(int pos1,int val,int l,int r,int pos = 1)
{
    if(l > r) return;
    if(l == r)
    {
        tree[pos] = val;
        return;
    }
    int mid = (l + r) / 2;
    if(pos1 > mid) upd(pos1, val,mid + 1, r, pos * 2 + 1);
    else upd(pos1, val,l, mid, pos * 2);
    tree[pos] = min(tree[pos * 2], tree[pos * 2 + 1]);
}
int query(int tl,int tr,int l,int r,int pos = 1)
{
    if(l > r || tl > tr || tl > r || l > tr) return INF;
    if(tr >= r && l >= tl) return tree[pos];
    int mid = (l + r) / 2;
    return min(query(tl, tr,mid + 1, r, pos * 2 + 1), query(tl, tr ,l, mid, pos * 2));
}
void solve()
{
    int n,q;
    cin >> n >> q;
    int a[n];
    unordered_map<int, set<int>, custom_hash> mp;
    for(int i = 0;n > i;i++) cin >> a[i], mp[a[i]].insert(i);
    for(int i = 0;n > i;i++)
    {
        if(mp[a[i]].upper_bound(i) == mp[a[i]].end()) upd(i, INF, 0, n - 1);
        else upd(i, *mp[a[i]].upper_bound(i), 0, n - 1);
    }
    while(q--)
    {
        int op;
        cin >> op;
        if(op == 1)
        {
            int k, u;
            cin >> k >> u;
            k--;
            if(a[k] == u) continue;
            if(mp[a[k]].lower_bound(k) != mp[a[k]].begin())
            {
                int bef = *(--mp[a[k]].lower_bound(k));
                int nxt = INF;
                if(mp[a[k]].upper_bound(k) != mp[a[k]].end()) nxt = *mp[a[k]].upper_bound(k);
                upd(bef, nxt, 0, n - 1);
            }
            mp[a[k]].erase(k);
            a[k] = u;
            mp[a[k]].insert(k);
            if(mp[a[k]].lower_bound(k) != mp[a[k]].begin())
            {
                int bef = *(--mp[a[k]].lower_bound(k));
                upd(bef, k, 0, n - 1);
            }
            if(mp[a[k]].upper_bound(k) != mp[a[k]].end())
            {
                int nxt = *mp[a[k]].upper_bound(k);
                upd(k, nxt, 0, n - 1);
            }
            else upd(k, INF, 0, n - 1);
            
        }
        else
        {
            int l, r;
            cin >> l >> r;
            l--,r--;
            if(query(l, r, 0, n - 1) > r)
            {
                cout << "YES" << endl;
            }
            else
            {
                cout << "NO" << endl;
            }
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