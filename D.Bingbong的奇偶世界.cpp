#include<bits/stdc++.h>
using namespace std;
#define i64 long long
const i64 mod = 1e9 + 7;
int main() {
    int n;
    cin >> n;
    vector<char>s(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> s[i];
    }
    i64 ans = 0, cnt = 0;;
    for (int i = 1; i <= n; i++) {
        if (s[i] == '0') {
            ans = (ans + cnt + 1) % mod;
            cnt = (cnt * 2) % mod;
        } else if ((s[i] - '0') & 1) {
            cnt = (cnt * 2 + 1) % mod;
        } else {
            ans = (ans + cnt + 1) % mod;
            cnt = (cnt * 2 + 1) % mod;
        }
    }
    cout << ans;
    return 0;
}

