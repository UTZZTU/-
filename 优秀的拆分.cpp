#include <stdio.h>
#include <iostream>
using namespace std;
int fun(int n)
{
	int i=2;
	while(i*2<=n)
	{
		i*=2;
	}
	return i;
}
int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin>>n;
	if(n%2!=0)
	printf("-1");
	else
	{
		while(n!=0)
		{
			printf("%d ",fun(n));
			n-=fun(n);
		}
	}
	return 0;
}