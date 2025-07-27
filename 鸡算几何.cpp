
#include <bits/stdc++.h>

using namespace std;
#define int long long
typedef long long ll;
#define IOS ios::sync_with_stdio(0)
#define CCT cin.tie(0),cout.tie(0)
#define pii pair<int,int>
const int N = 2e5 + 7, inf = 1e18 + 7, mod = 998244353;
const double eps = 1e-7;
#define dbg(x...) do{cout<<#x<<" -> ";err(x);}while (0)

void err() { cout << '\n'; }

template<class T, class... Ts>
void err(T arg, Ts... args) {
    cout << arg << ' ';
    err(args...);
}

struct node{
    double x,y;
}a[10];

struct Vec{
    double x,y;

    Vec(node u,node v){
        x = v.x - u.x;
        y = v.y - u.y;
    }

};

double dis(node a,node b){
    double d = (a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y);
    return sqrt(d);
}

double mul(Vec u,Vec v){
    return u.x * v.y - u.y * v.x;
}

void solve() {
    for (int i = 1; i <= 6; i++){
        cin >> a[i].x >> a[i].y;
    }

    double ab = dis(a[1],a[2]),bc = dis(a[2],a[3]);
    double de = dis(a[4],a[5]),ef = dis(a[5],a[6]);
    if (abs(ab - bc) <= eps){
        cout << "NO\n";
    }else{
        if (abs(ab - ef) <= eps){
            swap(de,ef);
            swap(a[4],a[6]);
        }
        Vec v1(a[2],a[1]),v2(a[2],a[3]),v3(a[5],a[4]),v4(a[5],a[6]);
        if (mul(v1,v2) * mul(v3,v4) > 0){
            cout << "NO\n";
        }else{
            cout << "YES\n";
        }
    }
}

signed main() {
    IOS;CCT;
    //cout << std::fixed << std::setprecision(10) << "\n";
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
