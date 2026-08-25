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
void solve()
{
   	int n;
   	cin >> n;
   	int p[n];
   	for(int i = 0;n > i;i++)
   	{
   		int sc_1,sc_2,sc_3;
   		cout << "1 " << i + 1 << endl;
   		cin >> sc_1;
   		if(sc_1 == 0) return;
   		cout << "1 " << i + 1 << endl;
   		cin >> sc_2;
   		if(sc_2 == 0) return;
   		sc_3 = sc_2 + sc_1;
   		sc_3 -= (i + 1) * (i) / 2;
   		p[i] = sc_2 - sc_3 / 2;
   	}
  
   	int a[n];
   	map<int,int> mp;
   	for(int i = n - 1;i > 0;i--)
   	{
   		int delta = p[i] - p[i - 1] + 1;
   		int st = 0;
   		int ind = n;
   		while(st != delta)
   		{
   			if(!mp[ind])
   			{
   				st++;
   			}
   			ind--;
   		}
   		mp[ind + 1] = 23LL;
   		a[i] = ind + 1;
   	}
   	int st = 0;
	int ind = n;
	while(st != p[0] + 1)
	{
		if(!mp[ind])
		{
			st++;
		}
		ind--;
	}
	mp[ind + 1] = 23LL;
	a[0] = ind + 1;
	
	map<int,int> index;
	for(int i = 1;n >= i;i++) index[a[i - 1]] = i;
	for(int i = 1;n >= i;i++)
	{
		cout << min(i, index[i]) << " " << max(i, index[i]) << endl;
		int x;
		cin >> x;
		if(x == 0) return;
		for(int j = min(i, index[i]) - 1; (max(i, index[i]) + min(i, index[i]) - 1) / 2 > j;j++)
		{
			swap(a[j], a[max(i, index[i]) - (j - min(i, index[i]) + 1) - 1]);
		}
		for(int i = 1;n >= i;i++)
		{
			index[a[i - 1]] = i;
		}
	}
}
int32_t main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	int tt;
	tt=1; 
	
	while(tt--) solve();

}
