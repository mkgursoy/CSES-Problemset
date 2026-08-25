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
    string s;
    cin >> s;
    string t = s;
    reverse(all(t));
    string new_s;
    for(auto it : s)
    {
        new_s += '#';
        new_s += it;
    }
    new_s += '#';
    int n = new_s.size();
    int p[n];
    int mx[n];
    fill(mx, mx + n, 1);
    
    int l = 0,r = 0;
    for(int i = 0;n > i;i++)
    {
        p[i] = max(0ll, min(r - i, p[l + (r - i)]));
        mx[i + p[i]] = max((2 * p[i] + 1 + (new_s[i + p[i]] != '#')) / 2, mx[i + p[i]]);
        while(i + p[i] < n && i - p[i] >= 0 && new_s[i - p[i]] == new_s[i + p[i]])
        {
            mx[i + p[i]] = max((2 * p[i] + 1 + (new_s[i + p[i]] != '#')) / 2, mx[i + p[i]]);
            p[i]++; 
        } 
        p[i]--;
        if(i + p[i] > r)
        {
            l = i - p[i];
            r = i + p[i];
        }
    }
    for(int i = 0;n > i;i++)
    {
        if(new_s[i] != '#')
        {
            cout << mx[i] << " ";
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
