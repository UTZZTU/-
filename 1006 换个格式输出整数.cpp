#include <bits/stdc++.h>
using namespace std;
int wz[10],k=1;
int main ()
{
	int n;
	cin>>n;
	while(n!=0)
	{
		wz[k]=n%10;
		n/=10;
		k++;
	}
	for(int i=1;i<=wz[3];i++)
	{
		printf("B");
	}
	for(int i=1;i<=wz[2];i++)
	{
		printf("S");
	}
	for(int i=1;i<=wz[1];i++)
	{
		printf("%d",i);
	}
	return 0;
}