#include <stdio.h>
#include <algorithm>
using namespace std;
int main ()
{
	int n,i,a[100005],b[100005],j,sum=0,hsz=0,k,p;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d %d",&a[i],&b[i]);
		if(b[i]==0)
		hsz++;
	}
	for(i=0;i<n-1;i++)
	{
		k=i;
		for(j=i+1;j<n;j++)
			if(a[k]<a[j])
			k=j;
			if(k!=i)
			{
				p=a[i];
				a[i]=a[k];
				a[k]=p;
				p=b[i];
				b[i]=b[k];
				b[k]=p;
			}
	}
	for(i=0;i<n-1;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if(a[i]==a[j])
			{
				if(b[i]>b[j])
				{
					p=b[i];
					b[i]=b[j];
					b[j]=p;
					break;
				}
			}
			else
			break;
		}
	}
	for(i=0;i<n/2;i++)
	{
		if(b[i]==0)
		sum++;
	}
	printf("%d %d\n",sum,n/2-sum);
	printf("%d %d",hsz-sum,n/2-(hsz-sum));
	return 0;
}
