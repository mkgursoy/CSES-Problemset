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
void solve()
{
    int n;
    cin >> n;
    if(n * (n + 1) % 4 == 0)
    {
        int sm = n * (n + 1) / 4;
        map<int,int> mp;
        vector<int> bir, iki;
        for(int i = n;i >= 1;i--)
        {
            if(sm > i)
            {
                sm -= i;
                bir.push_back(i);
                mp[i]++;
            }
            else
            {
                bir.push_back(sm);
                mp[sm]++;
                sm = 0;
                break;
            }
        }
        for(int i = 1;n >= i;i++)
        {
            if(!mp[i])
            {
                iki.push_back(i);
            }
        }
        cout << "YES" << endl;
        cout << bir.size() << endl;
        for(auto it : bir) cout << it << " ";
        cout << endl;
        cout << iki.size() << endl;
        for(auto it : iki) cout << it << " ";
        cout << endl;
    }
    else
    {
        cout << "NO" << endl;
    }
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int tt;
    tt=1; 
  //  cin >> tt;
    while(tt--) solve();
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
}