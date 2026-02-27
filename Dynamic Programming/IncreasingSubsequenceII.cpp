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
const int mxN = 3e5 + 7;
int tree[mxN];
void upd(int pos,int val)
{
    for( ;mxN > pos;pos += (pos & -pos))
    {
        tree[pos] = sum(tree[pos], val);
    }
}
int q(int pos)
{
    int res = 0;
    for( ;pos > 0;pos -= (pos & -pos)) res = sum(res, tree[pos]);
    return res;
}
void solve()
{
    int n;
    cin >> n;
    int timer = 0;
    int a[n];
    map<int,int> mp;
    for(auto& it : a) cin >> it, mp[it]++;
    for(auto& it : mp) it.second = ++timer;
    for(auto& it : a) it = mp[it];
    for(int i = 0;n > i;i++)
    {
        upd(a[i], q(a[i] - 1) + 1);
    }
    cout << q(mxN - 1) << endl;
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