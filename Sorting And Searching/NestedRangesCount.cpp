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
const int mxN = 5e5 + 7;
int tree[mxN + 1];
int n;
void upd(int pos)
{
    for( ;mxN >= pos;pos += pos & -pos) tree[pos]++;
}
int q(int pos)
{
    int res = 0;
    for( ;pos; pos -= pos & -pos) res += tree[pos];
    return res;
}
void solve()
{
    cin >> n;
    ar<int,3> a[n];
    map<int,int> mpx, mpy;
    for(int i = 0;n > i;i++) cin >> a[i][0] >> a[i][1], mpx[a[i][0]]++, mpy[a[i][1]]++, a[i][2] = i;
    int t = 0;
    for(auto& it : mpx) it.second = ++t;
    t = 0;
    for(auto& it : mpy) it.second = ++t;
    for(int i = 0;n > i;i++) a[i][0] = mpx[a[i][0]], a[i][1] = -mpy[a[i][1]];
    sort(a,a + n);
    vector<int> ans[2];
    ans[0].resize(n);
    ans[1].resize(n);
    for(int i = 0;n > i;i++)
    {
        ans[1][a[i][2]] = q(mxN) - q(-a[i][1] - 1);
        upd(-a[i][1]);
    }
    memset(tree,0,sizeof(tree));
    sort(a,a + n, greater<>());
    for(int i = 0;n > i;i++)
    {
        ans[0][a[i][2]] = q(-a[i][1]);
        upd(-a[i][1]);
    }
    for(auto it : ans)
    {
        for(auto it1 : it) cout << it1 << " ";
        cout << endl;
    }
    cout << endl;
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