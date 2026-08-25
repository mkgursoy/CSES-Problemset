#include <bits/stdc++.h>
#include <array>

using namespace std;

#define int long long
#define ar array
#define all(x) x.begin(),x.end()
#define double long double
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
bool cross1(ar<int,2> x, ar<int,2> y, int i)
{
	auto [a1, b1] = x;
	auto [a2, b2] = y;
	return (a1 + b1 * i) <= (a2 + b2 * i);
}
bool cross2(ar<int,2> x, ar<int,2> y, ar<int,2> z)
{
    auto [a1, b1] = x;
    auto [a2, b2] = y;
    auto [a3, b3] = z;
    
    return (a1 - a2) * (b3 - b1) >= (a1 - a3) * (b2 - b1);
}
bool cross3(ar<int,2> x, ar<int,2> y)
{
    auto [a1, b1] = x;
    auto [a2, b2] = y;
    return (a1 >= a2) && (b1 >= b2);
}
void solve()
{
    int n, m;
    cin >> n >> m;
    deque<ar<int,2>> dq;
    vector<ar<int,2>> denklemler;
    for(int i = 0;n > i;i++)
    {
    	ar<int,2> denklem;
    	int x, y;
    	cin >> x >> y;
    	denklem = {x, (y - x) / m};
    	denklemler.push_back(denklem);
    }
    sort(all(denklemler), [&](ar<int,2> x, ar<int,2> y)
    {
        return x > y;
    });
    for(auto denklem : denklemler)
    {
        while(dq.size() >= 2 && cross3(dq[0], dq[1]))
        {
          
            auto h = dq.front();
            dq.pop_front();
            dq.pop_front();
            dq.push_front(h);
        }
        
        if(dq.size() && cross3(dq.back(), denklem))
        {
            continue;
        }
    	while(dq.size() >= 2 && cross2(dq[dq.size() - 2], dq[dq.size() - 1] , denklem)) dq.pop_back();
    	dq.push_back(denklem);
    }
    for(int i = 0;m >= i;i++)
    {
    	while(dq.size() >= 2 && cross1(dq[0], dq[1], i)) dq.pop_front();
    	cout << dq[0][0] + dq[0][1] * i << " ";
    }
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int tt;
    tt=1; 
  
    while(tt--) solve();
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
}
