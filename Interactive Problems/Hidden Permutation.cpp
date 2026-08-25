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
int s_greater(int x,int y)
{
	cout << "? " << x << " " << y << endl;
	string s;
	cin >> s;
	return (s == "YES");
}
vector<int> merge_sort(vector<int> vec)
{
	if(vec.size() == 1) return vec;
	vector<int> vec1,vec2;
	for(int i = 0;vec.size() / 2 > i;i++) vec1.push_back(vec[i]);
	for(int i = vec.size() / 2;vec.size() > i;i++) vec2.push_back(vec[i]);
	vec1 = merge_sort(vec1);
	vec2 = merge_sort(vec2);
	int n = vec1.size(), m = vec2.size();
	int i = 0, j = 0;
	vector<int> new_vec;
	while(n > i && m > j)
	{
		bool b;
		b = s_greater(vec1[i], vec2[j]);
		if(b) new_vec.push_back(vec1[i++]);
		else new_vec.push_back(vec2[j++]);
	}
	while(n > i) new_vec.push_back(vec1[i++]);
	while(m > j) new_vec.push_back(vec2[j++]);
	return new_vec;
}
void solve()
{
   	int n;
   	cin >> n;
   	vector<int> vec(n);
   	iota(all(vec), 1LL);
   	vec = merge_sort(vec);
   	int a[n];
   	for(int i = 0;n > i;i++)
   	{
   		a[vec[i] - 1] = i + 1;
   	}
   	cout << "! ";
   	for(auto it : a) cout << it << " ";
   	cout << endl;
}
int32_t main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	int tt;
	tt=1; 
	
	while(tt--) solve();

}
