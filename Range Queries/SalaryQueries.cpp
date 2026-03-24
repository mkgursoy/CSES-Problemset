/*
    Author: Matkap (prefix_sum)
*/

#include <bits/stdc++.h>
#include <array>

using namespace std;

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
const int mxN = 1e6 + 7;
int tree[mxN];
void upd_pos(int pos,int n)
{
    for(pos++;n >= pos;pos += pos&-pos) tree[pos]++;
}
void upd_neg(int pos,int n)
{
    for(pos++;n >= pos;pos += pos&-pos) tree[pos]--;
}
int que(int pos)
{
    int res = 0;
    for(pos++;pos > 0;pos -= pos&-pos) res += tree[pos];
    return res;
}
void solve()
{
    int n, q;
    cin >> n >> q;
    int a[n];
    vector<int> vals;
    vector<ar<int,3>> ops;
    map<int,int> hash;
    for(int i = 0;n > i;i++) cin >> a[i],vals.push_back(a[i]);
    while(q--)
    {
        char op;
        int x,y;
        cin >> op >> x >> y;
        if(op == '!') ops.push_back({0,x,y}),vals.push_back(y);
        if(op == '?') ops.push_back({1,x,y}),vals.push_back(y),vals.push_back(x);
    }
    sort(all(vals));
    int t = 1;
    for(auto it : vals) hash[it] = t++;
    for(auto& [x,y,z] : ops)
    {
        if(x == 0)
        {
            z = hash[z];
        }
        if(x == 1)
        {
            y = hash[y];
            z = hash[z];
        }
    }
    for(auto& it : a) it = hash[it];
    for(int i = 0;n > i;i++) upd_pos(a[i], t);
    for(auto [x, y, z] : ops)
    {
        if(x == 0)
        {
            y--;
            upd_neg(a[y],t);
            a[y] = z;
            upd_pos(a[y],t);
        }
        if(x == 1)
        {
            cout << que(z) - que(y - 1) << endl;
        }
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