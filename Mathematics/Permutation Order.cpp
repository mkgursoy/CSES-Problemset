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
int fact[21];
void solve()
{
	fact[0] = 1;
	for(int i = 1;21 > i;i++) fact[i] = fact[i - 1] * i;
   	int op;
   	cin >> op;
   	if(op == 1)
   	{
   		int n, k;
   		cin >> n >> k;
   		k--;
   		set<int> st;
   		for(int i = 1;n >= i;i++) st.insert(i);
   		for(int i = 0;n > i;i++)
   		{
   			auto it = st.begin();
   			while(fact[n - i - 1] <= k)
   			{
   				k -= fact[n - i - 1];
   				it++;
   			}
   			cout << *it << " ";
   			st.erase(it);
   		}
   		cout << endl;
   	}
   	else
   	{
   		int n;
   		cin >> n;
   		int a[n];
   		int k = 1;
   		for(int i = 0;n > i;i++)
   		{
   			cin >> a[i];
   		}
   		set<int> st;
   		for(int i = 1;n >= i;i++) st.insert(i);
   		for(int i = 0;n > i;i++)
   		{
   			auto it = st.begin();
   			while(*it != a[i]) k += fact[n - i - 1], it++;
   			st.erase(it);
   		}
   		cout << k << endl;
   	}
}
int32_t main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	int tt;
	tt=1; 
	cin >> tt;
	while(tt--) solve();

}
