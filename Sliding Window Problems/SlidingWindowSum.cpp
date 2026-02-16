/*
    Author: Matkap (prefix_sum)
*/
 
#include <bits/stdc++.h>
#include <array>
 
using namespace std;
 
#define int long long
#define ar array
#define all(x) x.begin(),x.end()
 
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
const int mxN = 1e7 + 7;
int a[mxN];
void solve()
{
	int n,k;
	cin >> n >> k;
	int x1, a1, b, c;
	cin >> x1 >> a1 >> b >> c;
	int x = 0;
	int s = 0;
	a[0] = x1;
	s = x1;
	if(k == 1) x ^= s;
	for(int i = 1;n > i;i++)
	{
		a[i] = a1 * a[i - 1] + b;
		a[i] %= c;
		s += a[i];
		if(i >= k) s -= a[i - k];
		if(i >= k - 1) x ^= s;
	}
	cout << x << endl;
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