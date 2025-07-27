#include <bits/stdc++.h>
using namespace std;
int a[1000000 + 10];
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        scanf("%d", &n);
 
        int cnt1 = 1, cnt_1 = 0, cnt0 = 0;
        for (int i = 1; i <= n; i++)
        {
            scanf("%d", &a[i]);
        }
 
        int flag = 0;
        for (int i = 1; i <= n; i++)
        {
            if (a[i] == 1)
            {
                cnt1++;
            }
            else if (a[i] == -1)
            {
                cnt_1++;
                if (cnt1 <= cnt_1 - cnt0)
                {
                    flag = 1;
                    break;
                }
                else if (cnt1 <= cnt_1)
                {
                    int temp = (cnt_1 + 1 - cnt1 + 1) / 2;
                    cnt0 -= temp;
                    cnt_1 -= temp;
                    cnt1 += temp;
                }
            }
            else
            {
                if (cnt1 > cnt_1 + 1)
                {
                    cnt_1++;
                    cnt0++;
                }
                else
                {
                    cnt1++;
                }
            }
        }
 
        if (flag)
        {
            cout << -1 << '\n';
 
            continue;
        }
        int sum = cnt1;
        int cnt = cnt1 - cnt_1;
        int gcd = __gcd(sum, cnt);
 
        cout << sum / gcd << " " << cnt / gcd << '\n';
    }
    return 0;
}