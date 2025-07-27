#include<bits/stdc++.h>
using namespace std;
int n,head;
char a[2];
int b[130][130];//存图
int deg[130],fa[130];//deg存储度数，fa存储父亲，用来并查集判断是否联通
char ans[1330];//稍大于51*52/2
int find(int x)
{
   while(x!=fa[x]) x=fa[x]=fa[fa[x]];
   return x;
} 
void dfs(int x)//找欧拉回路/路径
{
	for(int i=64;i<=125;i++)
	  if(b[x][i])
	  {
	  	b[x][i]=b[i][x]=0;
	  	dfs(i);
	  }
	ans[n--]=x;//因为是回溯的时候存，所以倒着存
}
int main()
{
	cin>>n;
	for(int i=64;i<=125;i++)fa[i]=i;
    //A在ASCII码表里为65，z为122，所以64~125就足够了
	for(int i=1;i<=n;i++)
	{
		cin>>a;
		b[a[0]][a[1]]=b[a[1]][a[0]]=1;
		deg[a[0]]++;
		deg[a[1]]++;
		int xx=find(a[0]),yy=find(a[1]);
		fa[xx]=yy;
	}
	int cnt=0;
	for(int i=64;i<=125;i++)
	  if(fa[i]==i&&deg[i])cnt++;//祖宗结点
	if(cnt!=1){cout<<"No Solution"<<endl;return 0;}//如果不是连通图
	cnt=0;
	head=0;
	for(int i=64;i<=125;i++)
	{
		if(deg[i]&1)
		{
			cnt++;
			if(head==0)head=i;//顺道存储起点
		}
	}
	if(cnt&&cnt!=2){cout<<"No Solution"<<endl;return 0;}
    //如果有奇数度数的点，并且不是两个，说明不存在欧拉回路/路径
    if(head==0)//如果是欧拉回路
      for(int i=64;i<=125;i++)
        if(deg[i]){head=i;break;}//找欧拉回路的起点
    dfs(head);
    cout<<ans;
    return 0;
} 