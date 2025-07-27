#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <math.h>
#include <map>
#include <set>
#include <queue>

using namespace std;
#define endl '\n'
void solve(){
    int a,b,c,x,y,z;
    cin >> a >> b >> c >> x >> y >> z;
    int dx = a - x,dy = b - y,dz = c - z;
    if (dx % 20 || dy % 20 || dz % 20 || a + b + c != x + y + z){
        cout << -1 << endl;
        return;
    }
    dx /= 20,dy /= 20,dz /= 20;
    int mod = (dx % 3 + 3) % 3;
    if ((dy % 3 + 3) % 3 != mod || (dz % 3 + 3) % 3 % 3 != mod){
        cout << -1 << endl;
        return;
    }
    int num = 0;
    num += (dx > 0) + (dy > 0) + (dz > 0);
    if (num == 2) dx = -dx,dy = -dy,dz = -dz;
    x = min({dx,dy,dz}),z = max({dx,dy,dz}),y = dx + dy + dz - x - z;//排序
    int res = 0;
    res += -y,x -= y,z += y * 2,y = 0;
    res += z / 3 * 2;
    cout << res << endl;
}
signed main(){
    std::ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
}
