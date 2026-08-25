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
struct Trie
{
	constexpr static int LG = 60;
	vector<ar<int,2>> trie;
	Trie()
	{
		trie.emplace_back();
	}
	int newNode()
	{
		trie.emplace_back();
		return trie.size() - 1;
	}
	void insert(int val)
	{
		int pos = 0;
		for(int i = LG - 1;i >= 0;i--)
		{
			int x = (val >> i) & 1;
			if(!trie[pos][x]) trie[pos][x] = newNode();
			pos = trie[pos][x];
		}
	}
	int findMax(int val)
	{
		int pos = 0;
		int ans = 0;
		for(int i = LG - 1;i >= 0;i--)
		{
			int x = (val >> i) & 1;
			x ^= 1;
			if(!trie[pos][x]) x ^= 1;
			else ans += (1LL << i);
			if(!trie[pos][x]) break;
			pos = trie[pos][x];
		}
		return ans;
	}
};
void solve()
{
   	int n;
   	cin >> n;
   	int xr = 0;
   	Trie tr;
   	tr.insert(0);
   	int ans = 0;
   	while(n--)
   	{
   		int x;
   		cin >> x;
   		xr ^= x;
   		ans = max(ans, tr.findMax(xr));
   		tr.insert(xr);
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
