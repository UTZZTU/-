#include <iostream>
using namespace std;
int main ()
{
	int x,a[10000],ks=1,l=1,s=1;
	cin>>x;
	while(s<x)
	{
		s=s*10+1;
		l++;
	}
	while(s!=0)
	{
		a[ks]=s/x;
		ks++;
		s%=x;
		if(s==0)
		break;
		s=s*10+1;
		l++;
	}
	for(int i=1;i<ks;i++)
	printf("%d",a[i]);
	printf(" ");
	printf("%d",l);
	return 0;
}