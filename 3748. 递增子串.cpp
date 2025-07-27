#include <bits/stdc++.h>
using namespace std;
int t,n,f[200010];
string s;
int main ()
{
	scanf("%d",&t);
	for(int i=1;i<=t;i++)
	{
		scanf("%d",&n);
		getchar();
		cin>>s;
		printf("Case #%d:",i);
		for(int j=0;j<n;j++)
		{
			if(!j) f[0]=1;
			else
			{
				if(s[j]>s[j-1]) f[j]=f[j-1]+1;
				else f[j]=1;
			}
			printf(" %d",f[j]);
		}
		printf("\n");
	}
	return 0;
}