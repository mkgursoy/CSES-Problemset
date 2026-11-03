#include <bits/stdc++.h>
using namespace std;

#define all(x) x.begin(), x.end()
#define ar array

const int MOD = 1e9 + 7, INF = 1e17;

int sum(int x,int y,int mod = MOD)
{
    return (x + y + mod) % mod;
}

int mul(int x,int y,int mod = MOD)
{
    return x * 1LL * y % mod;
}

int binpow(int x,int y,int mod = MOD)
{
    int res = 1;

    while (y)
    {
        if (y & 1) res = mul(res, x, mod), y--;
        else x = mul(x, x, mod), y >>= 1;
    }

    return res;
}

int inv(int x,int mod = MOD)
{
    return binpow(x, mod - 2, mod);
}

const int mxN = 1e7 + 2;
int sq[mxN];
void solve()
{
    int n;
    cin >> n;
    vector<int> nums;
    for(int i = 0;n >= i * i;i++)
    {
        nums.push_back(i * i);
        sq[i * i] = i;
    }
    vector<ar<int,3>> nums_kare;
    for(int i = 0;nums.size() > i;i++)
    {
        for(int j = i;nums.size() > j;j++)
        {
            nums_kare.push_back({nums[i] + nums[j], sq[nums[i]], sq[nums[j]]});
        }
    }
    sort(all(nums_kare));
    int i = 0, j = nums_kare.size() - 1;
    while(i <= j)
    {
        while(i <= j && nums_kare[i][0] + nums_kare[j][0] > n) j--;
        if(nums_kare[i][0] + nums_kare[j][0] == n)
        {
            auto [u1, x1, x2] = nums_kare[i];
            auto [u2, x3, x4] = nums_kare[j];
            cout << x1 << " " << x2 << " " << x3 << " " << x4 << endl;
            return;
        }
        i++;
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    
    int tt = 1;
    cin >> tt;

    while(tt--) solve();

    #ifdef LOCAL

    cerr << "[TIME] " << fixed << setprecision(2) << 1000 * clock() / CLOCKS_PER_SEC << " ms\n";

    #endif
}
