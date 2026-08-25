#include <bits/stdc++.h>
#include <array>

using namespace std;

#define int long long
#define endl "\n"
#define ar array
#define double long double
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
const int mxN = 8, mxK = 107;
double dp[mxN][mxN][mxK];
double exp1[mxN][mxN];
ar<int,4> dir_x = {1,0,-1,0},dir_y = {0,1,0,-1};
void solve()
{
   	int robotCnt;
   	cin >> robotCnt;
 	for(int i = 0;mxN > i;i++) for(int j = 0;mxN > j;j++) exp1[i][j] = 1;
   	for(int i1 = 0;mxN > i1;i1++)
   	{
   		for(int j1 = 0;mxN > j1;j1++)
   		{
   			memset(dp,0,sizeof(dp));
   			dp[i1][j1][0] = 1.0;
			for(int k = 0;robotCnt > k;k++) 
			{
				for(int i = 0;mxN > i;i++) 
				{
					for(int j = 0;mxN > j;j++)
					{
						double cnt = 0;
						for(int dir = 0;4 > dir;dir++)
						{
							int new_i = i + dir_x[dir];
							int new_j = j + dir_y[dir];
							if(new_i < mxN && 0 <= new_i && 0 <= new_j && new_j < mxN) cnt++;
						}
						
						for(int dir = 0;4 > dir;dir++)
						{
							int new_i = i + dir_x[dir];
							int new_j = j + dir_y[dir];
							if(new_i < mxN && 0 <= new_i && 0 <= new_j && new_j < mxN)
							{
								
								dp[new_i][new_j][k + 1] += dp[i][j][k] / cnt;
							}
						}
					}
				}
			}
			for(int i = 0;mxN > i;i++) for(int j = 0;mxN > j;j++) exp1[i][j] *= 1.0 - dp[i][j][robotCnt];
   		}
   	}
   	
   	double ans = 0;
   	for(int i = 0;mxN > i;i++)
   	{
   		for(int j = 0;mxN > j;j++)
   		{
   			
   			ans += exp1[i][j];
   		}
   	}
   	cout << fixed << setprecision(6) << ans << endl;
}
int32_t main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	int tt;
	tt=1; 
	
	while(tt--) solve();

}
