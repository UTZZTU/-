#include<stdio.h>
#include <vector>
#include <iostream>
using namespace std;
int main ()
{
	vector<vector<int> > a(1010);
	int n,m,i,j,t,x,q;
	scanf("%d%d",&n,&m);
	for(i=1;i<=m;i++)
	{
		scanf("%d",&j);
		if(j==0)
		{
			scanf("%d%d",&t,&x);
			a[t].push_back(x);
		}
		else if(j==1)
		{
			scanf("%d",&t);
			if(a[t].size()!=0)
			{
				for(q=0;q<a[t].size()-1;q++)
				printf("%d ",a[t][q]);
				printf("%d",a[t][q]);
				printf("\n");
			}
			else
			printf("\n");
		}
		else if (j==2)
		{
			scanf("%d",&t);
			if(a[t].size()!=0)
			{
				a[t].clear();
			}
		}
	}
	return 0;
}