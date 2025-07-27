#include <bits/stdc++.h>
using namespace std;
int t,n,a,b,res;
int main ()
{
	scanf("%d",&t);
	while(t--)
	{
		res=0;
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
		{
			scanf("%d%d",&a,&b);
			if(a-b>0) res++;
		}
		printf("%d\n",res);
	}
	return 0;
}