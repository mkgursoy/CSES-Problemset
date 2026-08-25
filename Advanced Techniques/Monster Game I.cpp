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
int dp[mxN];
int f[mxN];
int s[mxN];
long double cross(int x,int y)
{
	if(f[y] == f[x]) return INF;
	return ((long double)(dp[x] - dp[y]) / (long double)(f[y] - f[x]));
}
void solve()
{
   	int n,x;
   	cin >> n >> x;
   	for(int i = 1;n >= i;i++) cin >> s[i];
   	for(int i = 1;n >= i;i++) cin >> f[i];
   	deque<int> dq;
   	dq.push_back(0);
   	f[0] = x;
   	dp[0] = 0;
   	for(int i = 1;n >= i;i++)
   	{
   		while(dq.size() >= 2 && cross(dq[0], dq[1]) <= s[i]) dq.pop_front();
   	
   		dp[i] = dp[dq[0]] + f[dq[0]] * s[i];
   	
   		while(dq.size() >= 2 && cross(dq[dq.size() - 2], dq[dq.size() - 1]) >= cross(dq[dq.size() - 1], i)) dq.pop_back();
   		dq.push_back(i);
   	}
   	cout << dp[n] << endl;
}
int32_t main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	int tt;
	tt=1; 
	
	while(tt--) solve();

}
