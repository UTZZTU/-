#include<stdio.h>
#include<string.h>
struct node
{
    int to;
    int next;
} p[10005];
int dfn[105],low[105];
int head[105],vis[105];
int cut[105];
int m,e,root;
int min(int a,int b)
{
    return a<b?a:b;
}
void add(int u,int v)
{
    p[e].to=v;
    p[e].next=head[u];
    head[u]=e++;
}
void dfs(int u,int father,int a)
{
    int son=0;
    vis[u]=1;
    dfn[u]=low[u]=a;
    for(int i=head[u]; i!=-1; i=p[i].next)
    {
        int v=p[i].to;
        if(vis[v]==1&&v!=father)
            low[u]=min(low[u],dfn[v]);
        if(vis[v]==0)
        {
            dfs(v,u,a+1);
            son++;
            low[u]=min(low[u],low[v]);
            if((u==root&&son>1)||(u!=root&&dfn[u]<=low[v]))
                cut[u]=1;
        }
    }
    vis[u]=2;
}
int main()
{
    while(scanf("%d",&m)&&m!=0)
    {
        memset(dfn,0,sizeof(dfn));
        memset(low,0,sizeof(low));
        memset(head,-1,sizeof(head));
        memset(vis,0,sizeof(vis));
        memset(cut,0,sizeof(cut));
        int n;
        e=0;
        while(scanf("%d",&n)&&n!=0)
        {
            while(getchar()!='\n')
            {
                int a;
                scanf("%d",&a);
                add(n,a);
                add(a,n);
            }
        }
        root=1;
        int sum=0;
        dfs(1,-1,1);
        for(int i=1; i<=m; i++)
            if(cut[i])
                sum++;
        printf("%d\n",sum);
    }
    return 0;
}