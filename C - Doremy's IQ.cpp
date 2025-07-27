#include <bits/stdc++.h>
 
#define IOS ios::sync_with_stdio(false);cin.tie(nullptr)
#define int long long
 
using namespace std;
 
const int N = 2e5 + 10;
 
int n, x;
int arr[N], brr[N];
 
void solve()
{
     cin >> n >> x;
 
     for(int i = 1; i <= n; i ++) cin >> arr[i];
 
     for(int i = 1; i <= n+3; i ++) brr[i] = 0;
     for(int i = n; i >= 1; i --)
     {
          brr[i] = brr[i+1];
          if(brr[i] < arr[i]) brr[i]++;//预处理我们每道题当前所需要的最低智商
     }
 
     for(int i = 1; i <= n; i ++)
     {
          if(x >= arr[i]) cout << 1;
          else
          {
               if(x >= brr[i])
               {
                    x--;
                    cout << 1;
               }
               else
                    cout << 0;
          }
     }
     cout << '\n';
}
 
signed main()
{
     IOS;
     int T;
     cin >> T;
     while(T--)
          solve();
     return 0;
}