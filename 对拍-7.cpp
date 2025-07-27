#include <bits/stdc++.h>
using namespace std;
int n,res,cnt,fa[1000010];
struct node
{
	int x,y,w;
}s[1000010];
bool cmp(node a,node b)
{
	return a.w<b.w;
}
int find(int x)
{
	while(x!=fa[x]) x=fa[x]=fa[fa[x]];
	return x;
}
void kruskal()
{
	sort(s+1,s+1+cnt,cmp);
	int tt=0;
	for(int i=1;i<=cnt;i++)
	{
		int eu=find(s[i].x),ev=find(s[i].y);
//		cout<<s[i].x<<" "<<s[i].y<<" "<<s[i].w<<endl;
		if(eu!=ev)
		{
			fa[eu]=ev;
			res+=s[i].w;
			tt++;
			if(tt==n-1)
			break;
		}
	}
}
int main ()
{
	for(int t=2;t<=1000;t++)
	{
		res=0;
		cnt=0;
		for(int i=1;i<=t;i++)
		{
			fa[i]=i;
			for(int j=i+1;j<=t;j++)
			{
				int w=i&j;
				s[++cnt].x=i;
				s[cnt].y=j;
				s[cnt].w=w;
			}
		}
		kruskal();
//		cout<<res;
		if(res!=0)
		cout<<res<<" "<<t<<endl;
//		else cout<<endl;
	}
	return 0;
}