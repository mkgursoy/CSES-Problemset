#include <bits/stdc++.h>
#include <array>

using namespace std;

#define int long long
#define endl "\n"
#define ar array
#define all(x) x.begin(),x.end()

const int INF = 1000000000000000009LL , MOD = 1e9 + 7;

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
struct Matrix
{
	int a[107][107];
	Matrix mult(Matrix x,Matrix y)
	{
		Matrix res;
		for(int i = 0;107 > i;i++) for(int j = 0;107 > j;j++) res.a[i][j] = INF;
		for(int i = 0;107 > i;i++)
		{
			for(int j = 0;107 > j;j++)
			{
				for(int k = 0;107 > k;k++)
				{
					res.a[i][k] = min(res.a[i][k],x.a[i][j] + y.a[j][k]);
				}
			}
		}
		return res;
	}
	Matrix Pow(Matrix mt,int power)
	{
		Matrix res;
		for(int i = 0;107 > i;i++) for(int j = 0;107 > j;j++) res.a[i][j] = INF;
		for(int i = 0;107 > i;i++) res.a[i][i] = 0;

		while(power)
		{
			if(power % 2 == 1)
			{
				res = mult(res, mt);
			}
			power /= 2;
			mt = mult(mt, mt);
		}
		return res;
	}

};
void solve()
{
   	Matrix adj;
   	int n,m,k;
   	cin >> n >> m >> k;
   	for(int i = 0;107 > i;i++) for(int j = 0;107 > j;j++) adj.a[i][j] = INF;
   	while(m--)
   	{
   		int x,y,z;
   		cin >> x >> y >> z;
   		x--,y--;
   		adj.a[x][y] = min(adj.a[x][y], z);
   	}
   	int ans = adj.Pow(adj,k).a[0][n - 1];
   	if(ans == INF)
   	{
   		cout << "-1" << endl;
   	}
   	else
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
