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
const int mxN = 2e5 + 7, mxLog = 20;
int sparse[mxLog][mxN];
int lg[mxN + 7];
int a[mxN];
int find(int l,int r)
{
    if(l == r) return a[l - 1];
    for(int i = 0;mxLog >= i;i++)
    {
        if(l + (1 << i) > r)
        {
            return min(sparse[i - 1][l] , find(l + (1LL << (i - 1)) , r));
        }
    }
    return min(sparse[mxLog - 1][l] , find(l + (1LL << (mxLog - 1)) , r));
}
void solve()
{
    int n,q;
    cin >> n >> q;      
    for(int i = 0;n > i;i++) cin >> a[i];
    for(int i = 1;n >= i;i++) sparse[0][i] = a[i-1];
    for(int i = 1;mxLog >= i;i++)
    {
        for(int j = 1;j + (1 << i) <= mxN;j++)
        {
            sparse[i][j] = min(sparse[i - 1][j] , sparse[i - 1][j + (1LL << (i - 1))]);
        }
    }
    lg[1] = 0;
    for(int i = 2;mxN >= i; i++)
    {
        lg[i] = lg[i / 2] + 1;
    }
    while(q--)
    {
        int x,y;
        cin >> x >> y;
        if(x > y) swap(x, y);
        int i = lg[y - x + 1];
        cout << min(sparse[i][x], sparse[i][y - (1LL << i) + 1]) << endl;
    }
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int tt;
    tt=1; 
  //  cin >> tt;
    while(tt--) solve();
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
}