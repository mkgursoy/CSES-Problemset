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
const int mxN = 1007;
int vis[mxN][mxN];
int grid[mxN][mxN];
int pos = 1;
int n;
bool check(int a,int b)
{
    return (a <= n && a >= 1 && b <= n && b >= 1 && vis[a][b] == 0);
}
vector<ar<int,2>> findMoves(int a,int b)
{
    vector<ar<int,2>> res;
    vector<ar<int,2>> moves = {{1, 2},{2, 1},{2, -1},{1, -2},{-2, 1},{-1, 2},{-1, -2},{-2, -1}};
    for(auto [dx, dy] : moves)
    {
        if(check(a + dx, b + dy))
        {
            res.push_back({a + dx, b + dy});
        }
    }
    return res;
}
void dfs()
{
    queue<ar<int,3>> q;
    q.push({1, 1, 0});
    vis[1][1] = 1;
    while(q.size())
    {
        auto [x, y, cnt] = q.front();
        q.pop();
        grid[x - 1][y - 1] = cnt + 1;
        vector<ar<int,2>> moves = findMoves(x, y);
        for(auto [x1, y1] : moves)
        {
            q.push({x1, y1, cnt + 1});
            vis[x1][y1] = 1;
        }
    }
}
void solve()
{
    cin >> n;
    dfs();
    for(int i = 0;n > i;i++)
    {
        for(int j = 0;n > j;j++) cout << grid[i][j] - 1 << " ";
        cout << endl;
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