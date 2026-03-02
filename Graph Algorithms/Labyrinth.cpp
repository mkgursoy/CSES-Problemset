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
    int n, m;
    cin >> n >> m;
    vector<vector<int>> vis(n, vector<int>(m));
    vector<vector<ar<int,2>>> bef(n, vector<ar<int,2>>(m));
    vector<vector<char>> a(n, vector<char>(m));
    int x1, y1;
    int x2, y2;
    for(int i = 0;n > i;i++)
    {
        for(int j = 0;m > j;j++)
        {
            cin >> a[i][j];
            if(a[i][j] == 'A')
            {
                x1 = i, y1 = j;
            }
            if(a[i][j] == 'B')
            {
                x2 = i, y2 = j;
            }
            bef[i][j] = {-23, -23};
        }
    }
    vector<ar<int,2>> dir = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    auto chk = [&](int x,int y) -> bool
    {
        return (x >= 0 && n > x && y >= 0 && m > y && !vis[x][y] && a[x][y] != '#');
    };
    bef[x1][y1] = {-1, -1};
    queue<ar<int,2>> bfs;
    bfs.push({x1, y1});
    vis[x1][y1] = 1;
    while(bfs.size())
    {
        auto [i, j] = bfs.front();
        bfs.pop();
        for(auto [di, dj] : dir)
        {
            if(chk(i + di, j + dj))
            {
                bef[i + di][j + dj] = {i, j};
                bfs.push({i + di, j + dj});
                vis[i + di][j + dj] = 1;
            }
        }
    }
    if(bef[x2][y2][0] == -23)
    {
        cout << "NO" << endl;
        return;
    }
    string cons = "";
    int i = x2, j = y2;
    while(bef[i][j][0] != -1)
    {
        auto [n_i, n_j] = bef[i][j];
        if(n_i == i + 1) cons += 'U';
        if(n_i == i - 1) cons += 'D';
        if(n_j == j + 1) cons += 'L';
        if(n_j == j - 1) cons += 'R';
        i = n_i, j = n_j;
    }
    reverse(all(cons));
    cout << "YES" << endl << cons.size() << endl << cons << endl;
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