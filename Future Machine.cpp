#include <bits/stdc++.h>
using namespace std;
int n,m,x,a[1000010],b[1000010];
int main ()
{
	scanf("%d%d%d",&n,&m,&x);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	for(int j=0;j<m;j++)
	{
		scanf("%d",&b[j]);
	}
	sort(b,b+m);
	for(int i=0;i<=n*m-1;i++)
	{
		int f[3]={x,a[i/m],b[i%m]};
		sort(f,f+3);
		x=f[1];
		cout<<x<<endl;
	}
	return 0;
}