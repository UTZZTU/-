#include <bits/stdc++.h>
using namespace std;
int n,a[110],t,b[110];
int main ()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
		}
		int pos=1;
		for(int i=1;i<=n;i++)
		{
			if(pos==a[i])
			{
				pos++;
			}
			b[i]=pos;
			pos++;
		}
		printf("%d\n",b[n]);
	}
	return 0;
}