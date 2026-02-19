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
string s1;
bool vis[8][8];
int cnt = 0;
bool chk(int i,int j)
{
    if(i >= 7 || j >= 7 || i < 0 || j < 0 || vis[i][j]) return false;
    return true;
};
void dfs(int i,int j,int c)
{
    if(c == 48 && i == 6 && j == 0)
    {
        cnt++;
        return;
    }
    if(i == 6 && j == 0) return;
    if(!chk(i + 1,j) && !chk(i - 1,j) && chk(i, j - 1) && chk(i, j + 1)) return;
    if(!chk(i,j + 1) && !chk(i,j - 1) && chk(i + 1,j) && chk(i - 1, j)) return;
    vis[i][j] = 1;
    if(s1[c] == 'R' && chk(i, j + 1)) dfs(i, j + 1,c + 1);
    if(s1[c] == 'L' && chk(i, j - 1)) dfs(i, j - 1,c + 1);
    if(s1[c] == 'U' && chk(i - 1, j)) dfs(i - 1, j,c + 1);
    if(s1[c] == 'D' && chk(i + 1, j)) dfs(i + 1, j,c + 1);
    if(s1[c] == '?' && chk(i, j + 1)) dfs(i, j + 1,c + 1);
    if(s1[c] == '?' && chk(i, j - 1)) dfs(i, j - 1,c + 1);
    if(s1[c] == '?' && chk(i - 1, j)) dfs(i - 1, j,c + 1);
    if(s1[c] == '?' && chk(i + 1, j)) dfs(i + 1, j,c + 1);
    vis[i][j] = 0;
};
void solve()
{
    cin >> s1;
    dfs(0,0,0);
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