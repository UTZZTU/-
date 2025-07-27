#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <stack>
using namespace std;
 
const int maxn = 210;
vector<int> G[maxn];
int pre[maxn],lowlink[maxn],sccno[maxn],dfs_clock,scc_cnt;
stack<int> S;
int indeg[maxn],outdeg[maxn];
 
void dfs(int u)
{
   pre[u]=lowlink[u]=++dfs_clock;
   S.push(u);
   for(int i=0;i<G[u].size();i++)
   {
       int v = G[u][i];
       if(!pre[v])
       {
           dfs(v);
           lowlink[u]=min(lowlink[u],lowlink[v]);
       }
       else if(!sccno[v])
       {
           lowlink[u]=min(lowlink[u],pre[v]);
       }
   }
 
   if(lowlink[u] == pre[u])
   {
       scc_cnt++;
       for(;;)
       {
           int x = S.top(); S.pop();
           sccno[x] = scc_cnt;
           if(x == u) break;
       }
   }
}
 
void find_scc(int n)
{
    dfs_clock = scc_cnt = 0;
    memset(sccno,0,sizeof(sccno));
    memset(pre,0,sizeof(pre));
    for(int i=1;i<=n;i++)
    {
        if(!pre[i])
            dfs(i);
    }
}
 
int main()
{
    int n;
    scanf("%d",&n);
    for(int i = 1;i <= n;i++)
    {
        int v;
        for(;;)
        {
            scanf("%d",&v);
            if(v == 0) break;
            G[i].push_back(v);
        }
    }
    find_scc(n);
    if(scc_cnt == 1)
    {
        puts("1");
        puts("0");
    }else
    {
        int sccout,sccin;
        for(int i=1;i<=n;i++)
            for(int j=0;j<G[i].size();j++)
        {
            int v = G[i][j];
            sccout = sccno[i];
            sccin = sccno[v];
            if(sccout == sccin)
            {
                continue;
            }
            outdeg[sccout]++;
            indeg[sccin]++;
        }
 
    int ans1=0,ans2=0;
    for(int i=1;i<=scc_cnt;i++)
    {
        if(indeg[i]==0)
        {
            ans1++;
        }
        if(outdeg[i]==0)
        {
            ans2++;
        }
    }
    printf("%d\n%d\n",ans1,max(ans1,ans2));
    }
    return 0;
}