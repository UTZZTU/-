#include <iostream>
using namespace std;
int main ()
{
	int n,k,i,sum=0,a;
	scanf("%d%d",&n,&k);
	for(i=1;i<=n;i++)
	{
		scanf("%d",&a);
		sum+=2*min(a,k-a);
	}
	printf("%d",sum);
	return 0;
}