#include <iostream>
using namespace std;
int main ()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n,sum=0,a[11][11],scx,scy,xzx,xzy;
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			cin>>a[i][j];
		}
		scx=1;
		scy=1;
		while(sum<n*n)
		{
			xzx=scx;
			xzy=scy;
			while(xzx<=n&&xzy>=1)
			{
			  if(sum==0)
			  printf("%d",a[xzx][xzy]);
			  else
			  printf(" %d",a[xzx][xzy]);
			   sum++;
			   xzx++;
			   xzy--;
			}
			if(scy<n)
			{
				scx=scx;
				scy=scy+1;
			}
			else
			{
				scx=scx+1;
				scy=scy;
			}
		}
		printf("\n");
	}
	return 0;
}
