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
using cd = complex<double>;
const double PI = acos(-1);

void fft(vector<cd> & a, bool invert) 
{
    int n = a.size();
    if(n == 1)
    {
        return;
    }

    vector<cd> a0(n / 2), a1(n / 2);
    for(int i = 0;n > 2 * i; i++) 
    {
        a0[i] = a[2 * i];
        a1[i] = a[2 * i + 1];
    }

    fft(a0, invert);
    fft(a1, invert);

    double ang = 2 * PI / n * (invert ? -1 : 1);
    cd w(1), wn(cos(ang), sin(ang));
    for(int i = 0;n > 2 * i; i++) 
    {
        a[i] = a0[i] + w * a1[i];
        a[i + n / 2] = a0[i] - w * a1[i];
        if (invert) 
        {
            a[i] /= 2;
            a[i + n / 2] /= 2;
        }
        w *= wn;
    }
}
vector<int> multiply(vector<int> const& a, vector<int> const& b) 
{
    vector<cd> fa(a.begin(), a.end()), fb(b.begin(), b.end());
    int n = 1;
    while (n < a.size() + b.size()) n *= 2;

    fa.resize(n);
    fb.resize(n);

    fft(fa, false);
    fft(fb, false);

    for (int i = 0; i < n; i++)
    {
        fa[i] *= fb[i];
    }

    fft(fa, true);

    vector<int> result(n);
    for (int i = 0; i < n; i++)
    {
        result[i] = round(fa[i].real());
    }

    return result;
}

void solve()
{
    string s;
    cin >> s;
    int n = s.size();
    vector<int> posi(2 * n), nega(2 * n);
    for(int i = 0;n > i;i++)
    {
        if(s[i] == '1')
        {
            posi[n + i] = 1;
            nega[n - i] = 1;
        }
    }
    vector<int> c = multiply(posi, nega);
    for(int i = 2 * n + 1;3 * n - 1 >= i;i++)
    {
        cout << c[i] << " ";
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
