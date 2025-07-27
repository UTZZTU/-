#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int inf=0x3f3f3f3f;
const int maxn=1e5+50;
struct edge{
    int to,w;
    edge(int too,int ww):to(too),w(ww){}
};
vector<edge>G[maxn];
int dp[maxn],maxl,s,maxx;

void dfs(int u,int f,int len){
    if(maxl<len){
        s=u;
        maxl=len;
    }
    for(int i=0;i<G[u].size();i++){
        int to=G[u][i].to, w=G[u][i].w;
        if(f==to) continue;
        dfs(to,u,len+w);
        dp[to]=max(dp[to],len+w);
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n,m,a,b;
    cin>>n>>m;
    while(m--)
    {
    	cin>>a>>b;
    	G[a].push_back(edge(b,1));
    	G[b].push_back(edge(a,1));
	}
    s=0; maxl=0;
    dfs(1,0,0);
    dfs(s,0,0);
    dfs(s,0,0);
    for(int i=1;i<=n;i++) maxx=max(maxx,dp[i]);
    cout<<maxx;
    return 0;
}