#include <iostream>
#include <algorithm>
using namespace std;
int main ()
{
	int a[20005];
	int n,i,max,min,num1=1,num2=1;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	sort(a+1,a+1+n);
	min=a[1];
	max=a[n];
	i=1;
	while(a[i+1]==a[i])
	{
		num1++;
		i++;
	}
	i=n;
	while(a[i]==a[i-1])
	{
		num2++;
		i--;
	}
	printf("%d %d\n",min,num1);
	printf("%d %d",max,num2);
	return 0;
}