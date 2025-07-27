#include <iostream>
#include <algorithm>
using namespace std;
int main ()
{
	int n,m,i,k,a[2000];
	scanf("%d %d",&n,&m);
	for(i=1;i<=n+m;i++)
	scanf("%d",&a[i]);
	sort(a+1,a+1+m+n);
	for(i=1;i<=m+n;i++)
	printf("%d ",a[i]);
	return 0;
}