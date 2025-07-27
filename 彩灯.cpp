#include <iostream>
using namespace std;
int a[10010];
int main ()
{
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	int m,x,sum=0,mb=0;
	cin>>m>>x;
	for(int i=1;i<=n;i++)
	if(a[i]==x)
	mb++;
	sum+=m/n*mb;
	for(int i=m/n*n+1;i<=m;i++)
	{
		if(a[i%n]==x)
		sum++;
	}
	printf("%d",sum);
	return 0;
}