#include <bits/stdc++.h>
#include <unordered_map>
#define int long long
using namespace std;

const int N = 1e6 + 10;

int n, m, k;
vector<pair<int, int>> seg[N], siro[N];

signed main()
{
   ios::sync_with_stdio(0);
   cin.tie(0);cout.tie(0);
   int T = 1;
   // cin >> T;
   while (T -- )
   {
       cin >> n >> m >> k;
       if (n == 1) return cout << "YES\n", 0;
       if (m >= 2 * k + 2) return cout << "NO\n", 0;
       for (int i = 0; i < k; i ++ )
       {
           int x1, x2, y;
           cin >> x1 >> x2 >> y;
           if (y < N) seg[y].push_back({x1, x2});
       }
       for (int i = 1; i <= m; i ++ )
       {
           sort(seg[i].begin(), seg[i].end());
           int curr = 1;
           for (int j = 0; j < seg[i].size(); j ++ )
           {
               int x1 = seg[i][j].first;
               int x2 = seg[i][j].second;
               if (curr < x1)
               {
                   siro[i].push_back({curr, x1 - 1});
               }
               while (j + 1 < seg[i].size() && seg[i][j + 1].first == x2 + 1)
               {
                   j ++;
                   x2 = seg[i][j].second;
               }
               curr = x2 + 1;
           }
           if (curr <= n) siro[i].push_back({curr, n});
       }
       int edge = 0, node = 0;
       for (int i = 1; i <= m; i ++ )
       {
           int idx = 0;
           for (int j = 0; j < siro[i].size(); j ++ )
           {
               int l1 = siro[i][j].first;
               int r1 = siro[i][j].second;
               edge += r1 - l1; 
               node += r1 - l1 + 1;
               for (; idx < siro[i + 1].size(); idx ++ )
               {
                   auto [l2, r2] = siro[i + 1][idx];
                   int L = max(l1, l2), R = min(r1, r2);
                   if (L <= R)
                   {
                       edge += R - L + 1;
                       if (L < R) return cout << "NO\n", 0;
                   }
                   if (r2 > r1) break;
               }
           }
       }
       if (edge == node - 1) cout << "YES\n";
       else cout << "NO\n";
   }

   return 0;
}