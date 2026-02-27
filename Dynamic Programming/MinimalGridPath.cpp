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
const int mxN = 3007;
int nxt[mxN][mxN];
char vis[mxN][mxN];
int dist[2 * mxN];
void solve()
{
    int n;
    cin >> n;
    string a[n];
    for(auto& it : a) cin >> it;
    vector<ar<int,4>> pq[2 * n + 1];
    vis[0][0] = 1;
    for(int i = 0;2 * n + 1 > i;i++) dist[i] = 'Z';
    auto chk = [&](int i,int j) -> bool
    {
        if(n > i && i >= 0 && n > j && j >= 0 && vis[i][j] == 0)
        {
            return true;
        } 
        return false;
    };
    pq[1].push_back({a[0][0] - 'A', 0, 0, -1});
    for(int length = 1;2 * n > length;length++)
    {
        sort(all(pq[length]), greater<>());
        while(pq[length].size())
        {
            auto [ch, i, j, dir] = pq[length].back();
            pq[length].pop_back();
            if(dist[length] < ch + 'A') break;
            else
            {
                dist[length] = ch + 'A';
            }
            nxt[i][j] = dir;
            if(chk(i + 1, j))
            {
                vis[i + 1][j] = 1;
                pq[length + 1].push_back({a[i + 1][j] - 'A', i + 1, j, 0});
            }
            if(chk(i, j + 1))
            {
                vis[i][j + 1] = 1;
                pq[length + 1].push_back({a[i][j + 1] - 'A', i, j + 1, 1});
            }
        }
    }
    string cvp = "";
    int i = n - 1, j = n - 1;
    while(i >= 0 && j >= 0)
    {
        cvp += a[i][j];
        if(nxt[i][j] == 0)
        {
            i--;
        }
        else if(nxt[i][j] == 1)
        {
            j--;
        }
        else
        {
            break;
        }
    }
    reverse(all(cvp));
    cout << cvp << endl;
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