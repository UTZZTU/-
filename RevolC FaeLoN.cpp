#include<cstdio>
#include<cstring>
#include<queue>
#include<vector>
#include<algorithm>
#include <stack>
using namespace std;
 
const int maxn = 1000 + 5;
 
int pre[maxn],dfs_clock;
vector<int> G[maxn];
int isbridge[maxn][maxn];
 
int dfs1(int u,int fa){
    int lowu = pre[u] = ++dfs_clock;
    for(int i = 0;i < G[u].size();i++){
        int v = G[u][i];
        if(!pre[v]){
            int lowv = dfs1(v,u);
            lowu = min(lowu,lowv);
            if(lowv > pre[u]){
                isbridge[u][v] = 1; isbridge[v][u] = 1;
            }
        }
        else if(pre[v] < pre[u] && v != fa){
            lowu = min(lowu,pre[v]);
        }
    }
    return lowu;
}
 
int fa[maxn],vis[maxn];
int find(int x){return x == fa[x]?x:fa[x] = find(fa[x]);}
 
void dfs2(int u){
    for(int i = 0;i < G[u].size();i++){
        int v = G[u][i];
        if(!vis[v] && !isbridge[u][v]){
            int X = find(u); int Y = find(v);
            if(X != Y) fa[X] = Y;
            vis[v] = 1;
            dfs2(v);
        }
    }
}
 
void find_bcc(int n){
    memset(pre,0,sizeof(pre));
    memset(isbridge,0,sizeof(isbridge));
    dfs_clock = 0;
    for(int i = 0;i < n;i++)
        if(!pre[i]) dfs1(i,-1);
    memset(vis,0,sizeof(vis));
    for(int i = 0;i < n;i++){
        if(!vis[i]) {
            vis[i] = 1;
            dfs2(i);
        }
    }
}
 
int degree[maxn];
int used[maxn];
 
int main(){
    int n,m;
    while(scanf("%d%d",&n,&m) != EOF){
        for(int i = 0;i < n;i++) {G[i].clear(); fa[i] = i;}
        while(m--){
            int u,v;
            scanf("%d%d",&u,&v);u--;v--;
            G[u].push_back(v); G[v].push_back(u);
        }
 
        find_bcc(n);
 
        memset(degree,0,sizeof(degree));
        for(int i = 0;i < n;i++){
            for(int j = 0;j < G[i].size();j++){
                int v = G[i][j];
                if(find(i) != find(v))  degree[find(v)]++;
            }
        }
 
        int sum = 0;
        memset(used,0,sizeof(used));
        for(int i = 0;i < n;i++){
            int x = find(i);
            if(!used[x]){
                used[x] = 1;
                if(degree[x] == 1) sum++;
                else if(degree[x] == 0) sum += 2;
            }
        }
        int cnt = 0;
        for(int i = 0;i < n;i++) if(used[i] == 1) cnt++;
        if(cnt == 1) {printf("0\n"); continue;}
        else printf("%d\n",(sum+1)/2);
    }
    return 0;
}