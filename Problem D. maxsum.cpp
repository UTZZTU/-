#include <bits/stdc++.h>
 
using ll = long long;
 
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n, w;
    std::cin >> n >> w;
    std::vector<ll> a(n+1),L(n+2),R(n+2),p(n+2);
    std::priority_queue<ll> q;
    for (int i = 1; i <= n; i++) {
        std::cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
        L[i] = L[i - 1] + a[i];
    }
    for (int i = n; i >= 1; i--) {
        R[i] = R[i + 1] + a[i];
    }
    for (int i = 0; i <= n; i++) {
        p[i] = n + 1;
    }
    int num = 0;
    bool f = false;
    int l = 0;
    for (int i = 0; i <= n; i++) {
        for (int j = p[i]; j >= 1; j--) {
            if (L[i] + R[j] > L[l + 1]) {
                p[i] = j;
                if (i == l) {
                    l++;
                    i = -1;
                    if (num >= w) {
                        f = true;
                    }
                }
                break;
            }
            q.push(L[n] - L[i] - R[j]);
            num++;
        }
        if (f) {
            break;
        }
    }
    while (w--) {
        std::cout << q.top() << " ";
        q.pop();
    }
    return 0;
}