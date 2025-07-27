#include<iostream>
using namespace std;
int ans = 0;
int nex[4][2] = { { 1, 0 }, { -1, 0 }, { 0, 1 }, { 0, -1 } };
int vis[20][20];    
bool check(int x, int y){
    if (vis[x][y] || x < 1 || x>4 || y < 1 || y>4)return false;
    return true;
}
void dfs(int x, int y, int cnt){
    if (cnt == 16){
        ans++;
        return;
    }
    for (int i = 0; i < 4; i++){
        int tx = x + nex[i][0];
        int ty = y + nex[i][1];
        if (!check(tx, ty))continue;
        vis[tx][ty] = 1;
        dfs(tx, ty, cnt + 1);
        vis[tx][ty] = 0;        //回溯
    }
}
int main(){
    for (int i = 1; i <= 4; i++){
        for (int j = 1; j <= 4; j++){
            vis[i][j] = 1;
            dfs(i, j, 1);
            vis[i][j] = 0;

        }
    }
    cout << ans << endl;
    return 0;
}