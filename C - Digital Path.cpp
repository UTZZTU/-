#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9 + 7;
const int N = 1005;
 
ll mp[N][N], dp[N][N][5];
int n, m, dir[4][2] = {0, 1, 0, -1, 1, 0, -1, 0};
 
//判是不是路径终点
bool check1(int x, int y) {
    for(int i = 0; i < 4; ++i) {
        int fx = x + dir[i][0];
        int fy = y + dir[i][1];
        if(fx >= 1 && fx <= n && fy >= 1 && fy <= m && mp[fx][fy] == mp[x][y] + 1) return 0;
    }
    return 1;
}
 
//判是不是路径起点
bool check2(int x, int y) {
    for(int i = 0; i < 4; ++i) {
        int fx = x + dir[i][0];
        int fy = y + dir[i][1];
        if(fx >= 1 && fx <= n && fy >= 1 && fy <= m && mp[fx][fy] == mp[x][y] - 1) return 0;
    }
    return 1;
}
 
ll dfs(int x, int y, int len) {
    if(len == 1) {
        if(check2(x, y)) dp[x][y][len] = 1;
        else dp[x][y][len] = 0;
        return dp[x][y][len];
    }
    if(dp[x][y][len] != -1) return dp[x][y][len] % mod;
    ll res = 0;
    for(int i = 0; i < 4; ++i) {
        int fx = x + dir[i][0];
        int fy = y + dir[i][1];
        if(fx < 1 || fx > n || fy < 1 || fy > m || mp[fx][fy] != mp[x][y] - 1) continue;
        res = (res + dfs(fx, fy, len - 1)) % mod;
        if(len == 4) res = (res + dfs(fx, fy, len)) % mod;
    }
    dp[x][y][len] = res % mod;
    return dp[x][y][len];
}
 
int main() {
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= m; ++j)
            scanf("%lld", &mp[i][j]);
    ll ans = 0;
    memset(dp, -1, sizeof(dp));
    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= m; ++j) {
            if(mp[i][j] != -1 && check1(i, j)) {
                ans = (ans + dfs(i, j, 4)) % mod;
            }
        }
    }
    printf("%lld\n", ans);
    return 0;
}
/*
2 4
1 2 3 4
3 3 4 1
*/