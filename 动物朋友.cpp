#include <bits/stdc++.h>
using namespace std;
int n,m,f[1000100],res,cnt;
int main ()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&f[i]);
	}
	int i=0,j=1;
	while(i<n)
	{
		while(res<m&&j<=n)
		{
			res+=f[j];
			j++;
		}
		if(res==m) cnt++;
		i++;
		res-=f[i];
	}
	printf("%d",cnt);
	return 0;
}