#include <bits/stdc++.h>
using namespace std;
#define sc(x) scanf("%d",&x)
#define sl(x) scanf("%lld",&x)
#define ll long long
#define pb push_back
#define PII pair<int,int>
const int Max=1e6+5;
const int mod=998244353;
const int N=2e5+5;
int mp[2005][2005];
int room[2005][2005];
int n,m,k;
int dir[4][2]={1,0,-1,0,0,1,0,-1};
void bfs(int x,int y){
    PII st,nx;
    st=make_pair(x,y);
    queue<PII>q;
    q.push(st);
    mp[x][y]=1;
    while(!q.empty()){
        st=q.front();
        q.pop();
        for(int i=0;i<4;i++){
            int hx=st.first+dir[i][0];
            int hy=st.second+dir[i][1];
            if(hx<=0||hy<=0||hx>n||hy>m) continue;
            if(room[hx][hy]==-1) continue;
            if(mp[hx][hy]) continue;
            mp[hx][hy]=mp[st.first][st.second]+1;
            q.push({hx,hy});
        }
    }
}
int mp1[2005][2005];
void bfs1(int x,int y){
    PII st,nx;
    st=make_pair(x,y);
    queue<PII>q;
    q.push(st);
    mp1[x][y]=1;
    while(!q.empty()){
        st=q.front();
        q.pop();
        for(int i=0;i<4;i++){
            int hx=st.first+dir[i][0];
            int hy=st.second+dir[i][1];
            if(hx<=0||hy<=0||hx>n||hy>m) continue;
            if(room[hx][hy]==-1) continue;
            if(mp1[hx][hy]) continue;
            mp1[hx][hy]=mp1[st.first][st.second]+1;
            q.push({hx,hy});
        }
    }
}
int main(){
    sc(n);sc(m);sc(k);
    int sx,sy,ex,ey;
    sc(sx);sc(sy);sc(ex);sc(ey);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            sc(room[i][j]);
        }
    }
    bfs(sx,sy);
    bfs1(ex,ey);
    // for(int i=1;i<=n;i++){
    //     for(int j=1;j<=m;j++) cout<<mp1[i][j]<<' ';cout<<endl;
    // }
    int ans=Max;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(room[i][j]>k){
                if(mp[i][j]&&mp1[i][j]){
                    ans=min(ans,mp[i][j]+mp1[i][j]-2);
                }
            }
        }
    }
    if(ans==Max) printf("-1\n");
    else cout<<ans<<endl;
}