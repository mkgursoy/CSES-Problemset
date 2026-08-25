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
const int mxN = 3007;
int yu[mxN][mxN];
int so[mxN][mxN];
int ca[mxN][mxN];
char grid[mxN][mxN];
void solve()
{
    int n, m;
    cin >> n >> m;
    for(int i = 0;n > i;i++)
    {
        for(int j = 0;n > j;j++)
        {
            cin >> grid[i][j];
        }
    }
    for(int i = 0;n > i;i++)
    {
        int last = 0;
        for(int j = 0;n > j;j++)
        {
            if(grid[i][last] != grid[i][j]) last = j;
            so[i][j] = j - last + 1;
        }
    }
    for(int j = 0;n > j;j++)
    {
        int last = 0;
        for(int i = 0;n > i;i++)
        {
            if(grid[last][j] != grid[i][j]) last = i;
            yu[i][j] = i - last + 1;
        }
    }
    int cnt = 0;
    for(int i = 0;n > i;i++)
    {
        for(int j = 0;n > j;j++)
        {
            if(i == 0 || j == 0)
            {
                ca[i][j] = 1;
            }
            else
            {
                if(grid[i - 1][j - 1] != grid[i][j]) ca[i][j] = 1;
                else
                {
                    ca[i][j] = min({1 + ca[i - 1][j - 1], yu[i][j], so[i][j]});
                }
            }
        }
    }
    int alf[26];
    memset(alf,0,sizeof(alf));
    for(int i = 0;n > i;i++) for(int j = 0;n > j;j++) alf[grid[i][j] - 'A'] += ca[i][j];
    for(int i = 0;m > i;i++) cout << alf[i] << endl;
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
