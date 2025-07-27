#include <bits/stdc++.h>
using namespace std;
int main ()
{
	for(int i=20;i>=1;i--)
	{
		for(int j=i-1;j>=1;j--)
		{
			for(int k=j-1;k>=1;k--)
			{
				for(int u=k-1;u>=1;u--)
				{
					double s=1.0/i+1.0/j+1.0/k+1.0/u;
					if(s==1.0)
					{
						printf("%d %d %d %d 0\n",i,j,k,u);
					}
				}
			}
		}
	}
	return 0;
}