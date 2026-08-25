#include <bits/stdc++.h>
#include <array>

using namespace std;

#define int long long
#define endl "\n"
#define ar array
#define all(x) x.begin(),x.end()

const int INF = 1e17 , MOD = 1e9 + 7;

int binpow(int base,int power)
{
	if(power == 1) return base;
	if(power == 0) return 1;
    
     if(power%2==1)
     {
     	 int a;
     	a = binpow(base,(power-1)/2);
     	return a*a*base;
     } 
     else
     {
     	 int a;
     	a = binpow(base,power/2);
     	return a*a;
     } 

}
const int mxN = 1e5 + 7;
int par[mxN];
int rank1[mxN];
int ans[mxN];
vector<int> upd;
map<ar<int,2>,int> mp;
int comp_cnt;
int find(int node)
{
	if(par[node] == node) return node;
	return find(par[node]);
}
void union_sets(int a,int b)
{
	a = find(a);
	b = find(b);
	if(a == b)
	{
		return;
	}
	if(rank1[a] > rank1[b]) swap(a,b);
	par[a] = b;
	rank1[b] += rank1[a];
	upd.push_back(a);
	comp_cnt--;
}
void rollback(int k)
{
	while((int)upd.size() > k)
	{
		int piv = upd.back();
		upd.pop_back();
		rank1[par[piv]] -= rank1[piv];
		par[piv] = piv;
		comp_cnt++;
	}
}
vector<ar<int,2>> tree[4*mxN + 23];
void update(int l,int r,int tl,int tr,int pos,ar<int,2> op)
{
	if(r < tl || tr < l) return;
	if(tr >= r && l >= tl)
	{
		
		tree[pos].push_back(op);
		return;
	}
	int mid = (l+r)/2;
	update(l,mid,tl,tr,pos*2,op);
	update(mid+1,r,tl,tr,pos*2+1,op);
}
void solveTree(int l,int r,int pos)
{
	int roll_cnt = upd.size();
	for(auto it : tree[pos])
	{
		union_sets(it[0],it[1]);
		
 	}

	if(l == r)
	{
		cout << comp_cnt << " ";
	}
	else
	{
		int mid = (l+r)/2;
		solveTree(l,mid,pos*2);
		solveTree(mid+1,r,pos*2+1);
	}
	rollback(roll_cnt);
}
void solve()
{
   	int n,m,q;
   	cin >> n >> m >> q;
   	comp_cnt = n;
   	upd.clear();
   	for(int i = 0;mxN >= i;i++) rank1[i] = i;
   	for(int i = 0;mxN >= i;i++) par[i] = i;
   	for(int i = 0;m > i;i++)
   	{
   		int x,y;
   		cin >> x >> y;
   		x--,y--;
   		if(x > y) swap(x,y);
   		mp[{x,y}] = 0;
   	}
   	for(int i = 1;q >= i;i++)
   	{
   		int op;
   		cin >> op;
   		if(op == 1)
   		{
   			int x,y;
   			cin >> x >> y;
   			x--,y--;
   			if(x > y) swap(x,y);

   			mp[{x,y}] = i;
   		}
   		if(op == 2)
   		{
   			int x,y;
   			cin >> x >> y;
   			x--,y--;
   			if(x > y) swap(x,y);

   			update(0,q,mp[{x,y}],i-1,1,{x,y});
   			mp.erase({x,y});
   		}

   	}
   	for(auto [f,s] : mp)
   	{
   		update(0,q,s,q,1,f);
   	}
   	solveTree(0,q,1);
}
int32_t main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	int tt;
	tt=1; 
	
	while(tt--) solve();

}
