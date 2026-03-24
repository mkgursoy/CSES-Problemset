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
void solve()
{
    int n,q;
    cin >> n >> q;
    vector<ar<int,2>> ch;
    int con[n + 1];
    con[n] = 0;
    int binlift[n + 1][18];
    int nxt[n + 1];
    int a[n];
    int old_a[n];
    for(int i = 0;n > i;i++)
    {
        cin >> a[i];
        old_a[i] = a[i];
    }
    int cur = 0;
    nxt[n - 1] = n; 
    nxt[n] = n;
    for(int i = n - 2;i >= 0;i--)
    {
        int j = i + 1;
        while(j != n && a[j] <= a[i]) j = nxt[j];
        nxt[i] = j;
    }
    int ans[n];
    for(int i = 0;n > i;i++)
    {
        con[i] = (nxt[i] - i) * a[i];
    }
    
    for(int i = 1;n > i;i++)
    {
        a[i] += a[i - 1];
    }
    for(int i = n;i >= 0;i--)
    {
        binlift[i][0] = nxt[i];
        con[i] += con[nxt[i]];
        for(int j = 1;18 > j;j++)
        {
            binlift[i][j] = binlift[binlift[i][j - 1]][j - 1];
        }
    }
    auto findPar = [&](int a,int b) -> int
    {
        for(int j = 17;j >= 0;j--)
        {
            if(a == -1) return -1;
            if(b >= (1LL << j))
            {
                b -= (1LL << j);
                a = binlift[a][j];
            }
        }
        return a;
    };
    while(q--)
    {
        int l,r;
        cin >> l >> r;
        l--,r--;
        int ll = 1, rr = n;
        while(rr > ll)
        {
            int mm = (ll + rr) / 2;
            int new_l = findPar(l, mm);
            if(new_l > r) rr = mm;
            else ll = mm + 1;
        }
        ll = findPar(l, ll - 1);
        cout << con[l] - con[ll] + (r - ll + 1) * old_a[ll] - (a[r] - (l > 0 ? a[l - 1] : 0)) << endl;
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