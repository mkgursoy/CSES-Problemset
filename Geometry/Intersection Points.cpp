#include <bits/stdc++.h>
#include <array>

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
const int mxN = 3e6 + 7;
int tree[mxN];
int constant = 1e6;
void u(int pos,int delta)
{
	for( ;mxN > pos;pos += (pos & -pos)) tree[pos] += delta;
}
int q(int l,int r)
{
	int res = 0;
	for( ;l ;l -= (l & -l)) res -= tree[l];
	for( ;r ; r-= (r & -r)) res += tree[r];
	return res;
}
void solve()
{
   	int n;
   	cin >> n;
   	vector<ar<int,3>> events;
   	vector<ar<int,2>> hor;
   	vector<int> vert;
   	vert.push_back(0), hor.push_back({0, 0});
   	for(int i = 0;n > i;i++)
   	{
   		int x1,y1,x2,y2;
   		cin >> x1 >> y1 >> x2 >> y2;
   		x1 += constant;
   		y1 += constant;
   		x2 += constant;
   		y2 += constant;
   		if(y2 == y1)
   		{
   			hor.push_back({x1, x2});
   			events.push_back({y1, (int)hor.size() - 1, 0});
   		}
   		else
   		{
   			vert.push_back(x1);
   			events.push_back({y1, -((int)vert.size() - 1), 1});
   			events.push_back({y2, -((int)vert.size() - 1), -1});
   		}

   	}
   	sort(all(events));
   	int ans = 0;
   	for(auto [y, type, extended_type] : events)
   	{
   		if(type < 0)
   		{
   			u(vert[-type], extended_type);
   		}
   		else
   		{
   			ans += q(hor[type][0], hor[type][1]);
   		}
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
