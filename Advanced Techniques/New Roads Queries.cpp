#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <queue>
#include <array>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <cmath>
#include <tuple>
#include <bitset>
#include <cstdint>
#include <stack>

#pragma optimize ("popcnt")

using namespace std;

#define ar array
#define all(x) x.begin(),x.end()
#define endl "\n"
#define dbg << "," << 
#define int long long int
#define ld long double
#define mp make_pair
#define pb push_back
#define mid (left+right)/2

const int INF = 1e17, MOD = 1e9 + 7, LIM = 200010;

int mul(int a, int b, int mod = MOD)
{
    return a * 1LL * b % mod;
}
int sum(int a, int b, int mod = MOD)
{
    return (a + b + mod) % mod;
}

int binpow(int base, int power, int mod = MOD)
{
    if (power == 1) return base;
    if (power == 0) return 1LL;

    if (power % 2 == 1)
    {
        int a;
        a = binpow(base, power / 2, mod);
        return mul(base, mul(a, a, mod), mod);
    }
    else
    {
        int a;
        a = binpow(base, power / 2, mod);
        return mul(a, a, mod);
    }
}
int inv(int a, int mod = MOD)
{
    return binpow(a, mod - 2, mod) % mod;
}

vector<array<int, 2>>* adj;
vector<int> par;
vector<int> sz;
vector<int> tin;
vector<int> tout;
vector<int> comp;
vector<bool> vis;
int t = 0;
int cmp = 0;

int per[LIM][25];
int mx[LIM][25];

void DFS(int node) {
    if (vis[node]) return;
    vis[node] = true;

    comp[node] = cmp;

    t++;
    tin[node] = t;

    for (auto k : adj[node]) {
        if (!vis[k[0]])
        {
            per[k[0]][0] = node;
            mx[k[0]][0] = k[1];
            DFS(k[0]);
        } 
    }

    t++;
    tout[node] = t;

    return;
}

int absolutePar(int node) {
    if (par[node] == -1) return node;
    else return absolutePar(par[node]);
}

bool isAnc(int a, int b) {
    if (a == 0) return true;
    return (tin[a] <= tin[b] && tout[b] <= tout[a]);
}

void solve()
{
    int n, m, q;
    cin >> n >> m >> q;

    adj = new vector<array<int, 2>>[n + 1];
    par = vector<int>(n + 1, -1);
    sz = vector<int>(n + 1, 1);

    tin = vector<int>(n + 1);
    tout = vector<int>(n + 1);
    comp = vector<int>(n + 1);
    vis = vector<bool>(n + 1);
    
    for (int i = 1; i <= m; i++) {

        int a, b;
        cin >> a >> b;

        a = absolutePar(a);
        b = absolutePar(b);

        if (a == b) continue;

        if (sz[b] > sz[a]) swap(a, b);

        par[b] = a;
        sz[a] += sz[b];

        adj[a].pb({ b,i });
        adj[b].pb({ a,i });

    }

    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            cmp++;
            DFS(i);
        }
    }

    for (int j = 1; j < 25; j++) {
        for (int i = 1; i <= n; i++) {
            per[i][j] = per[per[i][j - 1]][j - 1];
            mx[i][j] = max(mx[i][j - 1], mx[per[i][j - 1]][j - 1]);
        }
    }

    while (q--) {
        int a, b;
        cin >> a >> b;

        if (a == b) { cout << "0" << endl; continue; }
        if (comp[a] != comp[b]) { cout << "-1" << endl; continue; }
        if(tin[a] < tin[b]) swap(a, b);

        int maxA = 0;
        int maxB = 0;

        int lca = a;

        if (isAnc(a, b)) lca = a;
        else if (isAnc(b, a)) lca = b;
        else {

            for (int i = 24; i >= 0; i--) {
                if (!isAnc(per[lca][i], b)) lca = per[lca][i];
            }
            lca = per[lca][0];

        }

        for (int i = 24; i >= 0; i--) {
            if (!isAnc(per[a][i], lca)) maxA = max(maxA, mx[a][i]), a = per[a][i];
        }
        if(a != lca) maxA = max(maxA, mx[a][0]);

        for (int i = 24; i >= 0; i--) {
            if (!isAnc(per[b][i], lca)) maxB = max(maxB, mx[b][i]), b = per[b][i];
        }
        if(b != lca) maxB = max(maxB, mx[b][0]);

        cout << max(maxA, maxB) << endl;
    }

    return;
}

int32_t main()
{
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(false);
    
    int tc = 1;
    
    while (tc--) solve();
    cerr << endl << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
}
