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
struct Trie
{
	struct Node
	{
		int alf[26];
		int stop;
		Node()
		{
			stop = 0;
			memset(alf,0,sizeof(alf));
		}
	};
	vector<Node> tree;
	vector<int> dp;
	Trie(string _sz)
	{
		tree.emplace_back();
		dp.resize(_sz.size() + 7);
	}
	int newNode()
	{
		tree.emplace_back();
		return tree.size() - 1;
	}
	void insert(string s)
	{
		int pos = 0;
		for(auto it : s)
		{
			if(!tree[pos].alf[it - 'a']) tree[pos].alf[it - 'a'] = newNode();
			pos = tree[pos].alf[it - 'a'];
		}	
		tree[pos].stop = 1;
	}
	void Search(string s1,int x)
	{
		int ans = 0;
		int pos = 0;
		for(int i = x;s1.size() > i;i++)
		{
			char it = s1[i];
			if(!tree[pos].alf[it - 'a']) break;
			pos = tree[pos].alf[it - 'a'];
			if(tree[pos].stop == 1)
			{
				ans = sum(ans,dp[i + 1]);
			}
		}
		dp[x] = ans;
	}
	int findNumOfWays(string s)
	{
		dp[s.size()] = 1;
		int n = s.size();
		for(int i = n - 1;i >= 0;i--) Search(s,i);
		return dp[0];
	}
};
void solve()
{
   	string s;
   	cin >> s;
   	int k;
   	cin >> k;
   	Trie tree(s);
   	while(k--)
   	{
   		string h;
   		cin >> h;
   		tree.insert(h);
   	}
   	cout << tree.findNumOfWays(s) << endl;
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