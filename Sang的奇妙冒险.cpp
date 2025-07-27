#include <bits/stdc++.h>
using namespace std;
int n,a[1000010],b[1000010],len=1;
int bs(int x){
	int l = 1,r = len;
	int mid;
	while(l <= r){
		mid = l+r>>1;
		if(x >= b[mid]) l = mid + 1;
		else r = mid - 1;
	}
	return l;
}
int main ()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	printf("%d ",abs(a[1]-a[n])+n-1);
	if(a[1]>=a[n])
	{
		b[1]=a[n];
		for(int i=n-1;i>=1;i--)
		{
			if(a[i]<=a[1]&&a[i]>=a[n])
			{
				if(a[i] >= b[len])
					b[++len] = a[i];
				else{
					int j = bs(a[i]);
					b[j] = a[i];
				}
			}
		}
		printf("%d",len-1);
	}
	else
	{
		b[1]=a[1];
		for(int i=2;i<=n;i++)
		{
			if(a[i]<=a[n]&&a[i]>=a[1])
			{
				if(a[i] >= b[len])
					b[++len] = a[i];
				else{
					int j = bs(a[i]);
					b[j] = a[i];
				}
			}
		}
		printf("%d",len-1);
	}
	return 0;
}