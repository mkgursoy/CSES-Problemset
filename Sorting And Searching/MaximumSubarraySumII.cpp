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
    int n,a1,b1;
    cin >> n >> a1 >> b1;
    set<ar<int,2>> s;
    int a[n + 1];
    int ans = -INF;
    a[0] = 0;
    for(int i = 0;n > i;i++)
    {
        int x;
        cin >> x;
        a[i + 1] = x + a[i];
    }
    for(int i = a1;n >= i;i++)
    {
        s.insert({a[i - a1],i - a1});
        if(i > b1)
        {
            s.erase(s.find({a[i - b1 - 1],i - b1 -1}));
        }
        if(s.size()) ans = max(ans,a[i] - (*s.begin())[0]);
    }
    cout << ans << endl;
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