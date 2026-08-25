#include <bits/stdc++.h>
#include <array>

using namespace std;

#define int long long
#define endl "\n"
#define ar array
#define all(x) x.begin(),x.end()

const int INF = 1e17 , MOD = 1e9 + 7;

int binpow(int base,int power)
{
	if(power == 1) return base;
	if(power == 0) return 1;
    
     if(power%2==1)
     {
     	 int a;
     	a = binpow(base,(power-1)/2);
     	return a*a*base;
     } 
     else
     {
     	 int a;
     	a = binpow(base,power/2);
     	return a*a;
     } 

}

int mul(int a,int b)
{
	a %= MOD;
	b %= MOD;
	return a * 1LL * b % MOD;
}
int add(int a,int b)
{
	a %= MOD;
	b %= MOD;
	return (a + b + MOD) % MOD;
}
void solve()
{
   	int n;
   	cin >> n;
   	int ans = 0;
   	for(int i = 1;n >= i;i++)
   	{
   		int x = n / i;
   		int big = n / x;
   		ans = add(ans, mul(x,mul(mul(big + i,big - i + 1), ((int)1e9 + 8) / 2LL )));
   		i = big;
   		
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
