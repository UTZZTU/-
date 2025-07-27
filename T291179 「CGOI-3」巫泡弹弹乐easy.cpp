#include<bits/stdc++.h>
using namespace std;
#define re register
#define il inline
typedef long long ll;
struct Edge
{
	ll u,v,w;
}edge[200005];
ll fa[5005],n,m,ans,eu,ev,cnt,a[100010],b[100010],tt;
vector<pair<ll,ll>> vec;
il bool cmp(Edge a,Edge b)
{
    return a.w<b.w;
}
il ll find(int x)
{
    while(x!=fa[x]) x=fa[x]=fa[fa[x]];
    return x;
}
il void kruskal()
{
    sort(edge,edge+cnt,cmp);
    for(re int i=0;i<cnt;i++)
    {
        eu=find(edge[i].u), ev=find(edge[i].v);
        if(eu==ev)
        {
            continue;
        }
        ans+=edge[i].w;
        vec.push_back({edge[i].u,edge[i].v});
        fa[ev]=eu;
        if(++cnt==n-1)
        {
            break;
        }
    }
}
int main()
{
    cin>>n;
    for(re int i=1;i<=n;i++)
    {
        fa[i]=i;
    }
    for(int i=1;i<=n;i++)
    {
    	cin>>a[i];
	}
	for(int j=1;j<=n;j++)
	{
		cin>>b[j];
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			tt=max(a[i],a[j])+max(b[i],b[j]);
			edge[cnt].u=i,edge[cnt].v=j,edge[cnt].w=tt;
			cnt++;
		}
	}
    kruskal();
    printf("%lld\n",ans);
    for(int i=0;i<vec.size();i++)
    {
    	cout<<vec[i].first<<" "<<vec[i].second<<endl;
	}
    return 0;
}