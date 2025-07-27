#include <bits/stdc++.h>
using namespace std;
int a[110],k=1,cs[100010];
int main ()
{
	int n,pd=0;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)
	{
		int j=a[i],l=0;
		while(j!=1&&l<=200)
		{
			if(j&1)
		   j=(3*j+1)/2;
		   else
		   j=j/2;
		   cs[j]++;
		   l++;
		}
	}
	for(int i=n;i>=1;i--)
	{
		if(cs[a[i]]==0)
		{
			if(pd==1)
			printf(" ");
			else
			pd=1;
			printf("%d",a[i]);
		}
	}
	return 0;
}