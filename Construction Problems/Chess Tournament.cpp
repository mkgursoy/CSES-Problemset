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
   	set<ar<int,2>,greater<ar<int,2>>> st;
   	int a[n];
   	for(int i = 0;n > i;i++)
   	{
   		cin >> a[i];
   		
   		if(a[i] > 0)
   		st.insert({a[i], i});
   	}
   	map<ar<int,2>, int> mp;
   	vector<ar<int,2>> ans;
   	for(int i = 0;n > i;i++)
   	{
   		if(a[i] <= 0) continue;
   		st.erase({a[i], i});
   		vector<ar<int,2>> new_push;
   		while(a[i] > 0)
   		{	
   		
   			if(!st.size())
   			{
   				cout << "IMPOSSIBLE" << endl;
   				return;
   			}
   			auto [x, j] = *st.begin();
   			st.erase(st.begin());
   			if(mp[{i, j}])
   			{
   				new_push.push_back({x, j});
   				continue;
   			}
   		
   			mp[{i, j}]++;
   			a[j]--;
   			
   			a[i]--;
   			
   			ans.push_back({i, j});
   			if(a[j] > 0)
   			st.insert({a[j], j});
   		}
   		for(auto [x, j] : new_push) st.insert({x, j});
   	}
   	cout << ans.size() << endl;
  	for(auto [i, j] : ans) cout << i + 1 << " " << j + 1 << endl;
}
int32_t main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	int tt;
	tt=1; 
	
	while(tt--) solve();

}
