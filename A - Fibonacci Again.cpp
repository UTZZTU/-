#include <bits/stdc++.h>
using namespace std;
int a[1000010],n;
int main ()
{
	a[0]=1;
	a[1]=2;
	for(int i=2;i<=1000000;i++)
	{
		a[i]=a[i-1]+a[i-2];
		a[i]%=3;
	}
	while(scanf("%d",&n)!=EOF)
	{
		if(!a[n])
		cout<<"yes"<<endl;
		else
		cout<<"no"<<endl;
	}
	return 0;
}