#include<bits/stdc++.h>
using namespace std;
#define re register
#define il inline
typedef long long ll;
struct Edge
{
	ll u,v,w;
}edge[200005];
ll fa[50005],n,m,ans,eu,ev,cnt,c,pos,vec[50050];
bool check(ll x){
	ll mon=0,yy=1;
	for(int i=pos;i>=1;i--){
		if(vec[i]<=x)
		break;
		else{
			mon+=yy*vec[i];
			yy++;
		}
	}
	return mon<=c;
}
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
    sort(edge,edge+m,cmp);
    for(re int i=0;i<m;i++)
    {
        eu=find(edge[i].u), ev=find(edge[i].v);
        if(eu==ev)
        {
            continue;
        }
        ans+=edge[i].w;
        vec[++pos]=edge[i].w;
        fa[ev]=eu;
        if(++cnt==n-1)
        {
            break;
        }
    }
}
int main()
{
    scanf("%lld%lld%lld",&n,&m,&c);
    for(re int i=1;i<=n;i++)
    {
        fa[i]=i;
    }
    for(re int i=0;i<m;i++)
    {
        scanf("%lld%lld%lld",&edge[i].u,&edge[i].v,&edge[i].w);
    }
    kruskal();
    ll l=0,r=1000000000;
    while(l<r){
    	ll mid=(l+r)>>1;
    	if(check(mid))
    	r=mid;
    	else
    	l=mid+1;
	}
	cout<<l;
    return 0;
}