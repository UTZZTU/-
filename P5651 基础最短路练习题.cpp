#include<bits/stdc++.h>
using namespace std;
#define inf 1234567890
#define maxn 10005
inline int read()
{
    int x=0,k=1; char c=getchar();
    while(c<'0'||c>'9'){if(c=='-')k=-1;c=getchar();}
    while(c>='0'&&c<='9')x=(x<<3)+(x<<1)+(c^48),c=getchar();
    return x*k;
}//快读
int a[maxn][maxn],n,m,q;
inline void floyd()
{
    for(int k=1;k<=n;k++)
    //这里要先枚举k（可以理解为中转点）
	{
        for(int i=1;i<=n;i++)
		{
            if(i==k||a[i][k]==inf)
            {
                continue;
			}
			for(int j=1;j<=n;j++)
			{
				if(a[k][j]==inf)
				continue;
                a[i][j]=min(a[i][j],a[i][k]^a[k][j]);
                //松弛操作，即更新每两个点之间的距离
                //松弛操作有三角形的三边关系推出
                //即两边之和大于第三边
            }
        }
    }
}
int main()
{
    n=read(),m=read(),q=read();
    for(int i=1;i<=n;i++)
	{
        for(int j=1;j<=n;j++)
		{
            a[i][j]=inf;
        }
    }
	//初始化，相当于memset(a,inf,sizeof(a))
    for(int i=1,u,v,w;i<=m;i++)
	{
        u=read(),v=read(),w=read();
        a[u][v]=a[v][u]=w;
        //取min可以对付重边
    }
    floyd();
    for(int i=1;i<=q;i++)
    {
    	int u,v;
    	u=read(),v=read();
    	printf("%d\n",a[u][v]);
	}
    return 0;
}