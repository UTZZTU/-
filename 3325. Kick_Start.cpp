#include <bits/stdc++.h>
using namespace std;
int main () {
  int T; cin >> T;
  for (int t = 1; t <= T; t ++) {
    string s; cin >> s;
    int kick = 0, ans = 0;
    for (int i = 0; i < s.size() - 4; i ++) {
      if (s.substr(i, 4) == "KICK") kick ++, i += 2;
      else if (s.substr(i, 5) == "START") ans += kick, i += 4;
    }
    cout << "Case #" << t << ": " << ans << endl;
  }
  return 0;
}