#include<bits/stdc++.h>
using namespace std;

#define int long long

int32_t main()
{
    int n, k;
    cin >> n >> k;
    int a[n];
    int mx = -1;
    int total = 0;
    for(int i = 0;n > i;i++)
    {
        cin >> a[i];
        mx = max(mx, a[i]);
        total += a[i];
    } 
    int l = mx, r = total;
    while(r > l)
    {
        int mid = (l + r) / 2;
        int cnt = 0;
        int current_sum = 0;
        for(int i = 0;n > i;i++)
        {
            if(current_sum + a[i] > mid)
            {
                current_sum = a[i];
                cnt++;
            }
            else
            {
                current_sum += a[i];
            }
        }
        cnt++;
        if(cnt <= k) r = mid;
        else l = mid + 1;
    }
    cout << l << endl;
}
