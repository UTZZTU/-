#include<iostream>
#include<map>
using namespace std;
typedef long long ll;
int a[3000001];
int b[3000001];
map<ll,int> vis;
void solve()
{
     int n;
     cin >> n;
     vis.clear();
     for(int i = 1; i <= n ; i ++ )
     {
          cin >> a[i];
         while(a[i] % 2 == 0 && a[i] != 1)
          {
              a[i] = a[i] / 2;
          }
          vis[a[i]] ++ ;
     }
     int err = 0;
     for(int i = 1; i <= n ; i ++ )
     {
          cin >> b[i];
          int bj = 0;
          while(b[i] != 0)
          {
              if(vis[b[i]] > 0)
              {   bj = 1;
                  vis[b[i]] --;
                  break;
              }
              b[i] = b[i] / 2;
          }
          if(bj == 0)
          {
              err = 1;
          }
     }
     if(err)
     {
         cout << "NO" <<endl;
         return;
     }
     cout << "YES" << endl;
     return;
}
int main()
{
     int t;
     cin >> t;
     while(t -- )
     {
         solve();
     }
}