#include <bits/stdc++.h>
using namespace std;
int n,d,sum,a[1010];
int main ()
{
	scanf("%d %d",&n,&d);
	for(int i=1;i<=n;i++)
	scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(i==j)
			continue;
			if(abs(a[i]-a[j])<=d)
			sum++;
		}
	}
	cout<<sum;
	return 0;
}