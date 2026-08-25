#include <bits/stdc++.h>
#include <array>
 
using namespace std;
 
#define int long long
#define endl "\n"
#define ar array
#define all(x) x.begin(),x.end()
 
const int INF = 1e18 , MOD = 998244353LL;
void solve()
{
    int n,m;
    cin >> n >> m;
    int a[n];
    for(int i = 0;n > i;i++) cin >> a[i];
    int pref[n];
	int suf[n];
	pref[0] = a[0];
	suf[n - 1] = a[n - 1];
	for(int i = 1;n > i;i++) pref[i] = (i + 1) * a[i] + pref[i - 1];
	for(int i = n - 2;i >= 0;i--) suf[i] = (n - i) * a[i] + suf[i + 1];
	for(int i = 1;n > i;i++) a[i] += a[i - 1];
	auto cost = [&](int l,int r)
	{
		
		int mid = (l + r) / 2;
		int cost_left = (pref[mid] - pref[l - 1]) - l * (a[mid] - a[l - 1]);
		int cost_right = (suf[mid + 1] - suf[r + 1]) - (n - r - 1) * (a[r] - a[mid]);
		return cost_left + cost_right;
	};
	auto check = [&](int lmb) -> ar<int,2>
	{
		ar<int,2> dp[n];
		dp[0] = {lmb, 1};
		for(int i = 1;n > i;i++)
		{
			dp[i] = {INF,0};
			for(int j = i - 1;j >= 0;j--)
			{
				dp[i] = min(dp[i], {dp[j][0] + cost(j + 1, i - 1), dp[j][1] + 1});
			}
			dp[i] = min(dp[i], {(suf[0] - suf[i]) - (n - i) * (a[i - 1]), 1});
			dp[i][0] += lmb;
		}
		ar<int,2> ans = dp[n - 1];
		for(int i = n - 2;i >= 0;i--)
		{
			ans = min(ans, {dp[i][0] + (pref[n - 1] - pref[i]) - (i + 1) * (a[n - 1] - a[i]), dp[i][1]});
		}
		return ans;
	};
	int l = n, r = INF;
	while(r > l)
	{
		int mid = (l + r) / 2;
	
		if(check(mid)[1] >= m)
		{
			l = mid + 1;
		}
		else r = mid;
	}
	ar<int,2> a1 = check(l);

	cout << a1[0] - m * (l) << endl;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    int tt;
    tt=1; 
   
    while(tt--) solve();
 
}
