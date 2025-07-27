#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll f[200];
ll cal(int k,ll x,ll y) {
    if (k == 0) return 1;
    ll len = f[k], cnt = f[k * 2]/9;
//    printf("k = %d x = %lld y = %lld len = %lld cnt = %lld\n",k,x,y,len,cnt);
    if (x < len / 3) {
        if (y < len / 3) return cal(k - 1, x, y);
        if (y < len * 2 / 3) return cnt + cal(k - 1, len / 3 - 1 - x, y - len / 3);
        return cnt * 2 + cal(k - 1, x, y - len / 3 * 2);
    } else if (x < len * 2 / 3) {
        if (y < len / 3) return cnt * 5 + cal(k - 1, x - len / 3, len / 3 - 1 - y);
        else if (y < len * 2 / 3) return cnt * 4 + cal(k - 1, len * 2 / 3 - 1 - x, len * 2 / 3 - 1 - y);
        return cnt * 3 + cal(k - 1, x - len / 3, len - 1 - y);
    } else {
        if (y < len / 3) return cnt * 6 + cal(k - 1, x - len * 2 / 3, y);
        else if (y < len * 2 / 3) return cnt * 7 + cal(k - 1, len - 1 - x, y - len / 3);
        return cnt * 8 + cal(k - 1, x - len * 2 / 3, y - len * 2 / 3);
    }
}
int main() {
    f[0] = 1;
    for (int i = 1; i <= 39; i++) {
        f[i] = f[i - 1] * 3;
    }
    int k;
    ll x1, y1, x2, y2;
    scanf("%d%lld%lld%lld%lld", &k, &x1, &y1, &x2, &y2);
    ll ans1 = cal(k,x1,y1);
    ll ans2 = cal(k,x2,y2);
    ll ans = abs(ans1-ans2);
//    printf("%lld %lld\n", ans1,ans2);
    printf("%lld\n",ans);
    return 0;
}
