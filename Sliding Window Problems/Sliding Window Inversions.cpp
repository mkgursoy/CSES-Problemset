#include <bits/stdc++.h>
#include <bits/extc++.h>
#include <array>

using namespace std;
using namespace __gnu_pbds;

#define int long long
#define ar array
#define all(x) x.begin(),x.end()
#define ordered_set tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update>

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
 	ordered_set st;
 	int inv = 0;
 	int a[n];
 	for(int i = 0;n > i;i++)
 	{
 		cin >> a[i];
 		inv += st.size() - st.order_of_key(a[i] + 1);
 		st.insert(a[i]);
 		if(i >= k)
 		{
 			inv -= st.order_of_key(a[i - k]);
 			st.erase(st.find_by_order(st.order_of_key(a[i - k])));
 		}
 		if(i >= k - 1)
 		cout << inv << " ";
 	}
 	cout << endl;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int tt;
    tt=1; 
  
    while(tt--) solve();
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
}
