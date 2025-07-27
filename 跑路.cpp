#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mxn=60,mxe=1e4+10;
struct ty{
    int to,next;
}edge[mxe<<1];
int n,m,u,v;
int G[mxn][mxn][66],dis[mxn][mxn];
void init(){
    for(int z=1;z<=64;z++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                for(int k=1;k<=n;k++){
                    if(G[i][j][z-1]&&G[j][k][z-1]){
                        G[i][k][z]=1;
                        dis[i][k]=1;
                    }
                }
            }
        }
    }
}
void floyd(){
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
            }
        }
    }
}
signed main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++) dis[i][j]=1e18;
    }
    memset(G,0,sizeof(G));
    for(int i=1;i<=m;i++){
        cin>>u>>v;
        G[u][v][0]=1;
        dis[u][v]=1;
    }
    init();
    floyd();
    cout<<dis[1][n]<<'\n';
}