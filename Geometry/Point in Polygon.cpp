#include <bits/stdc++.h>
#include <array>

using namespace std;

#define int long long
#define endl "\n"
#define ar array
#define all(x) x.begin(),x.end()

const int INF = 1e9 + 7 , MOD = 998244353LL;

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
    
    if(power % 2 == 1)
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
bool LineSegmentInteraction(vector<point> a)
{
    int res1 = cross(minus1(a[0], a[2]), minus1(a[1], a[2]));
    int res2 = cross(minus1(a[0], a[3]), minus1(a[1], a[3]));
    int res3 = cross(minus1(a[2], a[0]), minus1(a[3], a[0]));
    int res4 = cross(minus1(a[2], a[1]), minus1(a[3], a[1]));
    if(((max(a[0].x, a[1].x)) < (min(a[2].x, a[3].x))) || ((min(a[0].x, a[1].x)) > (max(a[2].x, a[3].x))))
    {
        return false;
    }
    if(((max(a[0].y, a[1].y)) < (min(a[2].y, a[3].y))) || ((min(a[0].y, a[1].y)) > (max(a[2].y, a[3].y))))
    {
       	return false;
    }
    if((res1 == 0 || res2 == 0 || (res1 > 0) != (res2 > 0)) && (res3 == 0 || res4 == 0 || (res3 > 0) != (res4 > 0))) return true;
    else return false;
}
void solve()
{
    int n,q;
    cin >> n >> q;
    vector<point> a;
    for(int i = 0;n > i;i++)
    {
    	int x,y;
    	cin >> x >> y;
    	point new_point(x, y);
    	a.push_back(new_point);
    }
    a.push_back(a[0]);
    while(q--)
    {
    	int x,y;
    	cin >> x >> y;
    	point query(x, y);
    	bool f = false;
    	for(int i = 0;n > i;i++)
    	{
    		if(LineSegmentInteraction({a[i], a[i + 1], query, query}))
    		{
                
    			f = !f;
    			break;
    		}
    	}
    	if(f)
    	{
    		cout << "BOUNDARY" << endl;
    		continue;
    	}
    	int cnt = 0;
        srand(0);
    	point query2(INF, INF - rand() % (int)1e9 + 7);
    	for(int i = 0;n > i;i++)
    	{
    		if(LineSegmentInteraction({a[i], a[i + 1], query, query2}))
    		{
              
    			cnt++;
    		}
    	}
    	if(cnt % 2 == 0)
    	{
    		cout << "OUTSIDE" << endl;
    	}
    	else
    	{
    		cout << "INSIDE" << endl;
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
