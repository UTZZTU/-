#include <iostream>
#include <algorithm>
using namespace std;
void fun(int a[],int n,int& max1,int& max2)
{
	sort(a,a+n);
	max1=a[n-1];
	max2=a[n-2];
}
int main ()
{
	int a[22],n,i,q1,q2;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	fun(a,n,q1,q2);
	printf("%d %d",q1,q2);
	return 0;
}