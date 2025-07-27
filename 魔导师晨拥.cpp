#include <bits/stdc++.h>
using namespace std;
int n,m,a[10],sh=2,res;
int main ()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	cin>>a[i];
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(a[j]>0)
			{
				a[j]-=sh;
				if(a[j]==0)
				sh++;
			}
		}
		res+=sh;
	}
	cout<<res;
	return 0;
}