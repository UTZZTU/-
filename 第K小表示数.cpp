#include <bits/stdc++.h>

int main() {
    int k;
    std::array<int, 2> op = {0}, S;
    std::cin >> k >> S[0] >> S[1];
    using i64 = long long;
    std::vector<i64> s(k + 1);
    for (int i = 1; i <= k; i++) {
        i64 res = std::min(S[0] + s[op[0]], S[1] + s[op[1]]);
        for (int j = 0; j < 2; j++)
            if (S[j] + s[op[j]] == res)
                op[j]++;
        s[i] = res;
    }
    std::cout << s[k] << std::endl;
    return 0;
}
