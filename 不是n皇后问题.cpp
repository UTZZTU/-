#include <bits/stdc++.h>
using namespace std;
int n,pos=1;
int main ()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			printf("%d ",pos);
			pos++;
		}
		printf("\n");
	}
	return 0;
}