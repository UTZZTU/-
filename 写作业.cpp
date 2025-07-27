#include<iostream>
#include<cstring>
#include<vector>
using namespace std;
using LL = long long;

int main(){

#ifdef LOCAL
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
#endif

    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);

    int T;
    cin >> T;
    while(T--){
        LL a1, a2, b1, b2;
        cin >> a1 >> b1 >> a2 >> b2;
        LL ans = max(a1 + b1, a2 + b2);
        
        auto solve = [&](){
            LL t1 = a1 + b1;
            // b 第2门自己完成
            {
                LL t2 = max(b2, a1) + a2 / 2;
                ans = min(ans, max(t1, t2));
            }
            // b 第1门自己完成
            {
                LL t2 = max(a2, b1) + b2 / 2;
                ans = min(ans, max(t1, t2));
            }
            // b 都不是自己完成, a 先完成 1
            {
                LL t2 = max(a1 + a2 / 2, a1 + b1) + b2 / 2;
                ans = min(ans, max(t1, t2));
            }
            // b 都不是自己完成, a 先完成 2
            {
                LL t2 = max(b1 + b2 / 2, a1 + b1) + a2 / 2;
                ans = min(ans, max(t1, t2));
            }
        };

        solve();
        swap(a1, a2);
        swap(b1, b2);
        solve();

        // a 做 1, b 做 2
        {
            LL t1 = max(a1, b2) + b1 / 2;
            LL t2 = max(a1, b2) + a2 / 2;
            ans = min(ans, max(t1, t2));
        }
        // a 做 2, b 做 1
        swap(a1, b1);
        swap(a2, b2);
        {
            LL t1 = max(a1, b2) + b1 / 2;
            LL t2 = max(a1, b2) + a2 / 2;
            ans = min(ans, max(t1, t2));
        }
        cout << ans << '\n';
    }

}