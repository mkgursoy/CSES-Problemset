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
int ask(bool type, int q)
{
	int x;
	if(type == 0)
	{
		cout << "F " << q << endl;
		cin >> x;
		return x;
	}
	else if(type == 1)
	{
		cout << "S " << q << endl;
		cin >> x;
		return x;
	}
	else return -1;
}
void solve()
{
   	int n,k;
   	cin >> n >> k;
   	if(n >= k)
   	{
   		int f1 = ask(0, k);
   		int s1 = ask(1, 1);
   		if(f1 > s1)
   		{
   			cout << "! " << f1 << endl;
   			return;
   		}
   		f1 = ask(0, 1);
   		s1 = ask(1, k);
   		if(s1 > f1)
   		{
   			cout << "! " << s1 << endl;
   			return;
   		}
   	}
   	int l = max(1LL, k - n), r = min(n, k - 1);
   	while(r > l)
   	{
   		int mid = (l + r) / 2;
   		int F = mid, S = k - mid;
   		int f1 = ask(0, F);
   		int s1 = ask(1, S);
   		if(s1 > f1)
   		{
   			if(S != n)
   			{
   				int s2 = ask(1, S + 1);
   				if(s2 > f1)
   				{
   					r = mid;
   				}
   				else
   				{
   					cout << "! " << f1 << endl;
   					return;
   				}
   			}
   			else
   			{
   				cout << "! " << f1 << endl;
   				return;
   			}
   		}
   		else
   		{
   			if(F != n)
   			{
   				int f2 = ask(0, F + 1);
   				if(f2 > s1)
   				{
   					l = mid + 1;
   				}
   				else
   				{
   					cout << "! " << s1 << endl;
   					return;
   				}
   			}
   			else
   			{
   				cout << "! " << s1 << endl;
   				return;
   			}
   		}
   	}
   	int f1 = ask(0, l), s1 = ask(1, k - l);
   	cout << "! " << min(f1, s1) << endl;
}
int32_t main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	int tt;
	tt=1; 
	
	while(tt--) solve();

}
