#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main ()
{
	vector<vector<int> > a(60);
	int n,k,i,j,m,sum=0,t;
	double s;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%d",&m);
		for(j=1;j<=m;j++)
		{
			scanf("%d",&k);
			if(find(a[i].begin(),a[i].end(),k)==a[i].end())
			{
				a[i].push_back(k);
			}
		}
	}
	scanf("%d",&k);
	for(i=1;i<=k;i++)
	{
		sum=0;
		scanf("%d%d",&j,&m);
		for(t=0;t<a[j].size();t++)
		{
			if(find(a[m].begin(),a[m].end(),a[j][t])!=a[m].end())
			{
				sum++;
			}
		}
		s=sum*100.0/(a[j].size()+a[m].size()-sum);
		printf("%.2f%%",s);
		if(i!=k)
		printf("\n");
	}
	return 0;
}