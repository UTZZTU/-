#include <bits/stdc++.h>
using namespace std;
int t,n,l1,r1,l2,r2,res;
int main ()
{
	scanf("%d",&t);
	while(t--)
	{
		res=0;
		scanf("%d",&n);
		scanf("%d%d%d%d",&l1,&r1,&l2,&r2);
		for(int i=l1;i<=r1;i++)
		{
			if(n-i>=l2&&n-i<=r2)
			res++;
		}
		printf("%d\n",res);
	}
	return 0;
}