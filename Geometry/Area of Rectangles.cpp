#include<bits/stdc++.h>
using namespace std;

#define dongu(i, n) for (int i = 0, _n = (int)(n); i < _n; i++)
#define boyut(x) (int((x).size()))
#define tum(X) (X).begin(),(X).end()
#define ilk first
#define ikinci second

typedef pair<int, int> pii;

const int maxn = 100000 + 100;

int n;
vector<int> xs;
vector<pair<pii, pii>> foo;
int sum[8*maxn], add[8*maxn];

void degis(int x, int xl, int xr, int ql, int qr, int val) {
	if(xr <= ql || qr <= xl) 
	    return;
	if(ql <= xl && xr <= qr) {
		add[x] += val;
		if(add[x]) 
		    sum[x] = xs[xr] - xs[xl];
		else if(xr - xl == 1) 
		    sum[x] = 0;
		else 
		    sum[x] = sum[2*x+1] + sum[2*x+2];
		return;
	}

	int xm = (xl + xr) / 2;
	degis(2*x+1, xl, xm, ql, qr, val);
	degis(2*x+2, xm, xr, ql, qr, val);

	if(add[x]) 
	    sum[x] = xs[xr] - xs[xl];
	else 
	    sum[x] = sum[2*x+1] + sum[2*x+2];
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	cin >> n;
	dongu(i, n) {
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		if(x1 > x2) 
		    swap(x1, x2);
		if(y1 > y2) 
		    swap(y1, y2);
		xs.push_back(x1); xs.push_back(x2);
		foo.push_back({{y1, +1}, {x1, x2}});
		foo.push_back({{y2, -1}, {x1, x2}});
	}

	sort(tum(xs));
	xs.erase(unique(tum(xs)), xs.end());

	sort(tum(foo));

	long long cvp = 0;
	int prevy = 0;

	for(auto event: foo) {
		cvp += (event.ilk.ilk - prevy) * (long long)sum[0];
		event.ikinci.ilk = lower_bound(tum(xs), event.ikinci.ilk) - xs.begin();
		event.ikinci.ikinci = lower_bound(tum(xs), event.ikinci.ikinci) - xs.begin();
		degis(0, 0, boyut(xs) - 1, event.ikinci.ilk, event.ikinci.ikinci, event.ilk.ikinci);
		prevy = event.ilk.ilk;
	}
	
	cout << cvp << endl;

	return 0;
}
