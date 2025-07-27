// AC
#include<bits/stdc++.h>
using namespace std;
const int maxn = 2020;

vector<int> G[maxn];
int n, t[maxn];

int vis[maxn], e[maxn][maxn];
void bfs(int x){
    queue<int> q;
    q.push(x);
    vis[x] = 1;
    while(q.size()){
        int u = q.front();
        q.pop();
        for(int to : G[u]){
            if(vis[to])continue;
            vis[to] = 1;
            e[x][to] = e[x][u]+1;
            q.push(to);
        }
    }
}

int main(){
    cin >> n;
    for(int i = 1; i < n; i++){
        int u ,v ; 
        cin>>u>>v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    for(int i = 1; i <= n; i++) cin >> t[i];
    // bfs求任意2节点距离
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++) vis[j] = 0;
        bfs(i);
    }
    // 枚举3个节点
    int cnt = 0;
    for(int i = 1; i <= n; i++){
        for(int j = i+1; j <= n; j++){
            for(int k = j+1; k <= n; k++){
            	// 判断距离 注意由于数据量 这里的条件不能交换
                if(e[i][j]==e[j][k] && e[i][j]==e[i][k]){
                	// 判断类型
                    if(t[i]!=t[j] && t[i]!=t[k] && t[j]!=t[k]){
                        cnt++;
                    }
                }
            }
        }
    }
    cout << cnt << endl;
    return 0;
}
