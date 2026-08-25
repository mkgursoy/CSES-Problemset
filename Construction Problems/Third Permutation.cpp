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
    int a[n];
    int b[n];
    for(auto& it : a) cin >> it;
    for(auto& it : b) cin >> it;
    if(n == 2)
    {
        cout << "IMPOSSIBLE" << endl;
        return;
    }
    mt19937 mt(time(nullptr));
    int p[n];
    iota(p, p + n, 1);
    while(true)
    {
        shuffle(p, p + n, mt);
        bool bb = true;
        for(int i = 0;n > i;i++)
        {
            if(p[i] != a[i] && p[i] != b[i])
            {
                bb = bb;
            }
            else
            {
                bb = !bb;
                break;
            }
        }
        if(bb)
        {
            for(auto it : p) cout << it << " ";
            cout << endl;
            return;
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
