#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int a[20][20],o[101010];
int main ()
{
	int n;
	while(cin>>n)
	{
		vector<int> p;
		int i,j,sum=0;
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=n;j++)
			cin>>a[i][j];
		}
		for(i=1;i<=n;i++)
		{
			int mx=0,wz,mn=10101010;
			for(j=1;j<=n;j++)
			{
				if(a[i][j]>mx)
				{
					mx=a[i][j];
					wz=j;
				}
			}
			for(j=1;j<=n;j++)
			{
				mn=min(mn,a[j][wz]);
			}
			if(mn==mx)
			o[sum++]=mn;
		}
		if(sum==0)
		printf("No\n");
		else
		{
			for(i=0;i<sum-1;i++)
			printf("%d ",o[i]);
			printf("%d\n",o[i]);
		}
	}
	return 0;
}