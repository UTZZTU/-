#include <iostream>
#include <algorithm>
using namespace std;
int main ()
{
	int n,m,a[30],i;
	while(cin>>n>>m)
	{
		for(i=0;i<n;i++)
	cin>>a[i];
	sort(a,a+m+1);
	for(i=0;i<n-1;i++)
	printf("%d ",a[i]);
	printf("%d\n",a[i]);
	}
	return 0;
}