#include <bits/stdc++.h>
using namespace std;
int n,a[1000010],num1,num2;
int main ()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	for(int i=2;i<=n;i++)
	{
		if(a[i]<a[i-1])
		{
			num1++;
		}
		else if(a[i]>a[i-1])
		{
			num2++;
		}
		if(num1&&num2)
		{
			cout<<"bukeyi";
			return 0;
		}
	}
	cout<<"erfen is useful!";
	return 0;
}