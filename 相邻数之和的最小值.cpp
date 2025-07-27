#include <iostream>
using namespace std;
int a[30];
int main ()
{
	int n;
	while(cin>>n)
	{
		int mn=10000000,i,sum;
		for(i=1;i<=n;i++)
		cin>>a[i];
		sum=a[1]+a[2]+a[3];
		mn=min(mn,sum);
		for(i=4;i<=n;i++)
		{
			sum-=a[i-3];
			sum+=a[i];
			mn=min(mn,sum);
		}
		sum=a[1]+a[2]+a[n];
		mn=min(mn,sum);
		sum=a[1]+a[n-1]+a[n];
		mn=min(mn,sum);
		printf("%d\n",mn);
	}
	return 0;
}