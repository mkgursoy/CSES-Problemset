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
int tree2[mxN];
void upd(int pos,int val)
{
    for(pos++; mxN > pos;pos += (pos&-pos)) tree[pos] = sum(tree[pos], val);
}
int q(int l,int r)
{
    int res = 0;
    for(r++; r; r -= (r&-r)) res = sum(res, tree[r]);
    for( ; l; l -= (l&-l)) res = sum(res, -tree[l]);
    return res;
}
void upd2(int pos,int val)
{
    for(pos++; mxN > pos;pos += (pos&-pos)) tree2[pos] = sum(tree2[pos], val);
}
int q2(int l,int r)
{
    int res = 0;
    for(r++; r; r -= (r&-r)) res = sum(res, tree2[r]);
    for( ; l; l -= (l&-l)) res = sum(res, -tree2[l]);
    return res;
}
int ch(char c)
{
    return (c - 'a' + 1);
}
void solve()
{
    int n, qq;
    cin >> n >> qq;
    int pow53[n], inv_pow53[n];
    pow53[0] = 1;
    inv_pow53[0] = 1;
    for(int i = 1;n > i;i++)
    {
        pow53[i] = mul(53LL, pow53[i - 1]);
        inv_pow53[i] = inv(pow53[i]);
    }
    string s, t;
    cin >> t;
    s = t;
    reverse(all(t));
    for(int i = 0;n > i;i++)
    {
        upd(i, mul(pow53[i], ch(s[i])));
    }
    for(int i = 0;n > i;i++)
    {
        upd2(i, mul(pow53[i], ch(t[i])));
    }
    while(qq--)
    {
        int op;
        cin >> op;
        if(op == 1)
        {
            char ups;
            int i;
            cin >> i >> ups;
            i--;
            upd(i, mul(-pow53[i], ch(s[i])));
            upd2(n - i - 1, mul(-pow53[n - i - 1], ch(t[n - i - 1])));
            s[i] = ups;
            t[n - i - 1] = ups;
            upd(i, mul(pow53[i], ch(s[i])));
            upd2(n - i - 1, mul(pow53[n - i - 1], ch(t[n - i - 1])));
        }
        if(op == 2)
        {
            int l, r;
            cin >> l >> r;
            l--,r--;
            int hsh_s = mul(q(l, r), inv_pow53[l]);
            int hsh_t = mul(q2(n - r - 1, n - l - 1), inv_pow53[n - r - 1]);
            if(hsh_s == hsh_t) cout << "YES" << endl;
            else cout << "NO" << endl;
        }
    }
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int tt;
    tt=1; 
  
    while(tt--) solve();
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
}
