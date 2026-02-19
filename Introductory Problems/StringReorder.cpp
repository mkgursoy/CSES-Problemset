/*
    Author: Matkap (prefix_sum)
*/

#include <bits/stdc++.h>
#include <array>

using namespace std;

#define int long long
#define ar array
#define all(x) x.begin(),x.end()

const int INF = 1e17 , MOD = LONG_LONG_MAX;

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
char hsh(char v)
{
    v -= 'A';
    v = (char)26 - v;
    v += 'A';
    return v;
}
void solve()
{
    string s;
    cin >> s;
    set<pair<int, char>> st;
    map<char,int> mp;
    for(auto it : s)
    {
        if(mp[it] == 0)
        {
            mp[it]++;
            st.insert({mp[it], hsh(it)});
        }
        else
        {
            st.erase({mp[it], hsh(it)});
            mp[it]++;
            st.insert({mp[it], hsh(it)});
        }
    }
    int n = s.size();
    if((*(--st.end())).first > (n + 1) / 2)
    {
        cout << "-1" << endl;
        return;
    }
    char prev = '+';
    for(auto irrelevant : s)
    {
        n--;
        if((*(--st.end())).first > (n + 1) / 2)
        {
            cout << hsh((*(--st.end())).second);
            prev = hsh((*(--st.end())).second);
            pair<int,char> new_pair;
            new_pair = {(*(--st.end())).first - 1, (*(--st.end())).second};
            mp[hsh((*(--st.end())).second)]--;
            st.erase(--st.end());
            if(new_pair.first != 0)
            st.insert(new_pair);
        }
        else
        {
            for(char it = 'A';'Z' >= it;it++)
            {
                if(mp[it] > 0 && it != prev)
                {
                    cout << it;
                    prev = it;
                    st.erase({mp[it], hsh(it)});
                    mp[it]--;
                    if(mp[it] != 0)
                    st.insert({mp[it], hsh(it)});
                    break;
                }
            }
        }
    }
    cout << endl;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int tt;
    tt=1; 
    //cin >> tt;
    while(tt--) solve();
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
}