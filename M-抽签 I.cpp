#include <bits/stdc++.h>
using namespace std;
#define re register
int n,a[110],m;
int main ()
{
	scanf("%d",&n);
	for(re int i=1;i<=n;i++)
	scanf("%d",&a[i]);
	scanf("%d",&m);
	for(re int i=1;i<=n;i++)
	{
		for(re int j=1;j<=n;j++)
		{
			for(re int k1=1;k1<=n;k1++)
			{
				for(re int k2=1;k2<=n;k2++)
				{
					if(a[i]+a[j]+a[k1]+a[k2]==m)
					{
						cout<<"Yes";
						return 0;
					}
				}
			}
		}
	}
	cout<<"No";
	return 0;
}