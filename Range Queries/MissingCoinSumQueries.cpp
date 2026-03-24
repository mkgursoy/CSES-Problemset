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
int32_t tree[2 * mxN][32];
void upd(int iki,int pos_upd,int val)
{
    pos_upd += mxN;
    tree[pos_upd][iki] = val;
    while(pos_upd > 1)
    {
        pos_upd >>= 1;
 
        tree[pos_upd][iki] = min(tree[pos_upd * 2][iki], tree[pos_upd * 2 + 1][iki]);
    }
}
int query(int iki, int tl, int tr)
{
    int32_t res = 1e9 + 7;
    tr += 1;
    for(tr += mxN, tl += mxN; tr > tl ;tr >>= 1, tl >>= 1)
    {
        if(tl & 1) res = min(res, tree[tl++][iki]);
        if(tr & 1) res = min(tree[--tr][iki], res);
    }
    return res;
}
void solve()
{
    int n, q;
    cin >> n >> q;
    int a[n];
    for(int i = 0;n > i;i++) cin >> a[i];
    int pref[n][32];
    for(int j = 0;32 > j;j++) for(int i = 0;2 * mxN > i;i++) tree[i][j] = 1e9 + 7;
    for(int j = 0;32 > j;j++)
    {
        int prev = 0;
        for(int i = 0;n > i;i++)
        {
            if((1LL << j) <= a[i] && a[i] < (1LL << (j + 1))) upd(j, i, a[i]);
            if((1LL << j) <= a[i] && a[i] < (1LL << (j + 1))) prev += a[i];
            pref[i][j] = prev;
        }
    } 
    while(q--)
    {
        int l,r;
        cin >> l >> r;
        r--, l--;
        int sum_current = 0;
        for(int j = 0;31 > j;j++)
        {
            if((1LL << (j + 1)) > sum_current + 1 && query(j, l, r) > sum_current + 1) break;
            sum_current += pref[r][j] - (l ? pref[l - 1][j] : 0LL);
        }
        cout << sum_current + 1 << endl;
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