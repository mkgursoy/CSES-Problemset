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
struct point
{
	int x,y;
	point(int _x,int _y)
	{
		x = _x, y = _y;
	}
};
int cross(point a,point b)
{
	return a.x * b.y - a.y * b.x;
}
point minus1(point a,point b)
{
	point res(a.x - b.x, a.y - b.y);
	return res;
}
point plus(point a,point b)
{
	point res(a.x + b.x, a.y + b.y);
	return res;
}
void solve()
{
    vector<point> a;
    for(int i = 0;3 > i;i++)
    {
    	int x,y;
    	cin >> x >> y;
    	point new_point(x, y);
    	a.push_back(new_point);
    }
    int res = cross(minus1(a[0], a[2]), minus1(a[1], a[2]));
    if(res == 0) cout << "TOUCH" << endl;
    else if(res < 0) cout << "RIGHT" << endl;
    else cout << "LEFT" << endl;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int tt;
    tt=1; 
    cin >> tt;
    while(tt--) solve();
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
}