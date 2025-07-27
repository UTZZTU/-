#include <iostream>
using namespace std;
int main ()
{
	int n,m,max1=0,max2=0,min1=1000000000,min2=1000000000,k1,k2;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>k1>>k2;
		max1=max(max1,k1);
		min1=min(min1,k2);
	}
	cin>>m;
	for(int i=1;i<=m;i++)
	{
		cin>>k1>>k2;
		max2=max(max2,k1);
		min2=min(min2,k2);
	}
	if(max2<=min1&&max1<=min2)
	printf("0");
	else
	printf("%d",max(max2-min1,max1-min2));
	return 0;
}