#include <bits/stdc++.h>
using namespace std;
int t,n,s[200010],f[200010];
int main ()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&s[i]);
			f[i]=s[i];
		}
		sort(f+1,f+1+n);
		for(int i=1;i<=n;i++)
		{
			if(i!=1)
			printf(" ");
			if(s[i]==f[n])
			printf("%d",s[i]-f[n-1]);
			else
			printf("%d",s[i]-f[n]);
		}
		printf("\n");
	}
	return 0;
}