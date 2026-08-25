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
    int n, k;
    cin >> n >> k;
    int a[n];
    int cnt[n + 10];
    set<int> ms;
    for(int i = 0;n + 10 > i;i++) ms.insert(i), cnt[i] = 0;
    for(int i = 0;n > i;i++)
    {
        cin >> a[i];
        if(n + 10 > a[i])
        {
            cnt[a[i]]++;
            if(cnt[a[i]] == 1) ms.erase(a[i]);
        }
        if(i >= k && n + 10 > a[i - k])
        {
            cnt[a[i - k]]--;
            if(cnt[a[i - k]] == 0) ms.insert(a[i - k]);
        } 
        if(i >= k - 1)
        {
            cout << (*ms.begin()) << " ";
        }
    }
    cout << endl;
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
