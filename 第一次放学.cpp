#include <bits/stdc++.h>
using namespace std;
//#define int long long
int n,m,k,f[100010],tt[100010],maxx;
int main ()
{
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&f[i]);
		tt[f[i]]++;
	}
	sort(tt+1,tt+1+m);
	for(int i=1;i<=m;i++)
	{
		if(k>=tt[i])
		{
			k-=tt[i];
			tt[i]=0;
		}
		else
		{
			tt[i]-=k;
			break;
		}
	}
	for(int i=m;i>=1;i--)
	{
		maxx=max(maxx,tt[i]);
	}
	cout<<maxx;
	return 0;
}