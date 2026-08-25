#include <bits/stdc++.h>
#include <array>

using namespace std;

#define int long long
#define endl "\n"
#define ar array
#define all(x) x.begin(),x.end()

const int INF = 1e17 , MOD = 998244353LL;

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
    
    if(power % 2 == 1)
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
    int cnt = 0;
    int n1 = n - 1;
    while(n1) n1 /= 2, cnt += n1;
    int res = 0;
    if(n % 2 == 0)
    {
    	int a[n];
    	for(int i = 0;n > i;i++)
    	{
    		cin >> a[i];
    	}
    	n--;
    	for(int i = 1;n >= i;i++)
	    {
	    	int x = a[i - 1] ^ a[i];
	    	int cnt2 = 0;
	    	int i1 = i - 1;
	    	while(i1) i1 /= 2, cnt2 += i1;
	    	int n2 = n - i;
	    	while(n2) n2 /= 2, cnt2 += n2;
	    
	    	res ^= !(cnt ^ cnt2) * x;
	    }
    }
    else
    {
    	for(int i = 1;n >= i;i++)
	    {
	    	int x;
	    	cin >> x;
	    	int cnt2 = 0;
	    	int i1 = i - 1;
	    	while(i1) i1 /= 2, cnt2 += i1;
	    	int n2 = n - i;
	    	while(n2) n2 /= 2, cnt2 += n2;
	    	res ^= !(cnt ^ cnt2) * x;
	    }
    }
    cout << res << endl;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int tt;
    tt=1; 
   
    while(tt--) solve();

}
