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
    int n;
    cin >> n;
    int a[n][n];
    for(int i = 0;n > i;i++)
    {
        for(int j = 0;n > j;j++)
        {
            int st[n * n + 1];
            memset(st,0,sizeof(st));
            for(int i1 = 0;i > i1;i1++)
            {
                int j1 = j;
                st[a[i1][j1]]++;
            }
            for(int i1 = 0;j > i1;i1++)
            {
                int j1 = i;
                st[a[j1][i1]]++;
            }
            for(int num = 0;n * n + 1 > num;num++)
            {
                if(st[num] == 0)
                {
                    a[i][j] = num;
                    break;
                }
            }
        }
    }
    for(int i = 0;n > i;i++)
    {
        for(int j = 0;n > j;j++) cout << a[i][j] << " ";
        cout << endl;
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