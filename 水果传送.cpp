#include <iostream>
using namespace std;
int a[100010];
int main ()
{
	int m,k,t,zj;
	cin>>m>>k>>t;
	int i;
	zj=m/2+1;
	for(i=1;i<zj;i++)
	{
		if(t<=i-1)
		a[i]=0;
		else if(t>i-1&&t<=i+k/2+(zj-i-1)*k)
		a[i]=1;
		else
		{
			a[i]=1;
			int time;
			time=t-i-k/2-(zj-i-1)*k;
			a[i]=min(k,time+a[i]);
		}
	}
	if(t<=zj-1)
	a[zj]=0;
	else if(t>zj-1&&t<zj-1+k/2)
	{
		a[zj]=(t-zj+1)*2;
	}
	else
	a[zj]=k;
	for(i=zj+1;i<=m;i++)
	{
		a[i]=a[2*zj-i];
	}
	for(i=1;i<m;i++)
	printf("%d ",a[i]);
	printf("%d",a[i]);
	return 0;
}