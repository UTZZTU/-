#include <iostream>
#include <algorithm>
using namespace std;
int main ()
{
	int num[1111];
	int m,n,k;
	scanf("%d",&m);
	while(m--)
	{
		scanf("%d%d",&n,&k);
		for(int i=0;i<n;i++)
		{
			scanf("%d",&num[i]);
		}
		while(k--)
		{
			next_permutation(num,num+n);
		}
		for(int i=0;i<n;i++)
		{
			printf("%d ",num[i]);
		}
		printf("\n");
	}
	return 0;
}
