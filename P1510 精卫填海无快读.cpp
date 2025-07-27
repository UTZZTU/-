#include <iostream>
using namespace std;
int f[10010],vi[10010],k[10010];
int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int v,n,c,sum=0;
	cin>>v>>n>>c;
	int i,j;
	for(i=1;i<=n;i++)
	{
		cin>>vi[i]>>k[i];
		sum+=vi[i];
	}
	if(sum<v)
	{
		printf("Impossible");
		return 0;
	}
	for(i=1;i<=n;i++)
	{
		for(j=c;j>=k[i];j--)
		f[j]=max(f[j],f[j-k[i]]+vi[i]);
	}
	for(i=0;i<=c;i++)
	{
		if(f[i]>=v)
		{
			printf("%d",c-i);
			return 0;
		}
	}
	printf("Impossible");
	return 0;
}