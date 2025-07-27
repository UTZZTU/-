#include <iostream>
using namespace std;
int main ()
{
	int n;
	cin>>n;
	int *p=new int[100],sum=0;
	for(int i=0;i<n;i++)
	{
		cin>>*(p+i);
		sum+=*(p+i);
	}
		printf("a[%d]={",n);
		for(int i=0;i<n;i++)
		{
			cout<<*(p+i);
			if(i!=n-1)
			printf(",");
		}
	printf("}\n");
	printf("sum=%d",sum);
	return 0;
}