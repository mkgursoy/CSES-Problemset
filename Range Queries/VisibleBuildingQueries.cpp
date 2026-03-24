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
const int mxN = 1e5 + 7;
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
    int p[n];
    p[0] = -1;
    for(int i = 0;n > i;i++) cin >> a[i];
    vector<int> ind[n + 1];
    ind[0].push_back(0);
    for(int i = 1;n > i;i++)
    {
        int tp = i - 1;
        while(tp != -1 && a[tp] < a[i])
        {
            tp = p[tp];
        }
        p[i] = tp;
        ind[tp + 1].push_back(i);
    }
    
    vector<ar<int,3>> que(q);
    int ans[q];
    int t = 0;
    for(auto& [i_, j_, k] : que)
    {
        int i,j;
        cin >> i >> j;
        i--,j--;
        i_ = i, j_ = j, k = t++;
    }
    sort(all(que));
    int cur = -1;
    for(auto [i, j, k] : que)
    {
        while(cur < i)
        {
            cur++;
            for(auto it : ind[cur])
            {
                upd(it, 1LL);
            }
        }
        ans[k] = query(i, j);
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