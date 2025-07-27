#include<iostream>
using namespace std;
int fun(int a[],int m,int& t,int n)
{
	int i=0,pd=0;
	for(i=0;i<n;i++)
	{
		if(a[i]==m)
		{
			pd=1;
			t=i;
			break;
		}
	}
	return pd;
}
int main ()
{
	int a[25],n,i,m,wz=0;
	cin>>n;
	for(i=0;i<n;i++)
	cin>>a[i];
	cin>>m;
	if(fun(a,m,wz,n))
	{
		printf("%d",wz);
	}
	else
	printf("-1");
	return 0;
}