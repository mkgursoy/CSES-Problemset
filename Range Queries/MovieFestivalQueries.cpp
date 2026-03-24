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
const int mxA = 1e6 + 7;
int par[mxA][28];
void solve()
{
    int n,q;
    cin >> n >> q;
    memset(par, -1, sizeof(par));
    while(n--)
    {
        int x,y;
        cin >> x >> y;
        par[y][0] = max(par[y][0], x);
    }
    for(int j = 0;28 > j;j++)
    {
        for(int i = 0;mxA > i;i++)
        {
            if(j == 0 && i) par[i][0] = max(par[i - 1][0], par[i][0]);
            else if(j && par[i][j - 1] == -1) continue;
            else if(j) par[i][j] = par[par[i][j - 1]][j - 1];
        }
    }
    while(q--)
    {
        int x,y;
        cin >> x >> y;
        int ans = 0;
        for(int j = 27;j >= 0;j--)
        {
            if(par[y][j] >= x)
            {
                ans += (1LL << j);
                y = par[y][j];
            }
        }
        cout << ans << endl;
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