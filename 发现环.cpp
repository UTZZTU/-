#include<bits/stdc++.h>
using namespace std;
const int N=100000+6;
vector<int>edge[N];
bool vis[N];
int pre[N];
int ring[N];
int tot;
int flag;
void dfs(int x,int fa){
    vis[x]=true;
    for(int i=0;i<edge[x].size();i++){
        int v=edge[x][i];
        if(v==fa) continue;
        pre[v]=x;
        if(vis[v]){
            int tmp=v;
            flag=1;
            while(true){
                tmp=pre[tmp];
                ring[++tot]=tmp;
                if(tmp==v) break;
            }
            return;
        }
        else
            dfs(v,x);
        if(flag) return;
    }
}

int main(){
    int n; cin>>n;
    for(int i=1;i<=n;i++){
        int u,v;cin>>u>>v;
        edge[u].push_back(v);
        edge[v].push_back(u);
    }
    dfs(1,0);
    sort(ring+1,ring+tot+1);
    for(int i=1;i<=tot;i++) cout<<ring[i]<<" ";
    return 0;
}