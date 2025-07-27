#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int f[10100];
struct wp
{
	int v,w,zt;
};
vector<wp> p;
int main ()
{
	int h1,m1,h2,m2,n,e,v,w,zt;
	scanf("%d:%d %d:%d %d",&h1,&m1,&h2,&m2,&n);
	e=(h2-h1)*60+(m2-m1);
	for(int i=1;i<=n;i++)
	{
		cin>>w>>v>>zt;
		if(zt==0||zt==1)
		{
			p.push_back({v,w,zt});
		
		}
		else
		{
			for(int j=1;j<=zt;j*=2)
		{
			zt-=j;
			p.push_back({j*v,j*w,1});
		}
		if(zt)
		{
			p.push_back({zt*v,zt*w,1});
		}
		}
	}
	for(auto it:p)
	{
		if(it.zt==0)
		{
			for(int j=it.w;j<=e;j++)
			f[j]=max(f[j],f[j-it.w]+it.v);
		}
		else if(it.zt==1)
		{
			for(int j=e;j>=it.w;j--)
			f[j]=max(f[j],f[j-it.w]+it.v);
		}
	}
	cout<<f[e];
	return 0;
}