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
void solve()
{
	int n;
	cin >> n;
	multiset<int> axay, exay, axey, exey;
	int ans = 0;
	while(n--)
	{
		int x,y;
		cin >> x >> y;
		int p1 = -x-y;
		int p2 = +x-y;
		int p3 = -x+y;
		int p4 = +x+y;
		if(axay.size()) ans = max(ans, *axay.rbegin() + p1);
		if(exay.size()) ans = max(ans, *exay.rbegin() + p2);
		if(axey.size()) ans = max(ans, *axey.rbegin() + p3);
		if(exey.size()) ans = max(ans, *exey.rbegin() + p4);
		axay.insert(p4);
		exay.insert(p3);
		axey.insert(p2);
		exey.insert(p1);
		cout << ans << endl;
	}
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
