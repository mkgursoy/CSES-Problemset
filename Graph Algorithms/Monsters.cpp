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
const int mxN = 1e3 + 5,mxM = 1e3 + 5;
string s[mxN];
int n,m;
int sp[mxN][mxM];
ar<int,2> pre[mxN][mxM];
int vis[mxN][mxM];
ar<int,2> st;
vector<ar<int,2>> monsters;
bool check(int i,int j)
{
    if(n > i && i >= 0 && m > j && j >= 0 && vis[i][j] == 0 && s[i][j] != '#') return true;
    return false;
}
bool check2(int i,int j,int val)
{
    if(n > i && i >= 0 && m > j && j >= 0 && vis[i][j] == 0 && s[i][j] != '#' && (sp[i][j] == -1 || sp[i][j] > val)) return true;
    return false;
}
void tryPath()
{
    memset(vis,0,sizeof(vis));
    queue<ar<int,3>> que;
    que.push({st[0],st[1],0});
    vis[st[0]][st[1]] = 1;
    while(que.size())
    {
        ar<int,3> piv = que.front();
        if(piv[0] == 0 || piv[0] == n-1 || piv[1] == 0 || piv[1] == m-1)
        {
            cout << "YES" << endl;
            vector<char> ans;
            while(piv[0] != st[0] || piv[1] != st[1])
            {
 
                ar<int,2> pr = pre[piv[0]][piv[1]];         
                if(pr[0] == 1 && pr[1] == 0) ans.push_back('U');
                if(pr[0] == -1 && pr[1] == 0) ans.push_back('D');
                if(pr[0] == 0 && pr[1] == 1) ans.push_back('L');
                if(pr[0] == 0 && pr[1] == -1) ans.push_back('R');   
                piv[0] += pr[0];
                piv[1] += pr[1];
            }
            reverse(all(ans));
            cout << ans.size() << endl;
            for(auto it : ans) cout << it;
            exit(0);
        }
        que.pop();
        if(check2(piv[0]+1,piv[1],piv[2]+1))
        {
            pre[piv[0]+1][piv[1]] = {-1,0};
            que.push({piv[0]+1,piv[1],piv[2]+1});
            vis[piv[0]+1][piv[1]] = 1;
        }
        if(check2(piv[0]-1,piv[1],piv[2]+1))
        {
            pre[piv[0]-1][piv[1]] = {+1,0};
            que.push({piv[0]-1,piv[1],piv[2]+1});
            vis[piv[0]-1][piv[1]] = 1;
        }
        if(check2(piv[0],piv[1]+1,piv[2]+1))
        {
            pre[piv[0]][piv[1]+1] = {0,-1};
            que.push({piv[0],piv[1]+1,piv[2]+1});
            vis[piv[0]][piv[1]+1] = 1;
        }
        if(check2(piv[0],piv[1]-1,piv[2]+1))
        {
            pre[piv[0]][piv[1]-1] = {0,+1};
            que.push({piv[0],piv[1]-1,piv[2]+1});
            vis[piv[0]][piv[1]-1] = 1;
        }
    }
}
void fillAr()
{
    memset(sp,-1,sizeof(sp));
    queue<ar<int,3>> que;
    for(auto it : monsters) que.push({it[0],it[1],0}),sp[it[0]][it[1]] = 0,vis[it[0]][it[1]] = 1;
 
    while(que.size())
    {
        ar<int,3> piv = que.front();
        sp[piv[0]][piv[1]] = piv[2];
        que.pop();
 
        if(check(piv[0]+1,piv[1]))
        {
            que.push({piv[0]+1,piv[1],piv[2]+1});
            vis[piv[0]+1][piv[1]] = 1;
        }
        if(check(piv[0]-1,piv[1]))
        {
            que.push({piv[0]-1,piv[1],piv[2]+1});
            vis[piv[0]-1][piv[1]] = 1;
        }
        if(check(piv[0],piv[1]+1))
        {
            que.push({piv[0],piv[1]+1,piv[2]+1});
            vis[piv[0]][piv[1]+1] = 1;
        }
        if(check(piv[0],piv[1]-1))
        {
            que.push({piv[0],piv[1]-1,piv[2]+1});
            vis[piv[0]][piv[1]-1] = 1;
        }
    }
}
void solve()
{
    cin >> n >> m;
    for(int i = 0;n > i;i++)
    {
        cin >> s[i];
        for(int j = 0;m > j;j++)
        {
            if(s[i][j] == 'A') st = {i, j};
            if(s[i][j] == 'M') monsters.push_back({i,j});
        }
    } 
    fillAr();

    tryPath();
    cout << "NO" << endl;
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