#include <stdio.h>
#include <algorithm>
int main ()
{
	int n,s[200000],i;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&s[i]);
	}
	std::sort(s,s+n);
	for(i=0;i<n;i++)
	{
		if(s[i+1]-s[i]!=1)
		{
			printf("%d",s[i]+1);
			break;
		}
	}
	return 0;
}
