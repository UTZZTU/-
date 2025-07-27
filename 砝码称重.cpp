#include <bits/stdc++.h>
using namespace std;
int n,f[110][100100],a[100100],sum,res;
int main ()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		sum+=a[i];
	}
	f[0][0]=1;
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<=sum;j++)
		{
			if(f[i-1][j])
			{
				f[i][j]=1;
				f[i][j+a[i]]=1;
				if(j-a[i]>=0)
				f[i][j-a[i]]=1;
				else
				f[i][a[i]-j]=1;
			}
		}
	}
	for(int i=1;i<=sum;i++)
	{
		if(f[n][i]) res++;
	}
	cout<<res;
	return 0;
}