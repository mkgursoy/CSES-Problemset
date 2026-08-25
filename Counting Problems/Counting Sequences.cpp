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
        if(y & 1) res = mul(res, x, mod), y--;
        else x = mul(x, x, mod), y >>= 1;
    }

    return res;
}

int inv(int x,int mod = MOD)
{
    return binpow(x, mod - 2, mod);
}
const int mxN = 1e6 + 7;
int fact[mxN], inv_fact[mxN];
void fp()
{
    fact[0] = 1;
    for (int i = 1;mxN > i;i++) fact[i] = mul(i, fact[i - 1]);
    inv_fact[mxN - 1] = inv(fact[mxN - 1]);
    for (int i = mxN - 2;i >= 0;i--) inv_fact[i] = mul(i + 1, inv_fact[i + 1]);
}
int comb(int a,int b)
{
    return mul(fact[a], mul(inv_fact[b], inv_fact[a - b])); 
}
void solve()
{
    int n, k;
    cin >> n >> k;
    int ans = 0;
    for (int i = k;i >= 0;i--)
    {
        int coeff = ((k - i) & 1) ? -1LL : 1LL;
        ans = sum(ans, mul(coeff, mul(comb(k, i), binpow(i, n))));
    }
    cout << ans << endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    
    int tt = 1;
    
    fp();

    while(tt--) solve();
}
