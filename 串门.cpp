#include <bits/stdc++.h>
using namespace std;
#define int long long
struct Edge
{
    int u,v,w,next;
}e[1000100];
int head[1000100],cnt,n,m,vis[100100],maxx,pos,res,s,dis[100100];
inline void add(int u,int v,int w)
{
    e[++cnt].u=u;
    //杩欏彞璇濆浜庢棰樹笉闇€瑕侊紝浣嗗湪缂╃偣涔嬬被鐨勯棶棰樿繕鏄湁鐢ㄧ殑
    e[cnt].v=v;
    e[cnt].w=w;
    e[cnt].next=head[u];
    //瀛樺偍璇ョ偣鐨勪笅涓€鏉¤竟
    head[u]=cnt;
    //鏇存柊鐩墠璇ョ偣鐨勬渶鍚庝竴鏉¤竟锛堝氨鏄繖涓€鏉¤竟锛?
}
void dfs(int x,int sum)
{
	for(int i=head[x];i;i=e[i].next)
	{
		int v=e[i].v;
		if(vis[v]) continue;
		vis[v]=1;
		if(e[i].w+sum>maxx)
		{
			maxx=sum+e[i].w;
			pos=v;
		}
		dfs(v,sum+e[i].w);
	}
}
signed main ()
{
	scanf("%lld",&n);
	for(int i=1;i<n;i++)
	{
		int u,v,w;
		scanf("%lld%lld%lld",&u,&v,&w);
		add(u,v,w);
		add(v,u,w);
		res+=w*2;
		dis[u]++;
		dis[v]++;
	}
	for(int i=1;i<=n;i++)
	{
		if(dis[i]==1)
		{
			s=i;
			break;
		}
	}
	vis[s]=1;
	dfs(s,0);
	s=pos;
//	cout<<maxx<<" "<<pos<<endl;
	maxx=0;
	
//	memset(head,0,sizeof head);
	memset(vis,0,sizeof(vis));
//	cnt=0;
	vis[s]=1;
	dfs(s,0);
//	cout<<maxx<<" "<<pos<<endl;
	printf("%lld",res-maxx);
	return 0;
}