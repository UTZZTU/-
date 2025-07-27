#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

using i64 = long long;

int main() {
    auto match = [&](string s, string p) -> bool {
        int n = s.size(), m = p.size();
        s = ' ' + s, p = ' ' + p;
        vector<vector<bool>> f = vector<vector<bool>>(n + 1, vector<bool>(m + 1));
        f[0][0] = true;
        for (int i = 0; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (j + 1 < p.size() && p[j + 1] == '*') continue;
                if (i && p[j] != '*') f[i][j] = f[i - 1][j - 1] && (p[j] == s[i] || p[j] == '.');
                if (p[j] == '*') f[i][j] = f[i][j - 2] || i && f[i - 1][j] && (s[i] == p[j - 1] || p[j - 1] == '.');
            }
        }
        return f[n][m];
    };
    string s, p;
    cin >> s >> p;
    cout << (match(s, p) ? "true" : "false");
    return 0;
}
