#include <iostream>
using namespace std;
int n,m,a[200010],b[200010];
bool check(int x)
{
	int res1=0,res2=0;
	for(int i=1;i<=n;i++)
	{
		if(a[i]<=x) res1++;
	}
	for(int i=1;i<=m;i++)
	{
		if(x<=b[i]) res2++;
	}
	return res1>=res2;
}
int main ()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	for(int i=1;i<=m;i++)
	{
		scanf("%d",&b[i]);
	}
	int l=0,r=1e9+10;
	while(l<r)
	{
		int mid=l+r>>1;
		if(check(mid)) r=mid;
		else l=mid+1;
	}
	cout<<l;
	return 0;
}