#include <bits/stdc++.h>
using namespace std;
int n,a[1010];
double x,d;
int main ()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		x+=a[i];
	}
	x/=n;
	for(int i=1;i<=n;i++)
	{
		d+=(a[i]-x)*(a[i]-x);
	}
	d/=n;
	for(int i=1;i<=n;i++)
	{
		printf("%.6f\n",(a[i]-x)/sqrt(d));
	}
	return 0;
}