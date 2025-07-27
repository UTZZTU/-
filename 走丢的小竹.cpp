#include <bits/stdc++.h>
using namespace std;
int n,m,q,f[100010],sum,k;
int main ()
{
	scanf("%d%d%d",&n,&m,&q);
	sum=n;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&k);
		f[k]++;
	}
	while(q--)
	{
		scanf("%d",&k);
		cout<<sum-f[k]<<endl;
	}
	return 0;
}