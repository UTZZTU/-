#include <bits/stdc++.h>
using namespace std;
int f[100010];
int main ()
{
	int n,m,q;
	scanf("%d",&q);
	for(int i=1;i<=q;i++)
	{
		memset(f,0,sizeof(f));
		scanf("%d %d",&n,&m);
		for(int j=1;j<=n;j++)
		f[j]=j;
		for(int j=1;j<=m;j++)
		{
			for(int k=j*j;k<=n;k++)
			{
				f[k]=min(f[k],f[k-j*j]+1);
			}
		}
		cout<<f[n]<<endl;
	}
	return 0;
}