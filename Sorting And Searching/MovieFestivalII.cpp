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
    int n,k;
    cin >> n >> k;
    set<ar<int,2>> st;
    ar<int,3> a[n];
    int vis[n];
    int ans2 = 0;
    int ans[n];
    memset(vis,0,sizeof(vis));
    int cur = 0,cnt = 0;
    for(int i = 0;n > i;i++)
    {
        cin >> a[i][1] >> a[i][0];
        a[i][2] = i;        
    }
    sort(a,a + n);
    for(int i = 0;n > i;i++)
    {
        auto h = st.lower_bound({a[i][1] + 1,0});
 
        if(h != st.begin())
        {
            --h;
            ans[a[i][2]] = (*h)[1];
            st.erase(h);
        }
        else
        {
            ans[a[i][2]] = st.size();
        }       
        if(k > st.size())
        {
            st.insert({a[i][0],a[i][2]});
            ans2 += 1;
        }
    }
    cout << ans2 << endl;
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