/*
    Author: Matkap (prefix_sum)
*/

#include <bits/stdc++.h>
#include <array>

using namespace std;

#define int long long
#define ar array
#define all(x) x.begin(),x.end()
#define endl "\n"

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
const int mxN = 1005;
int tree[mxN][mxN];
int n;
void upd(int x,int y,int op)
{
    for(int i = x;n >= i;i += i & -i) for(int j = y;n >= j;j += j & -j) tree[i][j] += op;
}
int que(int x,int y)
{
    int res = 0;
    for(int i = x;i ;i -= i & -i) for(int j = y;j ;j -= j & -j) res += tree[i][j];
    return res;
}
void solve()
{
    int q;
    cin >> n >> q;
    string s[n];
    for(auto&it : s) cin >> it;
    for(int i = 0;n > i;i++)
    {
        for(int j = 0;n > j;j++)
        {
            if(s[i][j] == '*') upd(i + 1, j + 1, 1);
        }
    }
    while(q--)
    {
        int op;
        cin >> op;
        int i,j;
        cin >> i >> j;
        if(op == 1)
        {
            if(s[i - 1][j - 1] == '*') s[i - 1][j - 1] = '.', upd(i, j, -1);
            else if(s[i - 1][j - 1] == '.') s[i - 1][j - 1] = '*', upd(i, j, 1);
        }
        if(op == 2)
        {
            int i1, j1;
            cin >> i1 >> j1;
            cout << que(i1, j1) - que(i - 1, j1) - que(i1, j - 1) + que(i - 1,j - 1) << endl; 
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