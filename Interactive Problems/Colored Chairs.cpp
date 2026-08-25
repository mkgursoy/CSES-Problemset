#include <bits/stdc++.h>
#include <array>

using namespace std;

#define int long long
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
int ask(int pos)
{
	cout << "? " << pos << endl;
	char x;
	cin >> x;
	if(x == 'R') return 0;
	else if(x == 'B') return 1;
	else return -1;
}
void solve()
{
   	int n;
   	cin >> n;
   	int l = 2, r = n + 1;
   	int c = ask(1);
   	while(r > l)
   	{
   		int mid = (l + r) / 2;
   		int k = ask(mid);
   		if(((mid - l) % 2 == 1 && k == c) || ((mid - l) % 2 == 0 && k != c))
   		{
   			l = mid + 1;
   			c = k;
   		}
   		else r = mid;
   	}
   	cout << "! " << l - 1 << endl;
}
int32_t main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	int tt;
	tt=1; 
	
	while(tt--) solve();

}
