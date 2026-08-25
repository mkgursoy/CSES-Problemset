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
   	string s;
   	cin >> s;
   	map<char,int> mp;
   	for(auto it : s) mp[it]++;
   	int timer = 0;
   	for(auto& it : mp) it.second = timer++;
   	for(auto& it : s) it = ('a' + mp[it]);
   
   	int k = mp.size();
   	map<vector<int>, int> cnt;
   	vector<int> new_cnt(k);
   	int ans = 0;
   	cnt[new_cnt]++;
   	int bef = 0;
   	for(auto it : s)
   	{
   		new_cnt[it - 'a']++;
   		int base = *min_element(all(new_cnt));
   		vector<int> new_new_cnt(k);
   		for(int i = 0;k > i;i++) new_new_cnt[i] = new_cnt[i] - base;
   		ans += cnt[new_new_cnt]++;
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
