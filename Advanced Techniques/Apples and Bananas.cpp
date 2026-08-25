#include <bits/stdc++.h>
#include <array>

using namespace std;

#define int long long
#define ar array
#define all(x) x.begin(),x.end()
#define cd complex<double>

const int INF = 1e17 , MOD = 1e9 + 7;
const double PI = acos(-1);

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
void fft(vector<cd> &a, bool invert)
{
    int n = a.size();

    for(int i = 1, j = 0;n > i;i++)
    {
        int bit = n / 2;
        for( ; j & bit; bit /= 2) j ^= bit;
        j ^= bit;
        if(i < j) swap(a[i], a[j]);
    }

    for(int len = 2;n >= len;len *= 2)
    {
        double ang = 2 * PI / len * (invert ? -1 : 1);
        cd wn(cos(ang), sin(ang));
        for(int i = 0;n > i;i += len)
        {
            cd w(1);
            for(int j = 0;len / 2 > j;j++)
            {
                cd u = a[i + j], v = a[i + j + len / 2] * w;

                a[i + j] = u + v;
                a[i + j + len / 2] = u - v;

                w *= wn;
            }
        }
    }

    if(invert)
    {
        for(auto& it : a) it /= n;
    }
}
vector<int> multiply(const vector<int> &a, const vector<int> &b)
{
    vector<cd> fa(all(a)), fb(all(b)), fc;
    int n = 1;
    while(n < a.size() + b.size()) n *= 2;
    fa.resize(n), fb.resize(n), fc.resize(n);

    fft(fa, false);
    fft(fb, false);

    for(int i = 0;n > i;i++) fc[i] = fa[i] * fb[i];

    fft(fc, true);

    vector<int> res(n);

    for(int i = 0;n > i;i++) res[i] = round(fc[i].real());

    while(res.size() > 1 && res.back() == 0) res.pop_back();

    return res;
}
void solve()
{
    int k, n, m;
    cin >> k >> n >> m;
    vector<int> a(k + 1), b(k + 1);
    for(int i = 0;n > i;i++)
    {
        int x;
        cin >> x;
        a[x]++;
    }
    for(int i = 0;m > i;i++)
    {
        int x;
        cin >> x;
        b[x]++;
    }
    vector<int> c = multiply(a, b);

    for(int i = 2;2 * k >= i;i++)
    {
        if(c.size() <= i) cout << "0 ";
        else cout << c[i] << " ";
    }
    cout << endl;
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
