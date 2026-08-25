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
const int mxN = 1e7 + 7;
int a[mxN];
int pre_blok[mxN], suf_blok[mxN];
void solve()
{
	int n,k;
	cin >> n >> k;
	int x1, a1, b, c;
	cin >> x1 >> a1 >> b >> c;
	int x = 0;
	int s[32];
    memset(s,0,sizeof(s));
    a[0] = x1;
    for(int i = 1;n > i;i++)
    {
        a[i] = a1 * a[i - 1] + b;
        a[i] %= c;
    }
    if(k == 1)
    {
        for(int i = 0;n > i;i++)
        {
            x ^= a[i];
        }
        cout << x << endl;
        return;
    }
    int blok = -1;
    int orr = 0;
	for(int i = 0;n > i;i++)
	{
		if(i % k == 0) blok++, orr = 0;
        int ind = blok * k + i % k;
        pre_blok[ind] = (orr |= a[i]);
	}
  
    int pre_i = -1;
    blok = -1;
    for(int i = k - 1;n > i;i = min(n - 1, i + k))
    {
        blok++;
        orr = 0;
        for(int j = i;j > pre_i;j--)
        {
            orr |= a[j];
            int ind = blok * k + (i - j);
            suf_blok[ind] = orr;
        }
        if(i == n - 1) break;
        pre_i = i;
    }
  
    int blok_num = 0;
    for(int i = k - 1;n > i;i++)
    {
        if(i % k == 0) blok_num++;

        if(i % k == k - 1)
        {
            int ind = blok_num * k + i % k;
            x ^= pre_blok[ind];
        
        }
        else
        {
            int ind1 = blok_num * k + i % k;
            int ind2 = (blok_num - 1) * k + (k - 1 - i % k - 1);
            int blok1 = pre_blok[ind1];
            int blok2 = suf_blok[ind2];
        
            x ^= (blok1 | blok2);
        }

    }
	cout << x << endl;
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
