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
    vector<map<int,int>> places(8);
    vector<string> s(8);
    for(auto& it : s) cin >> it;
    for(int j = 0;8 > j;j++)
    {
        for(int i = 0;8 > i;i++)
        {
            if(s[i][j] == '*') places[j][i]++;
        }
    }
    auto chk = [&](vector<int> perm) -> bool
    {
        for(int i = 0;8 > i;i++)
        {
            if(places[i][perm[i]])
            {
                return false;
            } 
        }
        map<int,int> di1, di2;
        for(int i = 0;8 > i;i++)
        {
            int j = perm[i];
            if(di1[i + j] || di2[-i + j + 23]) return false;
            di1[i + j]++;
            di2[-i + j + 23]++;
        }
        return true;
    };
    vector<int> perm(8);
    iota(all(perm), 0);
    int cnt = 0;
    do
    {
        if(chk(perm)) cnt++;
    }
    while(next_permutation(all(perm)));
    cout << cnt << endl;
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