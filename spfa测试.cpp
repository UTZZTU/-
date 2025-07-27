#include<bits/stdc++.h>
const long long inf=2147483647;
const int maxn=100050;
const int maxm=500005;
using namespace std;
int n,m1,m2,s,num_edge=0;
int dis[maxn],vis[maxn],head[maxm];
inline int read()
{
	int x=0,k=1;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')k=-1;c=getchar();}
	while(c>='0'&&c<='9'){x=(x<<3)+(x<<1)+(c^48);c=getchar();}
	return x*k;
}
struct Edge
{
  int next,to,dis;
}edge[maxm]; //结构体表示静态邻接表
void addedge(int from,int to,int dis) //邻接表建图
{ //以下是数据结构书上的标准代码，不懂翻书看解释
  edge[++num_edge].next=head[from]; //链式存储下一条出边
  edge[num_edge].to=to; //当前节点编号
  edge[num_edge].dis=dis; //本条边的距离
  head[from]=num_edge; //记录下一次的出边情况
}
void spfa()
{
  queue<int> q; //spfa用队列，这里用了STL的标准队列
  for(int i=1; i<=n; i++) 
  {
    dis[i]=inf; //带权图初始化
    vis[i]=0; //记录点i是否在队列中，同dijkstra算法中的visited数组
  }
  q.push(s); dis[s]=0; vis[s]=1; //第一个顶点入队，进行标记
  while(!q.empty())
  {
    int u=q.front(); //取出队首
    q.pop(); vis[u]=0; //出队标记
    for(int i=head[u]; i; i=edge[i].next) //邻接表遍历，不多解释了（也可用vector代替）
    {
      int v=edge[i].to; 
      if(dis[v]>dis[u]+edge[i].dis) //如果有最短路就更改
      {
        dis[v]=dis[u]+edge[i].dis;
        if(vis[v]==0) //未入队则入队
        {
          vis[v]=1; //标记入队
          q.push(v);
        }
      }
    }
  }
}
int main()
{
  n=read();m1=read();m2=read();s=read();
  for(int i=1,f,g,w; i<=m1; i++)
  {
    f=read();g=read();w=read();
    addedge(f,g,w); //建图，有向图连一次边就可以了
    addedge(g,f,w);
  }
  for(int i=1,f,g,w;i<=m2;i++)
  {
  	f=read();g=read();w=read();
    cin>>f>>g>>w; 
    addedge(f,g,w);
  }
  spfa(); //开始跑spfa
  for(int i=1; i<=n; i++)
    if(s==i) cout<<0<<endl; //如果是回到自己，直接输出0
    else if(dis[i]==inf)
    cout<<"NO PATH"<<endl;
      else cout<<dis[i]<<endl; //否则打印最短距离
  return 0;
} //结束