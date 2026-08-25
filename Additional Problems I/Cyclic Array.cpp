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
const int mxN = 2e5 + 7;
ar<int,2> par[mxN][30];
void solve()
{
   	int n,k;
   	cin >> n >> k;
   	int a[n];
   	for(int i = 0;n > i;i++)
   	{
   		cin >> a[i];
   	}
   	int pref[n];
   	int sum = 0;
   	for(int i = 0;n > i;i++)
   	{
   		pref[i] = sum += a[i];
   	}
   	if(k >= sum)
   	{
   		cout << "1" << endl;
   		return;
   	}
   	int lst = 0;
   	for(int i = 0;n > i;i++)
   	{
   		auto h = upper_bound(pref,pref + n, k + lst) - pref;
   		if(h != n) par[i][0] = {(h) % n, (h - i)};
   		else
   		{
   			int delt = pref[h - 1] - lst;
   			h = upper_bound(pref,pref + n, k - delt) - pref;
   			par[i][0] = {(h) % n, n - (i - h)};
   		}
   		lst += a[i];
   	}
   	
   	for(int j = 1;29 > j;j++)
   	{
   		for(int i = 0;n > i;i++)
   		{
   			par[i][j][0] = par[par[i][j - 1][0]][j - 1][0];
   			par[i][j][1] = par[i][j - 1][1] + par[par[i][j - 1][0]][j - 1][1];
   		}
   	}
   	auto jump = [&](int a,int b) -> ar<int,2>
   	{
   		int sum1 = 0;
   		
   		for(int j = 29;j >= 0;j--)
   		{
   			if((1LL << j) <= b)
   			{
   				b -= (1LL << j);
   				sum1 += par[a][j][1];
   				a = par[a][j][0];
   			
   			}
   		}
   		return {a, sum1};
   	};
   	int ans = INF;
   	for(int i = 0;n > i;i++)
   	{
   		int l = 1, r = n;
   		while(r > l)
   		{
   			int mid = (l + r) / 2;
   			
   			if(jump(i, mid)[1] >= n) r = mid;
   			else l = mid + 1;
   		}
   		ans = min(ans, l);
   		
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
