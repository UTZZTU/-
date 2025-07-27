#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

using i64 = long long;

int main() {
    int n;
    cin >> n;
    vector<int> x(n), y(n);
    
    for (int i = 0; i < n; i++) {
        cin >> x[i] >> y[i];
    }
    
    int mx = 0;
    double k, b;
    
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int cnt = 0;
            auto f = [&](int k, int i, int j) -> bool {
                auto dx1 = x[i] - x[k], dy1 = y[i] - y[k];
                auto dx2 = x[j] - x[k], dy2 = y[j] - y[k];
                return dx1 * dy2 == dy1 * dx2;
            };
            for (int k = 0; k < n; k++) {
                if (f(k, i, j)) {
                    cnt++;
                }
            }
            if (cnt > mx) {
                k = (y[j] - y[i]) / (x[j] - x[i]);
                b = y[i] - k * x[i];
                mx = cnt;
            }
        }
    }
    
    printf("%.10lf %.10lf", k, b);
}
