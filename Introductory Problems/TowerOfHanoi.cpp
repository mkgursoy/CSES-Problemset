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
vector<ar<int,2>> vec;
void rec(int n,ar<int,3> hanoi)
{
    if(n == 1)
    {
        vec.push_back({hanoi[0], hanoi[1]});
        return;
    }
    swap(hanoi[1], hanoi[2]);
    rec(n - 1, hanoi);
    swap(hanoi[1], hanoi[2]);
    vec.push_back({hanoi[0], hanoi[1]});
    swap(hanoi[0], hanoi[2]);
    rec(n - 1, hanoi);
    swap(hanoi[0], hanoi[2]);
}
void solve()
{
    int n;
    cin >> n;
    rec(n, {1, 3, 2});
    cout << vec.size() << endl;
    for(auto [i, j] : vec) cout << i << " " << j << endl;
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