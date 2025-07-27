#include <stdio.h>
#include <vector>
#include <iostream>
using namespace std;
int main ()
{
	int n,s[100010],i,js=0,m,ds,ls=0;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%d",&s[i]);
	}
	while(js<n)
	{
	    
		for(m=1;m<=n;m++)
		{
			if(s[m]!=-1)
			{
				ds=s[m];
				s[m]=-1;
				js++;
				break;
			}
		}
		m++;
		for(m;m<=n;m++)
		{
			if(s[m]!=-1&&s[m]<ds)
			{
				ds=s[m];
				s[m]=-1;
				js++;
			}
		}
		ls++;
	}
	printf("%d",ls);
	return 0;
}