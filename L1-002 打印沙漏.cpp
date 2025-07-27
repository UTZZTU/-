#include <bits/stdc++.h>
using namespace std;
int n,t;
char c;
int main ()
{
	cin>>n>>c;
	for(int i=1;;i++)
	{
		if(2*i*i-1<=n)
		t=i;
		else
		break;
	}
	for(int i=t;i>=1;i--)
	{
		for(int j=1;j<=(2*t-2*i)/2;j++)
		printf(" ");
		for(int j=1;j<=2*i-1;j++)
		printf("%c",c);
		printf("\n");
	}
	for(int i=2;i<=t;i++)
	{
		for(int j=1;j<=(2*t-2*i)/2;j++)
		printf(" ");
		for(int j=1;j<=2*i-1;j++)
		printf("%c",c);
		printf("\n");
	}
	printf("%d",n-2*t*t+1);
	return 0;
}