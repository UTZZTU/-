#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int N=200005;
const int M=35;
const int INF=0x3f3f3f;
const ull sed=31;
const ll mod=1e9+7;
const double eps=1e-8;
typedef pair<int,int>P;
typedef pair<double,double>Pd;
 
int n,m,a,b;
vector<int>E[N];
bool vis[2][N];
ll cnt[2];
 
void add(int u,int v)
{
    E[u].push_back(v);
    E[v].push_back(u);
}
 
void dfs(int u,int p)
{
    if(vis[p][u]) return ;
    cnt[p]++;
    vis[p][u]=true;
    for(int i=0;i<E[u].size();i++)
    {
        int v=E[u][i];
        if(vis[p][v]) continue;
        dfs(v,p);
    }
}
int main()
{
    scanf("%d%d%d%d",&n,&m,&a,&b);
    for(int i=0;i<m;i++)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        add(u,v);
    }
    vis[0][b]=true;
    dfs(a,0);
    vis[1][a]=true;
    dfs(b,1);
    ll scnt=0; 
    for(int i=1;i<=n;i++) if(vis[0][i] && vis[1][i]) scnt++;
    printf("%lld\n",(cnt[0]-scnt+1)*(cnt[1]-scnt+1));
    return 0;
}
 

