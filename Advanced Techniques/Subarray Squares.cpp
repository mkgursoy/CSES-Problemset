#include <bits/stdc++.h>
#include <array>
 
using namespace std;
 
#define int long long
#define endl "\n"
#define ar array
#define all(x) x.begin(),x.end()
 
const int INF = 3 * 1e18 , MOD = 998244353LL;
void solve()
{
    int n,m;
    cin >> n >> m;
    int a[n];
    for(int i = 0;n > i;i++) cin >> a[i];
    int pref[n];
	pref[0] = a[0];
	for(int i = 1;n > i;i++) pref[i] = a[i] + pref[i - 1];
	auto cost = [&](int l,int r)
	{
		return (pref[r] - (l ? pref[l - 1] : 0LL)) * (pref[r] - (l ? pref[l - 1] : 0LL));
	};
	auto check = [&](int lmb) -> ar<int,2>
	{
		ar<int,2> dp[n];
		for(int i = 0;n > i;i++)
		{
			dp[i] = {cost(0, i) + lmb, 1LL};
			for(int j = i - 1;j >= 0;j--)
			{
				dp[i] = min(dp[i], {cost(j + 1, i) + dp[j][0] + lmb, dp[j][1] + 1});
			}
		}
		return dp[n - 1];
	};
	int l = 0, r = INF;
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
