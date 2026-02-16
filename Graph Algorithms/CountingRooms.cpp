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
const int mxN = 1e3 + 5,mxM = 1e3 + 5;
string s[mxN];
int vis[mxN][mxM];
int n,m;
bool check(int i,int j)
{
	if(n > i && i >= 0 && m > j && j >= 0 && vis[i][j] == 0 && s[i][j] == '.') return true;
	else return false;
}
void dfs(int i,int j)
{
	vis[i][j] = 1;
	if(check(i+1,j)) dfs(i+1,j);
	if(check(i-1,j)) dfs(i-1,j);
	if(check(i,j-1)) dfs(i,j-1);
	if(check(i,j+1)) dfs(i,j+1);
}
void solve()
{
	cin >> n >> m;
	int cnt = 0;
	for(int i = 0;n > i;i++) cin >> s[i];
	for(int i = 0;n > i;i++)
	{
		for(int j = 0;m > j;j++)
		{
			if(!vis[i][j] && s[i][j] == '.')
			{
				cnt += 1;
				dfs(i,j);
			}
		}
	}
	cout << cnt << endl;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int tt;
    tt=1; 
   // cin >> tt;
    while(tt--) solve();
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
}