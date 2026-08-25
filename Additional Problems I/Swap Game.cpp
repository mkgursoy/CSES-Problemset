#include <iostream>
#include <array>
#include<unordered_map>
#include<vector>
#include<queue>

using namespace std;

#define int long long
#define endl "\n"
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
int pw[10];
int calc(int x,int y,int ans)
{
	int x1 = (ans % (pw[x + 1])) / (pw[x]);
	int y1 = (ans % (pw[y + 1])) / (pw[y]);
	return ans - pw[x] * x1 - pw[y] * y1 + pw[y] * x1 + pw[x] * y1;
}
void solve()
{
	int n = 9;
   	vector<int> vec(9);
   	pw[0] = 1LL;
   	for(int i = 1;10 > i;i++) pw[i] = 9 * pw[i - 1];
   	vector<bool> mp(pw[9] * 7, false);
   	int op = 0;
   	for(int i = 0;9 > i;i++) cin >> vec[i], op += pw[8 - i] * (vec[i] - 1);
   	queue<ar<int,2>> bfs;
   	bfs.push({op, 1LL});
   	int tr = 0;
   	for(int i = 0;9 > i;i++) tr += pw[8 - i] * (i);
   	while(bfs.size())
   	{
   		auto [vec, moves] = bfs.front();
   		bfs.pop();
   		if(vec == tr)
		{
			cout << moves - 1 << endl;
			return;
		}
   		for(int i = 0;8 > i;i++)
   		{
   			int swap_h = 0;
   			if(i < 6) swap_h = calc(8 - i,8 - (i + 3), vec);
   			int swap_v = calc(8 - i,8 - (i + 1), vec);
   			if(!mp[swap_h] && i < 6)
   			{
   				mp[swap_h] = true;
   				bfs.push({swap_h, moves + 1});
   			}
   			if(!mp[swap_v] && i % 3 != 2)
   			{
   				mp[swap_v] = true;
   				bfs.push({swap_v, moves + 1});
   			}
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
