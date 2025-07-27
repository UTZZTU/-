#include<bits/stdc++.h>
using namespace std;
#define int long long
#define re register
#define il inline
il int read()
{
    re int x=0,f=1;char c=getchar();
    while(c<'0'||c>'9'){if(c=='-') f=-1;c=getchar();}
    while(c>='0'&&c<='9') x=(x<<3)+(x<<1)+(c^48),c=getchar();
    return x*f;
}

struct Edge
{
	int u,v,w;
}edge[200005];
int fa[5005],n,k,ans,eu,ev,cnt,num;
il bool cmp(Edge a,Edge b)
{
    return a.w<b.w;
}
il int find(int x)
{
    while(x!=fa[x]) x=fa[x]=fa[fa[x]];
    return x;
}
il void kruskal()
{
    sort(edge,edge+num,cmp);
    for(re int i=0;i<num;i++)
    {
        eu=find(edge[i].u), ev=find(edge[i].v);
        if(eu==ev)
        {
            continue;
        }
        ans+=edge[i].w;
        cout<<edge[i].u<<" "<<edge[i].v<<" "<<edge[i].w<<endl;
        fa[ev]=eu;
        if(++cnt==n-1)
        {
            break;
        }
    }
}
signed main()
{
    n=read(),k=read();
    for(re int i=1;i<=n;i++)
    {
        fa[i]=i;
    }
    for(int i=1;i<n;i++)
    {
        for(int j=i+1;j<=n;j++)
        {
        	if(j-i<=k)
        	{
        		edge[num].u=i;
        		edge[num].v=j;
        		edge[num].w=i*j/__gcd(i,j);
        		num++;
			}
			else
			{
				edge[num].u=i;
        		edge[num].v=j;
        		edge[num].w=__gcd(i,j);
        		num++;
			}
		}
    }
    kruskal();
    printf("%d",ans);
    return 0;
}