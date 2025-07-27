#include <bits/stdc++.h>
using namespace std;
int t,l,r,k;
int main ()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d%d",&l,&r,&k);
		int len=(r-l+1),tt;
		if(k==0)
		{
			printf("%d\n",len%2);
			continue;
		}
		if(l%2==0&&len&1)
		{
			tt=(len-1)/2;
		}
		else if(len%2==0&&len%2==0)
		{
			tt=(len)/2;
		}
		else if(l&1&&len&1)
		{
			tt=(len-1)/2+1;
		}else 
		{
			tt=(len)/2;
		}
		printf("%d\n",tt%2);
	}
	return 0;
}