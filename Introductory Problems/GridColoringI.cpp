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
    int n,m;
    cin >> n >> m;
    string a[n];
    for(auto& it : a) cin >> it;
    int p = 0;
    for(int i = 0;n > i;i++)
    {
        for(int j = 0;m > j;j++)
        {
            int fl[4];
            memset(fl,0,sizeof(fl));
            if(i) fl[(a[i - 1][j] - 'A')] = 1;
            if(j) fl[(a[i][j - 1] - 'A')] = 1;
            fl[(a[i][j] - 'A')] = 1;
            for(int k = 0;4 > k;k++)
            {
                if(!fl[k]) a[i][j] = k + 'A';
            }
        }
    }
    for(auto& it : a) cout << it << endl;
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