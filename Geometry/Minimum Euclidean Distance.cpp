#include <bits/stdc++.h>
#include <array>

using namespace std;

#define int long long
#define endl "\n"
#define ar array
#define all(x) x.begin(),x.end()

const int INF = 9e18 , MOD = 998244353LL;

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
    bool operator<(point a) const
    {
        return (x == a.x ? y < a.y : x < a.x);
    }
    bool operator==(point a) const
    {
        return x == a.x;
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
    int n;
    cin >> n;
    vector<point> a;
    for(int i = 0;n > i;i++)
    {
    	int x,y;
    	cin >> x >> y;
    	point new_point(x, y);
    	a.push_back(new_point);
    }
    sort(all(a));
    set<point> st;
    point new_point(a[0].y,a[0].x);
   
    st.insert(new_point);
    int ans = INF;
    int j = 0;
    for(int i = 1;n > i;i++)
    {
        while(i > j && a[i].x - a[j].x > sqrt(ans) + 1)
        {
            point erased(a[j].y, a[j].x);
            st.erase(erased);
            j++;
        }
        point comp1(a[i].y - sqrt(ans) - 1, 0LL);
        point comp2(a[i].y + sqrt(ans) + 1, 0LL);
        auto h = st.lower_bound(comp1);
        auto h2 = st.upper_bound(comp2);
        if(h2 != st.end()) h2++;
        if(h != st.begin()) h--;
        for( ;h2 != h;h++)
        {
            point k = *h;
          
            ans = min(ans, (a[i].x - k.y) * (a[i].x - k.y) + (a[i].y - k.x) * (a[i].y - k.x));
        }
       
        point new_point1(a[i].y,a[i].x);
        st.insert(new_point1);
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
