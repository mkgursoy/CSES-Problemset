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
const int SIZE = 447;
bool comp(ar<int,3> a,ar<int,3> b)
{
    if((int)(a[0] / SIZE) ^ (int)(b[0] / SIZE)) return (int)(a[0] / SIZE) < (int)(b[0] / SIZE);
    return a[1] < b[1];
}
int vals[200007];
void solve()
{
    int n,q;
    cin >> n >> q;
    vector<ar<int,3>> queries;
    int a[n];
    map<int,int> mp;
    for(int i = 0;n > i;i++) cin >> a[i],mp[a[i]] = 1;
    int t = 0;
    for(auto& it : mp) it.second = t++;
    for(int i = 0;n > i;i++) a[i] = mp[a[i]];
    for(int i = 0;q > i;i++)
    {
        int x,y;
        cin >> x >> y;
        x--,y--;
        queries.push_back({x,y,i});
    }
    sort(all(queries),comp);
    //memset(vals,0,sizeof(vals));
    int ans = 0;
    int l = 0,r = -1;
    int answer[q];
    for(auto [l1,r1,i] : queries)
    {
        while(r1 > r)
        {
            r++;
            if(vals[a[r]] == 0) ans++;
            vals[a[r]]++;
        }
        while(l1 < l)
        {
            l--;
            if(vals[a[l]] == 0) ans++;
            vals[a[l]]++;
        }
        while(r1 < r)
        {
            vals[a[r]]--;
            if(vals[a[r]] == 0) ans--;
            r--;
        }
        while(l1 > l)
        {
            vals[a[l]]--;
            if(vals[a[l]] == 0) ans--;
            l++;
        }
        answer[i] = ans;
    }
    for(auto it : answer) cout << it << endl;
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