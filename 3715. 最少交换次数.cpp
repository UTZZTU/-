#include <bits/stdc++.h>
using namespace std;
int a[1010],b[1010],c[1010],sum;
int main ()
{
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		c[a[i]]=i;
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<c[i];j++)
		{
			if(a[j]>i)
			b[i]++;
		}
	}
	for(int i=1;i<=n;i++)
	{
		if(i!=1)
		cout<<" ";
		cout<<b[i];
		sum+=b[i];
	}
	cout<<endl;
	cout<<sum;
	return 0;
}