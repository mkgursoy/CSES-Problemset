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
int findHash(char s)
{
	return s - '0';
}
vector<int> hsh(string s)
{
	int prev = 0;
	int pow = 1;
	vector<int> res;
	for(auto it : s)
	{
		res.push_back(sum(prev,mul(pow, findHash(it))));
		pow = mul(pow, 53);
		prev = res.back();
	}
	return res;
}
void solve()
{
   	string s,t;
   	cin >> s >> t;
   	int n = s.size();
   	vector<int> hsh_s = hsh(s);
   	vector<int> hsh_t = hsh(t);
   	int ans = 0;
   	int powers[n];
   	int inv_powers[n];
   	powers[0] = 1;
   	for(int i = 1;n > i;i++) powers[i] = mul(53,powers[i - 1]);
   	inv_powers[n - 1] = inv(powers[n - 1]);
  	for(int i = n - 2;i >= 0;i--) inv_powers[i] = mul(53, inv_powers[i + 1]);
   	for(int i = 0;s.size() > i + t.size() - 1;i++)
   	{
   		int r = hsh_s[i + t.size() - 1];
   		int l = 0;
   		if(i) l = hsh_s[i - 1];
   		
   		if(mul(sum(r, -l),inv_powers[i]) == hsh_t[t.size() - 1]) ans++;
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
