#include <iostream>
#include <stdlib.h>
using namespace std;
int n,f[1010]={1};
int main ()
{
	for(int i=1;i<=200;i++) 
	{
		for(int j=0;j<=i/2;j++)
		{
			f[i]+=f[j];
		}
	}
	while(scanf("%d",&n)!=EOF)
	{
		cout<<f[n]<<endl;
	}
	return 0;
}