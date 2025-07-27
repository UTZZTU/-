#include <iostream>
using namespace std;
int a[100010],t,n,res;
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
		res=0;
		while(1)
		{
			int judge=1;
			for(int i=1;i<=n;i++)
			{
				if(a[i]!=i)
				{
					swap(a[i],a[a[i]]);
					res++;
					judge=0;
				}
			}
			if(judge)
			break;
		}
		printf("%d\n",res);
	}
	return 0;
}