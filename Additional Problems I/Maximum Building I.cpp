#include <bits/stdc++.h>
#include <array>

using namespace std;

#define int long long
#define endl "\n"
#define ar array
#define all(x) x.begin(),x.end()

const int INF = 1e17 , MOD = 1e9 + 7;

int mul(int a,int b,int mod = MOD)
{
    a %= mod;
    b %= mod;
    return a * 1LL * b % mod;
}
int sum(int a,int b,int mod = MOD)
{
    a %= mod;
    b %= mod;
    return (a + b + mod) % mod;
}
int binpow(int base,int power,int mod = MOD)
{
    if(power == 1) return base;
    if(power == 0) return 1;
    
    if(power%2==1)
    {
         int a;    
         a = binpow(base,(power - 1)/2);
        return mul(base, mul(a, a, mod), mod);
    } 
    else
     {
        int a;
        a = binpow(base,power/2);
        return mul(a, a, mod);
    } 

}
int inv(int a,int mod = MOD)
{
    a %= mod;
    return binpow(a, mod - 2) % mod;
}
void solve()
{
    int n, m;
    cin >> n >> m;
    string s[n];
    for(auto& it : s) cin >> it;
    int nxt[n][m];
    int prev;
    for(int i = 0;n > i;i++)
    {
        prev = -1;
        for(int j = 0;m > j;j++)
        {
            if(s[i][j] == '*') prev = j;
            nxt[i][j] = prev;
        }
    }
    int ans = 0;
    for(int j = 0;m > j;j++)
    {
        stack<ar<int,2>> st;
        for(int i = 0;n > i;i++)
        {   
            int lmao = i;
            while(st.size() && st.top()[0] < nxt[i][j])
            {
                ans = max(ans, (i - st.top()[1]) * (j - st.top()[0]));
                lmao = st.top()[1];
                st.pop();
            } 
            st.push({nxt[i][j], lmao});
        }
        while(st.size()) ans = max(ans, (n - st.top()[1]) * (j - st.top()[0])), st.pop();
       
    }
    cout << ans << endl;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int tt;
    tt=1; 
    
    while(tt--) solve();

}
