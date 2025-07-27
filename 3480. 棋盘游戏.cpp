#include <bits/stdc++.h>
using namespace std;
const int N = 8, INF = 0x3f3f3f3f;
int ex, ey;
int g[N][N];
int opt[6][6][4]; //4个状态都要记录
int res, ans;
int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};
struct node
{
    int x, y, sum, status;
};
node start;
inline void bfs(node st)
{
    queue<node> q;
    q.push(st);
    while (q.size())
    {
        auto t = q.front();
        q.pop();
        for (int i = 0; i < 4; i ++ )
        {
            int  a = dx[i] + t.x, b = dy[i] + t.y;
            if (a >= 0 && a < 6 && b >= 0 && b < 6)
            {
                int  cost = t.status * g[a][b];
                if (t.sum + cost < opt[a][b][cost % 4])
                {
                    opt[a][b][cost % 4] = t.sum + cost;
                    node temp;
                    temp.x = a;
                    temp.y = b;
                    temp.sum = t.sum + cost;
                    temp.status = cost % 4 + 1;
                    q.push(temp);
                }
            }
        }
    }
}
inline void solve()
{
    memset(opt, 0x3f, sizeof opt);
    ans = INF;
    for (int i = 0; i < 6; i ++ )
        for (int j = 0; j < 6; j ++ )
            cin >> g[i][j];
    start.sum = 0, start.status = 1;
    cin >> start.x >> start.y >> ex >> ey;
    if (start.x == ex && start.y == ey)
    {
        puts("0");
        return;
    }
    bfs(start);
    for (int i = 0; i < 4; i ++ ) ans = min(ans, opt[ex][ey][i]);
    cout << ans << endl;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    solve();
    return 0;
}