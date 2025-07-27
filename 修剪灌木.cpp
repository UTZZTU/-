#include <iostream>
using namespace std;
int main ()
{
	int n,i;
	cin>>n;
	if(n==1)
	{
		printf("1");
		return 0;
	}
	else if(n==2)
	{
		printf("2\n2");
		return 0;
	}
	else
	{
		for(i=1;i<=n;i++)
		{
			printf("%d",max(2*(n-i),2*(i-1)));
			if(i!=n)
			printf("\n");
		}
	}
	return 0;
}
