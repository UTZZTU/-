#include <bits/stdc++.h>
#define LL long long
#define fu(x , y , z) for(int x = y ; x <= z ; x ++)
using namespace std;
const int N = 1e4 + 5;
const LL mod = 998244353;
int n , w , vis[N + 5] , b[N + 5] , b1 , ans1[N][2005];
long long p[N];
struct node {
    int id , v;
    bool operator > (const node &t) const 
    {
        return v > t.v;
    }
} ;
priority_queue<node , vector<node> , greater<node>> q;
int main () {
    // freopen ("plant.in" , "r" , stdin);
    int a;
    scanf ("%d%d" , &n , &w);
    fu (i , 1 , n) scanf ("%lld" , &p[i]);
    int w1 = sqrt (w);
    int a1;
    node now;
    LL ans = 1;
    fu (i , 2 , N) {
        if (!vis[i]) b[++b1] = i;
        fu (j , 1 , b1) {
            if (i * b[j] > N) break;
            vis[i * b[j]] = 1;
            if (i % b[j] == 0) break;
        }
    }
    // fu (i , 1 , 10) cout << b[i] << " ";
    // return 0;
    fu (i , 1 , b1) {
        a = 0;
        while (w % b[i] == 0) {
            w /= b[i];
            a ++;
        }
        fu (j , 1 , n) {
            a1 = 0;
            while (p[j] % b[i] == 0) {
                a1 ++;
                p[j] /= b[i];
            }
            q.push((node){j , a1 + 1});
        }
        while (a --) {
            now = q.top();
            q.pop();
            now.v ++;
            q.push(now);
        }
        while (!q.empty()) {
            now = q.top();
            q.pop();
            ans = ans * 1ll * now.v % mod;
        }
    }
    printf ("%lld" , ans);
    return 0;
}
