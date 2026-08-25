#include <bits/stdc++.h>
#include <array>

using namespace std;

#define fr freopen("/Users/metinkasim/Documents/in.txt","r",stdin);freopen("/Users/metinkasim/Documents/out.txt","w",stdout);
#define int long long
#define endl "\n"
#define ar array
#define all(x) x.begin(),x.end()

int mxn = 1e18;
int mnn = -mxn;

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
multiset<int> top;
multiset<int> bot;
int med = 0;
int low_sum = 0,high_sum = 0;

void fix()
{
	if(top.size() > bot.size())
	{
		low_sum += med;
		high_sum -= *(top.begin());
		bot.insert(med);
		med = *(top.begin());
		top.erase(top.begin());
	}
	if(bot.size() > top.size())
	{
		high_sum += med;
		low_sum -= *(--bot.end());
		top.insert(med);
		med = *(--bot.end());
		bot.erase(--bot.end());
	}
}

void push(int x)
{
	if(x > med)
	{
		high_sum += x;
		top.insert(x);
	}
	else
	{
		low_sum += x;		
		bot.insert(x);
	}
	fix();
}

void pop(int x)
{
	if(x > med)
	{
		high_sum -= x;
		top.erase(top.find(x));
	}
	else if(x < med)
	{
		low_sum -= x;
		bot.erase(bot.find(x));
	}
	else
	{
		low_sum -= *(--bot.end());
		med = *(--bot.end());
		bot.erase(--bot.end());
	}

	fix();
}

void solve()
{
   	int n,k;
   	cin >> n >> k;
   	int a[n];
   	for(int i = 0;n > i;i++)
   	{
   		cin >> a[i];
   	}
   	if(k == 1)
   	{
   		for(auto it : a) cout << "0 " << endl;
   		return;
   	}
   	if(k == 2)
   	{
   		for(int i = 1;n > i;i++)
   		{
   			cout << abs(a[i] - a[i-1]) << " ";
   		}
   		return;
   	}
   	med = a[0];  	
   	for(int i = 1;k > i;i++)
   	{
   		push(a[i]); 		
   	}
   	cout << (bot.size() * med - low_sum) + (high_sum - top.size() * med) << " ";
   	
   	for(int i = k;n > i;i++)
   	{	
   		pop(a[i-k]);
   		push(a[i]);	
   		cout << (bot.size() * med - low_sum) + (high_sum - top.size() * med) << " ";
   	}
   	cout << endl;

}

int32_t main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	int t;
	t=1;
	
	while(t--) solve();

}
