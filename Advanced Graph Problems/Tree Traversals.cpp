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
   	int n;
   	cin >> n;
   	int a[n];
   	int b[n];
   	int ind_b[n];
   	for(int i = 0;n > i;i++) cin >> a[i], a[i]--;
   	for(int i = 0;n > i;i++) cin >> b[i], ind_b[b[i] - 1] = i;
   	function<void(int,int,int)> dfs = [&](int i,int j,int k)
   	{
   		if(i > j || k >= n) return;
   		if(i == j)
   		{
   			cout << a[k] + 1 << " ";
   			return;
   		}
   		int i1 = ind_b[a[k]];
   		
   		dfs(i, i1 - 1, k + 1);
   		
   		dfs(i1 + 1, j, k + 1 + (i1 - i));
   		cout << a[k] + 1 << " ";
   	};
   	dfs(0, n - 1, 0);
}
int32_t main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	int tt;
	tt=1; 
	
	while(tt--) solve();

}
