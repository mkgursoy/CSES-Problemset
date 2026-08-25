#include <bits/stdc++.h>
#include <array>

using namespace std;

#define int long long
#define ar array
#define all(x) x.begin(),x.end()

string remove_zeros(string s) 
{
    int i = 0;
    while(i + 1 < s.size() && s[i] == '0') i++;
   	return s.substr(i);
}

string addition (string a, string b) 
{
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());

    string res = "";
    int carry = 0;

    for (int i = 0; i < max(a.size(), b.size()) || carry; i++) 
    {
        int sum = carry;
        if (i < a.size()) sum += a[i] - '0';
        if (i < b.size()) sum += b[i] - '0';

        res.push_back((sum % 10) + '0');
        carry = sum / 10;
    }

    reverse(res.begin(), res.end());
    return remove_zeros(res);
}

string subtraction (string a, string b) 
{
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());

    string res = "";
    int borrow = 0;

    for (int i = 0; i < a.size(); i++) 
    {
        int x = (a[i] - '0') - borrow;
        int y = (i < b.size() ? b[i] - '0' : 0);

        if (x < y) 
        {
            x += 10;
            borrow = 1;
        } 
        else 
        {
            borrow = 0;
        }

        res.push_back((x - y) + '0');
    }

    reverse(res.begin(), res.end());
    return remove_zeros(res);
}

string multiplication (string a, string b)
{
    int n = a.size();
    int m = b.size();
    vector<int> res(n + m, 0);

    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());

    for (int i = 0; i < n; i++) 
    {
        for (int j = 0; j < m; j++) 
        {
            res[i + j] += (a[i] - '0') * (b[j] - '0');
            res[i + j + 1] += res[i + j] / 10;
            res[i + j] %= 10;
        }
    }

    string ans = "";
    for (int i = res.size() - 1; i >= 0; i--)
    {
        ans.push_back(res[i] + '0');
    }

    return remove_zeros(ans);
}
bool bigger(string s,string y)
{
	if(s.size() > y.size()) return true;
	if(y.size() > s.size()) return false;
	return (s > y);
}
bool smaller(string s,string y)
{
	if(s.size() > y.size()) return false;
	if(y.size() > s.size()) return true;
	return (s < y);
}
string stringify(int x)
{
	string res = "";
	while(x) res += '0' + x % 10, x /= 10;
	reverse(all(res));
	return res;
}
void solve()
{
	string n;
	cin >> n;
	vector<string> x, y;
	string sm = "0";
	vector<ar<int,2>> regular_input;
	int reg_x, reg_y;
	while(cin >> reg_x >> reg_y)
	{
		regular_input.push_back({reg_x + 232323232323, reg_y + 232323232323});
	}
	for(string i = "0";bigger(n, i);i = addition(i, "1"))
	{
		string new_x, new_y;
		new_x = stringify(regular_input.back()[0]);
		new_y = stringify(regular_input.back()[1]);
		
		regular_input.pop_back();
		x.push_back(new_x);
		y.push_back(new_y);
	}
	
	sort(all(x), smaller);
	sort(all(y), smaller);
	string p_x = "0", p_y = "0";
	int ind = 0;
	for(string i = "0";bigger(n, i);i = addition(i, "1"))
	{
		
		sm = addition(sm, subtraction(multiplication(x[ind], i), p_x));
		sm = addition(sm, subtraction(multiplication(y[ind], i), p_y));
		p_x = addition(p_x, x[ind]);
		p_y = addition(p_y, y[ind]);
		ind++;
	}
	
	cout << sm << endl;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();
}
