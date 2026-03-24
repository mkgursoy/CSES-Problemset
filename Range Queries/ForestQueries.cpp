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
void solve()
{
    int n,q;
    cin >> n >> q;
    string s[n];
    int pref[n + 1][n + 1];
    memset(pref,0,sizeof(pref));
    for(int i = 0;n > i;i++) cin >> s[i];
    for(int i = 1;n >= i;i++)
    {
        for(int j = 1;n >= j;j++)
        {
            pref[i][j] = pref[i - 1][j] + pref[i][j - 1] - pref[i - 1][j - 1] + (s[i - 1][j - 1] == '*');
        }
    }
    while(q--)
    {
        int i1,j1,i2,j2;
        cin >> i1 >> j1 >> i2 >> j2;
        cout << pref[i2][j2] - pref[i2][j1 - 1] - pref[i1 - 1][j2] + pref[i1 - 1][j1 - 1] << endl;
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