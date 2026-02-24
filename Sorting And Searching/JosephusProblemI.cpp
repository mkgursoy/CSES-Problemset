/*
    Author: Matkap (prefix_sum)
*/
 
#include <bits/stdc++.h>
#include <bits/extc++.h>
#include <array>
 
using namespace std;
using namespace __gnu_pbds;
 
#define int long long
#define ar array
#define all(x) x.begin(),x.end()
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>
 
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
    ordered_set st;
    int n,k;
    k = 2;
    cin >> n;
    for(int i = 1;n >= i;i++) st.insert(i);
    int lst = 0;
    while(st.size())
    {
        cout << *st.find_by_order((lst + (k - 1) % st.size()) % st.size()) << endl;
        int llst = lst;
        lst = (lst + (k - 1) % st.size()) % st.size();
        st.erase(st.find_by_order((llst + (k - 1) % st.size()) % st.size()));
    }
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