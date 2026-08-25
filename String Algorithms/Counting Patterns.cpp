#include <bits/stdc++.h>
#include <array>

#pragma GCC optimize("O3")

using namespace std;

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
const int mxN = 5e5 + 7;
string inp[mxN];
struct Node
{
    vector<int> bit;
    int suff, outp;
    int go[26];
    Node()
    {
        suff = 0, outp = -1;
        memset(go, 0, sizeof(go));
    }
};
vector<Node> trie;
unordered_map<string,int> mp;
int new_node()
{
    trie.emplace_back();
    return trie.size() - 1;
}
void inserti(string s,int l)
{
    int nd = 0;
    for(auto it : s)
    {
        if(!trie[nd].go[it - 'a']) trie[nd].go[it - 'a'] = new_node();
        nd = trie[nd].go[it - 'a']; 
      
    }
    trie[nd].bit.push_back(l);
}
void find_suff_outp()
{
    queue<int> nds;
    nds.push(0);
    trie[0].suff = 0, trie[0].outp = -1;
    while(nds.size())
    {
        int nd = nds.front();
        nds.pop();
        int sf = trie[nd].suff;
        for(int i = 0;26 > i;i++)
        {
            if(trie[nd].go[i])
            {
                int sf2 = sf;
                while(sf2 && !trie[sf2].go[i]) sf2 = trie[sf2].suff;

                if(trie[sf2].go[i] && trie[sf2].go[i] != trie[nd].go[i]) trie[trie[nd].go[i]].suff = trie[sf2].go[i];

                if(trie[trie[trie[nd].go[i]].suff].bit.size()) trie[trie[nd].go[i]].outp = trie[trie[nd].go[i]].suff;
                else trie[trie[nd].go[i]].outp = trie[trie[trie[nd].go[i]].suff].outp;
                nds.push(trie[nd].go[i]);
            }
        }
    }
}
void solve()
{
    string s;
    cin >> s;
    int q;
    cin >> q;
    trie.emplace_back();
    for(int i = 0;q > i;i++)
    {
        cin >> inp[i];
        if(!mp.count(inp[i])) inserti(inp[i], i), mp[inp[i]] = i;
    }
    find_suff_outp();
    int pos[q];
    memset(pos,0,sizeof(pos));
    int nd = 0;
    for(auto it : s)
    {
        while(nd && !trie[nd].go[it - 'a']) nd = trie[nd].suff;
        nd = trie[nd].go[it - 'a'];
        int nd2 = nd;
        while(nd2 != -1)
        {
            for(auto it1 : trie[nd2].bit)
            {
                pos[it1]++;
            }
            nd2 = trie[nd2].outp;
        }
    }
    for(int i = 0;q > i;i++)
    {
        cout << pos[mp[inp[i]]] << "\n";
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
