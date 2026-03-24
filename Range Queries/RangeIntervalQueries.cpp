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
int tree[mxN];
void upd(int pos,int val)
{
    for(pos++;mxN > pos;pos += (pos & -pos)) tree[pos] += val;
}
int query(int l,int r)
{
    int res = 0;
    for(r++;r ;r -= (r & -r)) res += tree[r];
    for( ;l ;l -= (l & -l)) res -= tree[l];
    return res;
}
void solve()
{
    int n, q;
    cin >> n >> q;
    int a[n];
    vector<int> compress;
    for(int i = 0;n > i;i++) cin >> a[i], compress.push_back(a[i]);
    vector<ar<int,5>> queries(q);
    int t = 0;
    for(auto& [l, r, i, j, k] : queries)
    {
        int l_, r_, i_, j_;
        cin >> l_ >> r_ >> i_ >> j_;
        l_--, r_--;
        k = t++;
        l = l_, r = r_, i = i_, j = j_;
        compress.push_back(i), compress.push_back(j);
    }
    t = compress.size();
    sort(compress.begin(), compress.end());
    compress.erase(unique(compress.begin(), compress.end()), compress.end());
    for(auto& [l, r, i, j, k] : queries) i = lower_bound(all(compress), i) - compress.begin(),j = lower_bound(all(compress), j) - compress.begin();
    int ans[q];
    memset(ans,0,sizeof(ans));
    memset(tree,0,sizeof(tree));
    vector<int> ind[t];
    for(int i = 0;n > i;i++)
    {
        ind[lower_bound(all(compress), a[i]) - compress.begin()].push_back(i);
    }
    int cur = t;
    for(auto& [l, r, i, j, k] : queries) swap(l, i);
    sort(all(queries),greater<>());
    for(auto& [l, r, i, j, k] : queries) swap(l, i);
    for(auto [l, r, i, j, k] : queries)
    {
        while(cur > i)
        {
            cur--;
            for(auto it : ind[cur])
            {
                upd(it, 1LL);
            }
        }
        ans[k] += query(l, r);
    }
    cur = t;
    memset(tree,0,sizeof(tree));
    for(auto& [l, r, i, j, k] : queries) swap(l, j);
    sort(all(queries),greater<>());
    for(auto& [l, r, i, j, k] : queries) swap(l, j);
    for(auto [l, r, i, j, k] : queries)
    {
        while(cur > j + 1)
        {
            cur--;
            for(auto it : ind[cur])
            {
                upd(it, 1LL);
            }
        }
        ans[k] -= query(l, r);
    }
    for(auto it : ans) cout << it << endl;
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