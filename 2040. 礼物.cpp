#include <bits/stdc++.h>
using namespace std;
struct node
{
	int p,s;
}w[1010];
int f[1010],n,b,ans,e[1010];
int main ()
{
	cin>>n>>b;
	for(int i=1;i<=n;i++)
	{
		scanf("%d %d",&w[i].p,&w[i].s);
		f[i]=w[i].p+w[i].s;
	}
	for(int i=1;i<=n;i++)
	{
		f[i]=w[i].p/2+w[i].s;
		for(int j=1;j<=n;j++)
		e[j]=f[j];
		sort(e+1,e+1+n);
		int js=0,k=b;
		for(int j=1;j<=n;j++)
		{
			if(k-e[j]>=0)
			{
				js++;
				k-=e[j];
			}
			else
			break;
		}
		ans=max(ans,js);
		f[i]=w[i].p+w[i].s;
	}
	cout<<ans;
	return 0;
}