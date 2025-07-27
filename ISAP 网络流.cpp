#include<bits/stdc++.h>
using namespace std;
const int inf=2147483647;//inf:最大值 
int cnt=1,head[505];//cnt:第CNT条边head[i]:第i个点属于第几条边 
int n,m,s,t;//n个点m条边s:源点t:汇点 
inline int Read()
{
    int x=0;
    char c=getchar();
    while(c>'9'||c<'0')c=getchar();
    while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();
    return x;
}
struct Node
{
    int v;//当前点 
    int next;//连接点 
    int val;//容量 
}node[100010];//node[i]:第i条边的情况 
inline void addedge(int u,int v,int val)
{
    node[++cnt].v=v;
    node[cnt].val=val;
    node[cnt].next=head[u];
    head[u]=cnt;
}
int dep[505],gap[505];//dep[i]表示节点i的深度，gap[i]表示深度为i的点的数量 
void bfs()//倒着搜 
{
    memset(dep,-1,sizeof(dep));//把深度变为-1(0会导致gap崩坏) 
    memset(gap,0,sizeof(gap));
    dep[t]=0;//汇点深度为0 
    gap[0]=1;//深度为0的点有1个 
    queue<int>q; 
    q.push(t);//t点入栈 
    while(!q.empty())
	{
        int u=q.front();
        q.pop();
        for(int i=head[u];i;i=node[i].next)//head[u]:u点所在的边,node[i].next:u点所在的边的下一个点，就这样遍历下去 
		{
            int v=node[i].v;//v为当前边的下一个点 
            if(dep[v]!=-1)	continue;//dep[v]!=-1相当于v点已被遍历||不管 
            q.push(v);
            dep[v]=dep[u]+1;//v点的深度比u点大1 
            gap[dep[v]]++;
        }//直到所有点都被遍历过 
    }
    return;
}//从t到s跑一遍bfs，标记深度
long long maxflow;
int dfs(int u,int flow)
{
    if(u==t)
	{
        maxflow+=flow;
        return flow;
    }
    int used=0;
    for(int i=head[u];i;i=node[i].next)//head[u]:u点所在的边,node[i].next:u点所在的边的下一个点，就这样遍历下去 
	{
        int d=node[i].v;
        if(node[i].val&&dep[d]+1==dep[u])//如果这条边的残量大于0,且没有断层 
		{
            int mi=dfs(d,min(node[i].val,flow-used));
            if(mi){
                node[i].val-=mi;
                node[i^1].val+=mi;
                used+=mi;
            }
            if(used==flow)return used;
        }
    }
    //如果已经到了这里，说明该点出去的所有点都已经流过了
    //并且从前面点传过来的流量还有剩余
    //则此时，要对该点更改dep
    //使得该点与该点出去的点分隔开
    --gap[dep[u]];
    if(gap[dep[u]]==0)dep[s]=n+1;//出现断层，无法到达t了
    dep[u]++;//层++ 
    gap[dep[u]]++;//层数对应个数++
    return used; 
}
long long ISAP()
{
    maxflow=0;
    bfs();
    while(dep[s]<n)	dfs(s,inf);//每走一遍增广路,s的层数会加1,如果一直没有出现断层,最多跑n-dep(刚bfs完时s的深度)条增广路共有n个点 
    return maxflow;
}
int main()
{
    n=Read(),m=Read(),s=Read(),t=Read();
    int u,v,w;
    for(int i=1;i<=m;i++)
	{
		u=Read();
		v=Read();
		w=Read();
		addedge(u,v,w);//正向边 
		addedge(v,u,0);//反向边 
	}  
    printf("%lld\n",ISAP());
    return 0;
}