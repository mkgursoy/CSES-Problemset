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
    int pl[n];
    int a[n];
    for(int i = 0;n > i;i++)
    {
        int x;
        cin >> x;
        pl[x - 1] = i;
        a[i] = x - 1;
    }
    int ans = 1;
    for(int i = 0;n - 1 > i;i++)
    {
        if(pl[i] > pl[i + 1]) ans++;
    }
    while(q--)
    {
        int i, j;
        cin >> i >> j;
        i--,j--;
        if(i == j)
        {
            cout << ans << endl;
            continue;
        }
        i = a[i];
        j = a[j];
        if(i != n - 1 && pl[i] > pl[i + 1]) ans--;
        if(j != n - 1 && pl[j] > pl[j + 1]) ans--;
        if(i != 0 && pl[i - 1] > pl[i] && j != i - 1) ans--;
        if(j != 0 && pl[j - 1] > pl[j] && i != j - 1) ans--;
        swap(pl[i], pl[j]);
        swap(a[pl[i]], a[pl[j]]);
        if(i != n - 1 && pl[i] > pl[i + 1]) ans++;
        if(j != n - 1 && pl[j] > pl[j + 1]) ans++;
        if(i != 0 && pl[i - 1] > pl[i] && j != i - 1) ans++;
        if(j != 0 && pl[j - 1] > pl[j] && i != j - 1) ans++;
        cout << ans << endl;
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