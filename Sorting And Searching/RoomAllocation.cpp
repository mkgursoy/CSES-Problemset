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
    ar<int,3> a[n];
    int ans[n];
    int cur = 1;
    multiset<ar<int,3>> ms;
    for(int i = 0;n > i;i++) cin >> a[i][0] >> a[i][1],a[i][2] = i,ms.insert({a[i][0],a[i][2],a[i][1]});
    memset(ans,-1,sizeof(ans));
    sort(a,a + n);
    for(int i = 0;n > i;i++)
    {
        if(ans[a[i][2]] == -1)
        {
            ans[a[i][2]] = cur;
            auto h = ms.upper_bound({a[i][1] + 1,0});
            while(h != ms.end())
            {
                array<int,3> k = *h;
                ans[k[1]] = cur;
                ms.erase(h);
                h = ms.upper_bound({k[2] + 1,0});
            }
            cur++;
        }
 
 
    }
    cout << cur - 1 << endl;
    for(auto it : ans) cout << it << " ";
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