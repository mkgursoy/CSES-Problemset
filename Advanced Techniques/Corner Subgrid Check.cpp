#include <bits/stdc++.h>
#include <array>

using namespace std;
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
bool vis[mxN][mxN];
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
    for(char ch = 'A';'A' + m - 1 >= ch;ch++)
    {
        memset(vis,0,sizeof(vis));
        bool b = false;
        for(int i = 0;n > i;i++)
        {
            vector<int> ind;
            for(int j = 0;n > j;j++)
            {
                if(grid[i][j] == ch)
                {
                    ind.push_back(j);
                }
            }
            
            for(int k = 0;ind.size() > k;k++)
            {
                for(int l = k + 1;ind.size() > l;l++)
                {
                    if(vis[ind[k]][ind[l]])
                    {
                        b = true;
                        k = ind.size();
                        i = n;
                        break;
                    }
                    vis[ind[k]][ind[l]] = true;
                }
            }
        }
        cout << (b ? "YES" : "NO") << endl;
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
