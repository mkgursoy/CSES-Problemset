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
    set<int> st;
    int n;
    cin >> n;
    int deg[n];
    int a[n - 2];
    memset(deg,0LL,sizeof(deg));
    for(int i = 0;n - 2 > i;i++)
    {
    	cin >> a[i];
    	a[i]--;
    	deg[a[i]]++;
    }
    for(int i = 0;n > i;i++) st.insert(i);
    for(int i = 0;n - 2 > i;i++)
    {
    	if(st.count(a[i])) st.erase(a[i]);
    }
    for(int i = 0;n - 2 > i;i++)
    {
    	cout << *st.begin() + 1 << " " << a[i] + 1 << endl;
    	deg[a[i]]--;
    	st.erase(st.begin());
    	if(deg[a[i]] == 0) st.insert(a[i]);
    }
    cout << *st.begin() + 1 << " " << *(--st.end()) + 1 << endl;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int tt;
    tt=1; 
    //cin >> tt;
    while(tt--) solve();
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
}